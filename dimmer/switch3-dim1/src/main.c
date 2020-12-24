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

#include "mgos_uart.h"

/*******************************************************************************/
#define UART_NO 0
/*******************************************************************************/

/* For ATMEGA328P */
#define OUTPUT_PIN_1 3
#define OUTPUT_PIN_2 4
#define OUTPUT_PIN_3 5
#define OUTPUT_PIN_4 6

/* For ESP8266 */
#define INPUT_PIN_1 4
#define INPUT_PIN_2 5
#define INPUT_PIN_3 12
#define INPUT_PIN_4 13

int pvs_val1 = 0;
int pvs_val2 = 0;
int pvs_val3 = 0;
int pvs_val4 = 0;

/* For ESP8266 LED Pin*/
#define OUTPUT_LED_PIN 2
#define LED_OFF 1
#define LED_ON 0

mgos_timer_id save_timer_id = 0;
int random_variable = 2;
static bool save_timer_var = false;
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
  mgos_aws_shadow_updatef(0, "{gpio:[{pin: %d, state: %d, dim: %d}, {pin: %d, state: %d, dim: %d}, {pin: %d, state: %d, dim: %d}, {pin: %d, state: %d, dim: %d}]}", 
    OUTPUT_PIN_1, mgos_sys_config_get_outputPins_state_1(), mgos_sys_config_get_outputPins_dim_1(), 
    OUTPUT_PIN_2, mgos_sys_config_get_outputPins_state_2(), mgos_sys_config_get_outputPins_dim_2(), 
    OUTPUT_PIN_3, mgos_sys_config_get_outputPins_state_3(), mgos_sys_config_get_outputPins_dim_3(), 
    OUTPUT_PIN_4, mgos_sys_config_get_outputPins_state_4(), mgos_sys_config_get_outputPins_dim_4() );
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
   Button callback
