int relayPin = 11;   //Relay IN1 connected to pin 7
int micPin = A1;   // Mic connected to pin 6
int micVal = 0;      //HIGH is no sound, LOW is sound

boolean pwrToggle = true;

void setup ()
{
  Serial.begin(74880);  
  pinMode(relayPin, OUTPUT);  //Set pin for output
  //digitalWrite(relayPin, HIGH);  // HIGH is off, LOW is on
  //pinMode (micPin, INPUT) ;   //Set pin for input
}
void loop ()
{
  micVal = analogRead(micPin) ; // Listen...
  
  if (micVal > 600) // Hear something!!!
  {
      if (pwrToggle == true) {      //relay off (true) Turn it on and display message in serial Monitor
            Serial.println ("Relay on");
            digitalWrite(relayPin, HIGH);
            pwrToggle = false;
            delay (500);
      } else {    //relay on (true) Turn it off and display message in serial Monitor
            Serial.println ("Relay off");
            digitalWrite(relayPin, LOW);
            pwrToggle = true;
            delay (500);
      }
  }
  Serial.println (micVal);
  delay(5);
}
 
