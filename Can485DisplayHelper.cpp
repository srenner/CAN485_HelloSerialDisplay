#include <AltSoftSerial.h>
#include "Can485DisplayHelper.h"

AltSoftSerial lcd;

void DisplayInit() {
    lcd.begin(9600);
    delay(500); //wait for bootup
    clearDisplay();

    //set brightness (128-157)
    //lcd.write(0x7C);
    //lcd.write(157);

    //create custom chars
    byte fill1[8] = {
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10
    };
    byte fill2[8] = {
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18
    };

    byte fill3[8] = {
        0x1C,
        0x1C,
        0x1C,
        0x1C,
        0x1C,
        0x1C,
        0x1C,
        0x1C
    };

    byte fill4[8] = {
        0x1E,
        0x1E,
        0x1E,
        0x1E,
        0x1E,
        0x1E,
        0x1E,
        0x1E
    };
    byte fill5[8] = {
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F
    };
    byte fillMiddle[8] = {
        0x04,
        0x04,
        0x04,
        0x04,
        0x04,
        0x04,
        0x04,
        0x04  
    };
    // createCustomChar(0, fill1);
    // createCustomChar(1, fill2);
    // createCustomChar(2, fill3);
    // createCustomChar(3, fill4);
    // createCustomChar(4, fill5);
    // createCustomChar(5, fillMiddle);
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
    lcd.write(0xFE);
    lcd.write(0x01);
}

//writes the current display as the splash screen (not reliable)
void setSplash() {
    lcd.write(0x7C);
    lcd.write(0x09);
    delay(500); 
}

void writeToDisplay(char *content) {
    lcd.write(content);
}

void writeToDisplay(uint8_t content) {
    lcd.write(content);
}

void createCustomChar(int pos, byte data[]) {
    lcd.write(0xFE);
    lcd.write(0x4E);
    lcd.write((uint8_t)pos);
    for(int i = 0; i < 8; i++) {
        lcd.write(data[i]);
    }
    delay(10); 
}

void printCustomChars() {
    clearDisplay();
    setCursorPosition(1,1);
}







void writecharLCD() {
 unsigned short charArray[][8] = {                         //Self defined bar characters
   0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,              
   0x1F,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,
   0x1F,0x18,0x18,0x18,0x18,0x18,0x18,0x1F,
   0x1F,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1F,
   0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1F,
   0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
   0x10,0x18,0x1C,0x1E,0x1E,0x1C,0x18,0x10,             // bar terminator charactor
   0x0A,0x15,0x1F,0x00,0x1F,0x0C,0x1F,0x00          };        //single character that says "MB" sideways

 for (int j = 0; j < 8; j++) {
     //Serial.print("in the j loop ");
     //Serial.println(millis());
   lcd.write(254);
   lcd.write(64+j*8);

   for (int i = 0; i < 8; i++) {
     lcd.write(charArray[j][i]);
   } //end inner char for
 }// end outter for  
 delay(100);  
}

void LCDbar10(short percent, int value, short line, short terminator) {
 short cols, blox, numchar;

 lcd.write(0xFE);
 lcd.write(128+line);

 if (percent > 100) {
   percent = 100;
 }

 cols = percent/2;                     // x 0.5 (100% = 50 pixels)
 blox = cols/5;                        // calculate whole blocks

 if (blox > 0) {
   for (short idx = 1; idx <= blox; idx++) {
     lcd.write(5);
   }
 }

 lcd.write(cols % 5);
 
 while (blox < 9) {                  // clear end of graph display
   //lcd.write(0);
   blox ++;
 }
 
 lcd.write(0xFE);
 lcd.write(128+10+line);
 lcd.write(terminator);
 
 if (value < 10)   {lcd.print(" ");} //Number formating
 if (value < 100)  {lcd.print(" ");}
 if (value < 1000) {lcd.print(" ");}
 
 lcd.print(value, DEC);
}
