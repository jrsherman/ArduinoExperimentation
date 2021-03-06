// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  pinMode(9, OUTPUT); 
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    if(c=='H')
       digitalWrite(9,HIGH);
    else if(c=='L')
      digitalWrite(9,LOW);
    
    
  }
  
  /*int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer*/
  /*if(x > 15){
  digitalWrite(9,HIGH);
  Serial.println("Lem");
  }
  else
    digitalWrite(9,LOW);
  */

  
}
