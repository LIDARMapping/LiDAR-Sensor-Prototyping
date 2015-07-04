void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(millis() + ": ");
  Serial.println(digitalRead(8));
  delay(1);
}
