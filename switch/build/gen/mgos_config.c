/* clang-format off */
/*
 * Generated file - do not edit.
 * Command: /mongoose-os/tools/mgos_gen_config.py --c_name=mgos_config --c_global_name=mgos_sys_config --dest_dir=/data/fwbuild-volumes/2.19.0/apps/EDEN_3/esp8266/build_contexts/build_ctx_863855865/build/gen/ /mongoose-os/src/mgos_debug_udp_config.yaml /data/fwbuild-volumes/2.19.0/apps/EDEN_3/esp8266/build_contexts/build_ctx_863855865/build/gen/mos_conf_schema.yml
 */

#include "mgos_config.h"

#include <stdbool.h>

#include "mgos_config_util.h"


/* struct mgos_config */
static const struct mgos_conf_entry mgos_config_schema_[] = {
    {.type = CONF_TYPE_OBJECT, .key = "", .offset = 0, .num_desc = 281},
    {.type = CONF_TYPE_OBJECT, .key = "debug", .offset = offsetof(struct mgos_config, debug), .num_desc = 12},
    {.type = CONF_TYPE_STRING, .key = "udp_log_addr", .offset = offsetof(struct mgos_config, debug.udp_log_addr)},
    {.type = CONF_TYPE_INT, .key = "udp_log_level", .offset = offsetof(struct mgos_config, debug.udp_log_level)},
    {.type = CONF_TYPE_INT, .key = "mbedtls_level", .offset = offsetof(struct mgos_config, debug.mbedtls_level)},
    {.type = CONF_TYPE_INT, .key = "level", .offset = offsetof(struct mgos_config, debug.level)},
    {.type = CONF_TYPE_STRING, .key = "file_level", .offset = offsetof(struct mgos_config, debug.file_level)},
    {.type = CONF_TYPE_INT, .key = "event_level", .offset = offsetof(struct mgos_config, debug.event_level)},
    {.type = CONF_TYPE_INT, .key = "stdout_uart", .offset = offsetof(struct mgos_config, debug.stdout_uart)},
    {.type = CONF_TYPE_INT, .key = "stderr_uart", .offset = offsetof(struct mgos_config, debug.stderr_uart)},
    {.type = CONF_TYPE_INT, .key = "factory_reset_gpio", .offset = offsetof(struct mgos_config, debug.factory_reset_gpio)},
    {.type = CONF_TYPE_STRING, .key = "mg_mgr_hexdump_file", .offset = offsetof(struct mgos_config, debug.mg_mgr_hexdump_file)},
    {.type = CONF_TYPE_STRING, .key = "stdout_topic", .offset = offsetof(struct mgos_config, debug.stdout_topic)},
    {.type = CONF_TYPE_STRING, .key = "stderr_topic", .offset = offsetof(struct mgos_config, debug.stderr_topic)},
    {.type = CONF_TYPE_OBJECT, .key = "device", .offset = offsetof(struct mgos_config, device), .num_desc = 5},
    {.type = CONF_TYPE_STRING, .key = "id", .offset = offsetof(struct mgos_config, device.id)},
    {.type = CONF_TYPE_STRING, .key = "license", .offset = offsetof(struct mgos_config, device.license)},
    {.type = CONF_TYPE_STRING, .key = "mac", .offset = offsetof(struct mgos_config, device.mac)},
    {.type = CONF_TYPE_STRING, .key = "public_key", .offset = offsetof(struct mgos_config, device.public_key)},
    {.type = CONF_TYPE_STRING, .key = "sn", .offset = offsetof(struct mgos_config, device.sn)},
    {.type = CONF_TYPE_OBJECT, .key = "sys", .offset = offsetof(struct mgos_config, sys), .num_desc = 3},
    {.type = CONF_TYPE_STRING, .key = "tz_spec", .offset = offsetof(struct mgos_config, sys.tz_spec)},
    {.type = CONF_TYPE_INT, .key = "wdt_timeout", .offset = offsetof(struct mgos_config, sys.wdt_timeout)},
    {.type = CONF_TYPE_STRING, .key = "pref_ota_lib", .offset = offsetof(struct mgos_config, sys.pref_ota_lib)},
    {.type = CONF_TYPE_STRING, .key = "conf_acl", .offset = offsetof(struct mgos_config, conf_acl)},
    {.type = CONF_TYPE_OBJECT, .key = "mqtt", .offset = offsetof(struct mgos_config, mqtt), .num_desc = 27},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, mqtt.enable)},
    {.type = CONF_TYPE_STRING, .key = "server", .offset = offsetof(struct mgos_config, mqtt.server)},
    {.type = CONF_TYPE_STRING, .key = "client_id", .offset = offsetof(struct mgos_config, mqtt.client_id)},
    {.type = CONF_TYPE_STRING, .key = "user", .offset = offsetof(struct mgos_config, mqtt.user)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, mqtt.pass)},
    {.type = CONF_TYPE_DOUBLE, .key = "reconnect_timeout_min", .offset = offsetof(struct mgos_config, mqtt.reconnect_timeout_min)},
    {.type = CONF_TYPE_DOUBLE, .key = "reconnect_timeout_max", .offset = offsetof(struct mgos_config, mqtt.reconnect_timeout_max)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, mqtt.ssl_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, mqtt.ssl_key)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, mqtt.ssl_ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cipher_suites", .offset = offsetof(struct mgos_config, mqtt.ssl_cipher_suites)},
    {.type = CONF_TYPE_STRING, .key = "ssl_psk_identity", .offset = offsetof(struct mgos_config, mqtt.ssl_psk_identity)},
    {.type = CONF_TYPE_STRING, .key = "ssl_psk_key", .offset = offsetof(struct mgos_config, mqtt.ssl_psk_key)},
    {.type = CONF_TYPE_BOOL, .key = "clean_session", .offset = offsetof(struct mgos_config, mqtt.clean_session)},
    {.type = CONF_TYPE_INT, .key = "keep_alive", .offset = offsetof(struct mgos_config, mqtt.keep_alive)},
    {.type = CONF_TYPE_STRING, .key = "will_topic", .offset = offsetof(struct mgos_config, mqtt.will_topic)},
    {.type = CONF_TYPE_STRING, .key = "will_message", .offset = offsetof(struct mgos_config, mqtt.will_message)},
    {.type = CONF_TYPE_BOOL, .key = "will_retain", .offset = offsetof(struct mgos_config, mqtt.will_retain)},
    {.type = CONF_TYPE_INT, .key = "max_qos", .offset = offsetof(struct mgos_config, mqtt.max_qos)},
    {.type = CONF_TYPE_INT, .key = "recv_mbuf_limit", .offset = offsetof(struct mgos_config, mqtt.recv_mbuf_limit)},
    {.type = CONF_TYPE_BOOL, .key = "require_time", .offset = offsetof(struct mgos_config, mqtt.require_time)},
    {.type = CONF_TYPE_BOOL, .key = "cloud_events", .offset = offsetof(struct mgos_config, mqtt.cloud_events)},
    {.type = CONF_TYPE_INT, .key = "max_queue_length", .offset = offsetof(struct mgos_config, mqtt.max_queue_length)},
    {.type = CONF_TYPE_STRING, .key = "pub", .offset = offsetof(struct mgos_config, mqtt.pub)},
    {.type = CONF_TYPE_STRING, .key = "sub", .offset = offsetof(struct mgos_config, mqtt.sub)},
    {.type = CONF_TYPE_STRING, .key = "pub_update", .offset = offsetof(struct mgos_config, mqtt.pub_update)},
    {.type = CONF_TYPE_STRING, .key = "sub_update", .offset = offsetof(struct mgos_config, mqtt.sub_update)},
    {.type = CONF_TYPE_OBJECT, .key = "mqtt1", .offset = offsetof(struct mgos_config, mqtt1), .num_desc = 27},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, mqtt1.enable)},
    {.type = CONF_TYPE_STRING, .key = "server", .offset = offsetof(struct mgos_config, mqtt1.server)},
    {.type = CONF_TYPE_STRING, .key = "client_id", .offset = offsetof(struct mgos_config, mqtt1.client_id)},
    {.type = CONF_TYPE_STRING, .key = "user", .offset = offsetof(struct mgos_config, mqtt1.user)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, mqtt1.pass)},
    {.type = CONF_TYPE_DOUBLE, .key = "reconnect_timeout_min", .offset = offsetof(struct mgos_config, mqtt1.reconnect_timeout_min)},
    {.type = CONF_TYPE_DOUBLE, .key = "reconnect_timeout_max", .offset = offsetof(struct mgos_config, mqtt1.reconnect_timeout_max)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, mqtt1.ssl_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, mqtt1.ssl_key)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, mqtt1.ssl_ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cipher_suites", .offset = offsetof(struct mgos_config, mqtt1.ssl_cipher_suites)},
    {.type = CONF_TYPE_STRING, .key = "ssl_psk_identity", .offset = offsetof(struct mgos_config, mqtt1.ssl_psk_identity)},
    {.type = CONF_TYPE_STRING, .key = "ssl_psk_key", .offset = offsetof(struct mgos_config, mqtt1.ssl_psk_key)},
    {.type = CONF_TYPE_BOOL, .key = "clean_session", .offset = offsetof(struct mgos_config, mqtt1.clean_session)},
    {.type = CONF_TYPE_INT, .key = "keep_alive", .offset = offsetof(struct mgos_config, mqtt1.keep_alive)},
    {.type = CONF_TYPE_STRING, .key = "will_topic", .offset = offsetof(struct mgos_config, mqtt1.will_topic)},
    {.type = CONF_TYPE_STRING, .key = "will_message", .offset = offsetof(struct mgos_config, mqtt1.will_message)},
    {.type = CONF_TYPE_BOOL, .key = "will_retain", .offset = offsetof(struct mgos_config, mqtt1.will_retain)},
    {.type = CONF_TYPE_INT, .key = "max_qos", .offset = offsetof(struct mgos_config, mqtt1.max_qos)},
    {.type = CONF_TYPE_INT, .key = "recv_mbuf_limit", .offset = offsetof(struct mgos_config, mqtt1.recv_mbuf_limit)},
    {.type = CONF_TYPE_BOOL, .key = "require_time", .offset = offsetof(struct mgos_config, mqtt1.require_time)},
    {.type = CONF_TYPE_BOOL, .key = "cloud_events", .offset = offsetof(struct mgos_config, mqtt1.cloud_events)},
    {.type = CONF_TYPE_INT, .key = "max_queue_length", .offset = offsetof(struct mgos_config, mqtt1.max_queue_length)},
    {.type = CONF_TYPE_STRING, .key = "pub", .offset = offsetof(struct mgos_config, mqtt1.pub)},
    {.type = CONF_TYPE_STRING, .key = "sub", .offset = offsetof(struct mgos_config, mqtt1.sub)},
    {.type = CONF_TYPE_STRING, .key = "pub_update", .offset = offsetof(struct mgos_config, mqtt1.pub_update)},
    {.type = CONF_TYPE_STRING, .key = "sub_update", .offset = offsetof(struct mgos_config, mqtt1.sub_update)},
    {.type = CONF_TYPE_OBJECT, .key = "shadow", .offset = offsetof(struct mgos_config, shadow), .num_desc = 5},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, shadow.enable)},
    {.type = CONF_TYPE_STRING, .key = "lib", .offset = offsetof(struct mgos_config, shadow.lib)},
    {.type = CONF_TYPE_BOOL, .key = "get_on_connect", .offset = offsetof(struct mgos_config, shadow.get_on_connect)},
    {.type = CONF_TYPE_BOOL, .key = "ota_enable", .offset = offsetof(struct mgos_config, shadow.ota_enable)},
    {.type = CONF_TYPE_BOOL, .key = "autocommit", .offset = offsetof(struct mgos_config, shadow.autocommit)},
    {.type = CONF_TYPE_OBJECT, .key = "aws", .offset = offsetof(struct mgos_config, aws), .num_desc = 5},
    {.type = CONF_TYPE_STRING, .key = "thing_name", .offset = offsetof(struct mgos_config, aws.thing_name)},
    {.type = CONF_TYPE_OBJECT, .key = "greengrass", .offset = offsetof(struct mgos_config, aws.greengrass), .num_desc = 3},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, aws.greengrass.enable)},
    {.type = CONF_TYPE_INT, .key = "reconnect_timeout_min", .offset = offsetof(struct mgos_config, aws.greengrass.reconnect_timeout_min)},
    {.type = CONF_TYPE_INT, .key = "reconnect_timeout_max", .offset = offsetof(struct mgos_config, aws.greengrass.reconnect_timeout_max)},
    {.type = CONF_TYPE_OBJECT, .key = "update", .offset = offsetof(struct mgos_config, update), .num_desc = 9},
    {.type = CONF_TYPE_INT, .key = "timeout", .offset = offsetof(struct mgos_config, update.timeout)},
    {.type = CONF_TYPE_INT, .key = "commit_timeout", .offset = offsetof(struct mgos_config, update.commit_timeout)},
    {.type = CONF_TYPE_STRING, .key = "url", .offset = offsetof(struct mgos_config, update.url)},
    {.type = CONF_TYPE_INT, .key = "interval", .offset = offsetof(struct mgos_config, update.interval)},
    {.type = CONF_TYPE_STRING, .key = "extra_http_headers", .offset = offsetof(struct mgos_config, update.extra_http_headers)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_file", .offset = offsetof(struct mgos_config, update.ssl_ca_file)},
    {.type = CONF_TYPE_STRING, .key = "ssl_client_cert_file", .offset = offsetof(struct mgos_config, update.ssl_client_cert_file)},
    {.type = CONF_TYPE_STRING, .key = "ssl_server_name", .offset = offsetof(struct mgos_config, update.ssl_server_name)},
    {.type = CONF_TYPE_BOOL, .key = "enable_post", .offset = offsetof(struct mgos_config, update.enable_post)},
    {.type = CONF_TYPE_OBJECT, .key = "rpc", .offset = offsetof(struct mgos_config, rpc), .num_desc = 29},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, rpc.enable)},
    {.type = CONF_TYPE_BOOL, .key = "http_enable", .offset = offsetof(struct mgos_config, rpc.http_enable)},
    {.type = CONF_TYPE_BOOL, .key = "service_sys_enable", .offset = offsetof(struct mgos_config, rpc.service_sys_enable)},
    {.type = CONF_TYPE_INT, .key = "max_frame_size", .offset = offsetof(struct mgos_config, rpc.max_frame_size)},
    {.type = CONF_TYPE_INT, .key = "max_queue_length", .offset = offsetof(struct mgos_config, rpc.max_queue_length)},
    {.type = CONF_TYPE_INT, .key = "default_out_channel_idle_close_timeout", .offset = offsetof(struct mgos_config, rpc.default_out_channel_idle_close_timeout)},
    {.type = CONF_TYPE_STRING, .key = "acl_file", .offset = offsetof(struct mgos_config, rpc.acl_file)},
    {.type = CONF_TYPE_STRING, .key = "auth_domain", .offset = offsetof(struct mgos_config, rpc.auth_domain)},
    {.type = CONF_TYPE_STRING, .key = "auth_file", .offset = offsetof(struct mgos_config, rpc.auth_file)},
    {.type = CONF_TYPE_OBJECT, .key = "ws", .offset = offsetof(struct mgos_config, rpc.ws), .num_desc = 8},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, rpc.ws.enable)},
    {.type = CONF_TYPE_STRING, .key = "server_address", .offset = offsetof(struct mgos_config, rpc.ws.server_address)},
    {.type = CONF_TYPE_INT, .key = "reconnect_interval_min", .offset = offsetof(struct mgos_config, rpc.ws.reconnect_interval_min)},
    {.type = CONF_TYPE_INT, .key = "reconnect_interval_max", .offset = offsetof(struct mgos_config, rpc.ws.reconnect_interval_max)},
    {.type = CONF_TYPE_STRING, .key = "ssl_server_name", .offset = offsetof(struct mgos_config, rpc.ws.ssl_server_name)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, rpc.ws.ssl_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, rpc.ws.ssl_key)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, rpc.ws.ssl_ca_cert)},
    {.type = CONF_TYPE_OBJECT, .key = "mqtt", .offset = offsetof(struct mgos_config, rpc.mqtt), .num_desc = 5},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, rpc.mqtt.enable)},
    {.type = CONF_TYPE_STRING, .key = "pub_topic", .offset = offsetof(struct mgos_config, rpc.mqtt.pub_topic)},
    {.type = CONF_TYPE_STRING, .key = "sub_topic", .offset = offsetof(struct mgos_config, rpc.mqtt.sub_topic)},
    {.type = CONF_TYPE_BOOL, .key = "sub_wc", .offset = offsetof(struct mgos_config, rpc.mqtt.sub_wc)},
    {.type = CONF_TYPE_INT, .key = "qos", .offset = offsetof(struct mgos_config, rpc.mqtt.qos)},
    {.type = CONF_TYPE_OBJECT, .key = "uart", .offset = offsetof(struct mgos_config, rpc.uart), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "uart_no", .offset = offsetof(struct mgos_config, rpc.uart.uart_no)},
    {.type = CONF_TYPE_INT, .key = "baud_rate", .offset = offsetof(struct mgos_config, rpc.uart.baud_rate)},
    {.type = CONF_TYPE_INT, .key = "fc_type", .offset = offsetof(struct mgos_config, rpc.uart.fc_type)},
    {.type = CONF_TYPE_STRING, .key = "dst", .offset = offsetof(struct mgos_config, rpc.uart.dst)},
    {.type = CONF_TYPE_OBJECT, .key = "dash", .offset = offsetof(struct mgos_config, dash), .num_desc = 7},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, dash.enable)},
    {.type = CONF_TYPE_STRING, .key = "token", .offset = offsetof(struct mgos_config, dash.token)},
    {.type = CONF_TYPE_STRING, .key = "server", .offset = offsetof(struct mgos_config, dash.server)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, dash.ssl_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, dash.ssl_key)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, dash.ssl_ca_cert)},
    {.type = CONF_TYPE_BOOL, .key = "send_logs", .offset = offsetof(struct mgos_config, dash.send_logs)},
    {.type = CONF_TYPE_OBJECT, .key = "file_logger", .offset = offsetof(struct mgos_config, file_logger), .num_desc = 12},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, file_logger.enable)},
    {.type = CONF_TYPE_STRING, .key = "dir", .offset = offsetof(struct mgos_config, file_logger.dir)},
    {.type = CONF_TYPE_STRING, .key = "prefix", .offset = offsetof(struct mgos_config, file_logger.prefix)},
    {.type = CONF_TYPE_INT, .key = "max_file_size", .offset = offsetof(struct mgos_config, file_logger.max_file_size)},
    {.type = CONF_TYPE_INT, .key = "max_num_files", .offset = offsetof(struct mgos_config, file_logger.max_num_files)},
    {.type = CONF_TYPE_BOOL, .key = "timestamps", .offset = offsetof(struct mgos_config, file_logger.timestamps)},
    {.type = CONF_TYPE_INT, .key = "level", .offset = offsetof(struct mgos_config, file_logger.level)},
    {.type = CONF_TYPE_STRING, .key = "include", .offset = offsetof(struct mgos_config, file_logger.include)},
    {.type = CONF_TYPE_BOOL, .key = "syslog_enable", .offset = offsetof(struct mgos_config, file_logger.syslog_enable)},
    {.type = CONF_TYPE_BOOL, .key = "rpc_service_enable", .offset = offsetof(struct mgos_config, file_logger.rpc_service_enable)},
    {.type = CONF_TYPE_INT, .key = "buf_size", .offset = offsetof(struct mgos_config, file_logger.buf_size)},
    {.type = CONF_TYPE_BOOL, .key = "buf_line", .offset = offsetof(struct mgos_config, file_logger.buf_line)},
    {.type = CONF_TYPE_OBJECT, .key = "http", .offset = offsetof(struct mgos_config, http), .num_desc = 12},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, http.enable)},
    {.type = CONF_TYPE_STRING, .key = "listen_addr", .offset = offsetof(struct mgos_config, http.listen_addr)},
    {.type = CONF_TYPE_STRING, .key = "document_root", .offset = offsetof(struct mgos_config, http.document_root)},
    {.type = CONF_TYPE_STRING, .key = "index_files", .offset = offsetof(struct mgos_config, http.index_files)},
    {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, http.ssl_cert)},
    {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, http.ssl_key)},
    {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, http.ssl_ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "upload_acl", .offset = offsetof(struct mgos_config, http.upload_acl)},
    {.type = CONF_TYPE_STRING, .key = "hidden_files", .offset = offsetof(struct mgos_config, http.hidden_files)},
    {.type = CONF_TYPE_STRING, .key = "auth_domain", .offset = offsetof(struct mgos_config, http.auth_domain)},
    {.type = CONF_TYPE_STRING, .key = "auth_file", .offset = offsetof(struct mgos_config, http.auth_file)},
    {.type = CONF_TYPE_STRING, .key = "extra_headers", .offset = offsetof(struct mgos_config, http.extra_headers)},
    {.type = CONF_TYPE_OBJECT, .key = "i2c", .offset = offsetof(struct mgos_config, i2c), .num_desc = 5},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, i2c.enable)},
    {.type = CONF_TYPE_INT, .key = "freq", .offset = offsetof(struct mgos_config, i2c.freq)},
    {.type = CONF_TYPE_BOOL, .key = "debug", .offset = offsetof(struct mgos_config, i2c.debug)},
    {.type = CONF_TYPE_INT, .key = "sda_gpio", .offset = offsetof(struct mgos_config, i2c.sda_gpio)},
    {.type = CONF_TYPE_INT, .key = "scl_gpio", .offset = offsetof(struct mgos_config, i2c.scl_gpio)},
    {.type = CONF_TYPE_OBJECT, .key = "i2c1", .offset = offsetof(struct mgos_config, i2c1), .num_desc = 5},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, i2c1.enable)},
    {.type = CONF_TYPE_INT, .key = "freq", .offset = offsetof(struct mgos_config, i2c1.freq)},
    {.type = CONF_TYPE_BOOL, .key = "debug", .offset = offsetof(struct mgos_config, i2c1.debug)},
    {.type = CONF_TYPE_INT, .key = "sda_gpio", .offset = offsetof(struct mgos_config, i2c1.sda_gpio)},
    {.type = CONF_TYPE_INT, .key = "scl_gpio", .offset = offsetof(struct mgos_config, i2c1.scl_gpio)},
    {.type = CONF_TYPE_OBJECT, .key = "sntp", .offset = offsetof(struct mgos_config, sntp), .num_desc = 5},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, sntp.enable)},
    {.type = CONF_TYPE_STRING, .key = "server", .offset = offsetof(struct mgos_config, sntp.server)},
    {.type = CONF_TYPE_INT, .key = "retry_min", .offset = offsetof(struct mgos_config, sntp.retry_min)},
    {.type = CONF_TYPE_INT, .key = "retry_max", .offset = offsetof(struct mgos_config, sntp.retry_max)},
    {.type = CONF_TYPE_INT, .key = "update_interval", .offset = offsetof(struct mgos_config, sntp.update_interval)},
    {.type = CONF_TYPE_OBJECT, .key = "spi", .offset = offsetof(struct mgos_config, spi), .num_desc = 8},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, spi.enable)},
    {.type = CONF_TYPE_BOOL, .key = "debug", .offset = offsetof(struct mgos_config, spi.debug)},
    {.type = CONF_TYPE_INT, .key = "miso_gpio", .offset = offsetof(struct mgos_config, spi.miso_gpio)},
    {.type = CONF_TYPE_INT, .key = "mosi_gpio", .offset = offsetof(struct mgos_config, spi.mosi_gpio)},
    {.type = CONF_TYPE_INT, .key = "sclk_gpio", .offset = offsetof(struct mgos_config, spi.sclk_gpio)},
    {.type = CONF_TYPE_INT, .key = "cs0_gpio", .offset = offsetof(struct mgos_config, spi.cs0_gpio)},
    {.type = CONF_TYPE_INT, .key = "cs1_gpio", .offset = offsetof(struct mgos_config, spi.cs1_gpio)},
    {.type = CONF_TYPE_INT, .key = "cs2_gpio", .offset = offsetof(struct mgos_config, spi.cs2_gpio)},
    {.type = CONF_TYPE_OBJECT, .key = "wifi", .offset = offsetof(struct mgos_config, wifi), .num_desc = 61},
    {.type = CONF_TYPE_OBJECT, .key = "ap", .offset = offsetof(struct mgos_config, wifi.ap), .num_desc = 15},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, wifi.ap.enable)},
    {.type = CONF_TYPE_STRING, .key = "ssid", .offset = offsetof(struct mgos_config, wifi.ap.ssid)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, wifi.ap.pass)},
    {.type = CONF_TYPE_BOOL, .key = "hidden", .offset = offsetof(struct mgos_config, wifi.ap.hidden)},
    {.type = CONF_TYPE_INT, .key = "channel", .offset = offsetof(struct mgos_config, wifi.ap.channel)},
    {.type = CONF_TYPE_INT, .key = "max_connections", .offset = offsetof(struct mgos_config, wifi.ap.max_connections)},
    {.type = CONF_TYPE_STRING, .key = "ip", .offset = offsetof(struct mgos_config, wifi.ap.ip)},
    {.type = CONF_TYPE_STRING, .key = "netmask", .offset = offsetof(struct mgos_config, wifi.ap.netmask)},
    {.type = CONF_TYPE_STRING, .key = "gw", .offset = offsetof(struct mgos_config, wifi.ap.gw)},
    {.type = CONF_TYPE_STRING, .key = "dhcp_start", .offset = offsetof(struct mgos_config, wifi.ap.dhcp_start)},
    {.type = CONF_TYPE_STRING, .key = "dhcp_end", .offset = offsetof(struct mgos_config, wifi.ap.dhcp_end)},
    {.type = CONF_TYPE_INT, .key = "trigger_on_gpio", .offset = offsetof(struct mgos_config, wifi.ap.trigger_on_gpio)},
    {.type = CONF_TYPE_INT, .key = "disable_after", .offset = offsetof(struct mgos_config, wifi.ap.disable_after)},
    {.type = CONF_TYPE_STRING, .key = "hostname", .offset = offsetof(struct mgos_config, wifi.ap.hostname)},
    {.type = CONF_TYPE_BOOL, .key = "keep_enabled", .offset = offsetof(struct mgos_config, wifi.ap.keep_enabled)},
    {.type = CONF_TYPE_OBJECT, .key = "sta", .offset = offsetof(struct mgos_config, wifi.sta), .num_desc = 13},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, wifi.sta.enable)},
    {.type = CONF_TYPE_STRING, .key = "ssid", .offset = offsetof(struct mgos_config, wifi.sta.ssid)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, wifi.sta.pass)},
    {.type = CONF_TYPE_STRING, .key = "user", .offset = offsetof(struct mgos_config, wifi.sta.user)},
    {.type = CONF_TYPE_STRING, .key = "anon_identity", .offset = offsetof(struct mgos_config, wifi.sta.anon_identity)},
    {.type = CONF_TYPE_STRING, .key = "cert", .offset = offsetof(struct mgos_config, wifi.sta.cert)},
    {.type = CONF_TYPE_STRING, .key = "key", .offset = offsetof(struct mgos_config, wifi.sta.key)},
    {.type = CONF_TYPE_STRING, .key = "ca_cert", .offset = offsetof(struct mgos_config, wifi.sta.ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "ip", .offset = offsetof(struct mgos_config, wifi.sta.ip)},
    {.type = CONF_TYPE_STRING, .key = "netmask", .offset = offsetof(struct mgos_config, wifi.sta.netmask)},
    {.type = CONF_TYPE_STRING, .key = "gw", .offset = offsetof(struct mgos_config, wifi.sta.gw)},
    {.type = CONF_TYPE_STRING, .key = "nameserver", .offset = offsetof(struct mgos_config, wifi.sta.nameserver)},
    {.type = CONF_TYPE_STRING, .key = "dhcp_hostname", .offset = offsetof(struct mgos_config, wifi.sta.dhcp_hostname)},
    {.type = CONF_TYPE_OBJECT, .key = "sta1", .offset = offsetof(struct mgos_config, wifi.sta1), .num_desc = 13},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, wifi.sta1.enable)},
    {.type = CONF_TYPE_STRING, .key = "ssid", .offset = offsetof(struct mgos_config, wifi.sta1.ssid)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, wifi.sta1.pass)},
    {.type = CONF_TYPE_STRING, .key = "user", .offset = offsetof(struct mgos_config, wifi.sta1.user)},
    {.type = CONF_TYPE_STRING, .key = "anon_identity", .offset = offsetof(struct mgos_config, wifi.sta1.anon_identity)},
    {.type = CONF_TYPE_STRING, .key = "cert", .offset = offsetof(struct mgos_config, wifi.sta1.cert)},
    {.type = CONF_TYPE_STRING, .key = "key", .offset = offsetof(struct mgos_config, wifi.sta1.key)},
    {.type = CONF_TYPE_STRING, .key = "ca_cert", .offset = offsetof(struct mgos_config, wifi.sta1.ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "ip", .offset = offsetof(struct mgos_config, wifi.sta1.ip)},
    {.type = CONF_TYPE_STRING, .key = "netmask", .offset = offsetof(struct mgos_config, wifi.sta1.netmask)},
    {.type = CONF_TYPE_STRING, .key = "gw", .offset = offsetof(struct mgos_config, wifi.sta1.gw)},
    {.type = CONF_TYPE_STRING, .key = "nameserver", .offset = offsetof(struct mgos_config, wifi.sta1.nameserver)},
    {.type = CONF_TYPE_STRING, .key = "dhcp_hostname", .offset = offsetof(struct mgos_config, wifi.sta1.dhcp_hostname)},
    {.type = CONF_TYPE_OBJECT, .key = "sta2", .offset = offsetof(struct mgos_config, wifi.sta2), .num_desc = 13},
    {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, wifi.sta2.enable)},
    {.type = CONF_TYPE_STRING, .key = "ssid", .offset = offsetof(struct mgos_config, wifi.sta2.ssid)},
    {.type = CONF_TYPE_STRING, .key = "pass", .offset = offsetof(struct mgos_config, wifi.sta2.pass)},
    {.type = CONF_TYPE_STRING, .key = "user", .offset = offsetof(struct mgos_config, wifi.sta2.user)},
    {.type = CONF_TYPE_STRING, .key = "anon_identity", .offset = offsetof(struct mgos_config, wifi.sta2.anon_identity)},
    {.type = CONF_TYPE_STRING, .key = "cert", .offset = offsetof(struct mgos_config, wifi.sta2.cert)},
    {.type = CONF_TYPE_STRING, .key = "key", .offset = offsetof(struct mgos_config, wifi.sta2.key)},
    {.type = CONF_TYPE_STRING, .key = "ca_cert", .offset = offsetof(struct mgos_config, wifi.sta2.ca_cert)},
    {.type = CONF_TYPE_STRING, .key = "ip", .offset = offsetof(struct mgos_config, wifi.sta2.ip)},
    {.type = CONF_TYPE_STRING, .key = "netmask", .offset = offsetof(struct mgos_config, wifi.sta2.netmask)},
    {.type = CONF_TYPE_STRING, .key = "gw", .offset = offsetof(struct mgos_config, wifi.sta2.gw)},
    {.type = CONF_TYPE_STRING, .key = "nameserver", .offset = offsetof(struct mgos_config, wifi.sta2.nameserver)},
    {.type = CONF_TYPE_STRING, .key = "dhcp_hostname", .offset = offsetof(struct mgos_config, wifi.sta2.dhcp_hostname)},
    {.type = CONF_TYPE_INT, .key = "sta_cfg_idx", .offset = offsetof(struct mgos_config, wifi.sta_cfg_idx)},
    {.type = CONF_TYPE_INT, .key = "sta_connect_timeout", .offset = offsetof(struct mgos_config, wifi.sta_connect_timeout)},
    {.type = CONF_TYPE_BOOL, .key = "sta_all_chan_scan", .offset = offsetof(struct mgos_config, wifi.sta_all_chan_scan)},
    {.type = CONF_TYPE_OBJECT, .key = "additional", .offset = offsetof(struct mgos_config, additional), .num_desc = 15},
    {.type = CONF_TYPE_OBJECT, .key = "alert", .offset = offsetof(struct mgos_config, additional.alert), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "out_1", .offset = offsetof(struct mgos_config, additional.alert.out_1)},
    {.type = CONF_TYPE_INT, .key = "out_2", .offset = offsetof(struct mgos_config, additional.alert.out_2)},
    {.type = CONF_TYPE_INT, .key = "out_3", .offset = offsetof(struct mgos_config, additional.alert.out_3)},
    {.type = CONF_TYPE_INT, .key = "out_4", .offset = offsetof(struct mgos_config, additional.alert.out_4)},
    {.type = CONF_TYPE_OBJECT, .key = "timer", .offset = offsetof(struct mgos_config, additional.timer), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "out_1", .offset = offsetof(struct mgos_config, additional.timer.out_1)},
    {.type = CONF_TYPE_INT, .key = "out_2", .offset = offsetof(struct mgos_config, additional.timer.out_2)},
    {.type = CONF_TYPE_INT, .key = "out_3", .offset = offsetof(struct mgos_config, additional.timer.out_3)},
    {.type = CONF_TYPE_INT, .key = "out_4", .offset = offsetof(struct mgos_config, additional.timer.out_4)},
    {.type = CONF_TYPE_OBJECT, .key = "future", .offset = offsetof(struct mgos_config, additional.future), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "out_1", .offset = offsetof(struct mgos_config, additional.future.out_1)},
    {.type = CONF_TYPE_INT, .key = "out_2", .offset = offsetof(struct mgos_config, additional.future.out_2)},
    {.type = CONF_TYPE_INT, .key = "out_3", .offset = offsetof(struct mgos_config, additional.future.out_3)},
    {.type = CONF_TYPE_INT, .key = "out_4", .offset = offsetof(struct mgos_config, additional.future.out_4)},
    {.type = CONF_TYPE_OBJECT, .key = "outputPins", .offset = offsetof(struct mgos_config, outputPins), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "out_1", .offset = offsetof(struct mgos_config, outputPins.out_1)},
    {.type = CONF_TYPE_INT, .key = "out_2", .offset = offsetof(struct mgos_config, outputPins.out_2)},
    {.type = CONF_TYPE_INT, .key = "out_3", .offset = offsetof(struct mgos_config, outputPins.out_3)},
    {.type = CONF_TYPE_INT, .key = "out_4", .offset = offsetof(struct mgos_config, outputPins.out_4)},
    {.type = CONF_TYPE_OBJECT, .key = "inputPins", .offset = offsetof(struct mgos_config, inputPins), .num_desc = 4},
    {.type = CONF_TYPE_INT, .key = "in_1", .offset = offsetof(struct mgos_config, inputPins.in_1)},
    {.type = CONF_TYPE_INT, .key = "in_2", .offset = offsetof(struct mgos_config, inputPins.in_2)},
    {.type = CONF_TYPE_INT, .key = "in_3", .offset = offsetof(struct mgos_config, inputPins.in_3)},
    {.type = CONF_TYPE_INT, .key = "in_4", .offset = offsetof(struct mgos_config, inputPins.in_4)},
};

