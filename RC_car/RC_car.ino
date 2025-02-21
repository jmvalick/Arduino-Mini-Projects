int lSpeedPin = 5;
int rSpeedPin = 6;
int dir1 = 3;
int dir2 = 4;
int dir3 = 7;
int dir4 = 8;
int mSpeed;
int lSpeed;
int rSpeed;
int subSpeed;
int X1pin = A0;
int Y1pin = A1;
int X2pin = A2;
int Y2pin = A3;
int X1val;
int Y1val;
int X2val;
int Y2val;

void setup() {
  
  pinMode(lSpeedPin, OUTPUT);
  pinMode(rSpeedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(X1pin, INPUT);
  pinMode(Y1pin, INPUT);
  pinMode(X2pin, INPUT);
  pinMode(Y2pin, INPUT);
  Serial.begin(9600);

}

void loop() {

  X1val = analogRead(X1pin);
  Y2val = analogRead(Y2pin);
  
  if (X1val < 510){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, HIGH);
    mSpeed = -255./512. * X1val + 255.;
  }
  else if (X1val > 517){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    mSpeed = 255./512. * X1val - 255.;
  }
  else{
    mSpeed = 0;
  }
  
  
  if(Y2val < 510){
    subSpeed = -255./512. * Y2val + 255.;
    lSpeed = mSpeed - subSpeed;
    rSpeed = mSpeed;
  }
  else if(Y2val > 517){
    subSpeed = 255./512. * Y2val - 255.;
    rSpeed = mSpeed - subSpeed;
    lSpeed = mSpeed;
  }
  else{
    lSpeed = mSpeed;
    rSpeed = mSpeed;
  }
  
  
  if(lSpeed < 0){
      lSpeed = 0;
    }
  if(rSpeed < 0){
      rSpeed = 0;
    }
  if(lSpeed < 0){
      lSpeed = 0;
    }
  if(rSpeed > 250){
      rSpeed = 250;
    }
  if(lSpeed > 250){
      lSpeed = 250;
    }

  analogWrite(lSpeedPin, lSpeed);
  analogWrite(rSpeedPin, rSpeed);
  Serial.print(lSpeed);
  Serial.print("   ");
  Serial.println(rSpeed);
}
