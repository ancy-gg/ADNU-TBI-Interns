#include <Servo.h>

Servo Servo1;
//pin assignments
int servo = 9;
int potentio = A0;


void setup() {
  //initiate the servo motor object to pin 9 for control.
    Servo1.attach(servo);
}


void loop() {
    int reading = analogRead(potentio);
    //Converts the potentiometer value 0 to 1023 to an angle 0 to 180 degrees
    int angle = map(reading, 0, 1023, 0, 180);
    //Sets the servo motor to the calculated angle
    Servo1.write(angle);
}