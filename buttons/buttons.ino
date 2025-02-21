int led = 2;
int button = 10;
int buttonRead;
int dt = 100;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  
  buttonRead = digitalRead(button);
  Serial.println(buttonRead);
  delay(dt);

  if (buttonRead == 1){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

}
