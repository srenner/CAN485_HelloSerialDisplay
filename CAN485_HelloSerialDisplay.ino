#include <Arduino.h>
#include "Can485DisplayHelper.h"

#define BLOCK 255

void setup() {
  DisplayInit();
}

void loop() {
  clearDisplay();
  delay(200);
  
  setCursorPosition(1,1);
  writeToDisplay("Hello World!");
  delay(500);
  clearDisplay();
  delay(200);

  setCursorPosition(2,1);
  if(false) {
    for(int i = 0; i < 6; i++) {
      writeToDisplay(i);
      delay(50);
    }
  }
  if(true) {
    writeToDisplay(BLOCK);
    writeToDisplay(BLOCK);

  }


  delay(2000);
}

void printMockGauges() {
  setCursorPosition(1,1);
  writeToDisplay("AFR 13.5");
  writeToDisplay(BLOCK);
  writeToDisplay(BLOCK);
  writeToDisplay(BLOCK);

  setCursorPosition(2,1);
  writeToDisplay("TGT 14.7");
  writeToDisplay(BLOCK);
  writeToDisplay(BLOCK);
  writeToDisplay(BLOCK);
  writeToDisplay(BLOCK);
}
