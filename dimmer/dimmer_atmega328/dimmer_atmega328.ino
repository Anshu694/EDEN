/*
   Zero Cross Pin 2
   Dimmer Pin 6
   Other pins can be used as output pin
*/

#include <RBDdimmer.h>
#include <ArduinoJson.h>

/**************************************************************************/
#define MAX_BUFF 100        // Max UART Buff

#define ZERO_CROSS_PIN 2    // Zero Cross Pin
#define OUTPUT_PIN_1 3      // Output Pin 1
#define OUTPUT_PIN_2 4      // Output Pin 2
#define OUTPUT_PIN_3 5      // Output Pin 3
#define OUTPUT_PIN_4 6      // Dimmer Pin

dimmerLamp dimmer(OUTPUT_PIN_4);

volatile int i = 0;
volatile char buff[MAX_BUFF];
volatile bool isData = false;
/**************************************************************************/

/*
   Send UART response
*/
void sendResponse(int pin, int state, int dim) {
  Serial.print("{");
  Serial.print("\"pin\":");
  Serial.print(pin);
  Serial.print(",");
  Serial.print("\"state\":");
  Serial.print(state);
  Serial.print(",");
  Serial.print("\"dim\":");
  Serial.print(dim);
  Serial.println("}");
}

/*
   json parse and gpio control
*/
void processData(char *json) {
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.print("{");
    Serial.print("\"error\":");
    Serial.print("\"");
    Serial.print(error.f_str());
    Serial.print("\"");
    Serial.println("}");
    return;
  }
  int pin = doc["pin"];
  int state = doc["state"];
  int dim = doc["dim"];
  if (pin == 6) {
    if (state == 0)
    {
      dimmer.setPower(dim);
      dimmer.setState(OFF);
      //sendResponse(pin, state, dimmer.getPower());
    }
    else if (state == 1)
    {
      dimmer.setState(ON);
      dimmer.setPower(dim);
      //sendResponse(pin, state, dimmer.getPower());
    }
  }
  else {
    if (state == 0)
    {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
      //sendResponse(pin, state, 0);
    }
    else if (state == 1)
    {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH);
      //sendResponse(pin, state, 100);
    }
  }
}

/*
   Setup
*/
void setup() {
  Serial.begin(115200);
  dimmer.begin(NORMAL_MODE, OFF);

  pinMode(OUTPUT_PIN_1, OUTPUT);
  digitalWrite(OUTPUT_PIN_1, LOW);

  pinMode(OUTPUT_PIN_2, OUTPUT);
  digitalWrite(OUTPUT_PIN_2, LOW);

  pinMode(OUTPUT_PIN_3, OUTPUT);
  digitalWrite(OUTPUT_PIN_3, LOW);

  Serial.println("{}");
}

/*
   Loop
*/
void loop() {
  if (Serial.available() > 0) {
    char test = Serial.read();
    if (test == '{')
    {
      isData = true;
      i = 0;
      memset(buff, 0, MAX_BUFF);
    }
    else if (test == '}')
    {
      isData = false;
      buff[i] = test;
      processData(buff);
    }
    if (isData) {
      buff[i] = test;
      i++;
    }
  }
}
