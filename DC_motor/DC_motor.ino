int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int mSpeed;
int Xpin = A0;
int Ypin = A1;
int button = 13;
int Xval;
int Yval;
int Bval;

void setup() {
  
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  Serial.begin(9600);

}

void loop() {

  Xval = analogRead(Xpin);
  
  if (Xval < 510){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    mSpeed = -255./512. * Xval + 255.;
    analogWrite(speedPin, mSpeed);
  }

  if (Xval >= 520){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    mSpeed = 255./512. * Xval - 255.;
    analogWrite(speedPin, mSpeed);
  }

  Serial.println(Xval);
}
