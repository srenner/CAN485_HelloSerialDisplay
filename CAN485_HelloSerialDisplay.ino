#include <AltSoftSerial.h>

AltSoftSerial lcd;

void setup() {
  lcd.begin(9600);
  delay(500); //wait for bootup

  clearSerialLCD();
}

void loop() {
  lcd.write("Hello World ");
  delay(100);
  clearSerialLCD();
}

//not working reliably
void setAsSplash() {
  lcd.write(0x7C);
  lcd.write(0x09);
  delay(500); 
}

void clearSerialLCD() {
  // move cursor to beginning of first line
  lcd.write(254); 
  lcd.write(128);

  // clear display by sending spaces
  lcd.write("                "); 
  lcd.write("                ");

  // move cursor to beginning of first line
  lcd.write(254); 
  lcd.write(128);  
}
