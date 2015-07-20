// Code which utilizes LiDAR measurement
int zeroPin = A3; //analog, zero signal
int returnPin = A1; //analog, return signal
int syncPin = 8; //digital, sync signal
int previousSync = 0; //previously measured sync signal
int previousMeasurement = 0; //previously measured
int timebasePin = 10;
int timebase = 100;

struct measurement
{
  int meters;
  int syncPeriod;
};

int setupLIDAR()
{
  pinMode(syncPin, INPUT);
  pinMode(timebasePin, OUTPUT);
  return 0;
}

//double takeMeasurement(long milliseconds)
double takeMeasurement(int n)
 {   
   analogWrite(timebasePin, timebase);
   while(!syncHighToDown());  // Waits for sync to go high to low
   
   long start = millis();
   long startMeasurement = millis();   
   double totalDistance = 0.0;
   
   int i;
   for(i = 0; i < n; i++)
   {
     int previous = 0;
     int maxRet = 0, maxZero = 0;
     long maxRetTime = 0, maxZeroTime = 0;
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
   
     long endMeasurement = millis();
     
     if(maxRet < 0.25/5.0*1022)
     {
       return -1.0;
     }
     
     totalDistance += 9.11*((double)(maxRetTime - maxZeroTime))/(endMeasurement - startMeasurement);//- 1.493;

     startMeasurement = endMeasurement;
   }
   
   return totalDistance/(i);
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

int getTimeBase()
{
  return timebase;
}

void setTimeBase(int out)
{
  timebase = out;
}


