int photoPin = A0;
int led1 = 2;
int led2 = 3;
int lightVal;
int dt = 250;

void setup() {
  
  pinMode(photoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 
  lightVal = analogRead(photoPin);
  Serial.println(lightVal);

  if(lightVal >= 350){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }

  delay(dt);

}
