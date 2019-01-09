

/* Simple test of the functionality of the photo resistor

Connect the photoresistor one leg to pin 0, and pin to +5V
Connect a resistor (around 10k is a good value, higher
values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).

----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------
*/

int lightPin = 0;  //define a pin for Photo resistor
int led=5;     //define a pin for LED
int level;
int i;

int myFunction(){
  
  while(level >=  0){
level -= 5;
 analogWrite(led, level);
     delay(20);
  }
  
  int chill = analogRead(lightPin);
  if (chill > 85){
    
 return 0 ;
  }
  
  
  
  for( i=0; i<255; i+=5){
  
     analogWrite(led, i);
      delay(20);
   }
 
   while(i>0){
      i-=5;
  
     analogWrite(led, i);
      delay(20);
  
  
  }
  
  
   
   
   
  Serial.print("next ");
  
}



void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( led, OUTPUT );
      analogReference(DEFAULT);
}

void loop()
{
  
  int value = analogRead(lightPin);

   
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(10); //short delay for faster response to light.
   //Serial.println(value);
   if(value > 800) {
     
    digitalWrite(led, LOW);  
   Serial.print("over limit");
   } 
   
   else if(value < 85){
     int killer;
   killer = myFunction(); 
   }
   else {
     
     
     
      level = analogRead(lightPin);
      level =  map(level, 0, 1023, 255, 0)-15;
      level = constrain(level , 0,  255);
              Serial.println(value);
    analogWrite(led, level); 
   }
   
   
   
}

