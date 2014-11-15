#include <Servo.h>
#include <Wire.h>

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Wire.begin();

}

// ************************* INPUTS 
// XZ inputs
byte x,z,g;

//IR inputs
int irF, irL, irR, irB;

//Button inputs
int inSkype;

// ************************* OTHER CRAP
int state = 1;
int sct = 40; //sensorComparisonTolerance
int dir;      // direction

boolean personFound()
{
  //if ((irF > 0 || irB > 0) && (irL > 0 || irR > 0)) return true;
  if ((irF > 0) && (irL > 0 || irR > 0)) return true;
}

// -1 -> left; 0 -> forward; 1 -> right
int followDirection()
{
  
  if (irF - irL > sct && irF - irR > sct && abs(irL - irR) < sct) 
  {  // If you know he is forward, go forward
    return 0;
  }
  if (irL - irR > sct)
  {  // If you know he is left, go left
    return -1;
  }
  else return 1;  // if neither left nor right (or don't know know where he is), turn right


}

// ********************** TBD
void turnLeft()
{
  
}

// ********************** TBD
void turnRight()
{
}

// ********************** TBD
void goForward()
{
}

// ********************** TBD
void stopMvt()
{
}




// the loop routine runs over and over again forever:
void loop() {
  
  // **************  Get inputs
  getXzInputs();
  getIrInputs();
  //getButtonInput();   // ****** Add code for Skype
  // **************
  

  
    switch (state)
  {
    case 1: // find
//      if (personFound()) state = 2;
//      else 
//      {
//        if (irL > irR) turnLeft();
//        else turnRight();
//      }
        state = 2;
      
      break;
     case 2: //follow
         // Follow and search
         dir = followDirection();
         
         if (dir == -1) turnLeft();
         else if (dir == 1) turnRight();   
         else if (dir == 0) goForward(); 
         
//       if (! personFound()) state = 1;
//       else

         // Check XZ/Buttons
         if (g == 8) state = 3;
         //else if (g == 1) state = 4;
         //else if (g == 2) state = 5;
         else if (g == 3) state = 2;
         break;
      case 3: // pause
        stopMvt();
        if (g == 3) state = 2;
        break;
      case 4: // go left
        break;
      case 5: // go right
        break;
       

       
       
     
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