/* struct mgos_config_debug */
const struct mgos_conf_entry *mgos_config_debug_get_schema(void) {
  return &mgos_config_schema_[1];
}

void mgos_config_debug_set_defaults(struct mgos_config_debug *cfg) {
  cfg->udp_log_addr = NULL;
  cfg->udp_log_level = 3;
  cfg->mbedtls_level = 1;
  cfg->level = -1;
  cfg->file_level = NULL;
  cfg->event_level = 2;
  cfg->stdout_uart = 0;
  cfg->stderr_uart = 0;
  cfg->factory_reset_gpio = -1;
  cfg->mg_mgr_hexdump_file = NULL;
  cfg->stdout_topic = NULL;
  cfg->stderr_topic = NULL;
}

/* struct mgos_config_device */
const struct mgos_conf_entry *mgos_config_device_get_schema(void) {
  return &mgos_config_schema_[14];
}

void mgos_config_device_set_defaults(struct mgos_config_device *cfg) {
  cfg->id = "??????";
  cfg->license = NULL;
  cfg->mac = NULL;
  cfg->public_key = NULL;
  cfg->sn = NULL;
}

/* struct mgos_config_sys */
const struct mgos_conf_entry *mgos_config_sys_get_schema(void) {
  return &mgos_config_schema_[20];
}

void mgos_config_sys_set_defaults(struct mgos_config_sys *cfg) {
  cfg->tz_spec = NULL;
  cfg->wdt_timeout = 30;
  cfg->pref_ota_lib = NULL;
}

