const int clockPin = 2;    
const int latchPin = 3;   
const int dataPin = 4;   

// 7-segment patterns for digits 0-9 (common cathode)  
// Bits: DP-G-F-E-D-C-B-A 
const byte digitPatterns[10] = {  
  0x3F, // 0  
  0x06, // 1  
  0x5B, // 2  
  0x4F, // 3  
  0x66, // 4  
  0x6D, // 5  
  0x7D, // 6  
  0x07, // 7  
  0x7F, // 8  
  0x6F  // 9  
};  

void setup() {  
  pinMode(clockPin, OUTPUT);  
  pinMode(latchPin, OUTPUT);  
  pinMode(dataPin, OUTPUT);  
}  

void loop() {  
  for (int digit = 0; digit < 10; digit++) {  
    digitalWrite(latchPin, LOW);  
    shiftOut(dataPin, clockPin, MSBFIRST, digitPatterns[digit]);  
    digitalWrite(latchPin, HIGH);  
    delay(500);  // Adjust display time (milliseconds)  
  }  
} 
