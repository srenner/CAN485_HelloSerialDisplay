#include <Arduino.h>
#include "Can485DisplayHelper.h"

#define BLOCK 255

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Started");
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

  writecharLCD();
  delay(2000);
  //printMockGauges();

  //setCursorPosition(2,1);
  // for(int i = 0; i < 6; i++) {
  //   writeToDisplay(i);
  //   //writeToDisplay(255);
  //   delay(50);
  // }

  //delay(5000);
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
