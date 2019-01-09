
const int ledPin =  13;   

unsigned long previousMillis = 0;        // will store last time LED was updated

long interval;           // interval at which to blink (milliseconds)

int intervalSet;

int execute;
int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor
long setTimer;
int start=0;
int backToZero=1;
long setLoop;
int runThrough=0;
void setup() {
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}
void loop() { 

if(sensorValue<300&&backToZero==1&&intervalSet==1)
while(sensorValue<300){
  
     sensorValue = analogRead(sensorPin);
     unsigned long currentMillis = millis(); 
     
      if (currentMillis - previousMillis >= interval+4&&runThrough==0) {
          digitalWrite(ledPin,HIGH);
          delay(100);
          digitalWrite(ledPin,LOW);
          previousMillis = currentMillis;
          Serial.println(runThrough);
          runThrough=1;
          
  }if (currentMillis - previousMillis >= interval+4&&runThrough==1) {
          digitalWrite(ledPin,HIGH);
          delay(100);
          digitalWrite(ledPin,LOW);
          previousMillis = currentMillis;
          Serial.println(runThrough);
          runThrough=2;
  }
  if ((currentMillis - previousMillis >= interval+7)&&runThrough==2) {
          digitalWrite(ledPin,HIGH);
          delay(100);
          digitalWrite(ledPin,LOW);
          previousMillis = currentMillis;
          Serial.println(runThrough);
          runThrough=0;
  }

   }
sensorValue = analogRead(sensorPin);
//Serial.println(sensorValue);

if(sensorValue>500&&start==0&&backToZero==1){
  intervalSet=0;
  setTimer=millis();
  start=1;
  execute=1;
  backToZero=0; 
  Serial.print("Begin Loop: ");
  Serial.println(setTimer); 
}

  if(sensorValue>500&&start==1&&backToZero==1){
  setLoop=millis();
  start=0;
  execute=0;
  backToZero=0; 
   Serial.print("End Loop: ");
   Serial.println(setLoop);
   Serial.print("Loop Duration: ");
   Serial.print((setLoop-setTimer)/1000.0);
   Serial.println(" seconds");
  interval = (setLoop-setTimer);
  intervalSet= 1;
  previousMillis=millis();
   }
if(sensorValue<50){
  //Serial.println("return to 0");
  backToZero=1;
}
else{
  backToZero=0; 
}

}
