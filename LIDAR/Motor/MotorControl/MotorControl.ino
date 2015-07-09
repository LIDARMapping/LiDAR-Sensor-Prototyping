#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  int choice = 1;
  
  if(choice == 0){
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(100);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(100);                       // waits 15ms for the servo to reach the position 
    }   
  }
  
  else if(choice == 1){
    for(pos = 0; pos < 1800; pos += 2)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.writeMicroseconds(map(pos,0,1800,525,2260));              // tell servo to go to position in variable 'pos' 
      delay(100);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 1800; pos>=0; pos-=2)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.writeMicroseconds(map(pos,0,1800,525,2260));              // tell servo to go to position in variable 'pos' 
      delay(100);                       // waits 15ms for the servo to reach the position 
    } 
  }
}
