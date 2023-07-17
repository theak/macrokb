#include <time.h>
#include "Keyboard.h"

int pins[] = {0, 1, 2, 3, 6, 7};
int previous_states[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int pin_count = sizeof(pins) / sizeof(pins[0]);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < pin_count; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
  srand(time(NULL));
  Keyboard.begin();
  //while (!Serial);
}

void loop() {
  for (int i = 0; i < pin_count; i++) {
    int state = digitalRead(pins[i]);
    if (state == LOW && previous_states[i] == HIGH) {
      Serial.print("PRESSED: ");
      Serial.println(pins[i]);
      switch(pins[i]) {
        case 7:
          break;
        case 6:
          break;
        case 3:
          break;
        case 2:
          break;
        case 0:
          break;
        case 1:
          break;
      }
      delay(50);
      Keyboard.releaseAll();
      delay(250);
    }
    previous_states[i] = state;
  }
}
