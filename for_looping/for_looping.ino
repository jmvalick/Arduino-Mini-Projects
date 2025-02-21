int led1 = 5;
int led2 = 4;
int time1 = 500;
int time2 = 500;
int blinkCout1 = 3;
int blinkCount2 = 5;

void setup() {
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop() {
  
  for(int i = 0; i < blinkCout1; i++){
    digitalWrite(led1,HIGH);
    delay(time1);
    digitalWrite(led1, LOW);
    delay(time1);
  }
  
  for(int i = 0; i < blinkCount2; i++){
    digitalWrite(led2,HIGH);
    delay(time2);digitalWrite(led2, LOW);
    delay(time2);
  }

}
