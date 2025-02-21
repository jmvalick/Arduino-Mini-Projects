#include<IRremote.h>
int IRpin = 3;
IRrecv IR(IRpin);
decode_results cmd;
int dt = 100;

String myCMD;
int dir1 = 9;
int dir2 = 10; 
int speedPin = 5;
int mSpeed = 0;
int pwrState = 0;

void setup() {

  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(speedPin, OUTPUT);
 
}

void loop() {

  while(IR.decode(&cmd) == 0){
    }
  delay(dt);
  IR.resume();
  
  if (cmd.value == 0xFFA25D){
    myCMD = "POWER";
    Serial.println(myCMD);
    if(pwrState == 0){
      mSpeed = 255;
      pwrState = 1;
    }
    else{
      pwrState = 0;
      mSpeed = 0;
    }
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  
  if (cmd.value == 0xFF22DD){
    myCMD = "FAST BACK";
    Serial.println(myCMD);
    if(pwrState == 1){
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
    }
  }
  
  if (cmd.value == 0xFFC23D){
    myCMD = "FAST FORWARD";
    Serial.println(myCMD);
    if(pwrState == 1){
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
    }
  }

  if (cmd.value == 0xFFE01F){
    myCMD = "DOWN";
    Serial.println(myCMD);
    if(pwrState == 1){
      if(mSpeed == 0){
        mSpeed = 0;
      }
      else{
        mSpeed -= 15;
      }
    }
  }

  if (cmd.value == 0xFF906F){
    myCMD = "UP";
    Serial.println(myCMD);
    if(pwrState == 1){
      if(mSpeed == 255){
        mSpeed = 255;
      }
      else{
        mSpeed += 15;
      }
    }
  }
   analogWrite(speedPin, mSpeed);
   Serial.println(mSpeed);
 } 
 
