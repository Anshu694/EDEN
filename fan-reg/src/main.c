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

#include "mgos_adc.h"

#include "mgos_net.h"


#define INPUT_PIN_1 35
#define OUTPUT_PIN_1 13

#define INPUT_PIN_2 32
#define OUTPUT_PIN_2 27

#define INPUT_PIN_3 33
#define OUTPUT_PIN_3 26

#define INPUT_PIN_4 25
#define OUTPUT_PIN_4 16

// For ESP32
#define OUTPUT_LED_PIN 2
#define LED_OFF 0
#define LED_ON 1

const int ADC_PIN = 34;
const int T1 = 14;
const int T2 = 18;
const int T3 = 4;

/* to store val of fan regulator 0 to 4 */
int fan_state = 0;
int pvs_adc_state = 0;
int reg = 0;

int pvs_val1 = 0;
int pvs_val2 = 0;
int pvs_val3 = 0;
int pvs_val4 = 0;

int random_variable = 2;
static bool save_timer_var = false;
static int count = 0;
static double last_on_off = 0;
static int on_off_current_pin = -1;

mgos_timer_id save_timer_id = 0;
mgos_timer_id timer_id = 0;

/*
   This function replaces ?????? with last digits of mac address
   call during init
*/
static void set_device_param(void) {
    if (mgos_sys_config_get_device_id() != NULL) {
        char * device_id = strdup(mgos_sys_config_get_device_id());
        char * mqtt_ssl_cert = strdup(mgos_sys_config_get_mqtt_ssl_cert());
        char * mqtt_ssl_key = strdup(mgos_sys_config_get_mqtt_ssl_key());
        char * mqtt_pub = strdup(mgos_sys_config_get_mqtt_pub());
        char * mqtt_sub = strdup(mgos_sys_config_get_mqtt_sub());
        char * mqtt_pub_update = strdup(mgos_sys_config_get_mqtt_pub_update());
        char * mqtt_sub_update = strdup(mgos_sys_config_get_mqtt_sub_update());

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

        save_cfg( & mgos_sys_config, NULL);
    }
    return;
}

/*
  send the gpio state to aws
*/
static void report_to_aws() {
    /* send the state to aws */
    mgos_aws_shadow_updatef(0, "{gpio:[{pin: %d, state: %d}, {pin: %d, state: %d}, {pin: %d, state: %d}, {pin: %d, state: %d, reg: %d}]}", OUTPUT_PIN_1, mgos_gpio_read_out(OUTPUT_PIN_1), OUTPUT_PIN_2, mgos_gpio_read_out(OUTPUT_PIN_2), OUTPUT_PIN_3, mgos_gpio_read_out(OUTPUT_PIN_3), OUTPUT_PIN_4, fan_state, reg);
}

/*
   Subscribe to MQTT Topic
*/
static void sub(struct mg_connection * c,
    const char * fmt, ...) {
    char buf[100];
    struct mg_mqtt_topic_expression te = {
        .topic = buf,
        .qos = 1
    };
    uint16_t sub_id = mgos_mqtt_get_packet_id();
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    mg_mqtt_subscribe(c, & te, 1, sub_id);
    LOG(LL_INFO, ("Subscribing to %s (id %u)", buf, sub_id));
}

/*
   Save Timer callback
*/
static void save_timer_cb(void * arg) {
    if (save_timer_var) {
        save_timer_var = (!save_cfg( & mgos_sys_config, NULL));
    }
    (void) arg;
    return;
}

