#include <stdio.h>
#include "mgos.h"
#include "common/platform.h"
#include "mgos_app.h"
#include "mgos_gpio.h"
#include "mgos_timers.h"
#include "mgos_sys_config.h"
#include "mgos_wifi.h"
#include "mgos_system.h"
#include "mgos_mqtt.h"
#include "mgos_aws_shadow.h"
#include "mgos_rpc.h"
#include "mgos_net.h"


/* For ESP8266 */
#define OUTPUT_LED_PIN 2
#define LED_OFF 1
#define LED_ON 0


mgos_timer_id save_timer_id = 0;
mgos_timer_id sta1_timer_id = 0;

static bool save_timer_var = false;
static bool sta1_timer_var = false;


/*
   This function replaces ?????? with last digits of mac address
   call during init
*/
static void set_device_param(void) {
  if (mgos_sys_config_get_device_id() != NULL) {
    char *device_id     = strdup(mgos_sys_config_get_device_id());
    char *mqtt_ssl_cert   = strdup(mgos_sys_config_get_mqtt_ssl_cert());
    char *mqtt_ssl_key    = strdup(mgos_sys_config_get_mqtt_ssl_key());
    char *mqtt_pub      = strdup(mgos_sys_config_get_mqtt_pub());
    char *mqtt_sub      = strdup(mgos_sys_config_get_mqtt_sub());
    char *mqtt_pub_update   = strdup(mgos_sys_config_get_mqtt_pub_update());
    char *mqtt_sub_update   = strdup(mgos_sys_config_get_mqtt_sub_update());

    mgos_expand_mac_address_placeholders(device_id);
    mgos_expand_mac_address_placeholders(mqtt_ssl_cert);
    mgos_expand_mac_address_placeholders(mqtt_ssl_key);
    mgos_expand_mac_address_placeholders(mqtt_pub);
    mgos_expand_mac_address_placeholders(mqtt_sub);
    mgos_expand_mac_address_placeholders(mqtt_pub_update);
    mgos_expand_mac_address_placeholders(mqtt_sub_update);

    mgos_sys_config_set_device_id(device_id);
    mgos_sys_config_set_aws_thing_name(device_id);
    mgos_sys_config_set_mqtt_client_id(device_id);
    mgos_sys_config_set_mqtt_ssl_cert(mqtt_ssl_cert);
    mgos_sys_config_set_mqtt_ssl_key(mqtt_ssl_key);
    mgos_sys_config_set_mqtt_pub(mqtt_pub);
    mgos_sys_config_set_mqtt_sub(mqtt_sub);
    mgos_sys_config_set_mqtt_pub_update(mqtt_pub_update);
    mgos_sys_config_set_mqtt_sub_update(mqtt_sub_update);

    free(device_id);
    free(mqtt_ssl_cert);
    free(mqtt_ssl_key);
    free(mqtt_pub);
    free(mqtt_sub);
    free(mqtt_pub_update);
    free(mqtt_sub_update);

    save_cfg(&mgos_sys_config, NULL);

    return;
  }
}

