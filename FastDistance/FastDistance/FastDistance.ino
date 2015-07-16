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
 

