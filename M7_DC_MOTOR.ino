//Clockwise & Counter-clockwise
const int motorIn1 = 9;   // Motor control pin 1 (PWM capable)
const int motorIn2 = 10;  // Motor control pin 2 (PWM capable)


void setup() {
  pinMode(motorIn1, OUTPUT);  // Set motorIn1 as output (controls voltage/speed)
  pinMode(motorIn2, OUTPUT);  // Set motorIn2 as output (controls voltage/speed)
}


void loop() {
  clockwise(200);        // Rotate motor clockwise at PWM=120
  delay(1000);           // Maintain rotation for 1 second
  counterclockwise(200); // Rotate motor counter-clockwise at PWM=120
  delay(1000);           // Maintain rotation for 1 second
}


// Rotates motor clockwise by energizing motorIn1
void clockwise(int Speed) {
  analogWrite(motorIn1, Speed);  // Apply PWM voltage to motorIn1 (0-255)
  analogWrite(motorIn2, 0);      // Set motorIn2 to 0V (GND reference)
}


// Rotates motor counter-clockwise by energizing motorIn2
void counterclockwise(int Speed) {
  analogWrite(motorIn1, 0);      // Set motorIn1 to 0V (GND reference)
  analogWrite(motorIn2, Speed);  // Apply PWM voltage to motorIn2 (0-255)
}
