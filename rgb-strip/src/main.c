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
#include "mgos_rgb.h"

const int RED_PIN	=	12;		// D6
const int GREEN_PIN	=	14;		// D5
const int BLUE_PIN	=	4;		// D2


#define OUTPUT_LED_PIN 2
#define LED_OFF 1
#define LED_ON 0

mgos_timer_id save_timer_id = 0;
mgos_timer_id animation_timer_id = 0;
mgos_timer_id sta1_timer_id = 0;

int color_no = 1;
static bool save_timer_var = false;
static bool sta1_timer_var = false;

struct mgos_rgb_led rgb;

/*
   This function replaces ?????? with last digits of mac address
   call during init
*/
static void set_device_param(void) {
  if (mgos_sys_config_get_device_id() != NULL) {
    char *device_id         = strdup(mgos_sys_config_get_device_id());
    char *mqtt_ssl_cert     = strdup(mgos_sys_config_get_mqtt_ssl_cert());
    char *mqtt_ssl_key      = strdup(mgos_sys_config_get_mqtt_ssl_key());
    char *mqtt_pub          = strdup(mgos_sys_config_get_mqtt_pub());
    char *mqtt_sub          = strdup(mgos_sys_config_get_mqtt_sub());
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
static bool report_to_aws(void){
  
  if (mgos_sys_config_get_rgb_i() > 0) {
    return  mgos_aws_shadow_updatef(0, "{rgb:{i:%d,no:%d,t1:%d,t2:%d,c1:%Q,c2:%Q,c3:%Q,c4:%Q,c5:%Q,id:%Q}}", 
            mgos_sys_config_get_rgb_i(),mgos_sys_config_get_rgb_no(),mgos_sys_config_get_rgb_t1(),mgos_sys_config_get_rgb_t2(),
            mgos_sys_config_get_rgb_c1(),mgos_sys_config_get_rgb_c2(),mgos_sys_config_get_rgb_c3(),mgos_sys_config_get_rgb_c4(),
            mgos_sys_config_get_rgb_c5(),mgos_sys_config_get_rgb_id() );
  }
  else {
    return mgos_aws_shadow_updatef(0, "{rgb: {r: %d, g: %d, b: %d, fade: %d}}", rgb.r, rgb.g, rgb.b, rgb.fade );
  }
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
    mgos_sys_config_set_wifi_sta_enable(1);
    sta1_timer_var = false;
    save_timer_var = true;
  }
  (void) arg;
  return;
}


/*
   Animation Timer callback
*/
static void animation_timer_cb(void *arg) {
  if (mgos_sys_config_get_rgb_no() == 0)
  {
    mgos_clear_timer(animation_timer_id);
    mgos_rgb_led_set_hex(&rgb, 0);
    return;
  }
  uint32_t tempNo = 0;
  switch (color_no) {
    case 0:
      color_no = 1;
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c1(), NULL, 16);
      break;
    case 1:
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c1(), NULL, 16);
      break;
    case 2:
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c2(), NULL, 16);
      break;
    case 3:
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c3(), NULL, 16);
      break;
    case 4:
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c4(), NULL, 16);
      break;
    case 5:
      tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c5(), NULL, 16);
      break;
  }

  //mgos_rgb_led_set_hex(&rgb, tempNo);
  mgos_rgb_led_fade_hex(&rgb, tempNo, mgos_sys_config_get_rgb_t1());

  if (color_no < mgos_sys_config_get_rgb_no())
  {
    color_no++;
  }
  else{
    color_no = 1;
  }

  (void) arg;
  return;
}

static void button_cb(int pin, void *arg){
  LOG(LL_INFO, ("ON OFF Trigger"));
  /* Enable AP and set timeout */
  mgos_sys_config_set_wifi_ap_enable(true);
  mgos_sys_config_set_wifi_sta1_enable(1);
  mgos_sys_config_set_wifi_sta_enable(0);
  //mgos_sys_config_set_wifi_ap_disable_after(300);

  /* Save config and restart */
  save_cfg(&mgos_sys_config, NULL);
  mgos_system_restart_after(500);

  (void) pin;
  (void) arg;
}

/*
   WiFi RPC callback
*/
static void wifi_rpc_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {
   mgos_wdt_feed();
  struct mbuf fb;
  struct json_out out = JSON_OUT_MBUF(&fb);
  mbuf_init(&fb, 20);

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
    mgos_clear_timer(sta1_timer_id);
    mgos_sys_config_set_wifi_sta1_enable(0);
    mgos_sys_config_set_wifi_sta_enable(1);
    sta1_timer_var = false;
    save_timer_var = true;
   // mgos_sys_config_set_eden_ap_timer(false);
   
    json_printf(&out,"{type: %Q}" , "EDEN_RGB");
    mg_rpc_send_responsef(ri, "%.*s", fb.len, fb.buf);
    ri = NULL;
    mbuf_free(&fb);

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

static void rgb_set_color_hex_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args){
  mgos_wdt_feed();
  char* ctest = NULL;

  if (json_scanf(args.p, args.len, ri->args_fmt, &ctest) == 1){
    // Disable timer
    if (animation_timer_id != 0) { mgos_clear_timer(animation_timer_id); }
    // Set color
    uint32_t number = (uint32_t) strtol( ctest, NULL, 16);
    mgos_rgb_led_set_hex(&rgb, number);
    // Send response
    mg_rpc_send_responsef(ri, "{rgb:{hex:\"%s\"}}", ctest);
    // Save to fs
    mgos_sys_config_set_rgb_i(1);
    mgos_sys_config_set_rgb_c1(ctest);
    save_timer_var = true;
  }
  else {
    mg_rpc_send_errorf(ri, -1, "Bad request. Expected: {\"rgb\":{\"hex\":\"ffffff\"}}");
  }
  (void) cb_arg;
  (void) fi;
  free(ctest);
  return;
}

