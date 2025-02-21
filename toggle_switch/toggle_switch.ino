int led = 3;
int button = 10;
int newRead;
int oldRead;
int ledState;
int dt =  100;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  
  newRead = digitalRead(button);
  
  if (oldRead == 0 && newRead == 1){

    if(ledState == 0){
      digitalWrite(led, HIGH);
      ledState = 1;
    }

    else{
      digitalWrite(led, LOW);
      ledState = 0;
    }
  }

  oldRead = newRead;

  delay(dt);

}