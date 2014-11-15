#include <Servo.h>
#include <Wire.h>

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Wire.begin();

}

// XZ inputs
byte x,z,g;

//IR inputs
int irF, irL, irR, irB;

//Button inputs
int inSkype;





// the loop routine runs over and over again forever:
void loop() {
  
  // Get inputs
  getXzInputs();
  getIrInputs();
  //getButtonInput();   // ****** Add code for Skype

  
  //
//  delay(1);
//  int sensorValue = analogRead(A2);
//  timeCounter = timeCounter + 1;
  


//  if (timeCounter > 1000) 
//  {
//    Serial.println(dipCounter);
//    timeCounter = 0;
//    dipCounter = 0;
//    sum = 0;
//  }
//  else if (sensorValue > 890)
//  {
//    dipCounter = dipCounter + 1;
//    sum = sum + sensorValue;
//  }
  
  
//    Serial.println(sensorValue);
   // delay(1);        // delay in between reads for stability
}

