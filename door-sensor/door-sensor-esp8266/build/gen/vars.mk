APP=EDEN_DS
APP_BIN_LIBS=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/libmbedtls-esp8266-2.18.0.a /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/libmongoose-esp8266-2.18.0.a /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/libota-common-esp8266-2.18.0.a /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/libota-http-client-esp8266-2.18.0.a /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/libota-http-server-esp8266-2.18.0.a /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs/librpc-service-ota-esp8266-2.18.0.a
APP_CFLAGS=-DATCA_HAL_I2C=1 -DLFS_NO_DEBUG=1 -DMBEDTLS_AES_ATCA=1 -DMBEDTLS_ECP_ATCA=1 -DMBEDTLS_FREE_CERT_CHAIN=1 -DMBEDTLS_USER_CONFIG_FILE=\"mbedtls_platform_config.h\" -DMBEDTLS_X509_CA_CHAIN_ON_DISK=1 -DMGOS=1 -DMGOS_ENABLE_FILE_UPLOAD=1 -DMGOS_ENABLE_RPC_CHANNEL_HTTP=1 -DMGOS_ENABLE_SYS_SERVICE=1 -DMGOS_ENABLE_WEB_CONFIG=0 -DMGOS_ESP8266_WIFI_ENABLE_WPAENT=0 -DMGOS_HAVE_ATCA=1 -DMGOS_HAVE_AWS=1 -DMGOS_HAVE_CA_BUNDLE=1 -DMGOS_HAVE_CORE=1 -DMGOS_HAVE_HTTP_SERVER=1 -DMGOS_HAVE_I2C=1 -DMGOS_HAVE_MBEDTLS=1 -DMGOS_HAVE_MONGOOSE=1 -DMGOS_HAVE_MQTT=1 -DMGOS_HAVE_OTA_COMMON=1 -DMGOS_HAVE_OTA_HTTP_CLIENT=1 -DMGOS_HAVE_OTA_HTTP_SERVER=1 -DMGOS_HAVE_RPC_COMMON=1 -DMGOS_HAVE_RPC_LOOPBACK=1 -DMGOS_HAVE_RPC_MQTT=1 -DMGOS_HAVE_RPC_SERVICE_CONFIG=1 -DMGOS_HAVE_RPC_SERVICE_FS=1 -DMGOS_HAVE_RPC_SERVICE_GPIO=1 -DMGOS_HAVE_RPC_SERVICE_I2C=1 -DMGOS_HAVE_RPC_SERVICE_OTA=1 -DMGOS_HAVE_RPC_UART=1 -DMGOS_HAVE_RPC_WS=1 -DMGOS_HAVE_SHADOW=1 -DMGOS_HAVE_SPI=1 -DMGOS_HAVE_VFS_COMMON=1 -DMGOS_HAVE_VFS_DEV_PART=1 -DMGOS_HAVE_VFS_DEV_SPI_FLASH=1 -DMGOS_HAVE_VFS_FS_LFS=1 -DMGOS_HAVE_VFS_FS_SPIFFS=1 -DMGOS_HAVE_WIFI=1 -DMGOS_LFS1_COMPAT=0 -DMGOS_ROOT_FS_OPTS_LFS={"bs":4096,"is":128} -DMGOS_ROOT_FS_OPTS_SPIFFS={"bs":4096,"ps":256,"es":4096} -DMGOS_WIFI_ENABLE_AP_STA=1 -DMG_ENABLE_DNS=1 -DMG_ENABLE_DNS_SERVER=1 -DMG_ENABLE_MQTT=1 -DMG_ENABLE_SNTP=1 -DMG_ENABLE_SSL=1 -DMG_SSL_IF=MG_SSL_IF_MBEDTLS -DMG_SSL_IF_MBEDTLS_FREE_CERTS=1
APP_CONF_SCHEMA=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/gen/mos_conf_schema.yml
APP_CXXFLAGS=-DATCA_HAL_I2C=1 -DLFS_NO_DEBUG=1 -DMBEDTLS_AES_ATCA=1 -DMBEDTLS_ECP_ATCA=1 -DMBEDTLS_FREE_CERT_CHAIN=1 -DMBEDTLS_USER_CONFIG_FILE=\"mbedtls_platform_config.h\" -DMBEDTLS_X509_CA_CHAIN_ON_DISK=1 -DMGOS=1 -DMGOS_ENABLE_FILE_UPLOAD=1 -DMGOS_ENABLE_RPC_CHANNEL_HTTP=1 -DMGOS_ENABLE_SYS_SERVICE=1 -DMGOS_ENABLE_WEB_CONFIG=0 -DMGOS_ESP8266_WIFI_ENABLE_WPAENT=0 -DMGOS_HAVE_ATCA=1 -DMGOS_HAVE_AWS=1 -DMGOS_HAVE_CA_BUNDLE=1 -DMGOS_HAVE_CORE=1 -DMGOS_HAVE_HTTP_SERVER=1 -DMGOS_HAVE_I2C=1 -DMGOS_HAVE_MBEDTLS=1 -DMGOS_HAVE_MONGOOSE=1 -DMGOS_HAVE_MQTT=1 -DMGOS_HAVE_OTA_COMMON=1 -DMGOS_HAVE_OTA_HTTP_CLIENT=1 -DMGOS_HAVE_OTA_HTTP_SERVER=1 -DMGOS_HAVE_RPC_COMMON=1 -DMGOS_HAVE_RPC_LOOPBACK=1 -DMGOS_HAVE_RPC_MQTT=1 -DMGOS_HAVE_RPC_SERVICE_CONFIG=1 -DMGOS_HAVE_RPC_SERVICE_FS=1 -DMGOS_HAVE_RPC_SERVICE_GPIO=1 -DMGOS_HAVE_RPC_SERVICE_I2C=1 -DMGOS_HAVE_RPC_SERVICE_OTA=1 -DMGOS_HAVE_RPC_UART=1 -DMGOS_HAVE_RPC_WS=1 -DMGOS_HAVE_SHADOW=1 -DMGOS_HAVE_SPI=1 -DMGOS_HAVE_VFS_COMMON=1 -DMGOS_HAVE_VFS_DEV_PART=1 -DMGOS_HAVE_VFS_DEV_SPI_FLASH=1 -DMGOS_HAVE_VFS_FS_LFS=1 -DMGOS_HAVE_VFS_FS_SPIFFS=1 -DMGOS_HAVE_WIFI=1 -DMGOS_LFS1_COMPAT=0 -DMGOS_ROOT_FS_OPTS_LFS={"bs":4096,"is":128} -DMGOS_ROOT_FS_OPTS_SPIFFS={"bs":4096,"ps":256,"es":4096} -DMGOS_WIFI_ENABLE_AP_STA=1 -DMG_ENABLE_DNS=1 -DMG_ENABLE_DNS_SERVER=1 -DMG_ENABLE_MQTT=1 -DMG_ENABLE_SNTP=1 -DMG_ENABLE_SSL=1 -DMG_SSL_IF=MG_SSL_IF_MBEDTLS -DMG_SSL_IF_MBEDTLS_FREE_CERTS=1
APP_FS_FILES=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/ca-bundle/fs/ca.pem /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/fs/index.html
APP_INCLUDES=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/i2c/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/crypto /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/hal /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mbedtls/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mbedtls/include/esp8266 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mbedtls/mbedtls/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/include/esp8266 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mongoose/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-dev-part/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs1 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/include/spiffs /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/include/esp8266 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/core/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/core/include/esp8266 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mqtt/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/shadow/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/aws/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/http-server/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/ota-common/src /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/ota-common/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/ota-common/include/esp8266 /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/ota-http-client/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-common/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-loopback/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-mqtt/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-config/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-fs/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-gpio/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-i2c/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-ota/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-uart/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-ws/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/spi/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-dev-spi-flash/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/wifi/include /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/wifi/include/esp8266
APP_SOURCES=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/src/main.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/gen/mgos_deps_init.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/i2c/src/mgos_i2c_master.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/i2c/src/gpio/mgos_i2c_gpio_master.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/src/mgos_atca.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/src/mgos_atca_hal.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/atca_cfgs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/atca_command.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/atca_device.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/atca_execution.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/atca_iface.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_aes.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_aes_cbc.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_aes_cmac.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_aes_ctr.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_aes_gcm.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_checkmac.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_counter.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_derivekey.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_ecdh.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_gendig.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_genkey.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_hmac.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_info.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_kdf.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_lock.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_mac.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_nonce.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_privwrite.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_random.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_read.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_secureboot.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_selftest.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_sha.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_sign.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_updateextra.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_verify.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_basic_write.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/basic/atca_helpers.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/host/atca_host.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/atca/cryptoauthlib/lib/mbedtls/atca_mbedtls_wrap.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/src/mgos_vfs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/src/mgos_vfs_dev.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/src/mgos_vfs_internal.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/src/esp8266/esp_fs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-common/src/esp8266/esp_vfs_dev_sysflash.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-dev-part/src/mgos_vfs_dev_part.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/src/mgos_vfs_lfs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs/lfs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs/lfs_util.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs1/lfs1.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-lfs/littlefs1/lfs1_util.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/mgos_vfs_fs_spiffs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/spiffs/spiffs_cache.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/spiffs/spiffs_check.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/spiffs/spiffs_gc.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/spiffs/spiffs_hydrogen.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-fs-spiffs/src/spiffs/spiffs_nucleus.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/core/src/mgos_core.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/core/src/esp8266/esp_rboot.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mqtt/src/mgos_mqtt.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/mqtt/src/mgos_mqtt_conn.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/shadow/src/mgos_shadow.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/aws/src/mgos_aws.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/aws/src/mgos_aws_greengrass.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/aws/src/mgos_aws_shadow.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/http-server/src/mgos_http_server.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-common/src/mg_rpc.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-common/src/mg_rpc_channel.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-common/src/mg_rpc_channel_http.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-common/src/mgos_rpc.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-loopback/src/mg_rpc_channel_loopback.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-mqtt/src/mgos_rpc_channel_mqtt.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-config/src/mgos_service_config.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-fs/src/mgos_service_fs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-gpio/src/mgos_gpio_service.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-service-i2c/src/mgos_i2c_service.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-uart/src/mgos_rpc_channel_uart.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-ws/src/mgos_rpc_channel_ws.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/rpc-ws/src/mgos_rpc_ws.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/spi/src/mgos_spi.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/spi/src/mgos_spi_mjs.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/spi/src/common_gpio/mgos_spi_gpio.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/vfs-dev-spi-flash/src/mgos_vfs_dev_spi_flash.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/wifi/src/mgos_wifi.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/wifi/src/mjs_wifi.c /data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/deps/wifi/src/esp8266/esp_wifi.c
APP_VERSION=1.0.1
BOARD=
BUILD_DIR=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/objs
FFI_SYMBOLS=
FS_STAGING_DIR=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/fs
FW_DIR=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/fw
GEN_DIR=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/gen
MANIFEST_FINAL=/data/fwbuild-volumes/2.18.0/apps/EDEN_DS/esp8266/build_contexts/build_ctx_574370650/build/gen/mos_final.yml
MGOS=1
MGOS_ENABLE_SPI_GPIO=1
MGOS_HAVE_ATCA=1
MGOS_HAVE_AWS=1
MGOS_HAVE_CA_BUNDLE=1
MGOS_HAVE_CORE=1
MGOS_HAVE_HTTP_SERVER=1
MGOS_HAVE_I2C=1
MGOS_HAVE_MBEDTLS=1
MGOS_HAVE_MONGOOSE=1
MGOS_HAVE_MQTT=1
MGOS_HAVE_OTA_COMMON=1
MGOS_HAVE_OTA_HTTP_CLIENT=1
MGOS_HAVE_OTA_HTTP_SERVER=1
MGOS_HAVE_RPC_COMMON=1
MGOS_HAVE_RPC_LOOPBACK=1
MGOS_HAVE_RPC_MQTT=1
MGOS_HAVE_RPC_SERVICE_CONFIG=1
MGOS_HAVE_RPC_SERVICE_FS=1
MGOS_HAVE_RPC_SERVICE_GPIO=1
MGOS_HAVE_RPC_SERVICE_I2C=1
MGOS_HAVE_RPC_SERVICE_OTA=1
MGOS_HAVE_RPC_UART=1
MGOS_HAVE_RPC_WS=1
MGOS_HAVE_SHADOW=1
MGOS_HAVE_SPI=1
MGOS_HAVE_VFS_COMMON=1
MGOS_HAVE_VFS_DEV_PART=1
MGOS_HAVE_VFS_DEV_SPI_FLASH=1
MGOS_HAVE_VFS_FS_LFS=1
MGOS_HAVE_VFS_FS_SPIFFS=1
MGOS_HAVE_WIFI=1
MGOS_MBEDTLS_ENABLE_ATCA=1
MGOS_PATH=/mongoose-os
MGOS_ROOT_FS_OPTS_LFS={"bs":4096,"is":128}
MGOS_ROOT_FS_OPTS_SPIFFS={"bs":4096,"ps":256,"es":4096}
MGOS_WIFI_ENABLE_AP_STA=0
PLATFORM=esp8266