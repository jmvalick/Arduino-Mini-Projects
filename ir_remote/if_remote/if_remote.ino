#include<IRremote.h>
int IRpin = 3;
IRrecv IR(IRpin);
decode_results cmd;
int dt = 100;

String myCMD;

void setup() {

Serial.begin(9600);
IR.enableIRIn();
 
}

void loop() {

  while(IR.decode(&cmd) == 0){
    }
  delay(dt);
  IR.resume();
  
  if (cmd.value == 0xFFA25D){
    myCMD = "POWER";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFFE21D){
    myCMD = "FUNC/STOP";
    Serial.println(myCMD);
  }

  if (cmd.value == 0xFF629D){
    myCMD = "VOL+";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF22DD){
    myCMD = "FAST BACK";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF02FD){
    myCMD = "PAUSE";
    Serial.println(myCMD);
  }

  
  if (cmd.value == 0xFFC23D){
    myCMD = "FAST FORWARD";
    Serial.println(myCMD);
  }

  if (cmd.value == 0xFFE01F){
    myCMD = "DOWN";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFFA857){
    myCMD = "VOL-";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF906F){
    myCMD = "UP";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF9867){
    myCMD = "EQ";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFFB04F){
    myCMD = "ST/REPT";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF6897){
    myCMD = "0";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF30CF){
    myCMD = "1";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF18E7){
    myCMD = "2";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF7A85){
    myCMD = "3";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF10EF){
    myCMD = "4";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF38C7){
    myCMD = "5";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF5AA5){
    myCMD = "6";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF42BD){
    myCMD = "7";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF4AB5){
    myCMD = "8";
    Serial.println(myCMD);
  }
  
  if (cmd.value == 0xFF52AD){
    myCMD = "9";
    Serial.println(myCMD);
  } 
 
}
