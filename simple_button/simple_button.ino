int button = 2;
int buttonVal;
int dt = 100;

void setup() {

  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  Serial.begin(9600);

}

void loop() {

  buttonVal = digitalRead(button);
  Serial.print("Your button is: ");
  Serial.println(buttonVal);
  delay(dt);

}
