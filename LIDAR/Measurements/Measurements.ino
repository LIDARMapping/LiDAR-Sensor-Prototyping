#include<Servo.h>

Servo motor;
int motorPin = 9; //digital, motor connected here
int zeroPin = A3; //analog, zero signal
int returnPin = A1; //analog, return signal
int syncPin = 13; //digital, sync signal
int previousSync = 0; //previously measured sync signal
int previousMeasurement = 0; //previously measured
int spinDelay = 50; //delay between changing angles on the servo
int motorPos = 0; //angle at which the motor is at

void setup(){
  motor.attach(motorPin);
  Serial.begin(9600);
  pinMode(syncPin, INPUT);
  while(!syncHighToDown());  // Waits for sync to go high to low
  previousMeasurement = millis();
}

void loop(){
  spin(0);
  spin(1);
}

void spin(int dir){ //spins the motor. 0 - CCW, 1 - CW
  if(dir == 0){
    for(motorPos = 0; motorPos <= 1800; motorPos += 2){                                  
      motor.writeMicroseconds(map(motorPos,0,1800,525,2260)); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10          
      delay(spinDelay);
      //measure();      
    } 
  }
  else if(dir == 1){
    for(motorPos = 1800; motorPos >= 0; motorPos -= 2){                                    
      motor.writeMicroseconds(map(motorPos,0,1800,525,2260));              
      delay(spinDelay);
      //measure();      
    } 
  }  
}

void measure(){
   int previous = 0;
   int maxRet = 0, maxZero = 0;
   int maxRetTime, maxZeroTime;
   
   while(!syncHighToDown()) // Loops for the duration
   {
     if(analogRead(zeroPin) > maxZero)
     {
       maxZero = analogRead(zeroPin);
       maxZeroTime = millis();
     }
     
     if(analogRead(returnPin) > maxRet)
     {
       maxRet = analogRead(returnPin);
       maxRetTime = millis();
     }
   }
   
   int endMeasurement = millis();
   
   if(maxRet < 0.5/5.0*1025)
   {
     Serial.println("Out of Range");
   }
   else
   {
     float distance = 9.16 * (maxRetTime - maxZeroTime)/(endMeasurement - previousMeasurement);
     Serial.println(distance);
   }
   previousMeasurement = endMeasurement;  
}

int getSync()
{
  return previousSync = digitalRead(syncPin);
}

int getPreviousSync()
{
  return previousSync;
}

int syncHighToDown()
{
  int prev = getPreviousSync();
  int cur = getSync();
  return prev != 0 && cur == 0;
}
