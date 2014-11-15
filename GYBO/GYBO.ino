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

int state = 1;

boolean personFound()
{
  if ((irF > 0 || irB > 0) && (irL > 0 || irR > 0)) return true;
}

// ********************** TBD
void turnLeft()
{
  
}

// ********************** TBD
void turnRight()
{
}




// the loop routine runs over and over again forever:
void loop() {
  
  // **************  Get inputs
  getXzInputs();
  getIrInputs();
  //getButtonInput();   // ****** Add code for Skype
  // **************
  
  // **************  Get inputs
  
  
    switch (state)
  {
    case 1: // find
      if (personFound()) state = 2;
      else 
      {
        if (irL > irR) turnLeft();
        else turnRight();
      }
      
      break;
     case 2: //follow
       
     
       break;
     default:
       break;
  
  }
  


  
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

