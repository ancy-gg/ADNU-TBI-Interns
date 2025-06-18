const int LED = 8;
const int PB = 2; 

void setup() {
pinMode(LED, OUTPUT);
pinMode(PB, INPUT);
}

void loop() {
if (digitalRead(PB) == HIGH){
  digitalWrite(LED, HIGH);
} else{
  digitalWrite(LED, LOW);
  }
}
