const int ledPin =  13;      // the number of the LED pin


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







int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  unsigned long currentMillis = millis();
  Serial.println(currentMillis);

}