/*
    Set Fan Speed
    val range 0 to 4
*/
static void set_fan_speed(int val, int triac_1, int triac_2, int triac_3) {
    /* set gpio into output mode */
    mgos_gpio_set_mode(triac_1, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_set_mode(triac_2, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_set_mode(triac_3, MGOS_GPIO_MODE_OUTPUT);

    /* update global var */
    fan_state = val;
    pvs_adc_state = mgos_adc_read_voltage(ADC_PIN) / 660; /* val 0 to 4 */
    if (fan_state != 0 && fan_state != pvs_adc_state)
        reg = fan_state;
    else(reg = pvs_adc_state);

    switch (val) {
    case 0:
        mgos_gpio_write(T1, 0);
        mgos_gpio_write(T2, 0);
        mgos_gpio_write(T3, 0);
        break;
    case 1:
        mgos_gpio_write(T1, 0);
        mgos_gpio_write(T2, 1);
        mgos_gpio_write(T3, 0);
        break;
    case 2:
        mgos_gpio_write(T1, 0);
        mgos_gpio_write(T2, 0);
        mgos_gpio_write(T3, 1);
        break;
    case 3:
        mgos_gpio_write(T1, 0);
        mgos_gpio_write(T2, 1);
        mgos_gpio_write(T3, 1);
        break;
    case 4:
        mgos_gpio_write(T1, 1);
        mgos_gpio_write(T2, 0);
        mgos_gpio_write(T3, 0);
        break;
    }
    LOG(LL_WARN, ("Fan Speed: %d", val));
}

/*
    ADC callback
*/
static void adc_cb(void * arg) {
    if (mgos_sys_config_get_outputPins_out_4()) {
        int val = mgos_adc_read_voltage(ADC_PIN) / 660;
        if (val != pvs_adc_state) {
            set_fan_speed(val, T1, T2, T3);

            struct mg_connection * c = mgos_mqtt_get_global_conn();
            if (c != NULL) {
                mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{ type: gpio, pin: %d, state: %d, reg: %d, timer: %d, alert: %d, future: %d}", OUTPUT_PIN_4, val, reg, 0, 0, 0);
                report_to_aws();
            }

            LOG(LL_WARN, ("ADC val: %d prev: %d", val, pvs_adc_state));

            mgos_sys_config_set_inputPins_in_4(val);
            mgos_sys_config_set_outputPins_out_4(val);
            save_timer_var = true;
        }
    }
    (void) arg;
}

static void button_cb(int pin, void * arg) {
    int output_pin = -1;
    int * pvs_val = & random_variable;
    int new_val = -1;

    switch (pin) {
    case INPUT_PIN_1:
        pvs_val = & pvs_val1;
        output_pin = OUTPUT_PIN_1;
        new_val = !mgos_gpio_read(pin);
        break;
    case INPUT_PIN_2:
        pvs_val = & pvs_val2;
        output_pin = OUTPUT_PIN_2;
        new_val = !mgos_gpio_read(pin);
        break;
    case INPUT_PIN_3:
        pvs_val = & pvs_val3;
        output_pin = OUTPUT_PIN_3;
        new_val = !mgos_gpio_read(pin);
        break;
    case INPUT_PIN_4:
        pvs_val = & pvs_val4;
        output_pin = OUTPUT_PIN_4;
        new_val = !mgos_gpio_read(pin);
        break;
    }

    if ( * pvs_val != new_val && output_pin != -1) {
        double now = mg_time();

        /* handle 5 times on off */
        if (timer_id == 0 && now - last_on_off < 5.0 && pin == on_off_current_pin && count <= 10) {
            count++;
            if (count == 10) {
                LOG(LL_WARN, ("ON OFF trigger"));
                count = 0;

                // Enable AP and set timeout
                mgos_sys_config_set_wifi_ap_enable(true);
                mgos_sys_config_set_wifi_ap_disable_after(300);

                // Save config and restart
                save_cfg( & mgos_sys_config, NULL);
                mgos_system_restart_after(500);
            }
        } else {
            count = 0;
        }

        last_on_off = now;
        on_off_current_pin = pin;

        LOG(LL_INFO, ("#Button Pressed# Pin - %d, State - %d", pin, new_val));

        if (output_pin == OUTPUT_PIN_4) {
            if (new_val == 1) {
                int val;
                val = mgos_adc_read_voltage(ADC_PIN) / 660;
                mgos_sys_config_set_outputPins_out_4(new_val);
                mgos_sys_config_set_outputPins_reg(val);
                set_fan_speed(val, T1, T2, T3);
            } else {
                mgos_sys_config_set_outputPins_out_4(0);
                set_fan_speed(0, T1, T2, T3);
            }
        } else {
            mgos_gpio_set_mode(output_pin, MGOS_GPIO_MODE_OUTPUT);
            mgos_gpio_write(output_pin, new_val);
        }

        struct mg_connection * c = mgos_mqtt_get_global_conn();

        int alertVal = 0;
        int timerVal = 0;
        int futureVal = 0;

        switch (pin) {
        case INPUT_PIN_1:
            mgos_sys_config_set_outputPins_out_1(new_val);
            mgos_sys_config_set_inputPins_in_1(new_val);
            alertVal = mgos_sys_config_get_additional_alert_out_1();
            timerVal = mgos_sys_config_get_additional_timer_out_1();
            futureVal = mgos_sys_config_get_additional_future_out_1();
            break;
        case INPUT_PIN_2:
            mgos_sys_config_set_outputPins_out_2(new_val);
            mgos_sys_config_set_inputPins_in_2(new_val);
            alertVal = mgos_sys_config_get_additional_alert_out_2();
            timerVal = mgos_sys_config_get_additional_timer_out_2();
            futureVal = mgos_sys_config_get_additional_future_out_2();
            break;
        case INPUT_PIN_3:
            mgos_sys_config_set_outputPins_out_3(new_val);
            mgos_sys_config_set_inputPins_in_3(new_val);
            alertVal = mgos_sys_config_get_additional_alert_out_3();
            timerVal = mgos_sys_config_get_additional_timer_out_3();
            futureVal = mgos_sys_config_get_additional_future_out_3();
            break;
        case INPUT_PIN_4:
            mgos_sys_config_set_outputPins_out_4(new_val);
            mgos_sys_config_set_inputPins_in_4(new_val);
            alertVal = mgos_sys_config_get_additional_alert_out_4();
            timerVal = mgos_sys_config_get_additional_timer_out_4();
            futureVal = mgos_sys_config_get_additional_future_out_4();
            break;   
        }

        if (c != NULL) {
            if (pin == OUTPUT_PIN_4) {
                mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: %Q, pin: %d, state: %d, reg: %d, timer: %d, alert: %d, future: %d}", "gpio", output_pin, new_val, pvs_adc_state, timerVal, alertVal, futureVal);
            } else {
                mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: %Q, pin: %d, state: %d, timer: %d, alert: %d, future: %d}", "gpio", output_pin, new_val, timerVal, alertVal, futureVal);
            }
            report_to_aws();
        }
        * pvs_val = new_val;
        save_timer_var = true;
    }
    (void) arg;
}

