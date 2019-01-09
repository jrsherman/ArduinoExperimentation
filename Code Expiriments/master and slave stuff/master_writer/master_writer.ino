// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

char incomingByte;
#include <Wire.h>

void setup()
{ //Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}



void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                if(incomingByte=='H'){
                  Wire.beginTransmission(4);
                  Wire.write(incomingByte);
                  Wire.endTransmission();
                  Serial.println(incomingByte);   
                  
                }
                else if(incomingByte=='L'){
                  Wire.beginTransmission(4);
                  Wire.write(incomingByte);
                  Wire.endTransmission();
                  Serial.println(incomingByte);   
                }
                
        }
        
        
        
        
        
}