/* struct mgos_config_mqtt */
const struct mgos_conf_entry *mgos_config_mqtt_get_schema(void) {
  return &mgos_config_schema_[53];
}

void mgos_config_mqtt_set_defaults(struct mgos_config_mqtt *cfg) {
  cfg->enable = true;
  cfg->server = "a6ffpc9686vd8-ats.iot.us-west-2.amazonaws.com:8883";
  cfg->client_id = NULL;
  cfg->user = NULL;
  cfg->pass = NULL;
  cfg->reconnect_timeout_min = 2.0;
  cfg->reconnect_timeout_max = 60.0;
  cfg->ssl_cert = "aws-??????.crt.pem";
  cfg->ssl_key = "aws-??????.key.pem";
  cfg->ssl_ca_cert = "ca.pem";
  cfg->ssl_cipher_suites = NULL;
  cfg->ssl_psk_identity = NULL;
  cfg->ssl_psk_key = NULL;
  cfg->clean_session = true;
  cfg->keep_alive = 60;
  cfg->will_topic = NULL;
  cfg->will_message = NULL;
  cfg->will_retain = false;
  cfg->max_qos = 2;
  cfg->recv_mbuf_limit = 3072;
  cfg->require_time = false;
  cfg->cloud_events = true;
  cfg->max_queue_length = 6;
  cfg->pub = "?????\?/response";
  cfg->sub = "?????\?/request";
  cfg->pub_update = "?????\?/response/update";
  cfg->sub_update = "?????\?/request/update";
}

/* struct mgos_config_mqtt */
const struct mgos_conf_entry *mgos_config_mqtt1_get_schema(void) {
  return &mgos_config_schema_[53];
}

void mgos_config_mqtt1_set_defaults(struct mgos_config_mqtt *cfg) {
  cfg->enable = false;
  cfg->server = NULL;
  cfg->client_id = NULL;
  cfg->user = NULL;
  cfg->pass = NULL;
  cfg->reconnect_timeout_min = 2.0;
  cfg->reconnect_timeout_max = 60.0;
  cfg->ssl_cert = "aws-??????.crt.pem";
  cfg->ssl_key = "aws-??????.key.pem";
  cfg->ssl_ca_cert = "ca.pem";
  cfg->ssl_cipher_suites = NULL;
  cfg->ssl_psk_identity = NULL;
  cfg->ssl_psk_key = NULL;
  cfg->clean_session = true;
  cfg->keep_alive = 60;
  cfg->will_topic = NULL;
  cfg->will_message = NULL;
  cfg->will_retain = false;
  cfg->max_qos = 2;
  cfg->recv_mbuf_limit = 3072;
  cfg->require_time = false;
  cfg->cloud_events = true;
  cfg->max_queue_length = 6;
  cfg->pub = "?????\?/response";
  cfg->sub = "?????\?/request";
  cfg->pub_update = "?????\?/response/update";
  cfg->sub_update = "?????\?/request/update";
}

/* struct mgos_config_shadow */
const struct mgos_conf_entry *mgos_config_shadow_get_schema(void) {
  return &mgos_config_schema_[81];
}

void mgos_config_shadow_set_defaults(struct mgos_config_shadow *cfg) {
  cfg->enable = true;
  cfg->lib = NULL;
  cfg->get_on_connect = true;
  cfg->ota_enable = true;
  cfg->autocommit = false;
}

/* struct mgos_config_aws_greengrass */
const struct mgos_conf_entry *mgos_config_aws_greengrass_get_schema(void) {
  return &mgos_config_schema_[89];
}

void mgos_config_aws_greengrass_set_defaults(struct mgos_config_aws_greengrass *cfg) {
  cfg->enable = false;
  cfg->reconnect_timeout_min = 2;
  cfg->reconnect_timeout_max = 60;
}

/* struct mgos_config_aws */
const struct mgos_conf_entry *mgos_config_aws_get_schema(void) {
  return &mgos_config_schema_[87];
}

void mgos_config_aws_set_defaults(struct mgos_config_aws *cfg) {
  cfg->thing_name = NULL;
  mgos_config_aws_greengrass_set_defaults(&cfg->greengrass);
}

/* struct mgos_config_update */
const struct mgos_conf_entry *mgos_config_update_get_schema(void) {
  return &mgos_config_schema_[93];
}

void mgos_config_update_set_defaults(struct mgos_config_update *cfg) {
  cfg->timeout = 600;
  cfg->commit_timeout = 0;
  cfg->url = NULL;
  cfg->interval = 0;
  cfg->extra_http_headers = NULL;
  cfg->ssl_ca_file = "ca.pem";
  cfg->ssl_client_cert_file = NULL;
  cfg->ssl_server_name = NULL;
  cfg->enable_post = true;
}

/* struct mgos_config_rpc_ws */
const struct mgos_conf_entry *mgos_config_rpc_ws_get_schema(void) {
  return &mgos_config_schema_[113];
}

void mgos_config_rpc_ws_set_defaults(struct mgos_config_rpc_ws *cfg) {
  cfg->enable = true;
  cfg->server_address = NULL;
  cfg->reconnect_interval_min = 1;
  cfg->reconnect_interval_max = 60;
  cfg->ssl_server_name = NULL;
  cfg->ssl_cert = NULL;
  cfg->ssl_key = NULL;
  cfg->ssl_ca_cert = NULL;
}

/* struct mgos_config_rpc_mqtt */
const struct mgos_conf_entry *mgos_config_rpc_mqtt_get_schema(void) {
  return &mgos_config_schema_[122];
}

void mgos_config_rpc_mqtt_set_defaults(struct mgos_config_rpc_mqtt *cfg) {
  cfg->enable = true;
  cfg->pub_topic = "%.*s/rpc";
  cfg->sub_topic = "%.*s/rpc";
  cfg->sub_wc = true;
  cfg->qos = 1;
}

/* struct mgos_config_rpc_uart */
const struct mgos_conf_entry *mgos_config_rpc_uart_get_schema(void) {
  return &mgos_config_schema_[128];
}

void mgos_config_rpc_uart_set_defaults(struct mgos_config_rpc_uart *cfg) {
  cfg->uart_no = 0;
  cfg->baud_rate = 115200;
  cfg->fc_type = 2;
  cfg->dst = NULL;
}

/* struct mgos_config_rpc */
const struct mgos_conf_entry *mgos_config_rpc_get_schema(void) {
  return &mgos_config_schema_[103];
}

void mgos_config_rpc_set_defaults(struct mgos_config_rpc *cfg) {
  cfg->enable = true;
  cfg->http_enable = true;
  cfg->service_sys_enable = true;
  cfg->max_frame_size = 4096;
  cfg->max_queue_length = 25;
  cfg->default_out_channel_idle_close_timeout = 10;
  cfg->acl_file = NULL;
  cfg->auth_domain = "RPC";
  cfg->auth_file = NULL;
  mgos_config_rpc_ws_set_defaults(&cfg->ws);
  mgos_config_rpc_mqtt_set_defaults(&cfg->mqtt);
  mgos_config_rpc_uart_set_defaults(&cfg->uart);
}

/* struct mgos_config_dash */
const struct mgos_conf_entry *mgos_config_dash_get_schema(void) {
  return &mgos_config_schema_[133];
}

void mgos_config_dash_set_defaults(struct mgos_config_dash *cfg) {
  cfg->enable = false;
  cfg->token = NULL;
  cfg->server = "wss://mdash.net/api/v2/rpc";
  cfg->ssl_cert = NULL;
  cfg->ssl_key = NULL;
  cfg->ssl_ca_cert = "ca.pem";
  cfg->send_logs = false;
}

/* struct mgos_config_file_logger */
const struct mgos_conf_entry *mgos_config_file_logger_get_schema(void) {
  return &mgos_config_schema_[141];
}

void mgos_config_file_logger_set_defaults(struct mgos_config_file_logger *cfg) {
  cfg->enable = false;
  cfg->dir = "/";
  cfg->prefix = "log_";
  cfg->max_file_size = 4000;
  cfg->max_num_files = 10;
  cfg->timestamps = true;
  cfg->level = 2;
  cfg->include = NULL;
  cfg->syslog_enable = true;
  cfg->rpc_service_enable = false;
  cfg->buf_size = 256;
  cfg->buf_line = true;
}

/* struct mgos_config_http */
const struct mgos_conf_entry *mgos_config_http_get_schema(void) {
  return &mgos_config_schema_[154];
}

void mgos_config_http_set_defaults(struct mgos_config_http *cfg) {
  cfg->enable = true;
  cfg->listen_addr = "80";
  cfg->document_root = "/";
  cfg->index_files = NULL;
  cfg->ssl_cert = NULL;
  cfg->ssl_key = NULL;
  cfg->ssl_ca_cert = NULL;
  cfg->upload_acl = "*";
  cfg->hidden_files = NULL;
  cfg->auth_domain = NULL;
  cfg->auth_file = NULL;
  cfg->extra_headers = NULL;
}

/* struct mgos_config_i2c */
const struct mgos_conf_entry *mgos_config_i2c_get_schema(void) {
  return &mgos_config_schema_[173];
}

void mgos_config_i2c_set_defaults(struct mgos_config_i2c *cfg) {
  cfg->enable = false;
  cfg->freq = 100000;
  cfg->debug = false;
  cfg->sda_gpio = 12;
  cfg->scl_gpio = 14;
}

/* struct mgos_config_i2c */
const struct mgos_conf_entry *mgos_config_i2c1_get_schema(void) {
  return &mgos_config_schema_[173];
}

void mgos_config_i2c1_set_defaults(struct mgos_config_i2c *cfg) {
  cfg->enable = false;
  cfg->freq = 100000;
  cfg->debug = false;
  cfg->sda_gpio = 4;
  cfg->scl_gpio = 5;
}

/* struct mgos_config_sntp */
const struct mgos_conf_entry *mgos_config_sntp_get_schema(void) {
  return &mgos_config_schema_[179];
}

void mgos_config_sntp_set_defaults(struct mgos_config_sntp *cfg) {
  cfg->enable = true;
  cfg->server = "time.google.com";
  cfg->retry_min = 1;
  cfg->retry_max = 30;
  cfg->update_interval = 7200;
}

/* struct mgos_config_spi */
const struct mgos_conf_entry *mgos_config_spi_get_schema(void) {
  return &mgos_config_schema_[185];
}

void mgos_config_spi_set_defaults(struct mgos_config_spi *cfg) {
  cfg->enable = false;
  cfg->debug = false;
  cfg->miso_gpio = 12;
  cfg->mosi_gpio = 13;
  cfg->sclk_gpio = 14;
  cfg->cs0_gpio = 15;
  cfg->cs1_gpio = -1;
  cfg->cs2_gpio = -1;
}

/* struct mgos_config_wifi_ap */
const struct mgos_conf_entry *mgos_config_wifi_ap_get_schema(void) {
  return &mgos_config_schema_[195];
}

void mgos_config_wifi_ap_set_defaults(struct mgos_config_wifi_ap *cfg) {
  cfg->enable = true;
  cfg->ssid = "EDEN_3_??????";
  cfg->pass = "eden1234";
  cfg->hidden = false;
  cfg->channel = 6;
  cfg->max_connections = 10;
  cfg->ip = "192.168.4.1";
  cfg->netmask = "255.255.255.0";
  cfg->gw = "192.168.4.1";
  cfg->dhcp_start = "192.168.4.2";
  cfg->dhcp_end = "192.168.4.100";
  cfg->trigger_on_gpio = -1;
  cfg->disable_after = 300;
  cfg->hostname = NULL;
  cfg->keep_enabled = true;
}

/* struct mgos_config_wifi_sta */
const struct mgos_conf_entry *mgos_config_wifi_sta_get_schema(void) {
  return &mgos_config_schema_[239];
}

void mgos_config_wifi_sta_set_defaults(struct mgos_config_wifi_sta *cfg) {
  cfg->enable = false;
  cfg->ssid = NULL;
  cfg->pass = NULL;
  cfg->user = NULL;
  cfg->anon_identity = NULL;
  cfg->cert = NULL;
  cfg->key = NULL;
  cfg->ca_cert = NULL;
  cfg->ip = NULL;
  cfg->netmask = NULL;
  cfg->gw = NULL;
  cfg->nameserver = NULL;
  cfg->dhcp_hostname = NULL;
}

/* struct mgos_config_wifi_sta */
const struct mgos_conf_entry *mgos_config_wifi_sta1_get_schema(void) {
  return &mgos_config_schema_[239];
}

void mgos_config_wifi_sta1_set_defaults(struct mgos_config_wifi_sta *cfg) {
  cfg->enable = false;
  cfg->ssid = NULL;
  cfg->pass = NULL;
  cfg->user = NULL;
  cfg->anon_identity = NULL;
  cfg->cert = NULL;
  cfg->key = NULL;
  cfg->ca_cert = NULL;
  cfg->ip = NULL;
  cfg->netmask = NULL;
  cfg->gw = NULL;
  cfg->nameserver = NULL;
  cfg->dhcp_hostname = NULL;
}

/* struct mgos_config_wifi_sta */
const struct mgos_conf_entry *mgos_config_wifi_sta2_get_schema(void) {
  return &mgos_config_schema_[239];
}

void mgos_config_wifi_sta2_set_defaults(struct mgos_config_wifi_sta *cfg) {
  cfg->enable = false;
  cfg->ssid = NULL;
  cfg->pass = NULL;
  cfg->user = NULL;
  cfg->anon_identity = NULL;
  cfg->cert = NULL;
  cfg->key = NULL;
  cfg->ca_cert = NULL;
  cfg->ip = NULL;
  cfg->netmask = NULL;
  cfg->gw = NULL;
  cfg->nameserver = NULL;
  cfg->dhcp_hostname = NULL;
}

/* struct mgos_config_wifi */
const struct mgos_conf_entry *mgos_config_wifi_get_schema(void) {
  return &mgos_config_schema_[194];
}

void mgos_config_wifi_set_defaults(struct mgos_config_wifi *cfg) {
  mgos_config_wifi_ap_set_defaults(&cfg->ap);
  mgos_config_wifi_sta_set_defaults(&cfg->sta);
  mgos_config_wifi_sta1_set_defaults(&cfg->sta1);
  mgos_config_wifi_sta2_set_defaults(&cfg->sta2);
  cfg->sta_cfg_idx = 0;
  cfg->sta_connect_timeout = 30;
  cfg->sta_all_chan_scan = true;
}

/* struct mgos_config_additional_alert */
const struct mgos_conf_entry *mgos_config_additional_alert_get_schema(void) {
  return &mgos_config_schema_[257];
}

void mgos_config_additional_alert_set_defaults(struct mgos_config_additional_alert *cfg) {
  cfg->out_1 = 0;
  cfg->out_2 = 0;
  cfg->out_3 = 0;
  cfg->out_4 = 0;
}

/* struct mgos_config_additional_timer */
const struct mgos_conf_entry *mgos_config_additional_timer_get_schema(void) {
  return &mgos_config_schema_[262];
}

void mgos_config_additional_timer_set_defaults(struct mgos_config_additional_timer *cfg) {
  cfg->out_1 = 0;
  cfg->out_2 = 0;
  cfg->out_3 = 0;
  cfg->out_4 = 0;
}

/* struct mgos_config_additional_future */
const struct mgos_conf_entry *mgos_config_additional_future_get_schema(void) {
  return &mgos_config_schema_[267];
}

void mgos_config_additional_future_set_defaults(struct mgos_config_additional_future *cfg) {
  cfg->out_1 = 0;
  cfg->out_2 = 0;
  cfg->out_3 = 0;
  cfg->out_4 = 0;
}

/* struct mgos_config_additional */
const struct mgos_conf_entry *mgos_config_additional_get_schema(void) {
  return &mgos_config_schema_[256];
}

void mgos_config_additional_set_defaults(struct mgos_config_additional *cfg) {
  mgos_config_additional_alert_set_defaults(&cfg->alert);
  mgos_config_additional_timer_set_defaults(&cfg->timer);
  mgos_config_additional_future_set_defaults(&cfg->future);
}

/* struct mgos_config_outputPins */
const struct mgos_conf_entry *mgos_config_outputPins_get_schema(void) {
  return &mgos_config_schema_[272];
}

void mgos_config_outputPins_set_defaults(struct mgos_config_outputPins *cfg) {
  cfg->out_1 = 0;
  cfg->out_2 = 0;
  cfg->out_3 = 0;
  cfg->out_4 = 0;
}

/* struct mgos_config_inputPins */
const struct mgos_conf_entry *mgos_config_inputPins_get_schema(void) {
  return &mgos_config_schema_[277];
}

void mgos_config_inputPins_set_defaults(struct mgos_config_inputPins *cfg) {
  cfg->in_1 = 0;
  cfg->in_2 = 0;
  cfg->in_3 = 0;
  cfg->in_4 = 0;
}

/* struct mgos_config */
const struct mgos_conf_entry *mgos_config_get_schema(void) {
  return &mgos_config_schema_[0];
}

void mgos_config_set_defaults(struct mgos_config *cfg) {
  mgos_config_debug_set_defaults(&cfg->debug);
  mgos_config_device_set_defaults(&cfg->device);
  mgos_config_sys_set_defaults(&cfg->sys);
  cfg->conf_acl = "*";
  mgos_config_mqtt_set_defaults(&cfg->mqtt);
  mgos_config_mqtt1_set_defaults(&cfg->mqtt1);
  mgos_config_shadow_set_defaults(&cfg->shadow);
  mgos_config_aws_set_defaults(&cfg->aws);
  mgos_config_update_set_defaults(&cfg->update);
  mgos_config_rpc_set_defaults(&cfg->rpc);
  mgos_config_dash_set_defaults(&cfg->dash);
  mgos_config_file_logger_set_defaults(&cfg->file_logger);
  mgos_config_http_set_defaults(&cfg->http);
  mgos_config_i2c_set_defaults(&cfg->i2c);
  mgos_config_i2c1_set_defaults(&cfg->i2c1);
  mgos_config_sntp_set_defaults(&cfg->sntp);
  mgos_config_spi_set_defaults(&cfg->spi);
  mgos_config_wifi_set_defaults(&cfg->wifi);
  mgos_config_additional_set_defaults(&cfg->additional);
  mgos_config_outputPins_set_defaults(&cfg->outputPins);
  mgos_config_inputPins_set_defaults(&cfg->inputPins);
}

/* Global instance */
struct mgos_config mgos_sys_config;

/* Accessors */

