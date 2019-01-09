//channel (0-15), value (0-4095))
#include "Tlc5940.h"

void setup()
{
 
  Tlc.init(500);
  Tlc.clear();
}

/* This loop will create a Knight Rider-like effect if you have LEDs plugged
   into all the TLC outputs.  NUM_TLCS is defined in "tlc_config.h" in the
   library folder.  After editing tlc_config.h for your setup, delete the
   Tlc5940.o file to save the changes. */
int delayAmount = 200;
int dimAmount = 4095;

void loop()
{   if(dimAmount < 200)
      dimAmount = 4095;
    
    dimAmount -=300;
    
    
    for(int i = 0; i< 15; i+=3){
      Tlc.set(i, dimAmount);
       Tlc.update();
       delay(delayAmount);  
    }

    delay(delayAmount);

      
    for(int i = 0; i< 15; i+=3){
      Tlc.set(i, 0);
      Tlc.update();
       delay(delayAmount); 
    }


  dimAmount -=300;


    delay(delayAmount);
    
    
    for(int i = 1; i< 15; i+=3){
      Tlc.set(i, dimAmount);
       Tlc.update();
       delay(delayAmount);  
    }

    delay(delayAmount);

      
    for(int i = 1; i< 15; i+=3){
      Tlc.set(i, 0);
      Tlc.update();
       delay(delayAmount); 
    }

dimAmount -=300;



    delay(delayAmount);

        
    for(int i = 2; i< 15; i+=3){
      Tlc.set(i, dimAmount);
       Tlc.update();
       delay(delayAmount);  
    }

    delay(delayAmount);

      
    for(int i = 2; i< 15; i+=3){
      Tlc.set(i, 0);
      Tlc.update();
       delay(delayAmount); 
    }
    delay(delayAmount);
    
    
    
    
    
    
    
    
       for(int i = 0; i< 15; i+=3){
      Tlc.set(i, dimAmount);
      Tlc.set(i+1, dimAmount);
       Tlc.update();
       delay(delayAmount);  
    }

    delay(delayAmount);

      
    for(int i = 0; i< 15; i+=3){
      Tlc.set(i, 0);
      Tlc.set(i+1, 0);
      Tlc.update();
       delay(delayAmount); 
    }
    delay(delayAmount);
    
    
    
    
    
    
    
    
    
    
    


}

