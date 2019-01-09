#include <SoftwareSerial.h>

SoftwareSerial lcd(2, 3);
unsigned long number = 800;
void setup()
{
  Serial.begin(9600);  // start serial monitor serial
  lcd.begin(9600);  // start lcd serial
  lcd.write(0xFE); 
  lcd.write(0x01); 
 
   lcd.print("OMG");
 
   lcd.print(" this thing is working");

  
}



void loop()
{
 lcd.write(0xFE); 
  lcd.write(0x01);

  if(log10(number) >= 3){
  lcd.print((number-number%100)/1000);
  lcd.print(",");
  lcd.print(number%1000);
  }
  else

    
    lcd.print(number-number%100);
    lcd.print("     ");
  lcd.print(number);
  lcd.print("     ");
  lcd.print(log10(number));
  number+=1;
  delay(50);
}
