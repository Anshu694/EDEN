#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct mgos_rgb_led {
  int freq;
  int r, g, b; /* Current values or R, G, B and brightness. */
  int fade;
  int gpio_r, gpio_g, gpio_b;
  int prev_r, prev_g, prev_b;
};

/* Comment this line for Common cathode RGB*/
//#define MGOS_RGB_LED_COMMON_ANODE

#define MGOS_RGB_LED_DEFAULT_FREQ 400 /* Hz */

/* Init the LED pins. */
bool mgos_rgb_led_init(struct mgos_rgb_led *led, int gpio_r, int gpio_g, int gpio_b);

/* Set color and brightenss, 1-255. */
bool mgos_rgb_led_set(struct mgos_rgb_led *led, int r, int g, int b);

bool mgos_rgb_led_set_hex(struct mgos_rgb_led *led, uint32_t rgb);

bool mgos_rgb_led_fade_hex(struct mgos_rgb_led *led, uint32_t rgb, int mSecFade);

/* Set PWM frequency. */
bool mgos_rgb_led_set_freq(struct mgos_rgb_led *led, int freq);

/* Disable PWM and release the pins. */
bool mgos_rgb_led_deinit(struct mgos_rgb_led *led);

/* Fade */
bool mgos_rgb_led_fade(struct mgos_rgb_led *led, int redVal, int grnVal, int bluVal, int mSecFade);

#ifdef __cplusplus
}
#endif /* __cplusplus */
