#include <LiquidCrystal.h>  
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

// Change these values as needed:
const char line1[] = " Welcome to Naga City IoT Lab!     ";  
const char line2[] = "Ateneo de Naga University ";  
const int scrollDelay = 200;  

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  scrollMessage(line1, 0);
  scrollMessage(line2, 1);
}

void scrollMessage(const char* message, int row) {
  int messageLength = strlen(message);
 
  for (int i = 0; i < messageLength + 16; i++) {
    lcd.setCursor(0, row);
   
    for (int j = 0; j < 16; j++) {
      int charIndex = i - 16 + j;
     
      if (charIndex >= 0 && charIndex < messageLength) {
        lcd.print(message[charIndex]);
      } else {
        lcd.print(' ');
      }
    }
   
    delay(scrollDelay);
  }
}
