#include <AcceleroMMA7361.h>


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 


int pin = 9;
int pin2 = 6;
int pin3 = 5;
AcceleroMMA7361 accelero;
double x;
double y;
int z;
int averageMapped;
int averageConstrained;
const int numReadings = 10;


int averageMapped2;
int averageConstrained2;


int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average


const int numReadings2 = 10;
int readings2[numReadings2];      // the readings from the analog input
int index2 = 0;                  // the index of the current reading
int total2 = 0;                  // the running total
int average2 = 0;                // the average



void setup()
{

    myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;  
    
     for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++)
    readings2[thisReading2] = 0;  
    
   pinMode(pin, OUTPUT);
   pinMode(pin2, OUTPUT);
   pinMode(pin3, OUTPUT);
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accelero.calibrate();
  
    myservo.write(180); 
delay(200);  
   myservo.write(50); 
  
}

void loop()
{
  
  x = accelero.getXRaw();
  y = accelero.getYRaw();
  z = accelero.getZRaw();

   total= total - readings[index];        
  // read from the sensor:  
  readings[index] = x;
  // add the reading to the total:
  total= total + readings[index];      
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning:
    index = 0;                          

  // calculate the average:
  average = total / numReadings; 


  
   total2= total2 - readings2[index2];        
  // read from the sensor:  
  readings2[index2] = y;
  // add the reading to the total:
  total2= total2 + readings2[index2];      
  // advance to the next position in the array:  
  index2 = index2 + 1;                    

  // if we're at the end of the array...
  if (index2 >= numReadings2)              
    // ...wrap around to the beginning:
    index2 = 0;                          

  // calculate the average:
  average2 = total2 / numReadings2;       




  
  // send it to the computer as ASCII digits
  if(average-515 > 0){
    averageMapped = map(average-515, 0, 50, 90 ,180);
    averageConstrained = constrain(averageMapped , 90 ,180);
    averageConstrained =  90 - (averageConstrained - 90);
    //analogWrite(pin, averageConstrained);
    //analogWrite(pin2, 0);
  }
 else{
  averageMapped = map(average-515, 0, -45 , 90 ,0);
  averageConstrained = constrain(averageMapped , 0 ,90);
  
  averageConstrained =  90 - (averageConstrained - 90);
  //analogWrite(pin, averageConstrained);
  //analogWrite(pin, 0);
  }
  myservo.write(averageConstrained);
  //analogWrite(pin, averageConstrained);
  
  
  
  
  Serial.print(averageConstrained);
  Serial.print("\n");
  
/*
  Serial.println(averageConstrained);
  
  Serial.print("\nx: ");
  
  */

   if(average2-515 >= 0){
    averageMapped2 = map(average2-515, 0, 60, 0 ,300);
    averageConstrained2 = constrain(averageMapped2 , 0 ,180);
    analogWrite(pin3, averageConstrained2);

  }

   //Serial.println(averageConstrained2);
  
 // Serial.print("\ny: ");
  
  
  
  
  
  //Serial.print(map(x-515, 0, 50 , 0 ,180));
  \
  //analogWrite(pin2, 0);
  /*
  
  if(x-515 > -5 && x-515 < 5)
     analogWrite(pin, 10);
  else if(x-515 < 0)
     analogWrite(pin2, map(x-515, 0, -50 , 0 ,180));
  else{
    analogWrite(pin, map(x-515, 0, 50 , 0 ,180));
     analogWrite(pin2, 0);
  }*/
  /*
  Serial.print("\ty: ");
  Serial.print(map(y-515, 0, 50 , 0 ,180));
   if(y-515 <0)
     analogWrite(pin3, 0);
   else
    analogWrite(pin3, map(y-515, 0, 50 , 0 ,180));
  */
  
  /*
  Serial.print("\tz: ");
  Serial.print(z);
 */
 
  //delay(5);                                     //(make it readable)
  
}