/* debug */
const struct mgos_config_debug *mgos_config_get_debug(const struct mgos_config *cfg) { return &cfg->debug; }

/* debug.udp_log_addr */
const char * mgos_config_get_debug_udp_log_addr(const struct mgos_config *cfg) { return cfg->debug.udp_log_addr; }
const char * mgos_config_get_default_debug_udp_log_addr(void) { return NULL; }
void mgos_config_set_debug_udp_log_addr(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->debug.udp_log_addr, v); }

/* debug.udp_log_level */
int mgos_config_get_debug_udp_log_level(const struct mgos_config *cfg) { return cfg->debug.udp_log_level; }
int mgos_config_get_default_debug_udp_log_level(void) { return 3; }
void mgos_config_set_debug_udp_log_level(struct mgos_config *cfg, int v) { cfg->debug.udp_log_level = v; }

/* debug.mbedtls_level */
int mgos_config_get_debug_mbedtls_level(const struct mgos_config *cfg) { return cfg->debug.mbedtls_level; }
int mgos_config_get_default_debug_mbedtls_level(void) { return 1; }
void mgos_config_set_debug_mbedtls_level(struct mgos_config *cfg, int v) { cfg->debug.mbedtls_level = v; }

/* debug.level */
int mgos_config_get_debug_level(const struct mgos_config *cfg) { return cfg->debug.level; }
int mgos_config_get_default_debug_level(void) { return -1; }
void mgos_config_set_debug_level(struct mgos_config *cfg, int v) { cfg->debug.level = v; }

/* debug.file_level */
const char * mgos_config_get_debug_file_level(const struct mgos_config *cfg) { return cfg->debug.file_level; }
const char * mgos_config_get_default_debug_file_level(void) { return NULL; }
void mgos_config_set_debug_file_level(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->debug.file_level, v); }

/* debug.event_level */
int mgos_config_get_debug_event_level(const struct mgos_config *cfg) { return cfg->debug.event_level; }
int mgos_config_get_default_debug_event_level(void) { return 2; }
void mgos_config_set_debug_event_level(struct mgos_config *cfg, int v) { cfg->debug.event_level = v; }

/* debug.stdout_uart */
int mgos_config_get_debug_stdout_uart(const struct mgos_config *cfg) { return cfg->debug.stdout_uart; }
int mgos_config_get_default_debug_stdout_uart(void) { return 0; }
void mgos_config_set_debug_stdout_uart(struct mgos_config *cfg, int v) { cfg->debug.stdout_uart = v; }

/* debug.stderr_uart */
int mgos_config_get_debug_stderr_uart(const struct mgos_config *cfg) { return cfg->debug.stderr_uart; }
int mgos_config_get_default_debug_stderr_uart(void) { return 0; }
void mgos_config_set_debug_stderr_uart(struct mgos_config *cfg, int v) { cfg->debug.stderr_uart = v; }

/* debug.factory_reset_gpio */
int mgos_config_get_debug_factory_reset_gpio(const struct mgos_config *cfg) { return cfg->debug.factory_reset_gpio; }
int mgos_config_get_default_debug_factory_reset_gpio(void) { return -1; }
void mgos_config_set_debug_factory_reset_gpio(struct mgos_config *cfg, int v) { cfg->debug.factory_reset_gpio = v; }

/* debug.mg_mgr_hexdump_file */
const char * mgos_config_get_debug_mg_mgr_hexdump_file(const struct mgos_config *cfg) { return cfg->debug.mg_mgr_hexdump_file; }
const char * mgos_config_get_default_debug_mg_mgr_hexdump_file(void) { return NULL; }
void mgos_config_set_debug_mg_mgr_hexdump_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->debug.mg_mgr_hexdump_file, v); }

/* debug.stdout_topic */
const char * mgos_config_get_debug_stdout_topic(const struct mgos_config *cfg) { return cfg->debug.stdout_topic; }
const char * mgos_config_get_default_debug_stdout_topic(void) { return NULL; }
void mgos_config_set_debug_stdout_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->debug.stdout_topic, v); }

/* debug.stderr_topic */
const char * mgos_config_get_debug_stderr_topic(const struct mgos_config *cfg) { return cfg->debug.stderr_topic; }
const char * mgos_config_get_default_debug_stderr_topic(void) { return NULL; }
void mgos_config_set_debug_stderr_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->debug.stderr_topic, v); }

/* device */
const struct mgos_config_device *mgos_config_get_device(const struct mgos_config *cfg) { return &cfg->device; }

/* device.id */
const char * mgos_config_get_device_id(const struct mgos_config *cfg) { return cfg->device.id; }
const char * mgos_config_get_default_device_id(void) { return "??????"; }
void mgos_config_set_device_id(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->device.id, v); }

/* device.license */
const char * mgos_config_get_device_license(const struct mgos_config *cfg) { return cfg->device.license; }
const char * mgos_config_get_default_device_license(void) { return NULL; }
void mgos_config_set_device_license(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->device.license, v); }

/* device.mac */
const char * mgos_config_get_device_mac(const struct mgos_config *cfg) { return cfg->device.mac; }
const char * mgos_config_get_default_device_mac(void) { return NULL; }
void mgos_config_set_device_mac(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->device.mac, v); }

/* device.public_key */
const char * mgos_config_get_device_public_key(const struct mgos_config *cfg) { return cfg->device.public_key; }
const char * mgos_config_get_default_device_public_key(void) { return NULL; }
void mgos_config_set_device_public_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->device.public_key, v); }

/* device.sn */
const char * mgos_config_get_device_sn(const struct mgos_config *cfg) { return cfg->device.sn; }
const char * mgos_config_get_default_device_sn(void) { return NULL; }
void mgos_config_set_device_sn(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->device.sn, v); }

/* sys */
const struct mgos_config_sys *mgos_config_get_sys(const struct mgos_config *cfg) { return &cfg->sys; }

/* sys.tz_spec */
const char * mgos_config_get_sys_tz_spec(const struct mgos_config *cfg) { return cfg->sys.tz_spec; }
const char * mgos_config_get_default_sys_tz_spec(void) { return NULL; }
void mgos_config_set_sys_tz_spec(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->sys.tz_spec, v); }

/* sys.wdt_timeout */
int mgos_config_get_sys_wdt_timeout(const struct mgos_config *cfg) { return cfg->sys.wdt_timeout; }
int mgos_config_get_default_sys_wdt_timeout(void) { return 30; }
void mgos_config_set_sys_wdt_timeout(struct mgos_config *cfg, int v) { cfg->sys.wdt_timeout = v; }

/* sys.pref_ota_lib */
const char * mgos_config_get_sys_pref_ota_lib(const struct mgos_config *cfg) { return cfg->sys.pref_ota_lib; }
const char * mgos_config_get_default_sys_pref_ota_lib(void) { return NULL; }
void mgos_config_set_sys_pref_ota_lib(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->sys.pref_ota_lib, v); }

/* conf_acl */
const char * mgos_config_get_conf_acl(const struct mgos_config *cfg) { return cfg->conf_acl; }
const char * mgos_config_get_default_conf_acl(void) { return "*"; }
void mgos_config_set_conf_acl(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->conf_acl, v); }

/* mqtt */
const struct mgos_config_mqtt *mgos_config_get_mqtt(const struct mgos_config *cfg) { return &cfg->mqtt; }

/* mqtt.enable */
int mgos_config_get_mqtt_enable(const struct mgos_config *cfg) { return cfg->mqtt.enable; }
int mgos_config_get_default_mqtt_enable(void) { return true; }
void mgos_config_set_mqtt_enable(struct mgos_config *cfg, int v) { cfg->mqtt.enable = v; }

/* mqtt.server */
const char * mgos_config_get_mqtt_server(const struct mgos_config *cfg) { return cfg->mqtt.server; }
const char * mgos_config_get_default_mqtt_server(void) { return "a6ffpc9686vd8-ats.iot.us-west-2.amazonaws.com:8883"; }
void mgos_config_set_mqtt_server(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.server, v); }

/* mqtt.client_id */
const char * mgos_config_get_mqtt_client_id(const struct mgos_config *cfg) { return cfg->mqtt.client_id; }
const char * mgos_config_get_default_mqtt_client_id(void) { return NULL; }
void mgos_config_set_mqtt_client_id(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.client_id, v); }

/* mqtt.user */
const char * mgos_config_get_mqtt_user(const struct mgos_config *cfg) { return cfg->mqtt.user; }
const char * mgos_config_get_default_mqtt_user(void) { return NULL; }
void mgos_config_set_mqtt_user(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.user, v); }

/* mqtt.pass */
const char * mgos_config_get_mqtt_pass(const struct mgos_config *cfg) { return cfg->mqtt.pass; }
const char * mgos_config_get_default_mqtt_pass(void) { return NULL; }
void mgos_config_set_mqtt_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.pass, v); }

/* mqtt.reconnect_timeout_min */
double mgos_config_get_mqtt_reconnect_timeout_min(const struct mgos_config *cfg) { return cfg->mqtt.reconnect_timeout_min; }
double mgos_config_get_default_mqtt_reconnect_timeout_min(void) { return 2.0; }
void mgos_config_set_mqtt_reconnect_timeout_min(struct mgos_config *cfg, double v) { cfg->mqtt.reconnect_timeout_min = v; }

/* mqtt.reconnect_timeout_max */
double mgos_config_get_mqtt_reconnect_timeout_max(const struct mgos_config *cfg) { return cfg->mqtt.reconnect_timeout_max; }
double mgos_config_get_default_mqtt_reconnect_timeout_max(void) { return 60.0; }
void mgos_config_set_mqtt_reconnect_timeout_max(struct mgos_config *cfg, double v) { cfg->mqtt.reconnect_timeout_max = v; }

/* mqtt.ssl_cert */
const char * mgos_config_get_mqtt_ssl_cert(const struct mgos_config *cfg) { return cfg->mqtt.ssl_cert; }
const char * mgos_config_get_default_mqtt_ssl_cert(void) { return "aws-??????.crt.pem"; }
void mgos_config_set_mqtt_ssl_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_cert, v); }

/* mqtt.ssl_key */
const char * mgos_config_get_mqtt_ssl_key(const struct mgos_config *cfg) { return cfg->mqtt.ssl_key; }
const char * mgos_config_get_default_mqtt_ssl_key(void) { return "aws-??????.key.pem"; }
void mgos_config_set_mqtt_ssl_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_key, v); }

/* mqtt.ssl_ca_cert */
const char * mgos_config_get_mqtt_ssl_ca_cert(const struct mgos_config *cfg) { return cfg->mqtt.ssl_ca_cert; }
const char * mgos_config_get_default_mqtt_ssl_ca_cert(void) { return "ca.pem"; }
void mgos_config_set_mqtt_ssl_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_ca_cert, v); }

/* mqtt.ssl_cipher_suites */
const char * mgos_config_get_mqtt_ssl_cipher_suites(const struct mgos_config *cfg) { return cfg->mqtt.ssl_cipher_suites; }
const char * mgos_config_get_default_mqtt_ssl_cipher_suites(void) { return NULL; }
void mgos_config_set_mqtt_ssl_cipher_suites(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_cipher_suites, v); }

/* mqtt.ssl_psk_identity */
const char * mgos_config_get_mqtt_ssl_psk_identity(const struct mgos_config *cfg) { return cfg->mqtt.ssl_psk_identity; }
const char * mgos_config_get_default_mqtt_ssl_psk_identity(void) { return NULL; }
void mgos_config_set_mqtt_ssl_psk_identity(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_psk_identity, v); }

/* mqtt.ssl_psk_key */
const char * mgos_config_get_mqtt_ssl_psk_key(const struct mgos_config *cfg) { return cfg->mqtt.ssl_psk_key; }
const char * mgos_config_get_default_mqtt_ssl_psk_key(void) { return NULL; }
void mgos_config_set_mqtt_ssl_psk_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.ssl_psk_key, v); }

/* mqtt.clean_session */
int mgos_config_get_mqtt_clean_session(const struct mgos_config *cfg) { return cfg->mqtt.clean_session; }
int mgos_config_get_default_mqtt_clean_session(void) { return true; }
void mgos_config_set_mqtt_clean_session(struct mgos_config *cfg, int v) { cfg->mqtt.clean_session = v; }

/* mqtt.keep_alive */
int mgos_config_get_mqtt_keep_alive(const struct mgos_config *cfg) { return cfg->mqtt.keep_alive; }
int mgos_config_get_default_mqtt_keep_alive(void) { return 60; }
void mgos_config_set_mqtt_keep_alive(struct mgos_config *cfg, int v) { cfg->mqtt.keep_alive = v; }

/* mqtt.will_topic */
const char * mgos_config_get_mqtt_will_topic(const struct mgos_config *cfg) { return cfg->mqtt.will_topic; }
const char * mgos_config_get_default_mqtt_will_topic(void) { return NULL; }
void mgos_config_set_mqtt_will_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.will_topic, v); }

/* mqtt.will_message */
const char * mgos_config_get_mqtt_will_message(const struct mgos_config *cfg) { return cfg->mqtt.will_message; }
const char * mgos_config_get_default_mqtt_will_message(void) { return NULL; }
void mgos_config_set_mqtt_will_message(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.will_message, v); }

/* mqtt.will_retain */
int mgos_config_get_mqtt_will_retain(const struct mgos_config *cfg) { return cfg->mqtt.will_retain; }
int mgos_config_get_default_mqtt_will_retain(void) { return false; }
void mgos_config_set_mqtt_will_retain(struct mgos_config *cfg, int v) { cfg->mqtt.will_retain = v; }

/* mqtt.max_qos */
int mgos_config_get_mqtt_max_qos(const struct mgos_config *cfg) { return cfg->mqtt.max_qos; }
int mgos_config_get_default_mqtt_max_qos(void) { return 2; }
void mgos_config_set_mqtt_max_qos(struct mgos_config *cfg, int v) { cfg->mqtt.max_qos = v; }

/* mqtt.recv_mbuf_limit */
int mgos_config_get_mqtt_recv_mbuf_limit(const struct mgos_config *cfg) { return cfg->mqtt.recv_mbuf_limit; }
int mgos_config_get_default_mqtt_recv_mbuf_limit(void) { return 3072; }
void mgos_config_set_mqtt_recv_mbuf_limit(struct mgos_config *cfg, int v) { cfg->mqtt.recv_mbuf_limit = v; }

/* mqtt.require_time */
int mgos_config_get_mqtt_require_time(const struct mgos_config *cfg) { return cfg->mqtt.require_time; }
int mgos_config_get_default_mqtt_require_time(void) { return false; }
void mgos_config_set_mqtt_require_time(struct mgos_config *cfg, int v) { cfg->mqtt.require_time = v; }

/* mqtt.cloud_events */
int mgos_config_get_mqtt_cloud_events(const struct mgos_config *cfg) { return cfg->mqtt.cloud_events; }
int mgos_config_get_default_mqtt_cloud_events(void) { return true; }
void mgos_config_set_mqtt_cloud_events(struct mgos_config *cfg, int v) { cfg->mqtt.cloud_events = v; }

/* mqtt.max_queue_length */
int mgos_config_get_mqtt_max_queue_length(const struct mgos_config *cfg) { return cfg->mqtt.max_queue_length; }
int mgos_config_get_default_mqtt_max_queue_length(void) { return 6; }
void mgos_config_set_mqtt_max_queue_length(struct mgos_config *cfg, int v) { cfg->mqtt.max_queue_length = v; }

/* mqtt.pub */
const char * mgos_config_get_mqtt_pub(const struct mgos_config *cfg) { return cfg->mqtt.pub; }
const char * mgos_config_get_default_mqtt_pub(void) { return "?????\?/response"; }
void mgos_config_set_mqtt_pub(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.pub, v); }

/* mqtt.sub */
const char * mgos_config_get_mqtt_sub(const struct mgos_config *cfg) { return cfg->mqtt.sub; }
const char * mgos_config_get_default_mqtt_sub(void) { return "?????\?/request"; }
void mgos_config_set_mqtt_sub(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.sub, v); }

/* mqtt.pub_update */
const char * mgos_config_get_mqtt_pub_update(const struct mgos_config *cfg) { return cfg->mqtt.pub_update; }
const char * mgos_config_get_default_mqtt_pub_update(void) { return "?????\?/response/update"; }
void mgos_config_set_mqtt_pub_update(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.pub_update, v); }

/* mqtt.sub_update */
const char * mgos_config_get_mqtt_sub_update(const struct mgos_config *cfg) { return cfg->mqtt.sub_update; }
const char * mgos_config_get_default_mqtt_sub_update(void) { return "?????\?/request/update"; }
void mgos_config_set_mqtt_sub_update(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt.sub_update, v); }

/* mqtt1 */
const struct mgos_config_mqtt *mgos_config_get_mqtt1(const struct mgos_config *cfg) { return &cfg->mqtt1; }

/* mqtt1.enable */
int mgos_config_get_mqtt1_enable(const struct mgos_config *cfg) { return cfg->mqtt1.enable; }
int mgos_config_get_default_mqtt1_enable(void) { return false; }
void mgos_config_set_mqtt1_enable(struct mgos_config *cfg, int v) { cfg->mqtt1.enable = v; }

/* mqtt1.server */
const char * mgos_config_get_mqtt1_server(const struct mgos_config *cfg) { return cfg->mqtt1.server; }
const char * mgos_config_get_default_mqtt1_server(void) { return NULL; }
void mgos_config_set_mqtt1_server(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.server, v); }

/* mqtt1.client_id */
const char * mgos_config_get_mqtt1_client_id(const struct mgos_config *cfg) { return cfg->mqtt1.client_id; }
const char * mgos_config_get_default_mqtt1_client_id(void) { return NULL; }
void mgos_config_set_mqtt1_client_id(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.client_id, v); }

/* mqtt1.user */
const char * mgos_config_get_mqtt1_user(const struct mgos_config *cfg) { return cfg->mqtt1.user; }
const char * mgos_config_get_default_mqtt1_user(void) { return NULL; }
void mgos_config_set_mqtt1_user(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.user, v); }

/* mqtt1.pass */
const char * mgos_config_get_mqtt1_pass(const struct mgos_config *cfg) { return cfg->mqtt1.pass; }
const char * mgos_config_get_default_mqtt1_pass(void) { return NULL; }
void mgos_config_set_mqtt1_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.pass, v); }

