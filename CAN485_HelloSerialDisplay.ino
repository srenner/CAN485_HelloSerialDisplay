#include <AltSoftSerial.h>

AltSoftSerial lcd;

void setup() {
  lcd.begin(9600);
  delay(500); //wait for bootup
  clearSerialLCD();
}

void loop() {
  clearSerialLCD();
  delay(200);
  
  setCursorPosition(1,1);
  lcd.write("Hello World");
  delay(200);

  clearSerialLCD();
  delay(200);

  setCursorPosition(2,1);
  lcd.write("Hello World");
  delay(200);
}

//not working reliably
void setAsSplash() {
  lcd.write(0x7C);
  lcd.write(0x09);
  delay(500); 
}

void setCursorPosition(int row, int column) {
  lcd.write(254);
  if(row == 1) {
    lcd.write(127 + column);
  }
  else if(row == 2) {
    lcd.write(191 + column);
  }
}

void clearSerialLCD() {
  setCursorPosition(1,1);
  lcd.write("                "); 
  lcd.write("                ");
  setCursorPosition(1,1);
}
