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



/* For CURTAIN */
#define INPUT_PIN_1 12
#define OUTPUT_PIN_1 5

#define INPUT_PIN_2 14
#define OUTPUT_PIN_2 4

#define OUTPUT_LED_PIN 2
int pvs_val1 = 0;
int pvs_val2 = 0;

/* For ESP8266 */
#define LED_OFF 1
#define LED_ON 0


mgos_timer_id save_timer_id = 0;
mgos_timer_id sta1_timer_id = 0;
mgos_timer_id curtain_timer_id = 0;
int curtain_pin = 0;


int random_variable = 2;
static bool save_timer_var = false;
static bool sta1_timer_var = false;
static int count = 0;
static double last_on_off = 0;
static int on_off_current_pin = -1;


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
  send the gpio state to aws
*/
static void report_to_aws() {
  mgos_aws_shadow_updatef(0, "{gpio:[{pin: %d, state: %d}, {pin: %d, state: %d}, {time: %d}]}",
  	OUTPUT_PIN_1, mgos_gpio_read_out(OUTPUT_PIN_1), 
  	OUTPUT_PIN_2, mgos_gpio_read_out(OUTPUT_PIN_2),
	mgos_sys_config_get_outputPins_time());
}

/*
   Subscribe to MQTT Topic
*/
static void sub(struct mg_connection *c, const char *fmt, ...) {
  char buf[100];
  struct mg_mqtt_topic_expression te = {.topic = buf, .qos = 1};
  uint16_t sub_id = mgos_mqtt_get_packet_id();
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);
  mg_mqtt_subscribe(c, &te, 1, sub_id);
  LOG(LL_INFO, ("Subscribing to %s (id %u)", buf, sub_id));
}

/*
   Save Timer callback
*/
static void save_timer_cb(void *arg) {
  if (save_timer_var)
  {
    save_timer_var = ( !save_cfg(&mgos_sys_config, NULL) );
    save_timer_var = false;
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
    save_timer_var = true;
  }
  (void) arg;
  return;
}

/*
   curtain Timer callback
*/
static void curtain_timer_cb(void *arg) {

	mgos_clear_timer(curtain_timer_id);
	mgos_gpio_set_mode(curtain_pin, MGOS_GPIO_MODE_OUTPUT);
	mgos_gpio_write(curtain_pin, 0);
	//mgos_gpio_toggle(curtain_pin);
	(void) arg;
  return;
}


