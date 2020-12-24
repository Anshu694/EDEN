#include <stdbool.h>
#include <string.h>

#include <mgos_gpio.h>
#include <mgos_pwm.h>
#include "common/cs_dbg.h"
#include "mgos_system.h"

#include "mgos_rgb.h"

bool mgos_rgb_init (void){
	return true;
}


static bool mgos_rgb_led_apply(struct mgos_rgb_led *led) {
  /* Check LED brightness 
  if (led->br == 0)
  {
    //LOG(LL_DEBUG, ("PWM: OFF"));
    return mgos_rgb_led_deinit(led);
  }
  */

  float rv = led->r * (1.0f / 255);
  float gv = led->g * (1.0f / 255);
  float bv = led->b * (1.0f / 255);
  
  #if defined (MGOS_RGB_LED_COMMON_ANODE)
  rv = (1.0f - rv);
  gv = (1.0f - gv);
  bv = (1.0f - bv);
  #endif
  mgos_pwm_set(led->gpio_r, led->freq, rv);
  mgos_pwm_set(led->gpio_g, led->freq, gv);
  mgos_pwm_set(led->gpio_b, led->freq, bv);
  return true;
  /*
  return (mgos_pwm_set(led->gpio_r, led->freq, rv) &&
          mgos_pwm_set(led->gpio_g, led->freq, gv) &&
          mgos_pwm_set(led->gpio_b, led->freq, bv));
          */
}

bool mgos_rgb_led_init(struct mgos_rgb_led *led, int gpio_r, int gpio_g, int gpio_b) {
  memset(led, 0, sizeof(*led));
  led->gpio_r = gpio_r;
  led->gpio_g = gpio_g;
  led->gpio_b = gpio_b;
  led->freq = MGOS_RGB_LED_DEFAULT_FREQ;
  return mgos_rgb_led_apply(led);
}

bool mgos_rgb_led_set(struct mgos_rgb_led *led, int r, int g, int b) {
  led->r = r;
  led->g = g;
  led->b = b;
  return mgos_rgb_led_apply(led);
}

bool mgos_rgb_led_set_hex(struct mgos_rgb_led *led, uint32_t rgb) {
  return mgos_rgb_led_set(led, (rgb >> 16) & 0xff, (rgb >> 8) & 0xff, (rgb & 0xff));
}

bool mgos_rgb_led_fade_hex(struct mgos_rgb_led *led, uint32_t rgb, int mSecFade){
  return mgos_rgb_led_fade(led, (rgb >> 16) & 0xff, (rgb >> 8) & 0xff, (rgb & 0xff), mSecFade);
}

bool mgos_rgb_led_set_freq(struct mgos_rgb_led *led, int freq) {
  led->freq = freq;
  return mgos_rgb_led_apply(led);
}

bool mgos_rgb_led_deinit(struct mgos_rgb_led *led) {
  bool status =(mgos_pwm_set(led->gpio_r, 0, 0) &&
                mgos_pwm_set(led->gpio_g, 0, 0) &&
                mgos_pwm_set(led->gpio_b, 0, 0));
  #ifdef MGOS_RGB_LED_COMMON_ANODE
  mgos_gpio_write(led->gpio_r, 1);
  mgos_gpio_write(led->gpio_g, 1);
  mgos_gpio_write(led->gpio_b, 1);
  #endif
  return status;
}


int fadeRes = 500;
int fadeStep = 10;
int fadeCount = 50;

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue; // What's the overall gap?
  if (step) {                      // If its non-zero, 
    step = fadeRes/step;              //   divide by fadeRes >255
  } 
  return step;
}


int calculateVal(int step, int val, int i) {

  if ((step) && i % step == 0) {
    if (step > 0) {              //   increment the value if step is positive
      val += fadeStep;           
    } 
    else if (step < 0) {         //   or decrement it if step is negative
      val -= fadeStep;
    } 
  }
  // Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  } 
  else if (val < 0) {
    val = 0;
  }
  return val;
}

/* Fade */
bool mgos_rgb_led_fade(struct mgos_rgb_led *led, int redVal, int grnVal, int bluVal, int mSecFade){
  mgos_wdt_feed();

  /* fade time should be in range of 1 sec to 6 sec */  
  if ( (mSecFade < 6001) && (mSecFade > 999) )
  {
    int stepR = calculateStep(led->prev_r, redVal);
    int stepG = calculateStep(led->prev_g, grnVal); 
    int stepB = calculateStep(led->prev_b, bluVal);
    int delay = 20;
    fadeRes = 300;
    fadeCount = mSecFade/delay;
    fadeStep  = fadeRes/fadeCount;
    if (fadeStep < 1) {
      fadeStep = 1;
    }

    LOG(LL_DEBUG, ("RGB: fadeRes = %d, fadeCount = %d, fadeStep = %d,", fadeRes, fadeCount, fadeStep));
    LOG(LL_DEBUG, ("RGB: stepR = %d, stepG = %d, stepB = %d,", stepR, stepG, stepB));

    for (int i = 0; i <= fadeCount; i++) {
      led->r = calculateVal(stepR, led->r, i);
      led->g = calculateVal(stepG, led->g, i);
      led->b = calculateVal(stepB, led->b, i);
      mgos_wdt_feed();
      mgos_msleep(delay);             // Pause for 'wait' in milliseconds
      mgos_rgb_led_apply(led);        // Write current values to LED pins
    }
  } 

  led->r = redVal;
  led->g = grnVal;
  led->b = bluVal;
  led->fade = mSecFade;
 
  // Update current values for next time
  led->prev_r = led->r;
  led->prev_g = led->g;
  led->prev_b = led->b;

  LOG(LL_DEBUG, ("RGB: SET"));
  return mgos_rgb_led_apply(led);
}