/*
   WiFi RPC callback
*/
static void wifi_rpc_cb(struct mg_rpc_request_info * ri, void * cb_arg, struct mg_rpc_frame_info * fi, struct mg_str args) {
    struct mbuf fb;
    struct json_out out = JSON_OUT_MBUF( & fb);
    mbuf_init( & fb, 20);

    char * ssid = "";
    char * pass = "";

    if (json_scanf(args.p, args.len, ri -> args_fmt, & ssid, & pass) == 2) {
        // Set SSID and PASS
        mgos_sys_config_set_wifi_sta_enable(true);
        mgos_sys_config_set_wifi_sta_ssid(ssid);
        mgos_sys_config_set_wifi_sta_pass(pass);

        // Send response
        json_printf( & out, "{type: %Q, pin :%Q}", "EDEN_4F", "16,26,27,13");
        mg_rpc_send_responsef(ri, "%.*s", fb.len, fb.buf);
        ri = NULL;
        mbuf_free( & fb);

        // Disable AP, Save config and Restart
        mgos_sys_config_set_wifi_ap_enable(false);
        save_cfg( & mgos_sys_config, NULL);
        mgos_system_restart_after(500);
    }

    // Free memory
    free(ssid);
    free(pass);

    // To avoid compilation error UNUSED_PARAM
    (void) cb_arg;
    (void) fi;
}

/*
   Local GPIO RPC callback
*/
static void rpc_gpio_write_cb(struct mg_rpc_request_info * ri, void * cb_arg,
    struct mg_rpc_frame_info * fi, struct mg_str args) {
    int pin;
    int state;

    json_scanf(args.p, args.len, "{pin:%d, state:%d}", & pin, & state);

    struct mbuf fb;
    struct json_out out = JSON_OUT_MBUF( & fb);
    mbuf_init( & fb, 20);

    if (pin == OUTPUT_PIN_4) {
        set_fan_speed(state, T1, T2, T3);
    } else {
        mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_OUTPUT);
        mgos_gpio_write(pin, state);
        state = mgos_gpio_read_out(pin);
    }

    LOG(LL_INFO, ("#RPC# Pin - %d, State - %d", pin, state));

    switch (pin) {
    case OUTPUT_PIN_1:
        mgos_sys_config_set_outputPins_out_1(state);
        break;
    case OUTPUT_PIN_2:
        mgos_sys_config_set_outputPins_out_2(state);
        break;
    case OUTPUT_PIN_3:
        mgos_sys_config_set_outputPins_out_3(state);
        break;
    case OUTPUT_PIN_4:
        mgos_sys_config_set_outputPins_out_4(fan_state);
        break;

        save_timer_var = true;
    }

    json_printf( & out, "{pin:%d, state:%d}", pin, state);

    mg_rpc_send_responsef(ri, "%.*s", fb.len, fb.buf);
    ri = NULL;
    mbuf_free( & fb);

    (void) cb_arg;
    (void) fi;

}

