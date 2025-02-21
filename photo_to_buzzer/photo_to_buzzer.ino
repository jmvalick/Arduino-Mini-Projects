int readPin = A0;
int buzzer = 2;
float readValue;
int dt;

void setup() {
 
  pinMode(readPin,INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  readValue = analogRead(readPin);
  Serial.print(readValue);
  Serial.print("   ");
  dt = (readValue*(994./57.) + 60. - 99400./57.);
  Serial.println(dt);
  
  digitalWrite(buzzer, HIGH);
  delayMicroseconds(dt);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(dt);

}