/*
   Save Timer callback
*/
static void save_timer_cb(void *arg) {
  if (save_timer_var)
  {
    save_timer_var = ( !save_cfg(&mgos_sys_config, NULL) );
    mgos_gpio_set_mode(4, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_write(4, 0);
  }
  (void) arg;
  return;
}


/*
   sta1 Timer callback
*/
static void sta1_timer_cb(void *arg) {
  if (sta1_timer_var)
  {
    mgos_clear_timer(sta1_timer_id);
    mgos_sys_config_set_wifi_sta1_enable(0);
    sta1_timer_var = false;
    save_cfg(&mgos_sys_config, NULL);
  }
  (void) arg;
  return;
}


/*
   WiFi RPC callback
*/
static void wifi_rpc_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {
  mgos_wdt_feed();

  char* ssid = "";
  char* pass = "";

  if (json_scanf(args.p, args.len, ri->args_fmt, &ssid, &pass) == 2 )
  {
    /* Set SSID and PASS */
    mgos_sys_config_set_wifi_sta_enable(true);
    mgos_sys_config_set_wifi_sta_ssid(ssid);
    mgos_sys_config_set_wifi_sta_pass(pass);

    /* Disable AP */
    mgos_sys_config_set_wifi_ap_enable(false);
    mg_rpc_send_responsef(ri, "%d", 33);

    /* Save config and Restart */
    save_cfg(&mgos_sys_config, NULL);
    mgos_system_restart_after(500);
  }

  /* Free memory */
  free(ssid);
  free(pass);

  /* To avoid compilation error UNUSED_PARAM */
  (void) cb_arg;
  (void) fi;
}



/*
   MQTT callback
*/
static void mqtt_ev_handler(struct mg_connection *c, int ev, void *p, void *user_data) {
  mgos_wdt_feed();
  struct mg_mqtt_message *msg = (struct mg_mqtt_message *) p;

  /* MQTT connection */
  if (ev == MG_EV_MQTT_CONNACK) {
    mgos_gpio_set_mode(5, MGOS_GPIO_MODE_INPUT);
    if (mgos_aws_shadow_updatef( 0, "{door:{state: %d}}", mgos_gpio_read(5)))
    {
      save_timer_var = true;
    }
    //mgos_msleep(100);
  }

  /* MQTT sub ack */
  else if (ev == MG_EV_MQTT_SUBACK) {
    LOG(LL_WARN, ("Subscription %u acknowledged", msg->message_id));
  }
  (void) user_data;
}

/*
   OUTPUT_LED_PIN handler
*/
static void led_net_ev_handler(int ev, void *evd, void *arg) {
  switch (ev) {
    case MGOS_NET_EV_DISCONNECTED:
      LOG(LL_WARN, ("MGOS_NET_EV_DISCONNECTED"));
      mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
      if (!mgos_sys_config_get_wifi_ap_enable())
      {
      	mgos_sys_config_set_wifi_ap_enable(true);
      	save_cfg(&mgos_sys_config, NULL);
      	//mgos_wifi_setup_ap(&mgos_sys_config.wifi.ap);
        mgos_system_restart_after(500);
      }
      break;

    case MGOS_NET_EV_CONNECTING:
      LOG(LL_INFO, ("MGOS_NET_EV_CONNECTING"));
      break;

    case MGOS_NET_EV_CONNECTED:
      LOG(LL_INFO, ("MGOS_NET_EV_CONNECTED"));
      break;

    case MGOS_NET_EV_IP_ACQUIRED:
      LOG(LL_WARN, ("MGOS_NET_EV_IP_ACQUIRED"));
      mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
      mgos_sys_config_set_wifi_ap_enable(false);
      save_cfg(&mgos_sys_config, NULL);
      mgos_wifi_setup_ap(&mgos_sys_config.wifi.ap);
      LOG(LL_WARN, ("#### AP Disabled ####"));
      break;

    case MGOS_EVENT_CLOUD_DISCONNECTED:
      LOG(LL_WARN, ("MGOS_EVENT_CLOUD_DISCONNECTED"));
      if (mgos_sys_config_get_wifi_ap_enable())
      {
      	mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
      }
      else{
      	mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
      }
      break;

    case MGOS_EVENT_CLOUD_CONNECTED:
      LOG(LL_WARN, ("MGOS_EVENT_CLOUD_CONNECTED"));
      mgos_gpio_blink(OUTPUT_LED_PIN, 0, 0);
      mgos_gpio_write(OUTPUT_LED_PIN, LED_ON);
      break;
  }
  (void) evd;
  (void) arg;
}

/*
   App init
*/
enum mgos_app_init_result mgos_app_init(void) {
  /* Set LED OFF Default No connection */
  mgos_gpio_set_mode(OUTPUT_LED_PIN, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(OUTPUT_LED_PIN, LED_OFF);
  mgos_wdt_feed();

  /* Set device parameters */
  set_device_param();

  LOG(LL_WARN, ( "\n\n\n### Init Setting ### %d", mgos_sys_config_get_wifi_ap_enable() ));

  if ( mgos_sys_config_get_wifi_ap_enable() ) {
    /* Fast blink in AP Mode */
    mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
    LOG(LL_WARN, ("#### AP Started ####"));
  }
  if (mgos_sys_config_get_wifi_sta1_enable())
  {
  	/* Enable sta1 timer */
  	sta1_timer_id = mgos_set_timer(300000, true, sta1_timer_cb, NULL);
  }
	
  /* Add RPC handler */
  mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);

  /* Enable save config timer */
  save_timer_id = mgos_set_timer(1500, true, save_timer_cb, NULL);

  /* For LED indicator */
  mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, led_net_ev_handler, NULL);
  mgos_event_add_handler(MGOS_EVENT_CLOUD_CONNECTED, led_net_ev_handler, NULL);
  mgos_event_add_handler(MGOS_EVENT_CLOUD_DISCONNECTED, led_net_ev_handler, NULL);
  //mgos_msleep(10);

  /* Add MQTT handler */
  if (mgos_sys_config_get_mqtt_enable())
  {
    mgos_mqtt_add_global_handler(mqtt_ev_handler, NULL);
    //mgos_msleep(10);
  }
  mgos_wdt_feed();
  return MGOS_APP_INIT_SUCCESS;
}