/*
   Button callback
*/
static void button_cb(int pin, void *arg) {
  mgos_wdt_feed();

  int output_pin = -1;
  int *pvs_val = &random_variable;
  int new_val = -1;

  switch (pin) {
    case INPUT_PIN_1:
      pvs_val = &pvs_val1;
      output_pin = OUTPUT_PIN_1;
      new_val = !mgos_gpio_read(pin);
      break;

    case INPUT_PIN_2:
      pvs_val = &pvs_val2;
      output_pin = OUTPUT_PIN_2;
      new_val = !mgos_gpio_read(pin);
      break;
  }

  if (*pvs_val != new_val && output_pin != -1) {
    double now = mg_time();
    // handle 5 times on off
    if ( (now - last_on_off < 5.0) && (pin == on_off_current_pin) && (count <= 10) ) {
      count++;
      if (count == 10) {
        LOG(LL_WARN, ("ON OFF trigger"));
        count = 0;

        /* Enable AP and set timeout */
        mgos_sys_config_set_wifi_ap_enable(true);
        mgos_sys_config_set_wifi_sta1_enable(1);
        //mgos_sys_config_set_wifi_ap_disable_after(300);

        /* Save config and restart */
        save_cfg(&mgos_sys_config, NULL);
        mgos_system_restart_after(500);
      }
    }
    else {
      count = 0;
    }
    last_on_off = now;
    on_off_current_pin = pin;

    LOG(LL_INFO, ("Btn Pressed: Pin - %d, State - %d", pin, new_val));

    struct mg_connection *c = mgos_mqtt_get_global_conn();

    int alertVal = 0;
	int timerVal = 0;
	int futureVal = 0;

	if (output_pin == OUTPUT_PIN_1)
	{
		mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
		mgos_gpio_write(OUTPUT_PIN_2, 0);
		mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
		mgos_gpio_write(OUTPUT_PIN_1, (new_val > 0 ? 1 : 0));

		mgos_sys_config_set_outputPins_out_1(new_val);
		mgos_sys_config_set_outputPins_out_2(0);
		mgos_sys_config_set_inputPins_in_1(new_val);
		alertVal = mgos_sys_config_get_additional_alert_out_1();
		timerVal = mgos_sys_config_get_additional_timer_out_1();
		futureVal = mgos_sys_config_get_additional_future_out_1();
	}

	else if (output_pin == OUTPUT_PIN_2)
	{
		mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
		mgos_gpio_write(OUTPUT_PIN_1, 0);
		mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
		mgos_gpio_write(OUTPUT_PIN_2, (new_val > 0 ? 1 : 0));

		mgos_sys_config_set_outputPins_out_1(0);
		mgos_sys_config_set_outputPins_out_2(new_val);
		mgos_sys_config_set_inputPins_in_2(new_val);
		alertVal = mgos_sys_config_get_additional_alert_out_2();
		timerVal = mgos_sys_config_get_additional_timer_out_2();
		futureVal = mgos_sys_config_get_additional_future_out_2();
	}
	/*
	if (curtain_timer_id != 0)
	{
		mgos_clear_timer(curtain_timer_id);
	}
	curtain_pin = output_pin;
	curtain_timer_id = mgos_set_timer(mgos_sys_config_get_outputPins_time(), true, curtain_timer_cb, NULL);
	*/

	if (c != NULL)
	{
		mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{ type: gpio, pin: %d, state: %d, time: %d, timer: %d, alert: %d, future: %d}",  
			output_pin, new_val, mgos_sys_config_get_outputPins_time(), timerVal, alertVal, futureVal);
		report_to_aws();
	}

    *pvs_val = new_val;
    save_timer_var = true;
  }

  (void) arg;
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
    LOG(LL_WARN, ("MG_EV_MQTT_CONNACK: %d", msg->connack_ret_code));
    /* Check MQTT topics */
    if (mgos_sys_config_get_mqtt_sub() == NULL || mgos_sys_config_get_mqtt_pub() == NULL) {
      LOG(LL_ERROR, ("Run 'mgos config-set mqtt.sub=... mqtt.pub=...'"));
    }
    /* Subscribe to topics */
    else {
      sub(c, "%s", mgos_sys_config_get_mqtt_sub());
      sub(c, "%s", mgos_sys_config_get_mqtt_sub_update());
      report_to_aws();
    }
  }

  /* MQTT sub ack */
  else if (ev == MG_EV_MQTT_SUBACK) {
    LOG(LL_WARN, ("Subscription %u acknowledged", msg->message_id));
  }

  /* MQTT message */
  else if (ev == MG_EV_MQTT_PUBLISH) {
    struct mg_str *s = &msg->payload;
    struct mg_str *sTopic = &msg->topic;
    int pin, state;
    int time = 0;

    /* Our subscription is at QoS 1, we must acknowledge messages sent ot us. */
    mg_mqtt_puback(c, msg->message_id);

    //LOG(LL_DEBUG, ("message received: [%.*s]", (int) s->len, s->p));

    /* Message received on sub topic */
    if (!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub())) {
      if (json_scanf(s->p, s->len, "{gpio: {pin: %d, state: %d, time: %d}}", &pin, &state, &time) >= 2) {

      	int alertVal = 0;
        int timerVal = 0;
        int futureVal = 0;

      	if (pin == OUTPUT_PIN_1)
      	{
      		mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
      		mgos_gpio_write(OUTPUT_PIN_2, 0);
      		mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
        	mgos_gpio_write(OUTPUT_PIN_1, (state > 0 ? 1 : 0));

        	mgos_sys_config_set_outputPins_out_1(state);
        	mgos_sys_config_set_outputPins_out_2(0);
            alertVal = mgos_sys_config_get_additional_alert_out_1();
            timerVal = mgos_sys_config_get_additional_timer_out_1();
            futureVal = mgos_sys_config_get_additional_future_out_1();
      	}
      	else if (pin == OUTPUT_PIN_2)
      	{
      		mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
      		mgos_gpio_write(OUTPUT_PIN_1, 0);
      		mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
        	mgos_gpio_write(OUTPUT_PIN_2, (state > 0 ? 1 : 0));

        	mgos_sys_config_set_outputPins_out_1(0);
        	mgos_sys_config_set_outputPins_out_2(state);
            alertVal = mgos_sys_config_get_additional_alert_out_2();
            timerVal = mgos_sys_config_get_additional_timer_out_2();
            futureVal = mgos_sys_config_get_additional_future_out_2();
      	}

      	if (curtain_timer_id != 0)
		{
			mgos_clear_timer(curtain_timer_id);
		}
		if (time > 0)
		{
			curtain_pin = pin;
			curtain_timer_id = mgos_set_timer(time, true, curtain_timer_cb, NULL);
		}

        mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: gpio, pin: %d, state: %d, time: %d, timer: %d, alert: %d, future: %d}", 
        	pin, state, mgos_sys_config_get_outputPins_time(), timerVal, alertVal, futureVal);
        report_to_aws();
        save_timer_var = true;
      }
    }

    /* Message received on sub_update topic */
    else if (!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub_update())) {
      char *varType, *varToken;
      int value;
      if (json_scanf(s->p, s->len, "{pin: %d, type: %Q, value: %d, token: %Q}", &pin, &varType, &value, &varToken) == 4) {

        if (pin == OUTPUT_PIN_1) {
          if (!strcmp(varType, "timer")) {
            mgos_sys_config_set_additional_timer_out_1(value);
          } else if (!strcmp(varType, "alert")) {
            mgos_sys_config_set_additional_alert_out_1(value);
          } else if (!strcmp(varType, "future")) {
            mgos_sys_config_set_additional_future_out_1(value);
          }
        }

        else if (pin == OUTPUT_PIN_2) {
          if (!strcmp(varType, "timer")) {
            mgos_sys_config_set_additional_timer_out_2(value);
          } else if (!strcmp(varType, "alert")) {
            mgos_sys_config_set_additional_alert_out_2(value);
          } else if (!strcmp(varType, "future")) {
            mgos_sys_config_set_additional_future_out_2(value);
          }
        }

        mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub_update(), 1, false, "{pin: %d, type: %Q, value: %d, token: %Q}", pin, varType, value, varToken);
        save_timer_var = true;
      }
    }
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

  /* set the output gpio pin value at startup */
  int state_pin_1 = mgos_sys_config_get_outputPins_out_1();
  mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(OUTPUT_PIN_1, state_pin_1);

  mgos_gpio_set_mode(INPUT_PIN_1, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_1, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_1);

  /* set the output gpio pin value at startup */
  int state_pin_2 = mgos_sys_config_get_outputPins_out_2();
  mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(OUTPUT_PIN_2, state_pin_2);

  mgos_gpio_set_mode(INPUT_PIN_2, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_2, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_2);


  mgos_wdt_feed();
  mgos_msleep(10);

  /* Add RPC handler */
  mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);

  /* Enable save config timer */
  save_timer_id = mgos_set_timer(2500, true, save_timer_cb, NULL);

  /* For LED indicator */
  mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, led_net_ev_handler, NULL);
  mgos_event_add_handler(MGOS_EVENT_CLOUD_CONNECTED, led_net_ev_handler, NULL);
  mgos_event_add_handler(MGOS_EVENT_CLOUD_DISCONNECTED, led_net_ev_handler, NULL);
  mgos_msleep(10);

  /* Add MQTT handler */
  if (mgos_sys_config_get_mqtt_enable())
  {
    mgos_mqtt_add_global_handler(mqtt_ev_handler, NULL);
    mgos_msleep(10);
  }

  mgos_wdt_feed();
  return MGOS_APP_INIT_SUCCESS;
}