/* mqtt1.reconnect_timeout_min */
double mgos_config_get_mqtt1_reconnect_timeout_min(const struct mgos_config *cfg) { return cfg->mqtt1.reconnect_timeout_min; }
double mgos_config_get_default_mqtt1_reconnect_timeout_min(void) { return 2.0; }
void mgos_config_set_mqtt1_reconnect_timeout_min(struct mgos_config *cfg, double v) { cfg->mqtt1.reconnect_timeout_min = v; }

/* mqtt1.reconnect_timeout_max */
double mgos_config_get_mqtt1_reconnect_timeout_max(const struct mgos_config *cfg) { return cfg->mqtt1.reconnect_timeout_max; }
double mgos_config_get_default_mqtt1_reconnect_timeout_max(void) { return 60.0; }
void mgos_config_set_mqtt1_reconnect_timeout_max(struct mgos_config *cfg, double v) { cfg->mqtt1.reconnect_timeout_max = v; }

/* mqtt1.ssl_cert */
const char * mgos_config_get_mqtt1_ssl_cert(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_cert; }
const char * mgos_config_get_default_mqtt1_ssl_cert(void) { return "aws-??????.crt.pem"; }
void mgos_config_set_mqtt1_ssl_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_cert, v); }

/* mqtt1.ssl_key */
const char * mgos_config_get_mqtt1_ssl_key(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_key; }
const char * mgos_config_get_default_mqtt1_ssl_key(void) { return "aws-??????.key.pem"; }
void mgos_config_set_mqtt1_ssl_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_key, v); }

/* mqtt1.ssl_ca_cert */
const char * mgos_config_get_mqtt1_ssl_ca_cert(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_ca_cert; }
const char * mgos_config_get_default_mqtt1_ssl_ca_cert(void) { return "ca.pem"; }
void mgos_config_set_mqtt1_ssl_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_ca_cert, v); }

/* mqtt1.ssl_cipher_suites */
const char * mgos_config_get_mqtt1_ssl_cipher_suites(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_cipher_suites; }
const char * mgos_config_get_default_mqtt1_ssl_cipher_suites(void) { return NULL; }
void mgos_config_set_mqtt1_ssl_cipher_suites(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_cipher_suites, v); }

/* mqtt1.ssl_psk_identity */
const char * mgos_config_get_mqtt1_ssl_psk_identity(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_psk_identity; }
const char * mgos_config_get_default_mqtt1_ssl_psk_identity(void) { return NULL; }
void mgos_config_set_mqtt1_ssl_psk_identity(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_psk_identity, v); }

/* mqtt1.ssl_psk_key */
const char * mgos_config_get_mqtt1_ssl_psk_key(const struct mgos_config *cfg) { return cfg->mqtt1.ssl_psk_key; }
const char * mgos_config_get_default_mqtt1_ssl_psk_key(void) { return NULL; }
void mgos_config_set_mqtt1_ssl_psk_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.ssl_psk_key, v); }

/* mqtt1.clean_session */
int mgos_config_get_mqtt1_clean_session(const struct mgos_config *cfg) { return cfg->mqtt1.clean_session; }
int mgos_config_get_default_mqtt1_clean_session(void) { return true; }
void mgos_config_set_mqtt1_clean_session(struct mgos_config *cfg, int v) { cfg->mqtt1.clean_session = v; }

/* mqtt1.keep_alive */
int mgos_config_get_mqtt1_keep_alive(const struct mgos_config *cfg) { return cfg->mqtt1.keep_alive; }
int mgos_config_get_default_mqtt1_keep_alive(void) { return 60; }
void mgos_config_set_mqtt1_keep_alive(struct mgos_config *cfg, int v) { cfg->mqtt1.keep_alive = v; }

/* mqtt1.will_topic */
const char * mgos_config_get_mqtt1_will_topic(const struct mgos_config *cfg) { return cfg->mqtt1.will_topic; }
const char * mgos_config_get_default_mqtt1_will_topic(void) { return NULL; }
void mgos_config_set_mqtt1_will_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.will_topic, v); }

/* mqtt1.will_message */
const char * mgos_config_get_mqtt1_will_message(const struct mgos_config *cfg) { return cfg->mqtt1.will_message; }
const char * mgos_config_get_default_mqtt1_will_message(void) { return NULL; }
void mgos_config_set_mqtt1_will_message(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.will_message, v); }

/* mqtt1.will_retain */
int mgos_config_get_mqtt1_will_retain(const struct mgos_config *cfg) { return cfg->mqtt1.will_retain; }
int mgos_config_get_default_mqtt1_will_retain(void) { return false; }
void mgos_config_set_mqtt1_will_retain(struct mgos_config *cfg, int v) { cfg->mqtt1.will_retain = v; }

/* mqtt1.max_qos */
int mgos_config_get_mqtt1_max_qos(const struct mgos_config *cfg) { return cfg->mqtt1.max_qos; }
int mgos_config_get_default_mqtt1_max_qos(void) { return 2; }
void mgos_config_set_mqtt1_max_qos(struct mgos_config *cfg, int v) { cfg->mqtt1.max_qos = v; }

/* mqtt1.recv_mbuf_limit */
int mgos_config_get_mqtt1_recv_mbuf_limit(const struct mgos_config *cfg) { return cfg->mqtt1.recv_mbuf_limit; }
int mgos_config_get_default_mqtt1_recv_mbuf_limit(void) { return 3072; }
void mgos_config_set_mqtt1_recv_mbuf_limit(struct mgos_config *cfg, int v) { cfg->mqtt1.recv_mbuf_limit = v; }

/* mqtt1.require_time */
int mgos_config_get_mqtt1_require_time(const struct mgos_config *cfg) { return cfg->mqtt1.require_time; }
int mgos_config_get_default_mqtt1_require_time(void) { return false; }
void mgos_config_set_mqtt1_require_time(struct mgos_config *cfg, int v) { cfg->mqtt1.require_time = v; }

/* mqtt1.cloud_events */
int mgos_config_get_mqtt1_cloud_events(const struct mgos_config *cfg) { return cfg->mqtt1.cloud_events; }
int mgos_config_get_default_mqtt1_cloud_events(void) { return true; }
void mgos_config_set_mqtt1_cloud_events(struct mgos_config *cfg, int v) { cfg->mqtt1.cloud_events = v; }

/* mqtt1.max_queue_length */
int mgos_config_get_mqtt1_max_queue_length(const struct mgos_config *cfg) { return cfg->mqtt1.max_queue_length; }
int mgos_config_get_default_mqtt1_max_queue_length(void) { return 6; }
void mgos_config_set_mqtt1_max_queue_length(struct mgos_config *cfg, int v) { cfg->mqtt1.max_queue_length = v; }

/* mqtt1.pub */
const char * mgos_config_get_mqtt1_pub(const struct mgos_config *cfg) { return cfg->mqtt1.pub; }
const char * mgos_config_get_default_mqtt1_pub(void) { return "?????\?/response"; }
void mgos_config_set_mqtt1_pub(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.pub, v); }

/* mqtt1.sub */
const char * mgos_config_get_mqtt1_sub(const struct mgos_config *cfg) { return cfg->mqtt1.sub; }
const char * mgos_config_get_default_mqtt1_sub(void) { return "?????\?/request"; }
void mgos_config_set_mqtt1_sub(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.sub, v); }

/* mqtt1.pub_update */
const char * mgos_config_get_mqtt1_pub_update(const struct mgos_config *cfg) { return cfg->mqtt1.pub_update; }
const char * mgos_config_get_default_mqtt1_pub_update(void) { return "?????\?/response/update"; }
void mgos_config_set_mqtt1_pub_update(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.pub_update, v); }

/* mqtt1.sub_update */
const char * mgos_config_get_mqtt1_sub_update(const struct mgos_config *cfg) { return cfg->mqtt1.sub_update; }
const char * mgos_config_get_default_mqtt1_sub_update(void) { return "?????\?/request/update"; }
void mgos_config_set_mqtt1_sub_update(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->mqtt1.sub_update, v); }

/* shadow */
const struct mgos_config_shadow *mgos_config_get_shadow(const struct mgos_config *cfg) { return &cfg->shadow; }

/* shadow.enable */
int mgos_config_get_shadow_enable(const struct mgos_config *cfg) { return cfg->shadow.enable; }
int mgos_config_get_default_shadow_enable(void) { return true; }
void mgos_config_set_shadow_enable(struct mgos_config *cfg, int v) { cfg->shadow.enable = v; }

/* shadow.lib */
const char * mgos_config_get_shadow_lib(const struct mgos_config *cfg) { return cfg->shadow.lib; }
const char * mgos_config_get_default_shadow_lib(void) { return NULL; }
void mgos_config_set_shadow_lib(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->shadow.lib, v); }

/* shadow.get_on_connect */
int mgos_config_get_shadow_get_on_connect(const struct mgos_config *cfg) { return cfg->shadow.get_on_connect; }
int mgos_config_get_default_shadow_get_on_connect(void) { return true; }
void mgos_config_set_shadow_get_on_connect(struct mgos_config *cfg, int v) { cfg->shadow.get_on_connect = v; }

/* shadow.ota_enable */
int mgos_config_get_shadow_ota_enable(const struct mgos_config *cfg) { return cfg->shadow.ota_enable; }
int mgos_config_get_default_shadow_ota_enable(void) { return true; }
void mgos_config_set_shadow_ota_enable(struct mgos_config *cfg, int v) { cfg->shadow.ota_enable = v; }

/* shadow.autocommit */
int mgos_config_get_shadow_autocommit(const struct mgos_config *cfg) { return cfg->shadow.autocommit; }
int mgos_config_get_default_shadow_autocommit(void) { return false; }
void mgos_config_set_shadow_autocommit(struct mgos_config *cfg, int v) { cfg->shadow.autocommit = v; }

/* aws */
const struct mgos_config_aws *mgos_config_get_aws(const struct mgos_config *cfg) { return &cfg->aws; }

/* aws.thing_name */
const char * mgos_config_get_aws_thing_name(const struct mgos_config *cfg) { return cfg->aws.thing_name; }
const char * mgos_config_get_default_aws_thing_name(void) { return NULL; }
void mgos_config_set_aws_thing_name(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->aws.thing_name, v); }

/* aws.greengrass */
const struct mgos_config_aws_greengrass *mgos_config_get_aws_greengrass(const struct mgos_config *cfg) { return &cfg->aws.greengrass; }

/* aws.greengrass.enable */
int mgos_config_get_aws_greengrass_enable(const struct mgos_config *cfg) { return cfg->aws.greengrass.enable; }
int mgos_config_get_default_aws_greengrass_enable(void) { return false; }
void mgos_config_set_aws_greengrass_enable(struct mgos_config *cfg, int v) { cfg->aws.greengrass.enable = v; }

/* aws.greengrass.reconnect_timeout_min */
int mgos_config_get_aws_greengrass_reconnect_timeout_min(const struct mgos_config *cfg) { return cfg->aws.greengrass.reconnect_timeout_min; }
int mgos_config_get_default_aws_greengrass_reconnect_timeout_min(void) { return 2; }
void mgos_config_set_aws_greengrass_reconnect_timeout_min(struct mgos_config *cfg, int v) { cfg->aws.greengrass.reconnect_timeout_min = v; }

/* aws.greengrass.reconnect_timeout_max */
int mgos_config_get_aws_greengrass_reconnect_timeout_max(const struct mgos_config *cfg) { return cfg->aws.greengrass.reconnect_timeout_max; }
int mgos_config_get_default_aws_greengrass_reconnect_timeout_max(void) { return 60; }
void mgos_config_set_aws_greengrass_reconnect_timeout_max(struct mgos_config *cfg, int v) { cfg->aws.greengrass.reconnect_timeout_max = v; }

/* update */
const struct mgos_config_update *mgos_config_get_update(const struct mgos_config *cfg) { return &cfg->update; }

/* update.timeout */
int mgos_config_get_update_timeout(const struct mgos_config *cfg) { return cfg->update.timeout; }
int mgos_config_get_default_update_timeout(void) { return 600; }
void mgos_config_set_update_timeout(struct mgos_config *cfg, int v) { cfg->update.timeout = v; }

/* update.commit_timeout */
int mgos_config_get_update_commit_timeout(const struct mgos_config *cfg) { return cfg->update.commit_timeout; }
int mgos_config_get_default_update_commit_timeout(void) { return 0; }
void mgos_config_set_update_commit_timeout(struct mgos_config *cfg, int v) { cfg->update.commit_timeout = v; }

/* update.url */
const char * mgos_config_get_update_url(const struct mgos_config *cfg) { return cfg->update.url; }
const char * mgos_config_get_default_update_url(void) { return NULL; }
void mgos_config_set_update_url(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->update.url, v); }

/* update.interval */
int mgos_config_get_update_interval(const struct mgos_config *cfg) { return cfg->update.interval; }
int mgos_config_get_default_update_interval(void) { return 0; }
void mgos_config_set_update_interval(struct mgos_config *cfg, int v) { cfg->update.interval = v; }

/* update.extra_http_headers */
const char * mgos_config_get_update_extra_http_headers(const struct mgos_config *cfg) { return cfg->update.extra_http_headers; }
const char * mgos_config_get_default_update_extra_http_headers(void) { return NULL; }
void mgos_config_set_update_extra_http_headers(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->update.extra_http_headers, v); }

/* update.ssl_ca_file */
const char * mgos_config_get_update_ssl_ca_file(const struct mgos_config *cfg) { return cfg->update.ssl_ca_file; }
const char * mgos_config_get_default_update_ssl_ca_file(void) { return "ca.pem"; }
void mgos_config_set_update_ssl_ca_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->update.ssl_ca_file, v); }

/* update.ssl_client_cert_file */
const char * mgos_config_get_update_ssl_client_cert_file(const struct mgos_config *cfg) { return cfg->update.ssl_client_cert_file; }
const char * mgos_config_get_default_update_ssl_client_cert_file(void) { return NULL; }
void mgos_config_set_update_ssl_client_cert_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->update.ssl_client_cert_file, v); }

/* update.ssl_server_name */
const char * mgos_config_get_update_ssl_server_name(const struct mgos_config *cfg) { return cfg->update.ssl_server_name; }
const char * mgos_config_get_default_update_ssl_server_name(void) { return NULL; }
void mgos_config_set_update_ssl_server_name(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->update.ssl_server_name, v); }

/* update.enable_post */
int mgos_config_get_update_enable_post(const struct mgos_config *cfg) { return cfg->update.enable_post; }
int mgos_config_get_default_update_enable_post(void) { return true; }
void mgos_config_set_update_enable_post(struct mgos_config *cfg, int v) { cfg->update.enable_post = v; }

/* rpc */
const struct mgos_config_rpc *mgos_config_get_rpc(const struct mgos_config *cfg) { return &cfg->rpc; }

/* rpc.enable */
int mgos_config_get_rpc_enable(const struct mgos_config *cfg) { return cfg->rpc.enable; }
int mgos_config_get_default_rpc_enable(void) { return true; }
void mgos_config_set_rpc_enable(struct mgos_config *cfg, int v) { cfg->rpc.enable = v; }

/* rpc.http_enable */
int mgos_config_get_rpc_http_enable(const struct mgos_config *cfg) { return cfg->rpc.http_enable; }
int mgos_config_get_default_rpc_http_enable(void) { return true; }
void mgos_config_set_rpc_http_enable(struct mgos_config *cfg, int v) { cfg->rpc.http_enable = v; }

/* rpc.service_sys_enable */
int mgos_config_get_rpc_service_sys_enable(const struct mgos_config *cfg) { return cfg->rpc.service_sys_enable; }
int mgos_config_get_default_rpc_service_sys_enable(void) { return true; }
void mgos_config_set_rpc_service_sys_enable(struct mgos_config *cfg, int v) { cfg->rpc.service_sys_enable = v; }

/* rpc.max_frame_size */
int mgos_config_get_rpc_max_frame_size(const struct mgos_config *cfg) { return cfg->rpc.max_frame_size; }
int mgos_config_get_default_rpc_max_frame_size(void) { return 4096; }
void mgos_config_set_rpc_max_frame_size(struct mgos_config *cfg, int v) { cfg->rpc.max_frame_size = v; }

/* rpc.max_queue_length */
int mgos_config_get_rpc_max_queue_length(const struct mgos_config *cfg) { return cfg->rpc.max_queue_length; }
int mgos_config_get_default_rpc_max_queue_length(void) { return 25; }
void mgos_config_set_rpc_max_queue_length(struct mgos_config *cfg, int v) { cfg->rpc.max_queue_length = v; }

/* rpc.default_out_channel_idle_close_timeout */
int mgos_config_get_rpc_default_out_channel_idle_close_timeout(const struct mgos_config *cfg) { return cfg->rpc.default_out_channel_idle_close_timeout; }
int mgos_config_get_default_rpc_default_out_channel_idle_close_timeout(void) { return 10; }
void mgos_config_set_rpc_default_out_channel_idle_close_timeout(struct mgos_config *cfg, int v) { cfg->rpc.default_out_channel_idle_close_timeout = v; }

/* rpc.acl_file */
const char * mgos_config_get_rpc_acl_file(const struct mgos_config *cfg) { return cfg->rpc.acl_file; }
const char * mgos_config_get_default_rpc_acl_file(void) { return NULL; }
void mgos_config_set_rpc_acl_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.acl_file, v); }

/* rpc.auth_domain */
const char * mgos_config_get_rpc_auth_domain(const struct mgos_config *cfg) { return cfg->rpc.auth_domain; }
const char * mgos_config_get_default_rpc_auth_domain(void) { return "RPC"; }
void mgos_config_set_rpc_auth_domain(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.auth_domain, v); }

/* rpc.auth_file */
const char * mgos_config_get_rpc_auth_file(const struct mgos_config *cfg) { return cfg->rpc.auth_file; }
const char * mgos_config_get_default_rpc_auth_file(void) { return NULL; }
void mgos_config_set_rpc_auth_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.auth_file, v); }

/* rpc.ws */
const struct mgos_config_rpc_ws *mgos_config_get_rpc_ws(const struct mgos_config *cfg) { return &cfg->rpc.ws; }

/* rpc.ws.enable */
int mgos_config_get_rpc_ws_enable(const struct mgos_config *cfg) { return cfg->rpc.ws.enable; }
int mgos_config_get_default_rpc_ws_enable(void) { return true; }
void mgos_config_set_rpc_ws_enable(struct mgos_config *cfg, int v) { cfg->rpc.ws.enable = v; }

