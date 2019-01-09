// change in velocity over time acceleration
int led = 10;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


  pinMode(led, OUTPUT);
}



//v is km or mi per hour etc
// 5 feet per 
//5feet every .5 seconds
//distance travled over some time
//5 change in position/displacement 
//v = v1 * .98t

float time = 0;
float initialVelocity = 50;
float velocity = initialVelocity;






void loop() {
  velocity = initialVelocity  -4.9*time;
  
  if(velocity > 0){
  
  float velocityOut = velocity*1000;
  float mappedLed = map(velocityOut, 0 , 5000, 0 , 255);
  analogWrite(led, mappedLed);  
  //Serial.println(velocity);
  Serial.println(mappedLed);
  }
  else{
    velocity=initialVelocity;
    time = 0;
  }
  
  
  
  
  delay(10);
  time+=.01;
  
  
  
  // put your main code here, to run repeatedly: 
  
}