/*
   Local GPIO Read callback
*/
static void local_gpio_shadow_cb(struct mg_rpc_request_info * ri, void * cb_arg,
    struct mg_rpc_frame_info * fi, struct mg_str args) {
    struct mbuf fb;
    struct json_out out = JSON_OUT_MBUF( & fb);
    mbuf_init( & fb, 20);

    LOG(LL_WARN, ("RPC Service_called - %s", "local_gpio_shadow_cb"));

    /* for 4 switch */
    json_printf( & out, "{gpio:[{pin: %d, state: %d}, {pin: %d, state: %d}, {pin: %d, state: %d}, {pin: %d, state: %d}]}", OUTPUT_PIN_1, mgos_gpio_read_out(OUTPUT_PIN_1), OUTPUT_PIN_2, mgos_gpio_read_out(OUTPUT_PIN_2), OUTPUT_PIN_3, mgos_gpio_read_out(OUTPUT_PIN_3), OUTPUT_PIN_4, fan_state);

    mg_rpc_send_responsef(ri, "%.*s", fb.len, fb.buf);
    ri = NULL;
    mbuf_free( & fb);

    (void) args;
    (void) cb_arg;
    (void) fi;
}

/*
   MQTT callback
*/
static void mqtt_ev_handler(struct mg_connection * c, int ev, void * p, void * user_data) {
    struct mg_mqtt_message * msg = (struct mg_mqtt_message * ) p;

    // MQTT connection
    if (ev == MG_EV_MQTT_CONNACK) {
        LOG(LL_WARN, ("CONNACK: %d", msg -> connack_ret_code));
        // Check MQTT topics
        if (mgos_sys_config_get_mqtt_sub() == NULL || mgos_sys_config_get_mqtt_pub() == NULL) {
            LOG(LL_ERROR, ("Run 'mgos config-set mqtt.sub=... mqtt.pub=...'"));
        }
        // Subscribe to topics
        else {
            sub(c, "%s", mgos_sys_config_get_mqtt_sub());
            sub(c, "%s", mgos_sys_config_get_mqtt_sub_update());
            report_to_aws();
        }
    }

    // MQTT sub ack
    else if (ev == MG_EV_MQTT_SUBACK) {
        LOG(LL_WARN, ("Subscription %u acknowledged", msg -> message_id));
    }

    // MQTT message
    else if (ev == MG_EV_MQTT_PUBLISH) {
        struct mg_str * s = & msg -> payload;
        struct mg_str * sTopic = & msg -> topic;
        int pin, state;

        // Our subscription is at QoS 1, we must acknowledge messages sent to us.
        mg_mqtt_puback(c, msg -> message_id);

        //LOG(LL_DEBUG, ("message received: [%.*s]", (int) s->len, s->p));

        // Message received on sub topic
        if (!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub())) {
            if (json_scanf(s -> p, s -> len, "{gpio: {pin: %d, state: %d}}", & pin, & state) == 2) {

                // Set GPIO pin to a given state
                if (pin == OUTPUT_PIN_4) {
                    set_fan_speed(state, T1, T2, T3);
                } else {
                    mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_OUTPUT);
                    mgos_gpio_write(pin, (state > 0 ? 1 : 0));
                }

                int alertVal = 0;
                int timerVal = 0;
                int futureVal = 0;

                switch (pin) {
                case OUTPUT_PIN_1:
                    mgos_sys_config_set_outputPins_out_1(state);
                    alertVal = mgos_sys_config_get_additional_alert_out_1();
                    timerVal = mgos_sys_config_get_additional_timer_out_1();
                    futureVal = mgos_sys_config_get_additional_future_out_1();
                    break;
                case OUTPUT_PIN_2:
                    mgos_sys_config_set_outputPins_out_2(state);
                    alertVal = mgos_sys_config_get_additional_alert_out_2();
                    timerVal = mgos_sys_config_get_additional_timer_out_2();
                    futureVal = mgos_sys_config_get_additional_future_out_2();
                    break;
                case OUTPUT_PIN_3:
                    mgos_sys_config_set_outputPins_out_3(state);
                    alertVal = mgos_sys_config_get_additional_alert_out_3();
                    timerVal = mgos_sys_config_get_additional_timer_out_3();
                    futureVal = mgos_sys_config_get_additional_future_out_3();
                    break;
                case OUTPUT_PIN_4:
                    if (state > 0) {
                        mgos_sys_config_set_outputPins_reg(fan_state);
                        mgos_sys_config_set_outputPins_out_4(1);
                    } else
                        mgos_sys_config_set_outputPins_out_4(0);
                    alertVal = mgos_sys_config_get_additional_alert_out_4();
                    timerVal = mgos_sys_config_get_additional_timer_out_4();
                    futureVal = mgos_sys_config_get_additional_future_out_4();
                    break;
                }

                if (pin == OUTPUT_PIN_4) {
                    mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: %Q, pin: %d, state: %d, reg: %d, timer: %d, alert: %d, future: %d}", "gpio", pin, state, reg, timerVal, alertVal, futureVal);
                    report_to_aws();
                } else {
                    mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 1, false, "{type: %Q, pin: %d, state: %d, timer: %d, alert: %d, future: %d}", "gpio", pin, state, timerVal, alertVal, futureVal);
                }
                report_to_aws();
                save_timer_var = true;
            }
        } else if (!mg_vcmp(sTopic, mgos_sys_config_get_mqtt_sub_update())) {
            char * varType, * varToken;
            int value;
            if (json_scanf(s -> p, s -> len, "{pin: %d, type: %Q, value: %d, token: %Q}", & pin, & varType, & value, & varToken) == 4) {
                if (pin == OUTPUT_PIN_1) {
                    if (!strcmp(varType, "timer")) {
                        mgos_sys_config_set_additional_timer_out_1(value);
                    } else if (!strcmp(varType, "alert")) {
                        mgos_sys_config_set_additional_alert_out_1(value);
                    } else if (!strcmp(varType, "future")) {
                        mgos_sys_config_set_additional_future_out_1(value);
                    }
                } else if (pin == OUTPUT_PIN_2) {
                    if (!strcmp(varType, "timer")) {
                        mgos_sys_config_set_additional_timer_out_2(value);
                    } else if (!strcmp(varType, "alert")) {
                        mgos_sys_config_set_additional_alert_out_2(value);
                    } else if (!strcmp(varType, "future")) {
                        mgos_sys_config_set_additional_future_out_2(value);
                    }
                } else if (pin == OUTPUT_PIN_3) {
                    if (!strcmp(varType, "timer")) {
                        mgos_sys_config_set_additional_timer_out_3(value);
                    } else if (!strcmp(varType, "alert")) {
                        mgos_sys_config_set_additional_alert_out_3(value);
                    } else if (!strcmp(varType, "future")) {
                        mgos_sys_config_set_additional_future_out_3(value);
                    }
                } else if (pin == OUTPUT_PIN_4) {
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
static void led_net_ev_handler(int ev, void * evd, void * arg) {
    switch (ev) {
    case MGOS_NET_EV_DISCONNECTED:
        LOG(LL_WARN, ("MGOS_NET_EV_DISCONNECTED"));
        if (mgos_sys_config_get_wifi_ap_enable()) {
            mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        } else {
            mgos_gpio_blink(OUTPUT_LED_PIN, 500, 500);
        }
        break;

    case MGOS_NET_EV_CONNECTING:
        LOG(LL_INFO, ("MGOS_NET_EV_CONNECTING"));
        mgos_gpio_blink(OUTPUT_LED_PIN, 500, 500);
        break;

    case MGOS_NET_EV_CONNECTED:
        LOG(LL_INFO, ("MGOS_NET_EV_CONNECTED"));
        break;

    case MGOS_NET_EV_IP_ACQUIRED:
        LOG(LL_WARN, ("MGOS_NET_EV_IP_ACQUIRED"));
        mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
        break;

    case MGOS_EVENT_CLOUD_DISCONNECTED:
        LOG(LL_WARN, ("MGOS_EVENT_CLOUD_DISCONNECTED"));
        if (mgos_sys_config_get_wifi_ap_enable()) {
            mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        } else {
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
    // Set LED OFF Default No connection
    mgos_gpio_set_mode(OUTPUT_LED_PIN, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_write(OUTPUT_LED_PIN, LED_OFF);

    // Set device parameters
    set_device_param();

    LOG(LL_WARN, ("\n\n\n### Init Setting ### %d", mgos_sys_config_get_wifi_ap_enable()));

    if (mgos_sys_config_get_wifi_ap_enable()) {
        // Fast blink in AP Mode
        mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        LOG(LL_WARN, ("#### AP Started ####"));
    } else if (mgos_sys_config_get_wifi_sta_enable()) {
        mgos_gpio_blink(OUTPUT_LED_PIN, 500, 500);
    }

    mgos_adc_enable(ADC_PIN);

    /* read adc val 0 to 4 */
    int fan_state = mgos_adc_read_voltage(ADC_PIN) / 660;

    int state_pin_1 = mgos_sys_config_get_outputPins_out_1();
    // int state_pin_2 = mgos_sys_config_get_outputPins_out_2();
    int state_pin_3 = mgos_sys_config_get_outputPins_out_3();
    int state_pin_4 = mgos_sys_config_get_outputPins_out_4();

    /* set the output gpio pin value at startup */
    mgos_gpio_set_mode(OUTPUT_PIN_1, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_write(OUTPUT_PIN_1, state_pin_1);
    // mgos_gpio_set_mode(OUTPUT_PIN_2, MGOS_GPIO_MODE_OUTPUT);
    // mgos_gpio_write(OUTPUT_PIN_2, state_pin_2);
    mgos_gpio_set_mode(OUTPUT_PIN_3, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_write(OUTPUT_PIN_3, state_pin_3);
    if (state_pin_4 == 1) {
        set_fan_speed(fan_state, T1, T2, T3);
    } else
        set_fan_speed(0, T1, T2, T3);

    mgos_gpio_set_mode(INPUT_PIN_1, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(INPUT_PIN_1, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
    mgos_gpio_enable_int(INPUT_PIN_1);

    // mgos_gpio_set_mode(INPUT_PIN_2, MGOS_GPIO_MODE_INPUT);
    // mgos_gpio_set_int_handler(INPUT_PIN_2, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
    // mgos_gpio_enable_int(INPUT_PIN_2);

    mgos_gpio_set_mode(INPUT_PIN_3, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(INPUT_PIN_3, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
    mgos_gpio_enable_int(INPUT_PIN_3);

    mgos_gpio_set_mode(INPUT_PIN_4, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(INPUT_PIN_4, MGOS_GPIO_INT_EDGE_NEG, button_cb, NULL);
    mgos_gpio_enable_int(INPUT_PIN_4);

    mgos_set_timer(1500, MGOS_TIMER_REPEAT, adc_cb, NULL);

    mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);
    mg_rpc_add_handler(mgos_rpc_get_global(), "gpioWriteLocal", "{pin:%Q, state:%Q}", rpc_gpio_write_cb, NULL);
    mg_rpc_add_handler(mgos_rpc_get_global(), "gpioShadowLocal", "{}", local_gpio_shadow_cb, NULL);

    // Enable save config timer
    save_timer_id = mgos_set_timer(2500, true, save_timer_cb, NULL);

    // For LED indicator
    mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, led_net_ev_handler, NULL);
    mgos_event_add_handler(MGOS_EVENT_CLOUD_CONNECTED, led_net_ev_handler, NULL);
    mgos_event_add_handler(MGOS_EVENT_CLOUD_DISCONNECTED, led_net_ev_handler, NULL);

    // Add MQTT handler
    if (mgos_sys_config_get_mqtt_enable()) {
        mgos_mqtt_add_global_handler(mqtt_ev_handler, NULL);
        mgos_msleep(10);
    }

    return MGOS_APP_INIT_SUCCESS;
}