/* rpc.ws.server_address */
const char * mgos_config_get_rpc_ws_server_address(const struct mgos_config *cfg) { return cfg->rpc.ws.server_address; }
const char * mgos_config_get_default_rpc_ws_server_address(void) { return NULL; }
void mgos_config_set_rpc_ws_server_address(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.ws.server_address, v); }

/* rpc.ws.reconnect_interval_min */
int mgos_config_get_rpc_ws_reconnect_interval_min(const struct mgos_config *cfg) { return cfg->rpc.ws.reconnect_interval_min; }
int mgos_config_get_default_rpc_ws_reconnect_interval_min(void) { return 1; }
void mgos_config_set_rpc_ws_reconnect_interval_min(struct mgos_config *cfg, int v) { cfg->rpc.ws.reconnect_interval_min = v; }

/* rpc.ws.reconnect_interval_max */
int mgos_config_get_rpc_ws_reconnect_interval_max(const struct mgos_config *cfg) { return cfg->rpc.ws.reconnect_interval_max; }
int mgos_config_get_default_rpc_ws_reconnect_interval_max(void) { return 60; }
void mgos_config_set_rpc_ws_reconnect_interval_max(struct mgos_config *cfg, int v) { cfg->rpc.ws.reconnect_interval_max = v; }

/* rpc.ws.ssl_server_name */
const char * mgos_config_get_rpc_ws_ssl_server_name(const struct mgos_config *cfg) { return cfg->rpc.ws.ssl_server_name; }
const char * mgos_config_get_default_rpc_ws_ssl_server_name(void) { return NULL; }
void mgos_config_set_rpc_ws_ssl_server_name(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.ws.ssl_server_name, v); }

/* rpc.ws.ssl_cert */
const char * mgos_config_get_rpc_ws_ssl_cert(const struct mgos_config *cfg) { return cfg->rpc.ws.ssl_cert; }
const char * mgos_config_get_default_rpc_ws_ssl_cert(void) { return NULL; }
void mgos_config_set_rpc_ws_ssl_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.ws.ssl_cert, v); }

/* rpc.ws.ssl_key */
const char * mgos_config_get_rpc_ws_ssl_key(const struct mgos_config *cfg) { return cfg->rpc.ws.ssl_key; }
const char * mgos_config_get_default_rpc_ws_ssl_key(void) { return NULL; }
void mgos_config_set_rpc_ws_ssl_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.ws.ssl_key, v); }

/* rpc.ws.ssl_ca_cert */
const char * mgos_config_get_rpc_ws_ssl_ca_cert(const struct mgos_config *cfg) { return cfg->rpc.ws.ssl_ca_cert; }
const char * mgos_config_get_default_rpc_ws_ssl_ca_cert(void) { return NULL; }
void mgos_config_set_rpc_ws_ssl_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.ws.ssl_ca_cert, v); }

/* rpc.mqtt */
const struct mgos_config_rpc_mqtt *mgos_config_get_rpc_mqtt(const struct mgos_config *cfg) { return &cfg->rpc.mqtt; }

/* rpc.mqtt.enable */
int mgos_config_get_rpc_mqtt_enable(const struct mgos_config *cfg) { return cfg->rpc.mqtt.enable; }
int mgos_config_get_default_rpc_mqtt_enable(void) { return true; }
void mgos_config_set_rpc_mqtt_enable(struct mgos_config *cfg, int v) { cfg->rpc.mqtt.enable = v; }

/* rpc.mqtt.pub_topic */
const char * mgos_config_get_rpc_mqtt_pub_topic(const struct mgos_config *cfg) { return cfg->rpc.mqtt.pub_topic; }
const char * mgos_config_get_default_rpc_mqtt_pub_topic(void) { return "%.*s/rpc"; }
void mgos_config_set_rpc_mqtt_pub_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.mqtt.pub_topic, v); }

/* rpc.mqtt.sub_topic */
const char * mgos_config_get_rpc_mqtt_sub_topic(const struct mgos_config *cfg) { return cfg->rpc.mqtt.sub_topic; }
const char * mgos_config_get_default_rpc_mqtt_sub_topic(void) { return "%.*s/rpc"; }
void mgos_config_set_rpc_mqtt_sub_topic(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.mqtt.sub_topic, v); }

/* rpc.mqtt.sub_wc */
int mgos_config_get_rpc_mqtt_sub_wc(const struct mgos_config *cfg) { return cfg->rpc.mqtt.sub_wc; }
int mgos_config_get_default_rpc_mqtt_sub_wc(void) { return true; }
void mgos_config_set_rpc_mqtt_sub_wc(struct mgos_config *cfg, int v) { cfg->rpc.mqtt.sub_wc = v; }

/* rpc.mqtt.qos */
int mgos_config_get_rpc_mqtt_qos(const struct mgos_config *cfg) { return cfg->rpc.mqtt.qos; }
int mgos_config_get_default_rpc_mqtt_qos(void) { return 1; }
void mgos_config_set_rpc_mqtt_qos(struct mgos_config *cfg, int v) { cfg->rpc.mqtt.qos = v; }

/* rpc.uart */
const struct mgos_config_rpc_uart *mgos_config_get_rpc_uart(const struct mgos_config *cfg) { return &cfg->rpc.uart; }

/* rpc.uart.uart_no */
int mgos_config_get_rpc_uart_uart_no(const struct mgos_config *cfg) { return cfg->rpc.uart.uart_no; }
int mgos_config_get_default_rpc_uart_uart_no(void) { return 0; }
void mgos_config_set_rpc_uart_uart_no(struct mgos_config *cfg, int v) { cfg->rpc.uart.uart_no = v; }

/* rpc.uart.baud_rate */
int mgos_config_get_rpc_uart_baud_rate(const struct mgos_config *cfg) { return cfg->rpc.uart.baud_rate; }
int mgos_config_get_default_rpc_uart_baud_rate(void) { return 115200; }
void mgos_config_set_rpc_uart_baud_rate(struct mgos_config *cfg, int v) { cfg->rpc.uart.baud_rate = v; }

/* rpc.uart.fc_type */
int mgos_config_get_rpc_uart_fc_type(const struct mgos_config *cfg) { return cfg->rpc.uart.fc_type; }
int mgos_config_get_default_rpc_uart_fc_type(void) { return 2; }
void mgos_config_set_rpc_uart_fc_type(struct mgos_config *cfg, int v) { cfg->rpc.uart.fc_type = v; }

/* rpc.uart.dst */
const char * mgos_config_get_rpc_uart_dst(const struct mgos_config *cfg) { return cfg->rpc.uart.dst; }
const char * mgos_config_get_default_rpc_uart_dst(void) { return NULL; }
void mgos_config_set_rpc_uart_dst(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->rpc.uart.dst, v); }

/* dash */
const struct mgos_config_dash *mgos_config_get_dash(const struct mgos_config *cfg) { return &cfg->dash; }

/* dash.enable */
int mgos_config_get_dash_enable(const struct mgos_config *cfg) { return cfg->dash.enable; }
int mgos_config_get_default_dash_enable(void) { return false; }
void mgos_config_set_dash_enable(struct mgos_config *cfg, int v) { cfg->dash.enable = v; }

/* dash.token */
const char * mgos_config_get_dash_token(const struct mgos_config *cfg) { return cfg->dash.token; }
const char * mgos_config_get_default_dash_token(void) { return NULL; }
void mgos_config_set_dash_token(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->dash.token, v); }

/* dash.server */
const char * mgos_config_get_dash_server(const struct mgos_config *cfg) { return cfg->dash.server; }
const char * mgos_config_get_default_dash_server(void) { return "wss://mdash.net/api/v2/rpc"; }
void mgos_config_set_dash_server(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->dash.server, v); }

/* dash.ssl_cert */
const char * mgos_config_get_dash_ssl_cert(const struct mgos_config *cfg) { return cfg->dash.ssl_cert; }
const char * mgos_config_get_default_dash_ssl_cert(void) { return NULL; }
void mgos_config_set_dash_ssl_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->dash.ssl_cert, v); }

/* dash.ssl_key */
const char * mgos_config_get_dash_ssl_key(const struct mgos_config *cfg) { return cfg->dash.ssl_key; }
const char * mgos_config_get_default_dash_ssl_key(void) { return NULL; }
void mgos_config_set_dash_ssl_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->dash.ssl_key, v); }

/* dash.ssl_ca_cert */
const char * mgos_config_get_dash_ssl_ca_cert(const struct mgos_config *cfg) { return cfg->dash.ssl_ca_cert; }
const char * mgos_config_get_default_dash_ssl_ca_cert(void) { return "ca.pem"; }
void mgos_config_set_dash_ssl_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->dash.ssl_ca_cert, v); }

/* dash.send_logs */
int mgos_config_get_dash_send_logs(const struct mgos_config *cfg) { return cfg->dash.send_logs; }
int mgos_config_get_default_dash_send_logs(void) { return false; }
void mgos_config_set_dash_send_logs(struct mgos_config *cfg, int v) { cfg->dash.send_logs = v; }

/* file_logger */
const struct mgos_config_file_logger *mgos_config_get_file_logger(const struct mgos_config *cfg) { return &cfg->file_logger; }

/* file_logger.enable */
int mgos_config_get_file_logger_enable(const struct mgos_config *cfg) { return cfg->file_logger.enable; }
int mgos_config_get_default_file_logger_enable(void) { return false; }
void mgos_config_set_file_logger_enable(struct mgos_config *cfg, int v) { cfg->file_logger.enable = v; }

/* file_logger.dir */
const char * mgos_config_get_file_logger_dir(const struct mgos_config *cfg) { return cfg->file_logger.dir; }
const char * mgos_config_get_default_file_logger_dir(void) { return "/"; }
void mgos_config_set_file_logger_dir(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->file_logger.dir, v); }

/* file_logger.prefix */
const char * mgos_config_get_file_logger_prefix(const struct mgos_config *cfg) { return cfg->file_logger.prefix; }
const char * mgos_config_get_default_file_logger_prefix(void) { return "log_"; }
void mgos_config_set_file_logger_prefix(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->file_logger.prefix, v); }

/* file_logger.max_file_size */
int mgos_config_get_file_logger_max_file_size(const struct mgos_config *cfg) { return cfg->file_logger.max_file_size; }
int mgos_config_get_default_file_logger_max_file_size(void) { return 4000; }
void mgos_config_set_file_logger_max_file_size(struct mgos_config *cfg, int v) { cfg->file_logger.max_file_size = v; }

/* file_logger.max_num_files */
int mgos_config_get_file_logger_max_num_files(const struct mgos_config *cfg) { return cfg->file_logger.max_num_files; }
int mgos_config_get_default_file_logger_max_num_files(void) { return 10; }
void mgos_config_set_file_logger_max_num_files(struct mgos_config *cfg, int v) { cfg->file_logger.max_num_files = v; }

/* file_logger.timestamps */
int mgos_config_get_file_logger_timestamps(const struct mgos_config *cfg) { return cfg->file_logger.timestamps; }
int mgos_config_get_default_file_logger_timestamps(void) { return true; }
void mgos_config_set_file_logger_timestamps(struct mgos_config *cfg, int v) { cfg->file_logger.timestamps = v; }

/* file_logger.level */
int mgos_config_get_file_logger_level(const struct mgos_config *cfg) { return cfg->file_logger.level; }
int mgos_config_get_default_file_logger_level(void) { return 2; }
void mgos_config_set_file_logger_level(struct mgos_config *cfg, int v) { cfg->file_logger.level = v; }

/* file_logger.include */
const char * mgos_config_get_file_logger_include(const struct mgos_config *cfg) { return cfg->file_logger.include; }
const char * mgos_config_get_default_file_logger_include(void) { return NULL; }
void mgos_config_set_file_logger_include(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->file_logger.include, v); }

/* file_logger.syslog_enable */
int mgos_config_get_file_logger_syslog_enable(const struct mgos_config *cfg) { return cfg->file_logger.syslog_enable; }
int mgos_config_get_default_file_logger_syslog_enable(void) { return true; }
void mgos_config_set_file_logger_syslog_enable(struct mgos_config *cfg, int v) { cfg->file_logger.syslog_enable = v; }

/* file_logger.rpc_service_enable */
int mgos_config_get_file_logger_rpc_service_enable(const struct mgos_config *cfg) { return cfg->file_logger.rpc_service_enable; }
int mgos_config_get_default_file_logger_rpc_service_enable(void) { return false; }
void mgos_config_set_file_logger_rpc_service_enable(struct mgos_config *cfg, int v) { cfg->file_logger.rpc_service_enable = v; }

/* file_logger.buf_size */
int mgos_config_get_file_logger_buf_size(const struct mgos_config *cfg) { return cfg->file_logger.buf_size; }
int mgos_config_get_default_file_logger_buf_size(void) { return 256; }
void mgos_config_set_file_logger_buf_size(struct mgos_config *cfg, int v) { cfg->file_logger.buf_size = v; }

/* file_logger.buf_line */
int mgos_config_get_file_logger_buf_line(const struct mgos_config *cfg) { return cfg->file_logger.buf_line; }
int mgos_config_get_default_file_logger_buf_line(void) { return true; }
void mgos_config_set_file_logger_buf_line(struct mgos_config *cfg, int v) { cfg->file_logger.buf_line = v; }

/* http */
const struct mgos_config_http *mgos_config_get_http(const struct mgos_config *cfg) { return &cfg->http; }

/* http.enable */
int mgos_config_get_http_enable(const struct mgos_config *cfg) { return cfg->http.enable; }
int mgos_config_get_default_http_enable(void) { return true; }
void mgos_config_set_http_enable(struct mgos_config *cfg, int v) { cfg->http.enable = v; }

/* http.listen_addr */
const char * mgos_config_get_http_listen_addr(const struct mgos_config *cfg) { return cfg->http.listen_addr; }
const char * mgos_config_get_default_http_listen_addr(void) { return "80"; }
void mgos_config_set_http_listen_addr(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.listen_addr, v); }

/* http.document_root */
const char * mgos_config_get_http_document_root(const struct mgos_config *cfg) { return cfg->http.document_root; }
const char * mgos_config_get_default_http_document_root(void) { return "/"; }
void mgos_config_set_http_document_root(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.document_root, v); }

/* http.index_files */
const char * mgos_config_get_http_index_files(const struct mgos_config *cfg) { return cfg->http.index_files; }
const char * mgos_config_get_default_http_index_files(void) { return NULL; }
void mgos_config_set_http_index_files(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.index_files, v); }

/* http.ssl_cert */
const char * mgos_config_get_http_ssl_cert(const struct mgos_config *cfg) { return cfg->http.ssl_cert; }
const char * mgos_config_get_default_http_ssl_cert(void) { return NULL; }
void mgos_config_set_http_ssl_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.ssl_cert, v); }

/* http.ssl_key */
const char * mgos_config_get_http_ssl_key(const struct mgos_config *cfg) { return cfg->http.ssl_key; }
const char * mgos_config_get_default_http_ssl_key(void) { return NULL; }
void mgos_config_set_http_ssl_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.ssl_key, v); }

/* http.ssl_ca_cert */
const char * mgos_config_get_http_ssl_ca_cert(const struct mgos_config *cfg) { return cfg->http.ssl_ca_cert; }
const char * mgos_config_get_default_http_ssl_ca_cert(void) { return NULL; }
void mgos_config_set_http_ssl_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.ssl_ca_cert, v); }

/* http.upload_acl */
const char * mgos_config_get_http_upload_acl(const struct mgos_config *cfg) { return cfg->http.upload_acl; }
const char * mgos_config_get_default_http_upload_acl(void) { return "*"; }
void mgos_config_set_http_upload_acl(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.upload_acl, v); }

/* http.hidden_files */
const char * mgos_config_get_http_hidden_files(const struct mgos_config *cfg) { return cfg->http.hidden_files; }
const char * mgos_config_get_default_http_hidden_files(void) { return NULL; }
void mgos_config_set_http_hidden_files(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.hidden_files, v); }

/* http.auth_domain */
const char * mgos_config_get_http_auth_domain(const struct mgos_config *cfg) { return cfg->http.auth_domain; }
const char * mgos_config_get_default_http_auth_domain(void) { return NULL; }
void mgos_config_set_http_auth_domain(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.auth_domain, v); }

/* http.auth_file */
const char * mgos_config_get_http_auth_file(const struct mgos_config *cfg) { return cfg->http.auth_file; }
const char * mgos_config_get_default_http_auth_file(void) { return NULL; }
void mgos_config_set_http_auth_file(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.auth_file, v); }

/* http.extra_headers */
const char * mgos_config_get_http_extra_headers(const struct mgos_config *cfg) { return cfg->http.extra_headers; }
const char * mgos_config_get_default_http_extra_headers(void) { return NULL; }
void mgos_config_set_http_extra_headers(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->http.extra_headers, v); }

/* i2c */
const struct mgos_config_i2c *mgos_config_get_i2c(const struct mgos_config *cfg) { return &cfg->i2c; }

/* i2c.enable */
int mgos_config_get_i2c_enable(const struct mgos_config *cfg) { return cfg->i2c.enable; }
int mgos_config_get_default_i2c_enable(void) { return false; }
void mgos_config_set_i2c_enable(struct mgos_config *cfg, int v) { cfg->i2c.enable = v; }

/* i2c.freq */
int mgos_config_get_i2c_freq(const struct mgos_config *cfg) { return cfg->i2c.freq; }
int mgos_config_get_default_i2c_freq(void) { return 100000; }
void mgos_config_set_i2c_freq(struct mgos_config *cfg, int v) { cfg->i2c.freq = v; }

/* i2c.debug */
int mgos_config_get_i2c_debug(const struct mgos_config *cfg) { return cfg->i2c.debug; }
int mgos_config_get_default_i2c_debug(void) { return false; }
void mgos_config_set_i2c_debug(struct mgos_config *cfg, int v) { cfg->i2c.debug = v; }

/* i2c.sda_gpio */
int mgos_config_get_i2c_sda_gpio(const struct mgos_config *cfg) { return cfg->i2c.sda_gpio; }
int mgos_config_get_default_i2c_sda_gpio(void) { return 12; }
void mgos_config_set_i2c_sda_gpio(struct mgos_config *cfg, int v) { cfg->i2c.sda_gpio = v; }

/* i2c.scl_gpio */
int mgos_config_get_i2c_scl_gpio(const struct mgos_config *cfg) { return cfg->i2c.scl_gpio; }
int mgos_config_get_default_i2c_scl_gpio(void) { return 14; }
void mgos_config_set_i2c_scl_gpio(struct mgos_config *cfg, int v) { cfg->i2c.scl_gpio = v; }

