#include<Servo.h>

Servo motor;
int motorPin = 9; //digital
int zeroPin = 3; //analog
int returnPin = 1; //analog
int syncPin = 8; //digital
int previousSync = 0;
int previousMeasurement = 0;
int spinDelay = 15; //delay between changing angles on the servo

void setup() {
  motor.attach(motorPin);
  Serial.begin(9600);
}

void loop() {
   for(int motorPos = 0; motorPos <= 180; motorPos++){ // goes from 0 degrees to 180 degrees in steps of 1 degree 
     motor.write(motorPos); //move servo to the angle 'motorPos'
     while(motor.read() != motorPos){ //waits for the motor to get into position
      ; 
     }
 
     delay(spinDelay);                                 // waits 15ms for the servo to reach the position

  } 
}
