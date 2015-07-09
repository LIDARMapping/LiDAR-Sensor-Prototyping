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
   Serial.println("Number of measurements (0-9): ");
 }
 
 void loop()
 {
   if(Serial.available() > 0)
   {
     int n = Serial.read() - '0';
     double measurement = takeMeasurement(n);
     if(measurement < 0.0)
     {
       Serial.print("Out of Range");
     }
     else
     {
       Serial.print(measurement);
     }
     Serial.println("");
     Serial.println("Number of measurements (0-9): ");
   }
 }
 
double takeMeasurement(int n)
 {   
   while(!syncHighToDown());  // Waits for sync to go high to low
   
   int startMeasurement = millis();   
   double totalDistance = 0.0;
   
   for(int i = 0; i < n; i++)
   {
     int previous = 0;
     int maxRet = 0, maxZero = 0;
     int maxRetTime = 0, maxZeroTime = 0;
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
     
     if(maxRet < 0.25/5.0*1022)
     {
       return -1.0;
     }
     
     totalDistance += 2.0*((double)(maxRetTime - maxZeroTime))/(endMeasurement - startMeasurement);

     startMeasurement = endMeasurement;
   }
   
   return 10000*totalDistance/n;
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
