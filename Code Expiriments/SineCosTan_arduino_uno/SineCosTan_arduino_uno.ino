/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 9;           // the pin that the LED is attached to
int led2 = 10;           // the pin that the LED is attached to
int led3 = 11; 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
float x = 0;
// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
 
 
  //Serial.print("x val:");
  //Serial.println(x);

 
  //Serial.print("sin val:");



  float sine = sin(x);
  float cosine = cos(x);
  float tangent = sin(x+3);
  float mappedTangent = map(tangent*100,-100, 100, 0, 255);
  float mappedSine = map(sine*100,-100, 100, 0, 255);
  float mappedCosine = map(cosine*100,-100, 100, 0, 255);
  //Serial.println(sine*100);
  //Serial.println(mappedSine);
  //Serial.println(map(sine*100,-1000, 1000, 0, 255));
  x+=.01;
  //Tlc.set(1, mappedSine);
  //Tlc.set(3, mappedSine);

  analogWrite(led,mappedSine);
   analogWrite(led2,mappedCosine);
   analogWrite(led3,mappedTangent);
   

 delay(5);

  
 
                      
}

