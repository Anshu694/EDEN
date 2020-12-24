/* ATtiny85 Low-Power Timer */

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

volatile bool sleep = false;

void setup () {
  cli();                            // Disable interrupts during setup
  PCMSK |= (1 << INTERRUPT_PIN_B);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT3/PB13)
  PCMSK |= (1 << INTERRUPT_PIN_R);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT3/PB13)
  GIMSK |= (1 << PCIE);             // Enable PCINT interrupt in the general interrupt mask
  
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  pinMode(button, INPUT_PULLUP);
  pinMode(reed, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  pinMode(4, INPUT_PULLUP);
      
  adc_disable(); // ADC uses ~320uA
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sei();                            //last line of setup - enable interrupts after setup
}

// This is the interrupt handler called when there is any change on the INT_PIN
// ISR is defined in the headers - the ATtiny85 only has one handler

ISR(PCINT_VECTOR)
{
  sleep_disable();
  sleep = true;
}

void enterSleep (void)
{
  sleep_enable();
  sleep_cpu();
}

// Main loop ----------------------------------------------

void loop () {
  if(sleep){
    digitalWrite(0, LOW);
    sleep = false;
    delay(1);
  }
  
  if(digitalRead(PB3) == LOW){
    digitalWrite(0, HIGH);
    enterSleep();
  }
}
