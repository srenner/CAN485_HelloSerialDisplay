#include <AltSoftSerial.h>
#include "Can485DisplayHelper.h"

AltSoftSerial lcd;

void DisplayInit() {
    lcd.begin(9600);
    delay(500); //wait for bootup
    clearDisplay();
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

void clearDisplay() {
    setCursorPosition(1,1);
    lcd.write("                "); 
    lcd.write("                ");
    setCursorPosition(1,1);
}

//writes the current display as the splash screen
void setSplash() {
    lcd.write(0x7C);
    lcd.write(0x09);
    delay(500); 
}

void writeToDisplay(char *content) {
    lcd.write(content);
}
