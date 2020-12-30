/* ATtiny45 Low-Power Door Sensor
 * Suman Kr Das
 * 
 * PINs Used
 * PB0 -------- To power ESP8266 using PMOS
 * PB1 -------- BUTTON (Also used by ESP8266 for AP Mode and configuration)
 * PB2 -------- REED SWITCH (Also used by ESP8266 for sensing door status)
 * PB3 -------- Input from ESP8266 to cutoff power
 * PB4 -------- NA
 * PB5 -------- NA
 */
#include <avr/sleep.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Utility macro
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)

#define button PB1
#define reed PB2

#define INTERRUPT_PIN_B PCINT1
#define INTERRUPT_PIN_R PCINT2

#define PCINT_VECTOR PCINT0_vect      // This step is not necessary - it's a naming thing for clarit

volatile bool sleep = true;
volatile bool time_out = false;
volatile unsigned long int prev = 0;

/*
 * This is the interrupt handler called when there is any change on the INT_PIN
 * ISR is defined in the headers - the ATtiny85 only has one handler
 */
ISR(PCINT_VECTOR)
{
  sleep_disable();
  sleep = true;
}

/*
 * Enter Sleep
 */
void enterSleep (void)
{
  sleep_enable();
  sleep_cpu();
}

/*
 * Setup Function
 */
void setup () {
  cli();                              // Disable interrupts during setup
  PCMSK |= (1 << INTERRUPT_PIN_B);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT1)
  PCMSK |= (1 << INTERRUPT_PIN_R);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT2)
  GIMSK |= (1 << PCIE);               // Enable PCINT interrupt in the general interrupt mask
  
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  pinMode(button, INPUT_PULLUP);      // Set our interrupt pin as input with a pullup to keep it stable
  pinMode(reed, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);   
  pinMode(4, INPUT_PULLUP);
      
  adc_disable();                      // ADC uses ~320uA
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);// Set Sleep Mode
  sei();                              //last line of setup - enable interrupts after setup
  prev = millis();
}

/*
 * Main Loop
 */
void loop () {
  // Wake from sleep
  if(sleep){
    pinMode(0, OUTPUT);               // Set Pin to OUTPUT
    digitalWrite(0, LOW);             // Enable ESP8266
    sleep = false;
    prev = millis();
    delay(1);
  }
  
  // 3 Minute timeout max
  if((millis() - prev) > 180000){
    time_out = true;
  }

  // Go to sleep
  if((digitalRead(PB3) == LOW) || time_out == true){
    time_out = false;
    digitalWrite(0, HIGH);            // Disable ESP8266
    pinMode(0, INPUT_PULLUP);         // Set pin to i/p PULLUP
    enterSleep();                     // Go to sleep
  }
}
