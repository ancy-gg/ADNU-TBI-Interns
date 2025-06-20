const int motorIn1 = 9;    
const int motorIn2 = 10;   

void setup() {  
  pinMode(motorIn1, OUTPUT);  
  pinMode(motorIn2, OUTPUT);  
}  

void loop() {  
  clockwise(120);        // Adjust speed (0-255)  
  delay(1000);           // Adjust delay (in milliseconds)  
  counterclockwise(120); // Adjust speed (0-255)  
  delay(1000);           // Adjust delay (in milliseconds)  
}  

void clockwise(int Speed) {  
  analogWrite(motorIn1, Speed);  
  analogWrite(motorIn2, 0);  
}  

void counterclockwise(int Speed) {  
  analogWrite(motorIn1, 0);  
  analogWrite(motorIn2, Speed);  
} 
