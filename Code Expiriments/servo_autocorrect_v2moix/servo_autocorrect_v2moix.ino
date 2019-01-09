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
  int pure_val = 0;
  int initialVal = 1;
  int x1;
  int x2;
  int x3;
  int x4;
  int x5;
  int X1;
  int X2;
  int X3;
  int X4;
  int X5;
  int global_x1 = -500;
  int global_x2 = -500;
  
  int global_z1 = -500;
  int global_z2 = -500;
  int global_z3 = -500;
  int global_z4 = -500;
  int global_z5 = -500;

  int last_val=0;

   int counter = 1; 



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
 
 

 
 
  
}



int low_pass_filter(int x){
  if(global_x1 == -500){
     global_x1 = x;
     return x; 
  }
  if(global_x2 == -500){
     global_x2 = x;
     return x ;
  }
  
  int x1 = global_x1;
  int x2 = global_x2;
  int x3 = x;
	
  int avg_x2 = (x1 + 5*x2 + x3) / 7.0;
	
  global_x1 = x2;
  global_x2 = x3;
	
  return avg_x2;
}






int low_pass_filter5(int z){
  if(global_z1 == -500){
     global_z1 = z;
     return z; 
  }
  if(global_z2 == -500){
     global_z2 = z;
     return z ;
  }
  if(global_z3 == -500){
     global_z3 = z;
     return z ;
  }
  if(global_z4 == -500){
     global_z4 = z;
     return z ;
  }
  
  int z1 = global_z1;
  int z2 = global_z2;
  int z3 = global_z3;
  int z4 = global_z4;
  int z5 = z;
  	
  int avg_z3 = (z1 + 4*z2 + 8*z3 + 4*z4 + 2*z5)/19.0;
	
  global_z1 = z2;
  global_z2 = z3;
  global_z3 = z4;
  global_z4 = z5;
	
  return avg_z3;
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
  if (index2 >= numReadings2){              
    // ...wrap around to the beginning:
    index2 = 0;                          
  // calculate the average:
  average2 = total2 / numReadings2;       
}
  // send it to the computer as ASCII digits
  if(average-515 > 0){
    averageMapped = map(average-520, 0, 74, 90 ,180);
    averageConstrained = constrain(averageMapped , 90 ,180);
    averageConstrained =  90 - (averageConstrained - 90);
    //analogWrite(pin, averageConstrained);
    //analogWrite(pin2, 0);
  }
 else{
  averageMapped = map(average-520, 0, -74 , 90 ,0);
  averageConstrained = constrain(averageMapped , 0 ,90);
  
  averageConstrained =  90 - (averageConstrained - 90);
  //analogWrite(pin, averageConstrained);
  //analogWrite(pin, 0);
  }
  
 Serial.print(counter);
  Serial.print("\t \t \t");
  Serial.print(average-520);
 Serial.print("\t \t \t");
  

if(counter >=3 && last_val == averageConstrained){
  pure_val= averageConstrained;
   myservo.write(low_pass_filter5(pure_val));
  Serial.print(low_pass_filter5(pure_val));
  
  //counter++; 
}
else if(last_val == averageConstrained ){
  myservo.write(low_pass_filter5(averageConstrained));
  Serial.print(low_pass_filter5(averageConstrained));
  counter++; 
}
else {
  last_val= averageConstrained;
  myservo.write(low_pass_filter5(averageConstrained));
  Serial.print(low_pass_filter5(averageConstrained));
  counter=1;//reset counter since  a average Constrained is not the same number as last val
}

 
 
  //Serial.print("\t \t \t");
  //Serial.print(averageConstrained);
  Serial.print("\n");

   if(average2-515 >= 0){
    averageMapped2 = map(average2-520, 0, 60, 0 ,300);
    averageConstrained2 = constrain(averageMapped2 , 0 ,180);
    analogWrite(pin3, averageConstrained2);

  }
delay(100);
}
