
//with the tlcs first u set then after you are done setting you update for all

//of the leds in that turn

#include <SoftwareSerial.h>
#include "Tlc5940.h"
SoftwareSerial lcd(2, 3);
unsigned long number = 800;
void setup()
{
  Serial.begin(9600);  // start serial monitor serial
  lcd.begin(9600);  // start lcd serial
  lcd.write(0xFE); 
  lcd.write(0x01); 
 
   lcd.print("OMG");
 
   lcd.print(" this thing is working");
   
   
       Tlc.init();
    
    delay(1000);
  
  //Tlc.clear();
   // Tlc.set(3, 4000);
 
   // Tlc.set(1, 4000);

 // Tlc.update();
  //delay(1000);
   
   
  // Tlc.set(3, 0);
  //  Tlc.set(6, 0);
  //  Tlc.set(1, 0);
  //  Tlc.set(5, 0);
   Tlc.clear();
}
int setDecay =66;
int setDim =100;

float numberZ = 0;
int setValz;
void loop()
{


  Tlc.clear();
    
    
  setDim = 900*sin(22*numberZ)+1000;
  
  
  //setValz = 4*numberZ +20;
    //Tlc.clear();
 lcd.write(0xFE); 
  lcd.write(0x01);
  //lcd.print((int)(2000*sin(setDecay*numberZ)+2000));
  lcd.print(setDecay);
  
  Tlc.set(0, (int)(setDim*sin(setDecay*numberZ)+setDim));
  Tlc.set(1, (int)(setDim*sin(setDecay*numberZ)+setDim));
  Tlc.set(2, (int)(setDim*sin(setDecay*numberZ)+setDim));
  
  
  Tlc.set(3, (int)(setDim*sin(setDecay*numberZ-.4)+setDim));
 Tlc.set(4, (int)(setDim*sin(setDecay*numberZ-2)+setDim));
  Tlc.set(5, (int)(setDim*sin(setDecay*numberZ-2)+setDim));
  
  
  
  
  Tlc.set(6, (int)(setDim*sin(setDecay*numberZ-.7)+setDim));
  Tlc.set(7, (int)(setDim*sin(setDecay*numberZ-4)+setDim));
  Tlc.set(8, (int)(setDim*sin(setDecay*numberZ-4)+setDim));
  
  
  Tlc.set(9, (int)(setDim*sin(setDecay*numberZ-.9)+setDim));
  Tlc.set(10, (int)(setDim*sin(setDecay*numberZ-6)+setDim));
  Tlc.set(11, (int)(setDim*sin(setDecay*numberZ-6)+setDim));
  
   Tlc.set(12, (int)(setDim*sin(setDecay*numberZ-1.2)+setDim));
  Tlc.set(13, (int)(setDim*sin(setDecay*numberZ-8)+setDim));
  Tlc.set(14, (int)(setDim*sin(setDecay*numberZ-8)+setDim));
  
  
  
  //Tlc.set(1,setValz);
  Tlc.update();

  
  numberZ+=.001;
  delay(5*sin(5*numberZ)+15);

}
