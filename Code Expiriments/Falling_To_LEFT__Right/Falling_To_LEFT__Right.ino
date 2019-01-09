#include <AcceleroMMA7361.h>

AcceleroMMA7361 accelero;
int x;
int y;
int z;

void setup()
{
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accelero.calibrate();
}

void loop()
{
  x = accelero.getXRaw();
  y = accelero.getYRaw();
  z = accelero.getZRaw();
  Serial.print("\nx: ");
   
  Serial.print(x-515);
  Serial.print("\ty: ");
  if(y-515 > 5)
    Serial.print("Fell Right");
    
   if(y-515 < -5)
    Serial.print("Fell left");
  Serial.print(y-515);
 // Serial.print("\tz: ");
  //Serial.print(z);
  delay(15);                                     //(make it readable)
}
