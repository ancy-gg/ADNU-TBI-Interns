int relayControl = 7;  
int statusLed = 12;    

void setup() {
  pinMode(relayControl, OUTPUT);
  pinMode(statusLed, OUTPUT);  
  digitalWrite(statusLed, HIGH);  
}

void loop() {
  digitalWrite(relayControl, HIGH);  
  delay(8000);  // Adjust ON time (milliseconds)
  
  digitalWrite(relayControl, LOW);   
  delay(5000);  // Adjust OFF time (milliseconds)
}
