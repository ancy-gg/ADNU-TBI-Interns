#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address 0x27, 16 columns x 2 rows

const int potPin = A0;  // Potentiometer wiper to A0

void setup() {
  lcd.init();            // Initialize the LCD
  lcd.backlight();       // Turn on the backlight
}

void loop() {
  int analogValue = analogRead(potPin);              // Read analog input (0-1023)
  float voltage = analogValue * (5.0 / 1023.0);      // Convert to voltage (0-5V)

  lcd.setCursor(0, 0);
  lcd.print("Analog: ");
  lcd.print(analogValue);
  lcd.print("   ");  // Clear leftover chars

  lcd.setCursor(0, 1);
  lcd.print("Volt: ");
  lcd.print(voltage, 2);
  lcd.print(" V  "); // Clear leftover chars

  delay(50);
}
