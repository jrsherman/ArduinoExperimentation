const int ledPin =  13;      // the number of the LED pin


//the void loop is not as fast as the miliseconds going by...
//therefore when calling for milliseconds you will get the present miliseconds
//after the clock began and not a consecutive linear output of numbers
//from 1 to infinity-ish

// it seems to jump in intervals of about 40 milliseconds

// in fact it seems to be quick enough to read miliseconds 3 times at
//a time frame of 5000




//when no serial output is being read out with serial print
//the values of mili increment linearly


/*
nanosecond 	ns 	 
microsecond 	μs 	1 microsecond = 1,000 nanoseconds
millisecond 	ms 	1 millisecond = 1,000 microseconds
second (base unit of Time) 	sec or s 	1 second = 1,000 milliseconds
minute 	min 	1 minute = 60 seconds
hour 	hr 	1 hours = 60 minutes
day 	d 	1 day = 24 hours
week 	wk 	1 week = 7 days
fortnight 	4tnite 	1 4tnite = 2 weeks or 14 days

*/







void setup() {
  
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);  

Serial.println("Units After start ");
Serial.println("-----------------");  
}

boolean valueReached = 0;
boolean stopTimer = 0;

float timer1;
float timer2;

long previousMillis = 0;
long interval = 10;   




void loop()
{
  
  unsigned long currentMillis = millis();
  
  
  
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    Serial.println("blink");
  

}
  
  
  
  
  if(stopTimer != 1){
 /*
  Serial.print("Miliseconds: ");
  Serial.print(currentMillis);
  Serial.print("\t \t");
  Serial.print("Seconds: ");
  Serial.print(currentMillis/1000);
  
  Serial.print("\t \t");
  Serial.print("minuts: ");
  Serial.println((currentMillis/1000)/60);
  
  */
  }
  
  
  float timer1 = currentMillis;
  
  //countdown
  
  
  
  if (currentMillis == 5000 && valueReached == 0){
    Serial.print("Value Reached: ");
    Serial.println(currentMillis);
    
    
    
    stopTimer = 1;
    valueReached = 1;
  }
    
  

}
