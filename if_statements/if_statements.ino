int readPin = A0;
float voltage;
int delayTime = 100;
int bluePin = 2;
int greenPin = 3;
int yellowPin = 4;
int redPin = 5;

void setup() {
 
  pinMode(readPin,INPUT);
  Serial.begin(9600);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);

}

void loop() {
  
  float readValue = analogRead(readPin);
  voltage = (5./1023.) * readValue; //5V = 1023
  Serial.println(voltage); 

  if (voltage == 0.0){
    digitalWrite(bluePin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,LOW);
    digitalWrite(redPin,LOW);
  }

  if(voltage < 2.0 && voltage > 0.0){
    digitalWrite(bluePin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(yellowPin,LOW);
    digitalWrite(redPin,LOW);
  }

  if(voltage >= 2.0 && voltage < 4.0){
    digitalWrite(bluePin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,HIGH);
    digitalWrite(redPin,LOW);
  }

  if(voltage >= 4.0){
    digitalWrite(bluePin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,LOW);
    digitalWrite(redPin,HIGH);
  }

  delay(delayTime);

}