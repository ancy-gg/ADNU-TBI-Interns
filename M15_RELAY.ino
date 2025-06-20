// Control pin for the relay module
int relayControl = 7;


// Indicator LED pin showing device status
int statusLed = 12;


// Setup runs once when the device powers on
void setup() {
  // Configure relay pin as output
  pinMode(relayControl, OUTPUT);
 
  // Configure LED pin as output
  pinMode(statusLed, OUTPUT);  
 
  // Turn on status LED to show system is powered on
  digitalWrite(statusLed, HIGH);
}


// Main program loop runs repeatedly
void loop() {
  // Activate the relay (closes circuit)
  digitalWrite(relayControl, HIGH);
 
  // Keep relay active for 8 seconds (8000ms)
  delay(8000);
 
  // Deactivate the relay (opens circuit)
  digitalWrite(relayControl, LOW);
 
  // Keep relay inactive for 5 seconds (5000ms)
  delay(2000);
}
