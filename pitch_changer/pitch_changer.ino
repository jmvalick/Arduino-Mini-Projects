int readPin = A0;
int buzzer = 10;
float readValue;
int dt;

void setup() {
 
  pinMode(readPin,INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  readValue = analogRead(readPin);
  dt = (readValue*(9940./1023.) + 60.);

  digitalWrite(buzzer, HIGH);
  delayMicroseconds(dt);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(dt);

}
