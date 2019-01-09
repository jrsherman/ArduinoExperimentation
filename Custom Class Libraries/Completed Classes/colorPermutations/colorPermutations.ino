#include "functions.h"
#include "Tlc5940.h"
int fullColor=4095;
//color dimming note
// if the values are moved through quickly enough no matter how wide the color changes are
//you won't be able to percieve non fluidity
//Much like animation of comics or television it will look seemless. 24 fps is standard
// for television 
/* Strobe effect expirimentations 
The stroboscopic effect is a visual phenomenon caused by aliasing that
occurs when continuous motion is 
represented by a series of short or instantaneous samples.

Consider the stroboscope as used in mechanical analysis. 
This may be a "strobe light" that is fired at an adjustable rate.
For example, an object is rotating at 60 revolutions per second: 
if it is viewed with a series of short flashes at 60 times per second, 
each flash illuminates the object at the same position in its rotational 
cycle, so it appears that the object is stationary. Furthermore, at a 
frequency of 60 flashes per second, persistence of vision smooths out 
the sequence of flashes so that the perceived image is continuous.
 Tlc.set(0,fullColor);//blue 
      Tlc.set(2, fullColor);//blue correct
      Tlc.set(4, fullColor);//blue
      Tlc.update();
      delay(10);
      //strobe effect works with delay 5-15
      Tlc.set(0,0);//blue 
      Tlc.set(2,0);//blue correct
      Tlc.set(4,0);//blue
      Tlc.update();
      delay(2);
 */
void setup() {
  Serial.begin(57600); //need srl for output value checking
  randomSeed(analogRead(0));
  Tlc.init(); //start up Tlc board
  Tlc.clear(); //clear previous leftover outputs
}

void loop() {
      //with no delay it moves so fast it's almost a strobe
      // first try didint consider the different levels xxD
      /*
      Tlc.set(0,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(2,i);
        Tlc.set(4,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(0,fullColor);
      Tlc.set(2,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(4,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(0,fullColor);
       Tlc.set(4,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(2,i);
        Tlc.update();
        delay(2);
      }
//new
          Tlc.set(2,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(0,i);
        Tlc.set(4,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(2,fullColor);
      Tlc.set(0,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(4,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(2,fullColor);
       Tlc.set(4,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(0,i);
        Tlc.update();
        delay(2);
      }

//new
     Tlc.set(4,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(0,i);
        Tlc.set(2,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(4,fullColor);
      Tlc.set(0,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(2,i);
        Tlc.update();
        delay(2);
      }
      Tlc.set(2,fullColor);
       Tlc.set(4,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(0,i);
        Tlc.update();
        delay(2);
      }
// trial of all combinations of lighting colors
 Tlc.set(0,fullColor);
      for(int i=4095;i>0;i--){
        Tlc.set(2,i);
        Tlc.set(4,i);
        Tlc.update();
        delay(2);
      }
*/

  /*
    The next three nested for loops go through about 10,000,000 colors when incremented
    by 5 in one of the for loops and 1 in the other.
    It's difficult to notice the difference though.


    So..What is the point of this exchersize? We are trying to to have a color pallet
    that we can cycle through and a system we go run that will change colors while I play.


    So, now we come up with exactly what our program will do.
    
    program one
    random color generator
      -fade in/out different fade patterns
      -cycle to the next random color after program fade is finished for the loops desired.



   
   */



  //nested for loop for full iteration 
  //819 discrete loops   16,777,216 combinations of two colors with the third color set at full
  for(int i=4095;i>0;i-=500){
    for(int j=4095;j>0;j-=5){
      //Serial.print("blue: ");
      //Serial.print(fullColor);
      Serial.print("green: ");
      Serial.print(i);
      Serial.print("red: ");
       Serial.println(j);
       
      Tlc.set(0,fullColor);
      Tlc.set(2,i);
      Tlc.set(4,j);
      Tlc.update();
      delay(1); 
      }
    }
  //819 discrete loops   16,777,216 combinations of two colors with the third color set at full
 /*
  for(int i=4095;i>0;i-=500){
    for(int j=4095;j>0;j-=2){
      Tlc.set(2,fullColor);
      Tlc.set(0,i);
      Tlc.set(4,j);
      Tlc.update();
      delay(1); 
    }
   }
  //819 discrete loops   16,777,216 combinations of two colors with the third color set at full
  for(int i=4095;i>0;i-=500){
    for(int j=4095;j>0;j-=2){
      Tlc.set(4,fullColor);
      Tlc.set(0,i);
      Tlc.set(2,j);
      Tlc.update();
      delay(1); 
      }
    }*/
  delay(50);
}
