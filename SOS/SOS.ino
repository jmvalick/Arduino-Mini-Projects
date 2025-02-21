int greenLED = 4;
int t1 = 250;
int t2 = 500;
int t3 = 1000;

void setup() {
 
  pinMode(greenLED,OUTPUT);

}

void loop() {

//S
digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t1);

digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t1);

digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t1);

//O
digitalWrite(greenLED,HIGH);
delay(t2);
digitalWrite(greenLED,LOW);
delay(t2);

digitalWrite(greenLED,HIGH);
delay(t2);
digitalWrite(greenLED,LOW);
delay(t2);

digitalWrite(greenLED,HIGH);
delay(t2);
digitalWrite(greenLED,LOW);
delay(t2);

//S
digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t1);

digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t1);

digitalWrite(greenLED,HIGH);
delay(t1);
digitalWrite(greenLED,LOW);
delay(t3);
}
