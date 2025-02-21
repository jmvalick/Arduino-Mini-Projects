int tGreen = 10000;
int tYellow = 2000;
int tRed = 10000;

void setup() {

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

}

void loop() {

  digitalWrite(2,HIGH);
  delay(tGreen);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(tYellow);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(tRed);
  digitalWrite(4,LOW);

}
