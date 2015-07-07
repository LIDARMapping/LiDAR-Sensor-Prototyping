/* Distance Calculation
 * This script will find the peaks of the zero and return signal
 * and compare the difference in time with the period of the
 * sync signal in order to calculate a distance.
 */
 
 int sync = 8;
 int zero = A3;
 int ret = A1;
 
 int previousSync = 0;
 
 void setup()
 {
   Serial.begin(9600);
   
   // Initialize pin
   pinMode(sync, INPUT);
   while(!syncHighToDown());  // Waits for sync to go high to low
   Serial.println("Starting");
 }
 
 void loop()
 {
   int previous = 0;
   int startMeasurement = millis();
   int maxRet = 0, maxZero = 0;
   int maxRetTime, maxZeroTime;
   
   while(!syncHighToDown()) // Loops for the duration
   {
     if(analogRead(zero) > maxZero)
     {
       maxZero = analogRead(zero);
       maxZeroTime = millis();
     }
     
     if(analogRead(ret) > maxRet)
     {
       maxRet = analogRead(ret);
       maxRetTime = millis();
     }
   }
   
   int endMeasurement = millis();
   
   float distance = 9.16 * (maxRetTime - maxZeroTime)/(endMeasurement - startMeasurement);
   Serial.println(distance);
 }
 
 
int getSync()
{
  return previousSync = digitalRead(sync);
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
