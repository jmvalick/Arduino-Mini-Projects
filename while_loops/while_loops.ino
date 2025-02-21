int potVal;
int delayTime = 100;
int potPin = A0;
int led1 = 5;

void setup() {
  
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(led1, OUTPUT);

}

void loop() {
  
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(delayTime);

  while (potVal > 1000){

    digitalWrite(led1, HIGH);
    potVal = analogRead(potPin);
    Serial.println(potVal);
    delay(delayTime);

  }

  digitalWrite(led1, LOW);

}
