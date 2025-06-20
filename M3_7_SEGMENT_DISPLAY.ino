const int clockPin = 2;  // Shift register clock pin (SH_CP)
const int latchPin = 3;  // Shift register latch pin (ST_CP)
const int dataPin = 4;   // Shift register data pin (DS)


// 7-segment patterns for digits 0-9 (common cathode)
// Bits represent: DP-G-F-E-D-C-B-A
const byte digitPatterns[10] = {
  0x3F, // 0: ABCDEF
  0x06, // 1: BC
  0x5B, // 2: ABDEG
  0x4F, // 3: ABCDG
  0x66, // 4: BCDF
  0x6D, // 5: ACDFG
  0x7D, // 6: ACDEFG
  0x07, // 7: ABC
  0x7F, // 8: ABCDEFG
  0x6F  // 9: ABCDFG
};


void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}


void loop() {
  // Cycle through digits 0-9
  for (int digit = 0; digit < 10; digit++) {
    // Load data into shift register
    digitalWrite(latchPin, LOW);              // Begin data transfer
    shiftOut(dataPin, clockPin, MSBFIRST, digitPatterns[digit]);  // Send segment pattern
    digitalWrite(latchPin, HIGH);             // Update output
   
    delay(500);  // Display each digit for 0.5 seconds
  }
}
