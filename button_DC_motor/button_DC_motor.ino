int increaseBut = 3;
int decreaseBut = 2;
int dir1 = 9;
int dir2 = 10;
int speedPin = 11;
int mSpeed = 0;
int newState1;
int oldState1;
int newState2;
int oldState2;

void setup() {

  Serial.begin(9600);
  pinMode(increaseBut, INPUT);
  pinMode(decreaseBut, INPUT);
  digitalWrite(increaseBut, HIGH);
  digitalWrite(decreaseBut, HIGH);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(speedPin, OUTPUT);
  
}

void loop() {

  newState1 = digitalRead(increaseBut);
  newState2 = digitalRead(decreaseBut);

  if (newState1 == 0 and oldState1 == 1){
    mSpeed += 15;
    if(mSpeed > 255){
      mSpeed = 255;
    }
    if(mSpeed < 150 and mSpeed > 0){
      mSpeed =  150;
    }
  }
  
  if (newState2 == 0 and oldState2 == 1){
    mSpeed -= 15;
    if(mSpeed < -255){
      mSpeed = -255;
    }
    if(mSpeed > -150 and mSpeed < 0){
      mSpeed =  -150;
    }
  }

  if (mSpeed >= 0){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mSpeed);
  }

  if (mSpeed < 0){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, (-1*mSpeed));
  }
  
  oldState1 = newState1;
  oldState2 = newState2;
  Serial.println(mSpeed);
  
}
