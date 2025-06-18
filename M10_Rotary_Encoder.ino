// Pin definitions
const int ledPins[] = {2, 4, 6, 8, 10, 12};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

const int clkPin = A1;  // Rotary encoder CLK
const int dtPin  = A2;  // Rotary encoder DT
const int swPin  = A0;  // Rotary encoder switch

int currentLed = 0;
int lastClkState;
bool buttonPressed = false;

void setup() {
  // LED pins as output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);  // Use internal pull-up resistor

  lastClkState = digitalRead(clkPin);
}

void loop() {
  int clkState = digitalRead(clkPin);
  int dtState = digitalRead(dtPin);

  // Detect rotation
  if (clkState != lastClkState) {
    if (dtState != clkState) {
      // Clockwise
      currentLed++;
    } else {
      // Counter-clockwise
      currentLed--;
    }

    // Wrap around
    if (currentLed >= numLeds) currentLed = 0;
    if (currentLed < 0) currentLed = numLeds - 1;

    updateLeds();
  }

  lastClkState = clkState;

  // Button press: invert all LEDs
  if (digitalRead(swPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    invertLeds();
  }

  // Reset button press flag when button released
  if (digitalRead(swPin) == HIGH) {
    buttonPressed = false;
  }
}

// Turn on only the selected LED
void updateLeds() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], (i == currentLed) ? HIGH : LOW);
  }
}

// Invert the current state of all LEDs
void invertLeds() {
  for (int i = 0; i < numLeds; i++) {
    int currentState = digitalRead(ledPins[i]);
    digitalWrite(ledPins[i], !currentState);
  }
}