static void rgb_read_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args){
  mg_rpc_send_responsef(ri, "{r:%d, g:%d, b:%d}", rgb.r, rgb.g, rgb.b);
  (void) args;
  (void) cb_arg;
  (void) fi;
  return;
}

static void mqtt_ev_handler(struct mg_connection *c, int ev, void *p, void *user_data) {
  mgos_wdt_feed();
  struct mg_mqtt_message *msg = (struct mg_mqtt_message *) p;

  /* MQTT connection */
  if (ev == MG_EV_MQTT_CONNACK) {
    LOG(LL_INFO, ("CONNACK: %d", msg->connack_ret_code));
    if (mgos_sys_config_get_mqtt_sub() == NULL || mgos_sys_config_get_mqtt_pub() == NULL) {
      LOG(LL_ERROR, ("Run 'mgos config-set mqtt.sub=... mqtt.pub=...'"));
    }
    else {
      sub(c, "%s", mgos_sys_config_get_mqtt_sub());
      sub(c, "%s", mgos_sys_config_get_mqtt_sub_update());
      report_to_aws();
    }
  }

  /* MQTT sub ack */
  else if (ev == MG_EV_MQTT_SUBACK) {
    LOG(LL_INFO, ("Subscription %u acknowledged", msg->message_id));
  }

  /* MQTT message */
  else if (ev == MG_EV_MQTT_PUBLISH) {
    struct mg_str *s = &msg->payload;
    struct mg_str *sTopic = &msg->topic;
    int temp[4] = {-1,-1,-1,-1};

    /* Our subscription is at QoS 1, we must acknowledge messages sent ot us. */
    mg_mqtt_puback(c, msg->message_id);

    if(!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub())) {
      int i = 0;
      int no = 0;
      int t1 = 0;
      int t2 = 0;
      char* c1 = NULL;
      char* c2 = NULL;
      char* c3 = NULL;
      char* c4 = NULL;
      char* c5 = NULL;
      char* id = NULL;
      
      if(json_scanf(s->p, s->len, "{rgb: {r: %d, g: %d, b: %d, fade: %d}}", temp, temp+1, temp+2, temp+3) == 4) {
        for (int i = 0; i < 3; ++i)
        {
          if ( (temp[i]>255) || (temp[i]<0) ) { return; }
        }
        if (animation_timer_id != 0) { mgos_clear_timer(animation_timer_id); }
        //mgos_rgb_led_set(&rgb, temp[0], temp[1], temp[2]);
        mgos_rgb_led_fade(&rgb, temp[0], temp[1], temp[2], temp[3]);
        
        mgos_sys_config_set_rgb_r(rgb.r);
        mgos_sys_config_set_rgb_g(rgb.g);
        mgos_sys_config_set_rgb_b(rgb.b);
        mgos_sys_config_set_rgb_fade(rgb.fade);
        mgos_sys_config_set_rgb_i(0);
        
        //mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{rgb:{r:%d,g:%d,b:%d,fade:%d}}", rgb.r,rgb.g,rgb.b,rgb.fade);
        mgos_mqtt_pub(mgos_sys_config_get_mqtt_pub(), s->p, s->len, 1, false);
        report_to_aws();
        save_timer_var = true;
      }
      else if(json_scanf(s->p, s->len, "{rgb:{i:%d,no:%d,t1:%d,t2:%d,c1:%Q,c2:%Q,c3:%Q,c4:%Q,c5:%Q,id:%Q}}", &i,&no,&t1,&t2,&c1,&c2,&c3,&c4,&c5,&id) > 1){
        mgos_sys_config_set_rgb_i(i);
        mgos_sys_config_set_rgb_no(no);
        mgos_sys_config_set_rgb_t1(t1);
        mgos_sys_config_set_rgb_t2(t2);

        mgos_sys_config_set_rgb_c1(c1);
        mgos_sys_config_set_rgb_c2(c2);
        mgos_sys_config_set_rgb_c3(c3);
        mgos_sys_config_set_rgb_c4(c4);
        mgos_sys_config_set_rgb_c5(c5);
        mgos_sys_config_set_rgb_id(id);

        if (i > 10) {
          // Clear previous animation timer
          if (animation_timer_id != 0) { mgos_clear_timer(animation_timer_id); }
          //Set start color no
          color_no = 1;
          // Set timer for animation
          if (t2<300)
          {
          	t2 = 300;
          	mgos_sys_config_set_rgb_t2(t2);
          }
          int time = t1 + t2;
          animation_timer_id = mgos_set_timer(time, true, animation_timer_cb, NULL);
        }
        // Single color
        else if (i == 1) {
          // Clear previous animation timer
          if (animation_timer_id != 0) { mgos_clear_timer(animation_timer_id); }
          // Set color
          uint32_t tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c1(), NULL, 16);
          //mgos_rgb_led_set_hex(&rgb, tempNo);
          mgos_rgb_led_fade_hex(&rgb, tempNo, mgos_sys_config_get_rgb_t1());
        }
        // Send response
        mgos_mqtt_pub(mgos_sys_config_get_mqtt_pub(), s->p, s->len, 1, false);
        mgos_aws_shadow_updatef(0, "{rgb:{i:%d,no:%d,t1:%d,t2:%d,c1:%Q,c2:%Q,c3:%Q,c4:%Q,c5:%Q,id:%Q}}", i,no,t1,t2,c1,c2,c3,c4,c5,id );
        save_timer_var = true;
      }
      else if(json_scanf(s->p, s->len, "{rgb:{hex:%Q}}", &c1) == 1){
        // Clear previous animation timer
        if (animation_timer_id != 0) { mgos_clear_timer(animation_timer_id); }
        uint32_t number = (uint32_t) strtol( c1, NULL, 16);
        mgos_rgb_led_set_hex(&rgb, number);
        // Set color, send response & save to fs
        mgos_sys_config_set_rgb_i(1);
        mgos_sys_config_set_rgb_c1(c1);
        mgos_mqtt_pub(mgos_sys_config_get_mqtt_pub(), s->p, s->len, 1, false);
        mgos_aws_shadow_updatef(0, "{rgb:{hex:%Q}}", c1 );
        save_timer_var = true;
      }

      free(c1);
      free(c2);
      free(c3);
      free(c4);
      free(c5);
      free(id);
    }

    else if(!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub_update())) {
      char *varType, *varToken;
      int pin, value;
      if(json_scanf(s->p, s->len, "{pin: %d, type: %Q, value: %d, token: %Q}", &pin, &varType, &value, &varToken) == 4) {
        /* Do Something */
        mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub_update(), 1, false, "{pin: %d, type: %Q, value: %d, token: %Q}", pin, varType, value, varToken);
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

void mgos_app_preinit(void) {
	mgos_gpio_set_mode(RED_PIN, MGOS_GPIO_MODE_OUTPUT);
	mgos_gpio_write(RED_PIN, 0);
	mgos_gpio_set_mode(GREEN_PIN, MGOS_GPIO_MODE_OUTPUT);
	mgos_gpio_write(GREEN_PIN, 0);
	mgos_gpio_set_mode(BLUE_PIN, MGOS_GPIO_MODE_OUTPUT);
	mgos_gpio_write(BLUE_PIN, 0);
}

enum mgos_app_init_result mgos_app_init(void) {
	/* Set LED OFF Default No connection */
  mgos_gpio_set_mode(OUTPUT_LED_PIN, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(OUTPUT_LED_PIN, LED_OFF);
  mgos_wdt_feed();

  /* Set device parameters */
  set_device_param();
  
	mgos_rgb_led_init(&rgb, RED_PIN, GREEN_PIN, BLUE_PIN);

  // Update current values for next time
  rgb.prev_r = rgb.r;
  rgb.prev_g = rgb.g;
  rgb.prev_b = rgb.b;
  rgb.fade = mgos_sys_config_get_rgb_fade();

  mgos_gpio_set_button_handler(mgos_sys_config_get_eden_button(), 
                    MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_NEG, 50, button_cb, NULL);

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

	//mgos_msleep(1000);
  mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);
  mg_rpc_add_handler(mgos_rpc_get_global(), "RgbSetColorHEX", "{rgb:{hex:%Q}}", rgb_set_color_hex_cb, NULL);
  mg_rpc_add_handler(mgos_rpc_get_global(), "RgbRead", "", rgb_read_cb, NULL);

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

  if (mgos_sys_config_get_rgb_i() > 10) {
    int time = mgos_sys_config_get_rgb_t1() + mgos_sys_config_get_rgb_t2();
    animation_timer_id = mgos_set_timer(time, true, animation_timer_cb, NULL);
  }
  else if (mgos_sys_config_get_rgb_i() == 1) {
    uint32_t tempNo = (uint32_t) strtol( mgos_sys_config_get_rgb_c1(), NULL, 16);
    //mgos_rgb_led_set_hex(&rgb, tempNo);
    mgos_rgb_led_fade_hex(&rgb, tempNo, mgos_sys_config_get_rgb_t1());
  }
  else if (mgos_sys_config_get_rgb_i() == 0) {
    mgos_rgb_led_set(&rgb,  mgos_sys_config_get_rgb_r(),
                            mgos_sys_config_get_rgb_g(),
                            mgos_sys_config_get_rgb_b());
  }

	mgos_wdt_feed();
	return MGOS_APP_INIT_SUCCESS;
}
