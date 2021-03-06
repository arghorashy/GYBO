#include <Servo.h>
#include <Wire.h>

// ************************* INPUTS 
// XZ inputs
byte x,z,g;

//IR inputs
int irF, irL, irR;

//Button inputs
int inSkype;

// ************************* CONTROL VARIABLES
//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 10; //standby

//Motor A
int PWMA = 3; //Speed control 
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

// ************************* OTHER CRAP
int state = 1;
int sct = 40; //sensorComparisonTolerance
int dir;      // direction
int sp;       //speed


// the setup routine runs once when you press reset:
void setup() {
  
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  Serial.begin(9600);
  Wire.begin();
}


// For debugging
void irOut()
{
  Serial.print(irL);
  Serial.print(",");
  Serial.print(irF);
  Serial.print(",");
  Serial.print(irR);
  Serial.print(",");
  Serial.print(g);
  Serial.println("");
}

boolean personFound()
{
  //if ((irF > 0 || irB > 0) && (irL > 0 || irR > 0)) return true;
  if ((irF > 0) && (irL > 0 || irR > 0)) return true;
}


// If no significant IR, turn right
// If you see IR, but not directly in front, turn in the appropriate direction
// If the IR is in front, move forward, unless it reaches a certain intensity (close enough)
// -1 -> left; 0 -> forward; 1 -> right; 5 -> stop
int followDirection()
{
  
  if (irF - irL > sct && irF - irR > sct && abs(irL - irR) < sct*10000) 
  {  
    if (irF > 500)
    {
      Serial.print("Stop: ");
      irOut();
      return 5;
    }
    else
    { // If you know he is forward, go forward
      Serial.print("Forward: ");
      irOut();
      return 0;
    }
  }

  else if (irL - irR > sct)
  {  // If you know he is left, go left
     Serial.print("Left: ");
     irOut();
    return -1;
  }
  else if (irR - irL > sct)
  {
     Serial.print("Right: ");
     irOut();
    return 1; 
  }
  else 
  {
    Serial.print("Lost: ");
    irOut();
    return 1;  // if neither left nor right (or don't know know where he is), turn right
  }
  


}

// the loop routine runs over and over again forever:
void loop() {
  
  // **************  Get inputs
  getXzInputs();
  getIrInputs();
  sp = 800 ;//analogRead(A0);
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
         else if (dir == 5) stopMvt(); 
         
//       if (! personFound()) state = 1;
//       else

         // Check XZ/Buttons
         if (g == 8) state = 3;
         else if (g == 1) state = 5;
         else if (g == 2) state = 4;
         else if (g == 3) state = 2;
         break;
      case 3: // pause and wait to be summoned
        stopMvt();
        if (g == 3) state = 2;
        break;
      case 4: // go left (out of the way) and wait to be summoned
        turnLeft();
        delay(2000);
        goForward();
        delay(2000);
        state = 3;
        
        break;
      case 5: // go right (out of the way) and wait to be summoned
        turnRight();
        delay(2000);
        goForward();
        delay(2000);
        state = 3;
  
       break;
     default:
       break;
  
  }
  


  
}

