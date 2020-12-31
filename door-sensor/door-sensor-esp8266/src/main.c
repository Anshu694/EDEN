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


// PINS
#define R_SENSOR 5 //D1
#define AP_BUTTON 14 //D5
#define OUTPUT_ATTINY 4 //D2

// For ESP8266
#define OUTPUT_LED_PIN 2
#define LED_OFF 1
#define LED_ON 0

mgos_timer_id ap_timer_id = 0;
mgos_timer_id timeout_timer_id = 0;
mgos_timer_id sleep_timer_id = 0;
static bool sleep_timer_var = false;

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
   timeout_timer_cb
*/
static void timeout_timer_cb(void * arg) {
    // clear timeout timer
    mgos_clear_timer(timeout_timer_id);
    // Go to sleep
    mgos_gpio_set_mode(OUTPUT_ATTINY, MGOS_GPIO_MODE_OUTPUT);
    mgos_gpio_write(OUTPUT_ATTINY, 0);
    mgos_msleep(10);

    //system_deep_sleep_set_option(0);
    //system_deep_sleep(0);

    (void) arg;
    return;
}

/*
   ap_timer_cb
*/
static void ap_timer_cb(void * arg) {
    mgos_gpio_setup_input(AP_BUTTON, MGOS_GPIO_PULL_UP);
    if (!mgos_gpio_read(AP_BUTTON)) {
        if (!mgos_sys_config_get_wifi_ap_enable()) {
            mgos_sys_config_set_wifi_ap_enable(true);
            mgos_sys_config_set_wifi_ap_disable_after(150);
            save_cfg( & mgos_sys_config, NULL);
            mgos_system_restart_after(500);
        }
    }
    (void) arg;
    return;
}

/*
   sleep_timer_cb
*/
static void sleep_timer_cb(void * arg) {
    if (sleep_timer_var) {
        // save to device
        sleep_timer_var = (!save_cfg( & mgos_sys_config, NULL));
        // clear sleep timer
        mgos_clear_timer(sleep_timer_id);
        // Go to sleep
        mgos_gpio_set_mode(OUTPUT_ATTINY, MGOS_GPIO_MODE_OUTPUT);
        mgos_gpio_write(OUTPUT_ATTINY, 0);
        mgos_msleep(10);
        //deep_sleep_set_option( 0 );
        //system_deep_sleep(0);
    }
    (void) arg;
    return;
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

        // Send Response
        json_printf( & out, "{type: %Q}", "EDEN_DS");
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
   MQTT callback
*/
static void mqtt_ev_handler(struct mg_connection * c, int ev, void * p, void * user_data) {
    // MQTT connection
    if (ev == MG_EV_MQTT_CONNACK) {
        mgos_gpio_set_mode(R_SENSOR, MGOS_GPIO_MODE_INPUT);
        // update sensor value
        if (mgos_aws_shadow_updatef(0, "{door:{state: %d}}", mgos_gpio_read(R_SENSOR))) {
            sleep_timer_var = true;
        }
    }
    (void) c;
    (void) p;
    (void) user_data;
}

/*
   OUTPUT_LED_PIN handler
*/
static void led_net_ev_handler(int ev, void * evd, void * arg) {
    switch (ev) {
    case MGOS_NET_EV_DISCONNECTED:
        if (mgos_sys_config_get_wifi_ap_enable()) {
            mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        } else {
            mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
        }

        break;

    case MGOS_NET_EV_IP_ACQUIRED:
        mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
        if (mgos_sys_config_get_wifi_ap_enable()) {
            mgos_sys_config_set_wifi_ap_enable(false);
            save_cfg( & mgos_sys_config, NULL);
            mgos_wifi_setup_ap( & mgos_sys_config.wifi.ap);
            LOG(LL_WARN, ("#### AP Disabled ####"));
        }
        break;

    case MGOS_EVENT_CLOUD_DISCONNECTED:
        if (mgos_sys_config_get_wifi_ap_enable()) {
            mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        } else {
            mgos_gpio_blink(OUTPUT_LED_PIN, 1000, 1000);
        }
        break;

    case MGOS_EVENT_CLOUD_CONNECTED:
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

    /* Set device parameters */
    set_device_param();

    if (mgos_sys_config_get_wifi_ap_enable()) {
        /* Fast blink in AP Mode */
        mgos_gpio_blink(OUTPUT_LED_PIN, 250, 250);
        LOG(LL_WARN, ("#### AP Started ####"));

        // 2.5 Minute timeout for AP mode
        timeout_timer_id = mgos_set_timer(150000, true, timeout_timer_cb, NULL);
    } else {
        // 40 Sec timeout publishing data
        timeout_timer_id = mgos_set_timer(40000, true, timeout_timer_cb, NULL);
        // Check every 5Sec
        ap_timer_id = mgos_set_timer(5000, true, ap_timer_cb, NULL);
    }

    /* Add RPC handler */
    mg_rpc_add_handler(mgos_rpc_get_global(), "wifiSettings", "{ssid:%Q, pass:%Q}", wifi_rpc_cb, NULL);

    /* Enable sleep config timer */
    // 1 Sec after publishing data to AWS
    sleep_timer_id = mgos_set_timer(1000, true, sleep_timer_cb, NULL);

    /* For LED indicator */
    mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, led_net_ev_handler, NULL);
    mgos_event_add_handler(MGOS_EVENT_CLOUD_CONNECTED, led_net_ev_handler, NULL);
    mgos_event_add_handler(MGOS_EVENT_CLOUD_DISCONNECTED, led_net_ev_handler, NULL);

    /* Add MQTT handler */
    if (mgos_sys_config_get_mqtt_enable()) {
        mgos_mqtt_add_global_handler(mqtt_ev_handler, NULL);
    }
    return MGOS_APP_INIT_SUCCESS;
}