
void getXzInputs()
{
  Wire.beginTransmission(0x10);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.requestFrom(0x10, 1, true);
  if (Wire.available()) {
    x = Wire.read();
  }
  
  Wire.beginTransmission(0x10);
  Wire.write(0x0a);
  Wire.endTransmission();
  Wire.requestFrom(0x10, 1, true);
  if (Wire.available()) {
    z = Wire.read();
  }
  
  Wire.beginTransmission(0x10);
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.requestFrom(0x10, 1, true);
  if (Wire.available()) {
    g = Wire.read();
  }
  
  //Serial.print(x);
  //Serial.print(", ");
  //Serial.print(z);
  
  if (g != 0) {
    Serial.print(" gesture ");
    Serial.println(g);
  }
  
  //Serial.println(".");
  
}



void getIrInputs()
{
    irF = analogRead(A3)  -80; //-sp /3 ;       // Sketchy last minute touches...
    irL = analogRead(A1) - irF /3.5 ;//-sp /7;
    irR = analogRead(A2) ;
  //  irB += analogRead(A3);  
}


