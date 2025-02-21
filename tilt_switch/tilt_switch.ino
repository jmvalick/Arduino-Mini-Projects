int ledG = 2;
int ledR = 3;
int tiltSwitch = 13;
int tiltVal;

void setup() {

  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(tiltSwitch, INPUT);
  digitalWrite(tiltSwitch, HIGH);
  Serial.begin(9600);
  
}

void loop() {

  tiltVal = digitalRead(tiltSwitch);

  if (tiltVal == 0){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  }
  if (tiltVal == 1){
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
  }
  Serial.println(tiltVal);

}
