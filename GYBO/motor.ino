


void turnLeft()
{
  setMotorValues(1, sp, 0);
  setMotorValues(2, sp, 1);
}


void turnRight()
{
  setMotorValues(1, sp, 1);
  setMotorValues(2, sp, 0);
}


void goForward()
{
  setMotorValues(1, sp, 0);
  setMotorValues(2, sp, 0);
}


void stopMvt()
{
  setMotorValues(1, 0, 0);
  setMotorValues(2, 0, 0);
  stop();
}


// motor = 1,2
// speed = analogue value (0-1024)
// direction = 0,1 = {left,right}
void setMotorValues(int motor, int speed, int dir)
{

  double intermValue1 = double(speed)/1023.0;
  
  int controlValue1 = int(intermValue1*255.0);
  
  move(motor, controlValue1, dir); //motor 1, full speed, left
}

void move(int motor, int speed, int dir){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(dir == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }
  else if (motor == 2)
  {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
  

}

void stop(){
//enable standby  
  digitalWrite(STBY, LOW); 
}
