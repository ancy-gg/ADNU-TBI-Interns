/*
 * LCD Scrolling Display Program
 * Displays two messages that scroll horizontally on a 16x2 LCD
 * Hardware: 74HC595 shift register connected to LCD
 */


#include <LiquidCrystal.h>  // Include LCD library for display control


// Initialize LCD with custom pin configuration
// RS=4, EN=6, D4=10, D5=11, D6=12, D7=13
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);


// Message definitions with trailing spaces for smooth scrolling
const char line1[] = " Welcome to Naga City IoT Lab!     ";  // Top row message (18 chars: 16 visible + 2 spaces)
const char line2[] = "Ateneo de Naga University ";  // Bottom row message (20 chars: 18 visible + 2 spaces)
const int scrollDelay = 200;  // Time between scroll steps in milliseconds (controls speed)


// Setup runs once at program start
void setup() {
  lcd.begin(16, 2);  // Initialize LCD display with 16 columns and 2 rows
}


// Main program loop runs continuously
void loop() {
  scrollMessage(line1, 0);  // Scroll first message on top row (row 0)
  scrollMessage(line2, 1);  // Scroll second message on bottom row (row 1)
}


/**
 * Custom function to scroll messages horizontally
 * @param message The text string to scroll
 * @param row The LCD row (0 or 1) to display on
 *
 * How it works:
 * 1. Calculates message length
 * 2. Loops through virtual positions of message relative to display
 * 3. For each position:
 *    - Sets cursor to start of row
 *    - Prints 16-character segment of message at current offset
 *    - Fills empty spaces with blanks when message starts/ends
 * 4. Delays between positions to control scroll speed
 */
void scrollMessage(const char* message, int row) {
  int messageLength = strlen(message);  // Calculate actual string length
 
  // Loop through all possible display positions (message + 16 blank spaces)
  for (int i = 0; i < messageLength + 16; i++) {
    lcd.setCursor(0, row);  // Reset cursor to start of specified row
   
    // Build current 16-character view
    for (int j = 0; j < 16; j++) {
      int charIndex = i - 16 + j;  // Calculate position in message string
     
      // Print character if within valid range, otherwise print space
      if (charIndex >= 0 && charIndex < messageLength) {
        lcd.print(message[charIndex]);  // Display visible character
      } else {
        lcd.print(' ');  // Display blank space when out of message bounds
      }
    }
   
    delay(scrollDelay);  // Control scroll speed (lower = faster)
  }
 
  // Note: Display isn't cleared here to prevent flicker between messages
}
