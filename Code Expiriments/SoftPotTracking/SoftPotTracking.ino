int softpotPin = A0; //analog pin 0

void setup(){
  digitalWrite(softpotPin, HIGH); //enable pullup resistor
  Serial.begin(9600);
}


 int isInUse = 0;
 int initialSetDown = 0; 
 int greaterThan;
  int lastPosition;
void loop(){
  int softpotReading = analogRead(softpotPin);
  Serial.println(softpotReading); 
  
  
if(softpotReading < 1000 && isInUse == 0){
 isInUse = 1;
 initialSetDown = softpotReading;
  greaterThan = initialSetDown;
  lastPosition = initialSetDown;
  Serial.println("Slide Active"); 
  
}

if(softpotReading < 1000){
Serial.println(softpotReading);  
  
  if(softpotReading > initialSetDown - 10 && softpotReading < initialSetDown +20 || softpotReading > lastPosition -10 && softpotReading < lastPosition+10);
  else {
    Mouse.move(0,0,constrain(initialSetDown - softpotReading, -18,18));
    Serial.println(constrain(initialSetDown - softpotReading, -25,25));
  }
  
  lastPosition = softpotReading;
  delay(80);
  
  
 /*
 
 
  int tempRead = map(softpotReading,0,1000,0,25);
  if(tempRead > greaterThan){
    Mouse.move(0,0, greaterThan - tempRead);
    
  }
  
  else if(softpotReading < greaterThan){
     Mouse.move(0,0, greaterThan + tempRead);
    
  }
  
  */
  //greaterThan = tempRead;
  
  
}




if(softpotReading > 1000){
 isInUse = 0;
 initialSetDown = 0;
 greaterThan = 0;
  
}
}
