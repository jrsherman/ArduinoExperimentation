//channel (0-15), value (0-4095))
#include "Tlc5940.h"
int IRpin = 5;     
void setup()
{
 
  pinMode(IRpin, INPUT); 
  Serial.begin(9600);      
  
  
  Tlc.init(500);
  Tlc.clear();
  
  delay(1000);
}

/* This loop will create a Knight Rider-like effect if you have LEDs plugged
   into all the TLC outputs.  NUM_TLCS is defined in "tlc_config.h" in the
   library folder.  After editing tlc_config.h for your setup, delete the
   Tlc5940.o file to save the changes. */
int delayAmount = 40;
int dimAmount = 4095;

int cycle = 0;
boolean isOn = false;







float mappedInputValue(float y){
  //Serial.print("y in: ");
  //Serial.println(y);
  y = constrain(y , 1 , 2000 );
  //Serial.print("\n y after constrain: ");
  //Serial.println(y);
  
  y = map(y, 500,  1000, 4095 , 50);
   y = constrain(y , 100 , 4095 );
  //Serial.println(y);
  
  return y;
}




void loop()
{

  float volts = analogRead(IRpin)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  float distance = (65*pow(volts, -1.10));          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk
  float y = map(distance, 20, 90, 1, 4095); 
  Serial.println(y);      
if(y > 400 )
  isOn = false;


if (y < 400 && isOn == false){
  if(cycle == 3)
    cycle = 0;

  int i;
  int tempI;
  
  
  if(cycle == 0)
    i = 0;
  
  else if(cycle == 1)
    i = 1;
  
  else if(cycle == 2)
    i = 2;
    
  tempI = i;

    for(i; i< 12; i+=3){
      float invertedVal = mappedInputValue(y);
      Tlc.set(i, invertedVal);
      
      
      
      Tlc.update();
      delay(delayAmount);
    }

    delay(delayAmount);

    for(i = tempI; i< 12; i+=3){
      Tlc.set(i, 0);
      Tlc.update();
       delay(delayAmount); 
    }
 Tlc.clear();
 cycle++;
 isOn = true;
}

}

