int readPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(readPin) == HIGH){
    while(digitalRead(readPin) == HIGH){
      ;
    }  
  }
  if(digitalRead(readPin) == LOW){
    //read from the LIDAR  
  }
}
