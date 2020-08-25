#include <Arduino.h>
#include "Can485DisplayHelper.h"

void setup() {
  DisplayInit();
}

void loop() {
  clearDisplay();
  delay(200);
  
  setCursorPosition(1,1);
  writeToDisplay("Hello World?");
  delay(200);

  clearDisplay();
  delay(200);

  setCursorPosition(2,1);
  writeToDisplay("Hello World!");
  delay(200);
}