/* i2c1 */
const struct mgos_config_i2c *mgos_config_get_i2c1(const struct mgos_config *cfg) { return &cfg->i2c1; }

/* i2c1.enable */
int mgos_config_get_i2c1_enable(const struct mgos_config *cfg) { return cfg->i2c1.enable; }
int mgos_config_get_default_i2c1_enable(void) { return false; }
void mgos_config_set_i2c1_enable(struct mgos_config *cfg, int v) { cfg->i2c1.enable = v; }

/* i2c1.freq */
int mgos_config_get_i2c1_freq(const struct mgos_config *cfg) { return cfg->i2c1.freq; }
int mgos_config_get_default_i2c1_freq(void) { return 100000; }
void mgos_config_set_i2c1_freq(struct mgos_config *cfg, int v) { cfg->i2c1.freq = v; }

/* i2c1.debug */
int mgos_config_get_i2c1_debug(const struct mgos_config *cfg) { return cfg->i2c1.debug; }
int mgos_config_get_default_i2c1_debug(void) { return false; }
void mgos_config_set_i2c1_debug(struct mgos_config *cfg, int v) { cfg->i2c1.debug = v; }

/* i2c1.sda_gpio */
int mgos_config_get_i2c1_sda_gpio(const struct mgos_config *cfg) { return cfg->i2c1.sda_gpio; }
int mgos_config_get_default_i2c1_sda_gpio(void) { return 4; }
void mgos_config_set_i2c1_sda_gpio(struct mgos_config *cfg, int v) { cfg->i2c1.sda_gpio = v; }

/* i2c1.scl_gpio */
int mgos_config_get_i2c1_scl_gpio(const struct mgos_config *cfg) { return cfg->i2c1.scl_gpio; }
int mgos_config_get_default_i2c1_scl_gpio(void) { return 5; }
void mgos_config_set_i2c1_scl_gpio(struct mgos_config *cfg, int v) { cfg->i2c1.scl_gpio = v; }

/* sntp */
const struct mgos_config_sntp *mgos_config_get_sntp(const struct mgos_config *cfg) { return &cfg->sntp; }

/* sntp.enable */
int mgos_config_get_sntp_enable(const struct mgos_config *cfg) { return cfg->sntp.enable; }
int mgos_config_get_default_sntp_enable(void) { return true; }
void mgos_config_set_sntp_enable(struct mgos_config *cfg, int v) { cfg->sntp.enable = v; }

/* sntp.server */
const char * mgos_config_get_sntp_server(const struct mgos_config *cfg) { return cfg->sntp.server; }
const char * mgos_config_get_default_sntp_server(void) { return "time.google.com"; }
void mgos_config_set_sntp_server(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->sntp.server, v); }

/* sntp.retry_min */
int mgos_config_get_sntp_retry_min(const struct mgos_config *cfg) { return cfg->sntp.retry_min; }
int mgos_config_get_default_sntp_retry_min(void) { return 1; }
void mgos_config_set_sntp_retry_min(struct mgos_config *cfg, int v) { cfg->sntp.retry_min = v; }

/* sntp.retry_max */
int mgos_config_get_sntp_retry_max(const struct mgos_config *cfg) { return cfg->sntp.retry_max; }
int mgos_config_get_default_sntp_retry_max(void) { return 30; }
void mgos_config_set_sntp_retry_max(struct mgos_config *cfg, int v) { cfg->sntp.retry_max = v; }

/* sntp.update_interval */
int mgos_config_get_sntp_update_interval(const struct mgos_config *cfg) { return cfg->sntp.update_interval; }
int mgos_config_get_default_sntp_update_interval(void) { return 7200; }
void mgos_config_set_sntp_update_interval(struct mgos_config *cfg, int v) { cfg->sntp.update_interval = v; }

/* spi */
const struct mgos_config_spi *mgos_config_get_spi(const struct mgos_config *cfg) { return &cfg->spi; }

/* spi.enable */
int mgos_config_get_spi_enable(const struct mgos_config *cfg) { return cfg->spi.enable; }
int mgos_config_get_default_spi_enable(void) { return false; }
void mgos_config_set_spi_enable(struct mgos_config *cfg, int v) { cfg->spi.enable = v; }

/* spi.debug */
int mgos_config_get_spi_debug(const struct mgos_config *cfg) { return cfg->spi.debug; }
int mgos_config_get_default_spi_debug(void) { return false; }
void mgos_config_set_spi_debug(struct mgos_config *cfg, int v) { cfg->spi.debug = v; }

/* spi.miso_gpio */
int mgos_config_get_spi_miso_gpio(const struct mgos_config *cfg) { return cfg->spi.miso_gpio; }
int mgos_config_get_default_spi_miso_gpio(void) { return 12; }
void mgos_config_set_spi_miso_gpio(struct mgos_config *cfg, int v) { cfg->spi.miso_gpio = v; }

/* spi.mosi_gpio */
int mgos_config_get_spi_mosi_gpio(const struct mgos_config *cfg) { return cfg->spi.mosi_gpio; }
int mgos_config_get_default_spi_mosi_gpio(void) { return 13; }
void mgos_config_set_spi_mosi_gpio(struct mgos_config *cfg, int v) { cfg->spi.mosi_gpio = v; }

/* spi.sclk_gpio */
int mgos_config_get_spi_sclk_gpio(const struct mgos_config *cfg) { return cfg->spi.sclk_gpio; }
int mgos_config_get_default_spi_sclk_gpio(void) { return 14; }
void mgos_config_set_spi_sclk_gpio(struct mgos_config *cfg, int v) { cfg->spi.sclk_gpio = v; }

/* spi.cs0_gpio */
int mgos_config_get_spi_cs0_gpio(const struct mgos_config *cfg) { return cfg->spi.cs0_gpio; }
int mgos_config_get_default_spi_cs0_gpio(void) { return 15; }
void mgos_config_set_spi_cs0_gpio(struct mgos_config *cfg, int v) { cfg->spi.cs0_gpio = v; }

/* spi.cs1_gpio */
int mgos_config_get_spi_cs1_gpio(const struct mgos_config *cfg) { return cfg->spi.cs1_gpio; }
int mgos_config_get_default_spi_cs1_gpio(void) { return -1; }
void mgos_config_set_spi_cs1_gpio(struct mgos_config *cfg, int v) { cfg->spi.cs1_gpio = v; }

/* spi.cs2_gpio */
int mgos_config_get_spi_cs2_gpio(const struct mgos_config *cfg) { return cfg->spi.cs2_gpio; }
int mgos_config_get_default_spi_cs2_gpio(void) { return -1; }
void mgos_config_set_spi_cs2_gpio(struct mgos_config *cfg, int v) { cfg->spi.cs2_gpio = v; }

/* wifi */
const struct mgos_config_wifi *mgos_config_get_wifi(const struct mgos_config *cfg) { return &cfg->wifi; }

/* wifi.ap */
const struct mgos_config_wifi_ap *mgos_config_get_wifi_ap(const struct mgos_config *cfg) { return &cfg->wifi.ap; }

/* wifi.ap.enable */
int mgos_config_get_wifi_ap_enable(const struct mgos_config *cfg) { return cfg->wifi.ap.enable; }
int mgos_config_get_default_wifi_ap_enable(void) { return true; }
void mgos_config_set_wifi_ap_enable(struct mgos_config *cfg, int v) { cfg->wifi.ap.enable = v; }

/* wifi.ap.ssid */
const char * mgos_config_get_wifi_ap_ssid(const struct mgos_config *cfg) { return cfg->wifi.ap.ssid; }
const char * mgos_config_get_default_wifi_ap_ssid(void) { return "EDEN_3_??????"; }
void mgos_config_set_wifi_ap_ssid(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.ssid, v); }

/* wifi.ap.pass */
const char * mgos_config_get_wifi_ap_pass(const struct mgos_config *cfg) { return cfg->wifi.ap.pass; }
const char * mgos_config_get_default_wifi_ap_pass(void) { return "eden1234"; }
void mgos_config_set_wifi_ap_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.pass, v); }

/* wifi.ap.hidden */
int mgos_config_get_wifi_ap_hidden(const struct mgos_config *cfg) { return cfg->wifi.ap.hidden; }
int mgos_config_get_default_wifi_ap_hidden(void) { return false; }
void mgos_config_set_wifi_ap_hidden(struct mgos_config *cfg, int v) { cfg->wifi.ap.hidden = v; }

/* wifi.ap.channel */
int mgos_config_get_wifi_ap_channel(const struct mgos_config *cfg) { return cfg->wifi.ap.channel; }
int mgos_config_get_default_wifi_ap_channel(void) { return 6; }
void mgos_config_set_wifi_ap_channel(struct mgos_config *cfg, int v) { cfg->wifi.ap.channel = v; }

/* wifi.ap.max_connections */
int mgos_config_get_wifi_ap_max_connections(const struct mgos_config *cfg) { return cfg->wifi.ap.max_connections; }
int mgos_config_get_default_wifi_ap_max_connections(void) { return 10; }
void mgos_config_set_wifi_ap_max_connections(struct mgos_config *cfg, int v) { cfg->wifi.ap.max_connections = v; }

/* wifi.ap.ip */
const char * mgos_config_get_wifi_ap_ip(const struct mgos_config *cfg) { return cfg->wifi.ap.ip; }
const char * mgos_config_get_default_wifi_ap_ip(void) { return "192.168.4.1"; }
void mgos_config_set_wifi_ap_ip(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.ip, v); }

/* wifi.ap.netmask */
const char * mgos_config_get_wifi_ap_netmask(const struct mgos_config *cfg) { return cfg->wifi.ap.netmask; }
const char * mgos_config_get_default_wifi_ap_netmask(void) { return "255.255.255.0"; }
void mgos_config_set_wifi_ap_netmask(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.netmask, v); }

/* wifi.ap.gw */
const char * mgos_config_get_wifi_ap_gw(const struct mgos_config *cfg) { return cfg->wifi.ap.gw; }
const char * mgos_config_get_default_wifi_ap_gw(void) { return "192.168.4.1"; }
void mgos_config_set_wifi_ap_gw(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.gw, v); }

/* wifi.ap.dhcp_start */
const char * mgos_config_get_wifi_ap_dhcp_start(const struct mgos_config *cfg) { return cfg->wifi.ap.dhcp_start; }
const char * mgos_config_get_default_wifi_ap_dhcp_start(void) { return "192.168.4.2"; }
void mgos_config_set_wifi_ap_dhcp_start(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.dhcp_start, v); }

/* wifi.ap.dhcp_end */
const char * mgos_config_get_wifi_ap_dhcp_end(const struct mgos_config *cfg) { return cfg->wifi.ap.dhcp_end; }
const char * mgos_config_get_default_wifi_ap_dhcp_end(void) { return "192.168.4.100"; }
void mgos_config_set_wifi_ap_dhcp_end(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.dhcp_end, v); }

/* wifi.ap.trigger_on_gpio */
int mgos_config_get_wifi_ap_trigger_on_gpio(const struct mgos_config *cfg) { return cfg->wifi.ap.trigger_on_gpio; }
int mgos_config_get_default_wifi_ap_trigger_on_gpio(void) { return -1; }
void mgos_config_set_wifi_ap_trigger_on_gpio(struct mgos_config *cfg, int v) { cfg->wifi.ap.trigger_on_gpio = v; }

/* wifi.ap.disable_after */
int mgos_config_get_wifi_ap_disable_after(const struct mgos_config *cfg) { return cfg->wifi.ap.disable_after; }
int mgos_config_get_default_wifi_ap_disable_after(void) { return 300; }
void mgos_config_set_wifi_ap_disable_after(struct mgos_config *cfg, int v) { cfg->wifi.ap.disable_after = v; }

/* wifi.ap.hostname */
const char * mgos_config_get_wifi_ap_hostname(const struct mgos_config *cfg) { return cfg->wifi.ap.hostname; }
const char * mgos_config_get_default_wifi_ap_hostname(void) { return NULL; }
void mgos_config_set_wifi_ap_hostname(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.ap.hostname, v); }

/* wifi.ap.keep_enabled */
int mgos_config_get_wifi_ap_keep_enabled(const struct mgos_config *cfg) { return cfg->wifi.ap.keep_enabled; }
int mgos_config_get_default_wifi_ap_keep_enabled(void) { return true; }
void mgos_config_set_wifi_ap_keep_enabled(struct mgos_config *cfg, int v) { cfg->wifi.ap.keep_enabled = v; }

/* wifi.sta */
const struct mgos_config_wifi_sta *mgos_config_get_wifi_sta(const struct mgos_config *cfg) { return &cfg->wifi.sta; }

/* wifi.sta.enable */
int mgos_config_get_wifi_sta_enable(const struct mgos_config *cfg) { return cfg->wifi.sta.enable; }
int mgos_config_get_default_wifi_sta_enable(void) { return false; }
void mgos_config_set_wifi_sta_enable(struct mgos_config *cfg, int v) { cfg->wifi.sta.enable = v; }

/* wifi.sta.ssid */
const char * mgos_config_get_wifi_sta_ssid(const struct mgos_config *cfg) { return cfg->wifi.sta.ssid; }
const char * mgos_config_get_default_wifi_sta_ssid(void) { return NULL; }
void mgos_config_set_wifi_sta_ssid(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.ssid, v); }

/* wifi.sta.pass */
const char * mgos_config_get_wifi_sta_pass(const struct mgos_config *cfg) { return cfg->wifi.sta.pass; }
const char * mgos_config_get_default_wifi_sta_pass(void) { return NULL; }
void mgos_config_set_wifi_sta_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.pass, v); }

/* wifi.sta.user */
const char * mgos_config_get_wifi_sta_user(const struct mgos_config *cfg) { return cfg->wifi.sta.user; }
const char * mgos_config_get_default_wifi_sta_user(void) { return NULL; }
void mgos_config_set_wifi_sta_user(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.user, v); }

/* wifi.sta.anon_identity */
const char * mgos_config_get_wifi_sta_anon_identity(const struct mgos_config *cfg) { return cfg->wifi.sta.anon_identity; }
const char * mgos_config_get_default_wifi_sta_anon_identity(void) { return NULL; }
void mgos_config_set_wifi_sta_anon_identity(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.anon_identity, v); }

/* wifi.sta.cert */
const char * mgos_config_get_wifi_sta_cert(const struct mgos_config *cfg) { return cfg->wifi.sta.cert; }
const char * mgos_config_get_default_wifi_sta_cert(void) { return NULL; }
void mgos_config_set_wifi_sta_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.cert, v); }

/* wifi.sta.key */
const char * mgos_config_get_wifi_sta_key(const struct mgos_config *cfg) { return cfg->wifi.sta.key; }
const char * mgos_config_get_default_wifi_sta_key(void) { return NULL; }
void mgos_config_set_wifi_sta_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.key, v); }

/* wifi.sta.ca_cert */
const char * mgos_config_get_wifi_sta_ca_cert(const struct mgos_config *cfg) { return cfg->wifi.sta.ca_cert; }
const char * mgos_config_get_default_wifi_sta_ca_cert(void) { return NULL; }
void mgos_config_set_wifi_sta_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.ca_cert, v); }

/* wifi.sta.ip */
const char * mgos_config_get_wifi_sta_ip(const struct mgos_config *cfg) { return cfg->wifi.sta.ip; }
const char * mgos_config_get_default_wifi_sta_ip(void) { return NULL; }
void mgos_config_set_wifi_sta_ip(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.ip, v); }

/* wifi.sta.netmask */
const char * mgos_config_get_wifi_sta_netmask(const struct mgos_config *cfg) { return cfg->wifi.sta.netmask; }
const char * mgos_config_get_default_wifi_sta_netmask(void) { return NULL; }
void mgos_config_set_wifi_sta_netmask(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.netmask, v); }

/* wifi.sta.gw */
const char * mgos_config_get_wifi_sta_gw(const struct mgos_config *cfg) { return cfg->wifi.sta.gw; }
const char * mgos_config_get_default_wifi_sta_gw(void) { return NULL; }
void mgos_config_set_wifi_sta_gw(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.gw, v); }

/* wifi.sta.nameserver */
const char * mgos_config_get_wifi_sta_nameserver(const struct mgos_config *cfg) { return cfg->wifi.sta.nameserver; }
const char * mgos_config_get_default_wifi_sta_nameserver(void) { return NULL; }
void mgos_config_set_wifi_sta_nameserver(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.nameserver, v); }

/* wifi.sta.dhcp_hostname */
const char * mgos_config_get_wifi_sta_dhcp_hostname(const struct mgos_config *cfg) { return cfg->wifi.sta.dhcp_hostname; }
const char * mgos_config_get_default_wifi_sta_dhcp_hostname(void) { return NULL; }
void mgos_config_set_wifi_sta_dhcp_hostname(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta.dhcp_hostname, v); }

/* wifi.sta1 */
const struct mgos_config_wifi_sta *mgos_config_get_wifi_sta1(const struct mgos_config *cfg) { return &cfg->wifi.sta1; }

/* wifi.sta1.enable */
int mgos_config_get_wifi_sta1_enable(const struct mgos_config *cfg) { return cfg->wifi.sta1.enable; }
int mgos_config_get_default_wifi_sta1_enable(void) { return false; }
void mgos_config_set_wifi_sta1_enable(struct mgos_config *cfg, int v) { cfg->wifi.sta1.enable = v; }

/* wifi.sta1.ssid */
const char * mgos_config_get_wifi_sta1_ssid(const struct mgos_config *cfg) { return cfg->wifi.sta1.ssid; }
const char * mgos_config_get_default_wifi_sta1_ssid(void) { return NULL; }
void mgos_config_set_wifi_sta1_ssid(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.ssid, v); }

/* wifi.sta1.pass */
const char * mgos_config_get_wifi_sta1_pass(const struct mgos_config *cfg) { return cfg->wifi.sta1.pass; }
const char * mgos_config_get_default_wifi_sta1_pass(void) { return NULL; }
void mgos_config_set_wifi_sta1_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.pass, v); }

/* wifi.sta1.user */
const char * mgos_config_get_wifi_sta1_user(const struct mgos_config *cfg) { return cfg->wifi.sta1.user; }
const char * mgos_config_get_default_wifi_sta1_user(void) { return NULL; }
void mgos_config_set_wifi_sta1_user(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.user, v); }

