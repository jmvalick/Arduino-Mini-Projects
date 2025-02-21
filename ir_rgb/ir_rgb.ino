#include<IRremote.h>
int IRpin = 3;
IRrecv IR(IRpin);
decode_results cmd;
int dt = 100;

String myCMD;

int red = 9;
int green = 10;
int blue = 6;
int rV = 255;
int gV = 255;
int bV = 255;

int pwrState = 0;
int dimVal = 0;

void setup() {

  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 
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
      pwrState = 1;
    }
    else{
      pwrState = 0;
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 0);
    }
  }
 
  if (cmd.value == 0xFFE01F){
    myCMD = "DOWN";
    Serial.println(myCMD);
    if (rV > 51){
      rV = rV - 51;
    }
    if (gV > 51){
      gV = gV - 51;
    }
    if (bV > 51){
      bV = bV - 51;
    }
  }

  if (cmd.value == 0xFF906F){
    myCMD = "UP";
    Serial.println(myCMD);
    if (rV < 255 && rV != 0){
      rV = rV + 51;
    }
    if (gV < 255 && gV != 0){
      gV = gV + 51;
    }
    if (bV < 255 && bV != 0){
      bV = bV + 51;
    }
  }
  
  if (cmd.value == 0xFF6897){
    myCMD = "0";
    Serial.println(myCMD);
    rV = 255;
    gV = 255;
    bV = 255;
  }
  
  if (cmd.value == 0xFF30CF){
    myCMD = "1";
    Serial.println(myCMD);
    rV = 255;
    gV = 0;
    bV = 0;
  }
  
  if (cmd.value == 0xFF18E7){
    myCMD = "2";
    Serial.println(myCMD);
    rV = 255;
    gV = 0;
    bV = 30;
  }
  
  if (cmd.value == 0xFF7A85){
    myCMD = "3";
    Serial.println(myCMD);
    rV = 255;
    gV = 0;
    bV = 175;
  }
  
  if (cmd.value == 0xFF10EF){
    myCMD = "4";
    Serial.println(myCMD);
    rV = 0;
    gV = 0;
    bV = 255;
  }
  
  if (cmd.value == 0xFF38C7){
    myCMD = "5";
    Serial.println(myCMD);
    rV = 0;
    gV = 255;
    bV = 255;
  }
  
  if (cmd.value == 0xFF5AA5){
    myCMD = "6";
    Serial.println(myCMD);
    rV = 0;
    gV = 255;
    bV = 75;
  }
  
  if (cmd.value == 0xFF42BD){
    myCMD = "7";
    Serial.println(myCMD);
    rV = 0;
    gV = 255;
    bV = 0;
  }
  
  if (cmd.value == 0xFF4AB5){
    myCMD = "8";
    Serial.println(myCMD);
    rV = 255;
    gV = 255;
    bV = 0;
  }
  
  if (cmd.value == 0xFF52AD){
    myCMD = "9";
    Serial.println(myCMD);
    rV = 255;
    gV = 30;
    bV = 0;
  } 
  
  if(pwrState == 1){
    analogWrite(red, rV);
    analogWrite(green, gV);
    analogWrite(blue, bV);
  }
  Serial.println(rV);
 
}
