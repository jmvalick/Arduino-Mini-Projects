//Pins
int relayPin = 5;  
int micPin = A5;   
int micVal = 0;      

//consts
const int noiseThresh = 800;    //threshold of noise
const int clapNum = 2;          //number of claps to change state
const int maxClapTime = 2000;   //time allowed between claps

//variables
boolean pwrToggle = true;       //relay state
int counter = 0;                //clap count
float timer = 0.0;              //time after clap

void setup ()
{
  Serial.begin(230400);  
  pinMode(relayPin, OUTPUT);     //Set relayPin for output
  digitalWrite(relayPin, HIGH);  // HIGH is off, LOW is on
  pinMode (micPin, INPUT) ;      //Set micPin for input
}
void loop (){
  
  micVal = analogRead (micPin);
  
  if (micVal > noiseThresh){  // Hear something

    counter += 1;

    if (pwrToggle == true && counter == clapNum) {  //relay off (true) Turn it on and display message in serial Monitor
      Serial.println ("Relay on");
      digitalWrite(relayPin, LOW);
      pwrToggle = false;
      counter = 0;
    }
    if (pwrToggle == false && counter == clapNum) { //relay on (false) Turn it off and display message in serial Monitor
      Serial.println ("Relay off");
      digitalWrite(relayPin, HIGH);
      pwrToggle = true;
      counter = 0;
    }

    else {  //first clap
      timer = millis();
    }
    delay (500);
  }  

  if ((millis() - timer) > maxClapTime){  //if no second clap after maxTime reset counter and timer
    counter = 0;
    timer = millis();
  }

  //Serial.print(counter);
  //Serial.print("  "); 
  //Serial.print(timer);
  //Serial.print("   ");
  //Serial.println(micVal);
}