/* wifi.sta1.anon_identity */
const char * mgos_config_get_wifi_sta1_anon_identity(const struct mgos_config *cfg) { return cfg->wifi.sta1.anon_identity; }
const char * mgos_config_get_default_wifi_sta1_anon_identity(void) { return NULL; }
void mgos_config_set_wifi_sta1_anon_identity(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.anon_identity, v); }

/* wifi.sta1.cert */
const char * mgos_config_get_wifi_sta1_cert(const struct mgos_config *cfg) { return cfg->wifi.sta1.cert; }
const char * mgos_config_get_default_wifi_sta1_cert(void) { return NULL; }
void mgos_config_set_wifi_sta1_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.cert, v); }

/* wifi.sta1.key */
const char * mgos_config_get_wifi_sta1_key(const struct mgos_config *cfg) { return cfg->wifi.sta1.key; }
const char * mgos_config_get_default_wifi_sta1_key(void) { return NULL; }
void mgos_config_set_wifi_sta1_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.key, v); }

/* wifi.sta1.ca_cert */
const char * mgos_config_get_wifi_sta1_ca_cert(const struct mgos_config *cfg) { return cfg->wifi.sta1.ca_cert; }
const char * mgos_config_get_default_wifi_sta1_ca_cert(void) { return NULL; }
void mgos_config_set_wifi_sta1_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.ca_cert, v); }

/* wifi.sta1.ip */
const char * mgos_config_get_wifi_sta1_ip(const struct mgos_config *cfg) { return cfg->wifi.sta1.ip; }
const char * mgos_config_get_default_wifi_sta1_ip(void) { return NULL; }
void mgos_config_set_wifi_sta1_ip(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.ip, v); }

/* wifi.sta1.netmask */
const char * mgos_config_get_wifi_sta1_netmask(const struct mgos_config *cfg) { return cfg->wifi.sta1.netmask; }
const char * mgos_config_get_default_wifi_sta1_netmask(void) { return NULL; }
void mgos_config_set_wifi_sta1_netmask(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.netmask, v); }

/* wifi.sta1.gw */
const char * mgos_config_get_wifi_sta1_gw(const struct mgos_config *cfg) { return cfg->wifi.sta1.gw; }
const char * mgos_config_get_default_wifi_sta1_gw(void) { return NULL; }
void mgos_config_set_wifi_sta1_gw(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.gw, v); }

/* wifi.sta1.nameserver */
const char * mgos_config_get_wifi_sta1_nameserver(const struct mgos_config *cfg) { return cfg->wifi.sta1.nameserver; }
const char * mgos_config_get_default_wifi_sta1_nameserver(void) { return NULL; }
void mgos_config_set_wifi_sta1_nameserver(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.nameserver, v); }

/* wifi.sta1.dhcp_hostname */
const char * mgos_config_get_wifi_sta1_dhcp_hostname(const struct mgos_config *cfg) { return cfg->wifi.sta1.dhcp_hostname; }
const char * mgos_config_get_default_wifi_sta1_dhcp_hostname(void) { return NULL; }
void mgos_config_set_wifi_sta1_dhcp_hostname(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta1.dhcp_hostname, v); }

/* wifi.sta2 */
const struct mgos_config_wifi_sta *mgos_config_get_wifi_sta2(const struct mgos_config *cfg) { return &cfg->wifi.sta2; }

/* wifi.sta2.enable */
int mgos_config_get_wifi_sta2_enable(const struct mgos_config *cfg) { return cfg->wifi.sta2.enable; }
int mgos_config_get_default_wifi_sta2_enable(void) { return false; }
void mgos_config_set_wifi_sta2_enable(struct mgos_config *cfg, int v) { cfg->wifi.sta2.enable = v; }

/* wifi.sta2.ssid */
const char * mgos_config_get_wifi_sta2_ssid(const struct mgos_config *cfg) { return cfg->wifi.sta2.ssid; }
const char * mgos_config_get_default_wifi_sta2_ssid(void) { return NULL; }
void mgos_config_set_wifi_sta2_ssid(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.ssid, v); }

/* wifi.sta2.pass */
const char * mgos_config_get_wifi_sta2_pass(const struct mgos_config *cfg) { return cfg->wifi.sta2.pass; }
const char * mgos_config_get_default_wifi_sta2_pass(void) { return NULL; }
void mgos_config_set_wifi_sta2_pass(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.pass, v); }

/* wifi.sta2.user */
const char * mgos_config_get_wifi_sta2_user(const struct mgos_config *cfg) { return cfg->wifi.sta2.user; }
const char * mgos_config_get_default_wifi_sta2_user(void) { return NULL; }
void mgos_config_set_wifi_sta2_user(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.user, v); }

/* wifi.sta2.anon_identity */
const char * mgos_config_get_wifi_sta2_anon_identity(const struct mgos_config *cfg) { return cfg->wifi.sta2.anon_identity; }
const char * mgos_config_get_default_wifi_sta2_anon_identity(void) { return NULL; }
void mgos_config_set_wifi_sta2_anon_identity(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.anon_identity, v); }

/* wifi.sta2.cert */
const char * mgos_config_get_wifi_sta2_cert(const struct mgos_config *cfg) { return cfg->wifi.sta2.cert; }
const char * mgos_config_get_default_wifi_sta2_cert(void) { return NULL; }
void mgos_config_set_wifi_sta2_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.cert, v); }

/* wifi.sta2.key */
const char * mgos_config_get_wifi_sta2_key(const struct mgos_config *cfg) { return cfg->wifi.sta2.key; }
const char * mgos_config_get_default_wifi_sta2_key(void) { return NULL; }
void mgos_config_set_wifi_sta2_key(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.key, v); }

/* wifi.sta2.ca_cert */
const char * mgos_config_get_wifi_sta2_ca_cert(const struct mgos_config *cfg) { return cfg->wifi.sta2.ca_cert; }
const char * mgos_config_get_default_wifi_sta2_ca_cert(void) { return NULL; }
void mgos_config_set_wifi_sta2_ca_cert(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.ca_cert, v); }

/* wifi.sta2.ip */
const char * mgos_config_get_wifi_sta2_ip(const struct mgos_config *cfg) { return cfg->wifi.sta2.ip; }
const char * mgos_config_get_default_wifi_sta2_ip(void) { return NULL; }
void mgos_config_set_wifi_sta2_ip(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.ip, v); }

/* wifi.sta2.netmask */
const char * mgos_config_get_wifi_sta2_netmask(const struct mgos_config *cfg) { return cfg->wifi.sta2.netmask; }
const char * mgos_config_get_default_wifi_sta2_netmask(void) { return NULL; }
void mgos_config_set_wifi_sta2_netmask(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.netmask, v); }

/* wifi.sta2.gw */
const char * mgos_config_get_wifi_sta2_gw(const struct mgos_config *cfg) { return cfg->wifi.sta2.gw; }
const char * mgos_config_get_default_wifi_sta2_gw(void) { return NULL; }
void mgos_config_set_wifi_sta2_gw(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.gw, v); }

/* wifi.sta2.nameserver */
const char * mgos_config_get_wifi_sta2_nameserver(const struct mgos_config *cfg) { return cfg->wifi.sta2.nameserver; }
const char * mgos_config_get_default_wifi_sta2_nameserver(void) { return NULL; }
void mgos_config_set_wifi_sta2_nameserver(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.nameserver, v); }

/* wifi.sta2.dhcp_hostname */
const char * mgos_config_get_wifi_sta2_dhcp_hostname(const struct mgos_config *cfg) { return cfg->wifi.sta2.dhcp_hostname; }
const char * mgos_config_get_default_wifi_sta2_dhcp_hostname(void) { return NULL; }
void mgos_config_set_wifi_sta2_dhcp_hostname(struct mgos_config *cfg, const char * v) { mgos_conf_set_str(&cfg->wifi.sta2.dhcp_hostname, v); }

/* wifi.sta_cfg_idx */
int mgos_config_get_wifi_sta_cfg_idx(const struct mgos_config *cfg) { return cfg->wifi.sta_cfg_idx; }
int mgos_config_get_default_wifi_sta_cfg_idx(void) { return 0; }
void mgos_config_set_wifi_sta_cfg_idx(struct mgos_config *cfg, int v) { cfg->wifi.sta_cfg_idx = v; }

/* wifi.sta_connect_timeout */
int mgos_config_get_wifi_sta_connect_timeout(const struct mgos_config *cfg) { return cfg->wifi.sta_connect_timeout; }
int mgos_config_get_default_wifi_sta_connect_timeout(void) { return 30; }
void mgos_config_set_wifi_sta_connect_timeout(struct mgos_config *cfg, int v) { cfg->wifi.sta_connect_timeout = v; }

/* wifi.sta_all_chan_scan */
int mgos_config_get_wifi_sta_all_chan_scan(const struct mgos_config *cfg) { return cfg->wifi.sta_all_chan_scan; }
int mgos_config_get_default_wifi_sta_all_chan_scan(void) { return true; }
void mgos_config_set_wifi_sta_all_chan_scan(struct mgos_config *cfg, int v) { cfg->wifi.sta_all_chan_scan = v; }

/* additional */
const struct mgos_config_additional *mgos_config_get_additional(const struct mgos_config *cfg) { return &cfg->additional; }

/* additional.alert */
const struct mgos_config_additional_alert *mgos_config_get_additional_alert(const struct mgos_config *cfg) { return &cfg->additional.alert; }

/* additional.alert.out_1 */
int mgos_config_get_additional_alert_out_1(const struct mgos_config *cfg) { return cfg->additional.alert.out_1; }
int mgos_config_get_default_additional_alert_out_1(void) { return 0; }
void mgos_config_set_additional_alert_out_1(struct mgos_config *cfg, int v) { cfg->additional.alert.out_1 = v; }

/* additional.alert.out_2 */
int mgos_config_get_additional_alert_out_2(const struct mgos_config *cfg) { return cfg->additional.alert.out_2; }
int mgos_config_get_default_additional_alert_out_2(void) { return 0; }
void mgos_config_set_additional_alert_out_2(struct mgos_config *cfg, int v) { cfg->additional.alert.out_2 = v; }

/* additional.alert.out_3 */
int mgos_config_get_additional_alert_out_3(const struct mgos_config *cfg) { return cfg->additional.alert.out_3; }
int mgos_config_get_default_additional_alert_out_3(void) { return 0; }
void mgos_config_set_additional_alert_out_3(struct mgos_config *cfg, int v) { cfg->additional.alert.out_3 = v; }

/* additional.alert.out_4 */
int mgos_config_get_additional_alert_out_4(const struct mgos_config *cfg) { return cfg->additional.alert.out_4; }
int mgos_config_get_default_additional_alert_out_4(void) { return 0; }
void mgos_config_set_additional_alert_out_4(struct mgos_config *cfg, int v) { cfg->additional.alert.out_4 = v; }

/* additional.timer */
const struct mgos_config_additional_timer *mgos_config_get_additional_timer(const struct mgos_config *cfg) { return &cfg->additional.timer; }

/* additional.timer.out_1 */
int mgos_config_get_additional_timer_out_1(const struct mgos_config *cfg) { return cfg->additional.timer.out_1; }
int mgos_config_get_default_additional_timer_out_1(void) { return 0; }
void mgos_config_set_additional_timer_out_1(struct mgos_config *cfg, int v) { cfg->additional.timer.out_1 = v; }

/* additional.timer.out_2 */
int mgos_config_get_additional_timer_out_2(const struct mgos_config *cfg) { return cfg->additional.timer.out_2; }
int mgos_config_get_default_additional_timer_out_2(void) { return 0; }
void mgos_config_set_additional_timer_out_2(struct mgos_config *cfg, int v) { cfg->additional.timer.out_2 = v; }

/* additional.timer.out_3 */
int mgos_config_get_additional_timer_out_3(const struct mgos_config *cfg) { return cfg->additional.timer.out_3; }
int mgos_config_get_default_additional_timer_out_3(void) { return 0; }
void mgos_config_set_additional_timer_out_3(struct mgos_config *cfg, int v) { cfg->additional.timer.out_3 = v; }

/* additional.timer.out_4 */
int mgos_config_get_additional_timer_out_4(const struct mgos_config *cfg) { return cfg->additional.timer.out_4; }
int mgos_config_get_default_additional_timer_out_4(void) { return 0; }
void mgos_config_set_additional_timer_out_4(struct mgos_config *cfg, int v) { cfg->additional.timer.out_4 = v; }

/* additional.future */
const struct mgos_config_additional_future *mgos_config_get_additional_future(const struct mgos_config *cfg) { return &cfg->additional.future; }

/* additional.future.out_1 */
int mgos_config_get_additional_future_out_1(const struct mgos_config *cfg) { return cfg->additional.future.out_1; }
int mgos_config_get_default_additional_future_out_1(void) { return 0; }
void mgos_config_set_additional_future_out_1(struct mgos_config *cfg, int v) { cfg->additional.future.out_1 = v; }

/* additional.future.out_2 */
int mgos_config_get_additional_future_out_2(const struct mgos_config *cfg) { return cfg->additional.future.out_2; }
int mgos_config_get_default_additional_future_out_2(void) { return 0; }
void mgos_config_set_additional_future_out_2(struct mgos_config *cfg, int v) { cfg->additional.future.out_2 = v; }

/* additional.future.out_3 */
int mgos_config_get_additional_future_out_3(const struct mgos_config *cfg) { return cfg->additional.future.out_3; }
int mgos_config_get_default_additional_future_out_3(void) { return 0; }
void mgos_config_set_additional_future_out_3(struct mgos_config *cfg, int v) { cfg->additional.future.out_3 = v; }

/* additional.future.out_4 */
int mgos_config_get_additional_future_out_4(const struct mgos_config *cfg) { return cfg->additional.future.out_4; }
int mgos_config_get_default_additional_future_out_4(void) { return 0; }
void mgos_config_set_additional_future_out_4(struct mgos_config *cfg, int v) { cfg->additional.future.out_4 = v; }

/* outputPins */
const struct mgos_config_outputPins *mgos_config_get_outputPins(const struct mgos_config *cfg) { return &cfg->outputPins; }

/* outputPins.out_1 */
int mgos_config_get_outputPins_out_1(const struct mgos_config *cfg) { return cfg->outputPins.out_1; }
int mgos_config_get_default_outputPins_out_1(void) { return 0; }
void mgos_config_set_outputPins_out_1(struct mgos_config *cfg, int v) { cfg->outputPins.out_1 = v; }

/* outputPins.out_2 */
int mgos_config_get_outputPins_out_2(const struct mgos_config *cfg) { return cfg->outputPins.out_2; }
int mgos_config_get_default_outputPins_out_2(void) { return 0; }
void mgos_config_set_outputPins_out_2(struct mgos_config *cfg, int v) { cfg->outputPins.out_2 = v; }

/* outputPins.out_3 */
int mgos_config_get_outputPins_out_3(const struct mgos_config *cfg) { return cfg->outputPins.out_3; }
int mgos_config_get_default_outputPins_out_3(void) { return 0; }
void mgos_config_set_outputPins_out_3(struct mgos_config *cfg, int v) { cfg->outputPins.out_3 = v; }

/* outputPins.out_4 */
int mgos_config_get_outputPins_out_4(const struct mgos_config *cfg) { return cfg->outputPins.out_4; }
int mgos_config_get_default_outputPins_out_4(void) { return 0; }
void mgos_config_set_outputPins_out_4(struct mgos_config *cfg, int v) { cfg->outputPins.out_4 = v; }

/* inputPins */
const struct mgos_config_inputPins *mgos_config_get_inputPins(const struct mgos_config *cfg) { return &cfg->inputPins; }

/* inputPins.in_1 */
int mgos_config_get_inputPins_in_1(const struct mgos_config *cfg) { return cfg->inputPins.in_1; }
int mgos_config_get_default_inputPins_in_1(void) { return 0; }
void mgos_config_set_inputPins_in_1(struct mgos_config *cfg, int v) { cfg->inputPins.in_1 = v; }

/* inputPins.in_2 */
int mgos_config_get_inputPins_in_2(const struct mgos_config *cfg) { return cfg->inputPins.in_2; }
int mgos_config_get_default_inputPins_in_2(void) { return 0; }
void mgos_config_set_inputPins_in_2(struct mgos_config *cfg, int v) { cfg->inputPins.in_2 = v; }

/* inputPins.in_3 */
int mgos_config_get_inputPins_in_3(const struct mgos_config *cfg) { return cfg->inputPins.in_3; }
int mgos_config_get_default_inputPins_in_3(void) { return 0; }
void mgos_config_set_inputPins_in_3(struct mgos_config *cfg, int v) { cfg->inputPins.in_3 = v; }

/* inputPins.in_4 */
int mgos_config_get_inputPins_in_4(const struct mgos_config *cfg) { return cfg->inputPins.in_4; }
int mgos_config_get_default_inputPins_in_4(void) { return 0; }
void mgos_config_set_inputPins_in_4(struct mgos_config *cfg, int v) { cfg->inputPins.in_4 = v; }
bool mgos_sys_config_get(const struct mg_str key, struct mg_str *value) {
  return mgos_config_get(key, value, &mgos_sys_config, mgos_config_schema());
}
bool mgos_sys_config_set(const struct mg_str key, const struct mg_str value, bool free_strings) {
  return mgos_config_set(key, value, &mgos_sys_config, mgos_config_schema(), free_strings);
}

const struct mgos_conf_entry *mgos_config_schema(void) {
  return mgos_config_get_schema();
}

/* Strings */
static const char *mgos_config_str_table[] = {
  "%.*s/rpc",
  "*",
  "/",
  "192.168.4.1",
  "192.168.4.100",
  "192.168.4.2",
  "255.255.255.0",
  "80",
  "??????",
  "?????\?/request",
  "?????\?/request/update",
  "?????\?/response",
  "?????\?/response/update",
  "EDEN_3_??????",
  "RPC",
  "a6ffpc9686vd8-ats.iot.us-west-2.amazonaws.com:8883",
  "aws-??????.crt.pem",
  "aws-??????.key.pem",
  "ca.pem",
  "eden1234",
  "log_",
  "time.google.com",
  "wss://mdash.net/api/v2/rpc",
};

bool mgos_config_is_default_str(const char *s) {
  int num_str = (sizeof(mgos_config_str_table) / sizeof(mgos_config_str_table[0]));
  for (int i = 0; i < num_str; i++) {
    if (mgos_config_str_table[i] == s) return true;
  }
  return false;
}
