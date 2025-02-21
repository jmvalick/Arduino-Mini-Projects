int led = 3;
int buzzer = 2;
int buttonUp = 9;
int buttonDown = 10;
int brightness = 0;
int dt =  100;
int dt2 = 500;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  
  if(digitalRead(buttonUp) == 1){
    if (brightness == 255){
      brightness = 255;
      digitalWrite(buzzer,HIGH);
      delay(dt2);
      digitalWrite(buzzer,LOW);
    }
    else{
    brightness += 5;
    }
  }

  if(digitalRead(buttonDown) == 1){
    if (brightness == 0){
      brightness = 0;
    }
    else{
    brightness -= 5;
    }
  }

  Serial.println(brightness);
  analogWrite(led,brightness);

  delay(dt);

}