#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <string>
#include <iterator>
#include <serstream>

using namespace std;

// <iostream> declares cout/cerr, but the application must define them
// because it's up to you what to do with them.
namespace std
{
  ohserialstream cout(Serial);
}



/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(57600);
  
  int cutIndex = 3;
  int sizeA = 7;
  int sizeB = 3;
  int arrayCounter = sizeA+sizeB; 
  string a = "bearcat";
  
  string b = "dog";
  int array[arrayCounter];
  
  
  for (int i = 0; i < 7-cutIndex-1; i ++){
    cout << a[i];
    array[i] = a[i];
    
  }
  for(int i = 0; i < sizeB; i++){
    cout << b[i];
    array[i] = b[i];
    
  }
  for(int i =cutIndex; i < sizeA; i++){
    cout << a[i];
    array[i] = a[i];
  }
  
  
  
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {

}
