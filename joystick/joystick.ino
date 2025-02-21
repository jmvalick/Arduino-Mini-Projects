int Xpin = A0;
int Ypin = A1;
int button = 2;
int Xval;
int Yval;
int Bval;
int buzz1 = 10;
int led = 11;
int dt1;
int brightness;

void setup() {

  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  pinMode(buzz1, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Bval = digitalRead(button);

  //Serial.print("X: ");
  //Serial.print(Xval);
  //Serial.print("  Y: ");
  //Serial.print(Yval);
  //Serial.print("  Button: ");
  //Serial.println(Bval);

  dt1 = 9700./1023.*Xval + 300;
  brightness = -255./1023.*Yval + 255;

  analogWrite(led,brightness);

  if (Bval == 0){
    digitalWrite(buzz1, HIGH);
    delayMicroseconds(dt1);
    digitalWrite(buzz1, LOW);
    delayMicroseconds(dt1);
  }

}
