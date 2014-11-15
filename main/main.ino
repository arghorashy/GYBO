#include <Servo.h>

/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

int timeCounter = 0;
int dipCounter = 0;
int sum = 0;

// the loop routine runs over and over again forever:
void loop() {
  delay(1);
  int sensorValue = analogRead(A2);
  timeCounter = timeCounter + 1;
  


  if (timeCounter > 1000) 
  {
    Serial.println(dipCounter);
    timeCounter = 0;
    dipCounter = 0;
    sum = 0;
  }
  else if (sensorValue > 890)
  {
    dipCounter = dipCounter + 1;
    sum = sum + sensorValue;
  }
  
  
    Serial.println(sensorValue);
   // delay(1);        // delay in between reads for stability
}

