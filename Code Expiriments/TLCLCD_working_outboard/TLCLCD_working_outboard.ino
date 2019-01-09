
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
    Tlc.set(3, 4000);
 
    Tlc.set(1, 4000);

  Tlc.update();
  delay(1000);
   Tlc.set(3, 0);
    Tlc.set(6, 0);
    Tlc.set(1, 0);
    Tlc.set(5, 0);
   Tlc.clear();
}

float numberZ = 0;
int setValz;
void loop()
{


  Tlc.clear();
    
    
 
  
  
  //setValz = 4*numberZ +20;
    //Tlc.clear();
 lcd.write(0xFE); 
  lcd.write(0x01);
  lcd.print((int)(2000*sin(40*numberZ)+2000));
  lcd.print(setValz);
  
  Tlc.set(0, (int)(2000*sin(40*numberZ-10)+2000));
  Tlc.set(1, (int)(1000*sin(56*numberZ)+1000));
  Tlc.set(2, (int)(2000*sin(10*numberZ-30)+2000));
  
  
  Tlc.set(3, (int)(2000*sin(40*numberZ-10)+2000));
  Tlc.set(4, (int)(1000*sin(56*numberZ)+1000));
  Tlc.set(5, (int)(2000*sin(10*numberZ-30)+2000));
  
  
  
  
  Tlc.set(6, (int)(2000*sin(40*numberZ-10)+2000));
  Tlc.set(7, (int)(1000*sin(56*numberZ)+1000));
  Tlc.set(8, (int)(2000*sin(10*numberZ-30)+2000));
  
  
  Tlc.set(9, (int)(2000*sin(40*numberZ-10)+2000));
  Tlc.set(10, (int)(1000*sin(56*numberZ)+1000));
  Tlc.set(11, (int)(2000*sin(10*numberZ-30)+2000));
  
  
  
  
  //Tlc.set(1,setValz);
  Tlc.update();

  
  numberZ+=.001;
  delay(20);

}
