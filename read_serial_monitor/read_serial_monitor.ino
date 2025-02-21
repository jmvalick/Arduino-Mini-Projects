String msg = "How many blinks do you want?";
String msg2 = "Which color would you like to blink?";
String color;
int ledColor;
int numBlinks;
int delayTime = 500;
int ledRed = 5;
int ledYellow = 4;
int ledGreen = 3;

void setup() {
 
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

}

void loop() {
  
  Serial.println(msg);

  while (Serial.available() == 0){

  }

  numBlinks = Serial.parseInt();

  Serial.println(msg2);
  while (Serial.available() == 0){

  }

  color = Serial.readString();

  if(color == "Red"){
    ledColor = ledRed;
  }
  if(color == "Yellow"){
    ledColor = ledYellow;
  }
  if(color == "Green"){
    ledColor = ledGreen;
  }

  for(int i = 1; i <= numBlinks; i ++){
    digitalWrite(ledColor, HIGH);
    delay(delayTime);
    digitalWrite(ledColor, LOW);
    delay(delayTime);
  }

}
