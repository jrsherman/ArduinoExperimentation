#include <testClass.h>

void setup(){
Serial.begin(9600);  
}



void loop(){
  
  PrintClass instance1(20);
  
  //instance1.displayLine();
  
  instance1.largestFactor();
  
  

  
  delay(50);
}
