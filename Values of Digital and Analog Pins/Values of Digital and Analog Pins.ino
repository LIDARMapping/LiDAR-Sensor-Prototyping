// Print the serial console the current value on a digital pin and two analog pins
// Print the current number of milliseconds since the start
// 0 is A3
// return is A1
// Sync is D8

unsigned long time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void loop() {
  //Prints the time in milliseconds since the start  
  time = millis();
  
  //Initialize values of sensorValue1, sensorValue2, and sensorValue3
  int sensorValue1 = analogRead(A3);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = digitalRead(8);
  
  //Convert analog pin values to voltage units
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);

  //Print values with spaces in between
  Serial.print(voltage1);
  Serial.print(" ");
  Serial.print(voltage2);
  Serial.print(" ");
  Serial.print(sensorValue3);
  Serial.print(" ");
  Serial.println(time);      
}
