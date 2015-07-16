/* Distance Calculation
 * This script will find the peaks of the zero and return signal
 * and compare the difference in time with the period of the
 * sync signal in order to calculate a distance.
 */
  
 void setup()
 {
   Serial.begin(9600);
   setupLIDAR();
   setTimeBase(0);
 }
 
 void loop()
 {
     if(getTimeBase() > 150)
     {
       return;
     }
     else
     {
       Serial.print(getTimeBase());
       Serial.print(' ');
     }
     setTimeBase(getTimeBase() + 1);
     double measurement = takeMeasurement(100);
     if(measurement < 0.0)
     {
       Serial.println("NaN");
     }
     else
     {
       Serial.println(measurement);
     }
 }
 

