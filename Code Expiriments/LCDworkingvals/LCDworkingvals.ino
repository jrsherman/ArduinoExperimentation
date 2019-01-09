#include <LiquidCrystal.h>
#include <LCDKeypad.h>

// exponential equations and sine waves don't look super great for fading at lower light levels
//unless you are going at a faster rate this seems to hold true for the 0-255 range of values
// on the tlc there is more of a resolution for these leds 0-4150 which should give a smoother appearence for the pwm signals
 //linear fades would be molst applicable for this type of fading
 //also light mixing will further disguise shakeyness in light output with les stutter
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);



char msgs[5][16] = {"Right Key OK ",
                    "Up Key OK    ",               
                    "Down Key OK  ",
                    "Left Key OK  ",
                    "Select Key OK" };
                    
                    
                    
int led = 11;                      
int adc_key_val[5] ={50, 200, 400, 600, 800 };
int NUM_KEYS = 5;
int adc_key_in;
int key=-1;
int oldkey=-1;
int delayAmount = 30;
 
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
 
  lcd.print("ADC key testing"); 
}

int brightnessMap = 255;
float i = 0;
void loop()
{
  
  
  adc_key_in = analogRead(0);    // read the value from the sensor 
  key = get_key(adc_key_in);  // convert into key press
   if (key != oldkey)   // if keypress is detected
   {
     delay(50);  // wait for debounce time
     adc_key_in = analogRead(0);    // read the value from the sensor 
     key = get_key(adc_key_in);    // convert into key press
     if (key != oldkey)    
     {   
       lcd.setCursor(0, 1);
       oldkey = key;
       if (key >=0)
       {
           if(key == 1 && brightnessMap != 255){
             brightnessMap+=5;
             
           }
           else if(key == 2 && brightnessMap != 0){
              brightnessMap-=5;
             
           }
           
           lcd.clear();
           lcd.print(key);
           if(key == 3){
              delayAmount-=5; 
           }else if (key ==0){
             
            delayAmount +=5; 
           }
           lcd.print("  Delay Amount: ");
           lcd.setCursor(5,1);
           lcd.print(delayAmount);
           
           
           
            delay(200);
           
       }
     }
   }
  
  lcd.clear();
  lcd.setCursor(0,0);
 //float brightness = 125*(float)sin(i)+125;
 float brightness = 10*sin(i);
   lcd.print("Sine:   ");
  lcd.setCursor(8,0); 
  lcd.print(brightness);
  lcd.setCursor(0,1);
 
 /*
  lcd.print("Cosine: ");
  lcd.setCursor(8,1); 
  lcd.print((float)cos(i));
 */
  lcd.print("MapSine: ");
 lcd.setCursor(8,1); 
 /*
 lcd.print("S shunt: ");
 if(brightness-(int)brightness >= .5){
   lcd.print((int)brightness+1);
   analogWrite(led, (int)brightness+1);   
 }
 else {
   lcd.print((int)brightness);
   analogWrite(led, (int)brightness);  
 }
 */
 float sine = sin(i);
 float mappedSine = map(sine*1000000,-1000000, 1000000,0,   brightnessMap);
 lcd.print(mappedSine);
 analogWrite(led, mappedSine);  
  i+=.5;
  delay(delayAmount);
}


int get_key(unsigned int input)
{
    int k;
    for (k = 0; k < NUM_KEYS; k++)
    {
      if (input < adc_key_val[k])
      {
        return k;
      }
    }   
    if (k >= NUM_KEYS)k = -1;  // No valid key pressed
    return k;
}