*/
static void button_cb(int pin, void *arg) {
  mgos_wdt_feed();

  int output_pin = -1;
  int *pvs_val = &random_variable;
  int new_val = -1;
  int dim = -1;

  switch (pin) {
    case INPUT_PIN_1:
      pvs_val = &pvs_val1;
      output_pin = OUTPUT_PIN_1;
      new_val = !mgos_gpio_read(pin);
      dim = mgos_sys_config_get_outputPins_dim_1();
      break;

    case INPUT_PIN_2:
      pvs_val = &pvs_val2;
      output_pin = OUTPUT_PIN_2;
      new_val = !mgos_gpio_read(pin);
      dim = mgos_sys_config_get_outputPins_dim_2();
      break;

    case INPUT_PIN_3:
      pvs_val = &pvs_val3;
      output_pin = OUTPUT_PIN_3;
      new_val = !mgos_gpio_read(pin);
      dim = mgos_sys_config_get_outputPins_dim_3();
      break;

    case INPUT_PIN_4:
      pvs_val = &pvs_val4;
      output_pin = OUTPUT_PIN_4;
      new_val = !mgos_gpio_read(pin);
      dim = mgos_sys_config_get_outputPins_dim_4();
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

    mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", output_pin, new_val, dim);

    struct mg_connection *c = mgos_mqtt_get_global_conn();

    int alertVal = 0;
    int timerVal = 0;
    int futureVal = 0;

    switch (pin) {
      case INPUT_PIN_1:
        mgos_sys_config_set_outputPins_state_1(new_val);
        mgos_sys_config_set_inputPins_state_1(new_val);
        alertVal = mgos_sys_config_get_additional_alert_out_1();
        timerVal = mgos_sys_config_get_additional_timer_out_1();
        futureVal = mgos_sys_config_get_additional_future_out_1();
        break;

      case INPUT_PIN_2:
        mgos_sys_config_set_outputPins_state_2(new_val);
        mgos_sys_config_set_inputPins_state_2(new_val);
        alertVal = mgos_sys_config_get_additional_alert_out_2();
        timerVal = mgos_sys_config_get_additional_timer_out_2();
        futureVal = mgos_sys_config_get_additional_future_out_2();
        break;

      case INPUT_PIN_3:
        mgos_sys_config_set_outputPins_state_3(new_val);
        mgos_sys_config_set_inputPins_state_3(new_val);
        alertVal = mgos_sys_config_get_additional_alert_out_3();
        timerVal = mgos_sys_config_get_additional_timer_out_3();
        futureVal = mgos_sys_config_get_additional_future_out_3();
        break;

      case INPUT_PIN_4:
        mgos_sys_config_set_outputPins_state_4(new_val);
        mgos_sys_config_set_inputPins_state_4(new_val);
        alertVal = mgos_sys_config_get_additional_alert_out_4();
        timerVal = mgos_sys_config_get_additional_timer_out_4();
        futureVal = mgos_sys_config_get_additional_future_out_4();
        break;
    }

    if (c != NULL) {
      mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{ type: gpio, pin: %d, state: %d, dim: %d, timer: %d, alert: %d, future: %d}" , output_pin, new_val, dim, timerVal, alertVal, futureVal);
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
    //report_to_aws();
  }

  /* MQTT message */
  else if (ev == MG_EV_MQTT_PUBLISH) {
    struct mg_str *s = &msg->payload;
    struct mg_str *sTopic = &msg->topic;
    int pin, state, dim;

    /* Our subscription is at QoS 1, we must acknowledge messages sent ot us. */
    mg_mqtt_puback(c, msg->message_id);

    //LOG(LL_DEBUG, ("message received: [%.*s]", (int) s->len, s->p));

    /* Message received on sub topic */
    if (!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub())) {
      if (json_scanf(s->p, s->len, "{gpio: {pin: %d, state: %d, dim: %d}}", &pin, &state, &dim) == 3) {
        
        int alertVal = 0;
        int timerVal = 0;
        int futureVal = 0;
        mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", pin, state, dim);

        switch (pin) {
          case OUTPUT_PIN_1:
            mgos_sys_config_set_outputPins_state_1(state);
            mgos_sys_config_set_outputPins_dim_1(dim);
            alertVal = mgos_sys_config_get_additional_alert_out_1();
            timerVal = mgos_sys_config_get_additional_timer_out_1();
            futureVal = mgos_sys_config_get_additional_future_out_1();
            break;

          case OUTPUT_PIN_2:
            mgos_sys_config_set_outputPins_state_2(state);
            mgos_sys_config_set_outputPins_dim_2(dim);
            alertVal = mgos_sys_config_get_additional_alert_out_2();
            timerVal = mgos_sys_config_get_additional_timer_out_2();
            futureVal = mgos_sys_config_get_additional_future_out_2();
            break;

          case OUTPUT_PIN_3:
            mgos_sys_config_set_outputPins_state_3(state);
            mgos_sys_config_set_outputPins_dim_3(dim);
            alertVal = mgos_sys_config_get_additional_alert_out_3();
            timerVal = mgos_sys_config_get_additional_timer_out_3();
            futureVal = mgos_sys_config_get_additional_future_out_3();
            break;

          case OUTPUT_PIN_4:
            mgos_sys_config_set_outputPins_state_4(state);
            mgos_sys_config_set_outputPins_dim_4(dim);
            alertVal = mgos_sys_config_get_additional_alert_out_4();
            timerVal = mgos_sys_config_get_additional_timer_out_4();
            futureVal = mgos_sys_config_get_additional_future_out_4();
            break;
        }

        mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: %Q, pin: %d, state: %d, dim: %d, timer: %d, alert: %d, future: %d}" , "gpio" , pin, state, dim, timerVal, alertVal, futureVal);
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


        else if (pin == OUTPUT_PIN_3) {
          if (!strcmp(varType, "timer")) {
            mgos_sys_config_set_additional_timer_out_3(value);
          } else if (!strcmp(varType, "alert")) {
            mgos_sys_config_set_additional_alert_out_3(value);
          } else if (!strcmp(varType, "future")) {
            mgos_sys_config_set_additional_future_out_3(value);
          }
        }

        else if (pin == OUTPUT_PIN_4) {
          if (!strcmp(varType, "timer")) {
            mgos_sys_config_set_additional_timer_out_4(value);
          } else if (!strcmp(varType, "alert")) {
            mgos_sys_config_set_additional_alert_out_4(value);
          } else if (!strcmp(varType, "future")) {
            mgos_sys_config_set_additional_future_out_4(value);
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

  /* UART init */
  struct mgos_uart_config ucfg;
  mgos_uart_config_set_defaults(UART_NO, &ucfg);

  ucfg.baud_rate = 115200;
  ucfg.num_data_bits = 8;
  ucfg.parity = MGOS_UART_PARITY_NONE;
  ucfg.stop_bits = MGOS_UART_STOP_BITS_1;
  
  if (!mgos_uart_configure(UART_NO, &ucfg)) {
    return MGOS_APP_INIT_ERROR;
  }
  mgos_uart_printf(UART_NO, "{}");
  mgos_msleep(10);
  mgos_uart_printf(UART_NO, "{}");
  mgos_msleep(10);
  mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", OUTPUT_PIN_1, mgos_sys_config_get_outputPins_state_1(), mgos_sys_config_get_outputPins_dim_1());
  mgos_msleep(10);
  mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", OUTPUT_PIN_2, mgos_sys_config_get_outputPins_state_2(), mgos_sys_config_get_outputPins_dim_2());
  mgos_msleep(10);
  mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", OUTPUT_PIN_3, mgos_sys_config_get_outputPins_state_3(), mgos_sys_config_get_outputPins_dim_3());
  mgos_msleep(10);
  mgos_uart_printf(UART_NO, "{pin: %d, state: %d, dim: %d}", OUTPUT_PIN_4, mgos_sys_config_get_outputPins_state_4(), mgos_sys_config_get_outputPins_dim_4());

  mgos_wdt_feed();
  mgos_msleep(10);

  mgos_gpio_set_mode(INPUT_PIN_1, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_1, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_1);

  mgos_gpio_set_mode(INPUT_PIN_2, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_2, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_2);

  mgos_gpio_set_mode(INPUT_PIN_3, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_3, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_3);

  mgos_gpio_set_mode(INPUT_PIN_4, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(INPUT_PIN_4, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
  mgos_gpio_enable_int(INPUT_PIN_4);

  /* Add RPC handler */
  mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);
  //mg_rpc_add_handler(mgos_rpc_get_global(), "gpioWriteLocal", "{pin:%Q, state:%Q}", rpc_gpio_write_cb, NULL);
  //mg_rpc_add_handler(mgos_rpc_get_global(), "gpioShadowLocal", "{}", local_gpio_shadow_cb, NULL);

  /* Enable save config timer */
  save_timer_id = mgos_set_timer(2000, true, save_timer_cb, NULL);

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