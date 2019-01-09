int softpotPin = A0; //analog pin 0

void setup(){
  digitalWrite(softpotPin, HIGH); //enable pullup resistor
  Serial.begin(9600);
}


 int isInUse = 0;
 int initialSetDown = 0; 
 int greaterThan;
  int lastPosition;
  
  int previous;
void loop(){
  int softpotReading = analogRead(softpotPin);
  Serial.println(softpotReading); 
  
  
if(softpotReading < 1000 && isInUse == 0){
 isInUse = 1;
 Keyboard.press( KEY_RIGHT_SHIFT);
 initialSetDown = softpotReading;
  greaterThan = initialSetDown;
  previous = initialSetDown;
  Serial.println("Slide Active"); 
  
}

if(softpotReading < 1000 && !(softpotReading > previous-30 && softpotReading < previous+20 )){
  Keyboard.begin();
  
  
  
  if(softpotReading > previous){
    Mouse.move(0,0, -1);
   
  }
  else if(softpotReading < previous){
   Mouse.move(0,0, 1);
  } 
  previous = softpotReading;

  delay(20);
  
}




if(softpotReading > 1000){
 isInUse = 0;
 initialSetDown = 0;
 previous = 0;
 Keyboard.releaseAll();
  
}
}
