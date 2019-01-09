#include "Tlc5940.h"
//channel (0-15), value (0-4095))
class Note{
  public:
  
    friend void validateTest();
    Note(char noteInput);//creates object with just the letter note input
    Note(char noteInput, int MIDIvelocity);//object with two parameters note and velocity
    Note(char noteInput, int MIDIvelocity, int octave);//object with three parameters note velocity and which ocvatve
    Note(char noteInput, char sharpFlat, int MIDIvelocity, int octave);//object with four note parameters with the sharps and flats included
    void validateInput();
    void augmentNote();
    void noteOff();
    void noteOn();
    void executeNoteState();
    void changeNoteOctave(int);
    //checks the array slots to see if ID is already taken, if not fill in a 1 to indicate slot is taken for the moment
    static int IDSlotAssignment[16];
    //array full of Note on array Ids
    static const int arrayOnIds[16];
    static const int arrayOffIds[16];

  private:
    int noteState;
    int setOctave;
    int savedOctave;
    int applyOctave;
    int augmentVal;
    char noteInput;
    char sharpFlat;  
    int MIDIvelocity;
    int memberIDOn;
    int memberIDOff;
    int temporaryIDSlotIndex;    
};





Note::Note(char noteInput):noteState(0),noteInput(noteInput),sharpFlat(0),MIDIvelocity(100){
  //no octave is applied  
  applyOctave = 0;
  //sharp or flat is set to null value
  augmentVal = 0;
  validateInput();
}

Note::Note(char noteInput, int MIDIvelocity):noteState(0),noteInput(noteInput),sharpFlat(0),MIDIvelocity(MIDIvelocity){   
  applyOctave = 0;
  augmentVal = 0;  
  validateInput();
}

Note::Note(char noteInput, int MIDIvelocity, int octave):noteState(0),noteInput(noteInput),sharpFlat(sharpFlat),setOctave(octave), MIDIvelocity(MIDIvelocity){
  applyOctave = 0;
  augmentVal = 0;
  validateInput();
}

Note::Note(char noteInput, char sharpFlat,int MIDIvelocity, int octave):noteState(0),noteInput(noteInput),sharpFlat(sharpFlat),setOctave(octave),MIDIvelocity(MIDIvelocity){
  applyOctave = 0;
  augmentVal = 0; 
  augmentNote();
  validateInput();
}

void Note::changeNoteOctave(int octave){
  noteInput = savedOctave+(octave*12);
}

int Note::IDSlotAssignment[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//note on IDs
const int Note::arrayOnIds[16] = {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159};
//corresponding note off IDs
const int Note::arrayOffIds[16] =  {128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143};

//poly id
void Note::noteOn(){  
  if(noteState >= 128 && noteState<= 143  || noteState == 0){
    for(int i = 0; i < 16; i++){
      if(IDSlotAssignment[i] == 0){
        temporaryIDSlotIndex = i; //set index member var
        memberIDOn = arrayOnIds[i];
        memberIDOff = arrayOffIds[i];
        IDSlotAssignment[i]  = 1;
        break;
      } 
      
    }
    Serial.println(memberIDOn);
    noteState = memberIDOn;
    executeNoteState();

  }
}
void Note::noteOff(){
  //note off
  //remember midi works by having serveral note on place holders
  //this is built to tag which note went on and now if that same note is
  //still on turn it off.
  if(noteState >= 144 && noteState < 159)
    //get ready to execute note off by setting noteState to the off value
    noteState = memberIDOff;
    executeNoteState();
    noteState = 0;
    memberIDOn = 0;
    memberIDOff = 0;
    IDSlotAssignment[temporaryIDSlotIndex] = 0;   
}

void Note::executeNoteState(){
  Serial1.write(noteState);//send note on or note off command 
  Serial1.write(noteInput);//send pitch data
  Serial1.write(MIDIvelocity);//send velocity data  
}
void Note::augmentNote(){
  //augment note adds a half step with # or takes it down
  //a half step with b
  //I think this is added after the note on has already been instantiated.
  //so this method will alter the existing note object
  if(sharpFlat == '#')
    augmentVal = 1;
  else if(sharpFlat == 'b')
    augmentVal = -1;
  //if setoctave param is 0 don't do anything with this block
  if(setOctave == 0);
  else
    applyOctave = setOctave*12;
}
//|| !(noteInput >= 'A' && noteInput <= 'G')





//make a friend function
void Note::validateInput(){ 
  //Serial.println((int)noteInput);
  if(!(noteInput >= 'a' && noteInput <= 'g'))
  {
    Serial.print("Not a valid Note \n");
  }
  else {
    // If you want to check the values that are output
    //remember they will be Mostly Caps because we are setting the midi notes with ascii not the other way around

      switch(noteInput){
       case 'a':
       case 'A':
       
         noteInput = 69+applyOctave + augmentVal;
         break;
         
       case 'b':
       case 'B':
         noteInput = 71+applyOctave+augmentVal;
         break;
         
        case 'c':
        case 'C':
          noteInput = 72+applyOctave+augmentVal;
         break;
         
       case 'd':
       case 'D':
         noteInput = 74+applyOctave+augmentVal;
         break;
         
        case 'e':
        case 'E':
          noteInput = 76+applyOctave+augmentVal;
          break;
          
       case 'f':
       case 'F':
         noteInput = 77+applyOctave+augmentVal;
         break;
         
        case 'g':
        case 'G':
          noteInput = 79+applyOctave+augmentVal;
          break;
          
       default:
         noteInput = 69+applyOctave+augmentVal;
         break;
      }
      savedOctave = noteInput;
  }
}







int IRpin = 5;
//setting infrared input to analog in pin 5
//*----------------------*//
//yellow goes to ground
//black goes to power
//red goes to input 5

//infrared range finder notes*
//the object is sensed only with the reflection of the led output
//thus the hand must be placed directly over the led side of the range finder
// placing the hand over the reciever will not return real values.

int delayRate = 60;

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average




void setup() {
  
  //Serial(1-5) can only be used on the arduino mega because it has expanded serial in/out ports
  //if the user has a shield that goes straight into serial(0) you will have to use two wires to rout
  //the signal into a different serial port so the user has two lines of communication with serial.
  
  
  
  Serial1.begin(31250);
  //begin midi communication serial(baud rate 31250 is necessary)
  Serial.begin(9600);
  //begin serial communication this will give outputs in the serial window or with an lcd screen
  //once implimented
  
   for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
  pinMode(IRpin, INPUT);
  // setting analog pin 5 to input 
  //initializing the tlc5940 to values of 100 for an initial light output for power validation etc.
  Tlc.init(100);
  delay(1000);
  Tlc.clear();
}

float mappedInputValue(float y){
  
  //Serial.print("y in: ");
  //Serial.println(y);
  y = constrain(y , 1 , 2000 );
  //Serial.print("\n y after constrain: ");
  //Serial.println(y);
  y = map(y, 500,  1000, 4095 , 50);
  y = constrain(y , 100 , 4095 );
  //Serial.println(y);
  return y;
}





int noteDivision = ((21)/7);

long timerSetTwo = 10000;// set timer to start at 10 seconds after program start
long timerTwoInterval = 10000; // set timer to start at 10 seconds
boolean executeAnimation = 0;
long timerAnimationTimer = 1000;
long timerAnimationInterval = 60;//sets lenght between led pops
int count = 0;
int delayAmount = 40;
int dimAmount = 4095;
int cycle = 0;
boolean isOn = false;
boolean runThrough = 0;
boolean isOnTheremin = 0;


//note notes :P
//*----------------------------------*//
//Note note1('a', 40);       ( note letter ,velocity(0-127))
//Note note1('a', 40, 2);     (note letter, velocity, octave)
//Note(char noteInput, char sharpFlat,int MIDIvelocity, int octave)      (note,   # or b ,   velocity(0-127),   octave)

//is a method of the note object .changeNoteOctave(2)

/*-------Setting up note objects---------*/
//none augmented notes aka c scale
//augmented notes are indented by a space for clarity
Note note1('a', 24);
 Note note1point5('a','#', 40, 0);
Note note2('b', 80);
Note note3('c', 23);
 Note note3point5('c','#', 40, 0);
Note note4('d', 18);
 Note note4point5('d','#', 40, 0);
Note note5('e', 30);
Note note6('f', 14);
 Note note6point5('f','#', 40, 0);
Note note7('g', 20);
 Note note7point5('g','#', 40, 0);

int notePop = 0;
int notePop2 = 0;
int notePop3 = 0;
int notePop4 = 0;
int countColor = 2;

void loop() {
  unsigned long currentMillis = millis();
  float volts = analogRead(IRpin)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  float distance = (65*pow(volts, -1.10));          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk
  
  
  
  //averaging the readings
  //perhaps gaussian blur would be better?
   // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = distance; 
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
  // send it to the computer as ASCII digits
  Serial.println(average-20);   
  float y_mapped = map(average, 20, 41, 0, 127);
  float y = average ;
  
  
  
  /*
      if(average-20 > noteDivision*7){
        
        Serial.println("pop7");
        note2.noteOff();
        note3.noteOff();
        note4.noteOff();
        note5.noteOff();
        note6.noteOff();
        note7.noteOff();
        note1.noteOff();
        
        
      }
      else if(average-20 > noteDivision*6 && ){
        
        Serial.println("pop6");
  
        note3.noteOff();
        note4.noteOff();
        note5.noteOff();
        note6.noteOff();
        note7.noteOff();
        note1.noteOff();
         
        note2.noteOn();
        delay(200);
      }
      else if(average-20 > noteDivision*5)
      {
         Serial.println("pop5");
        
        note2.noteOff();
        note3.noteOff();
        note4.noteOff();
        note5.noteOff();
        note6.noteOff();
        note7.noteOff();
        
        note1.noteOn();
        delay(200);
     
      }
      else if(average-20 > noteDivision*4)
      
      {
         Serial.println("pop4");
        note1.noteOff();
        note2.noteOff();
        note3.noteOff();
        note4.noteOff();
        note5.noteOff();
        note6.noteOff();
        
        note7.noteOn();
          delay(200);
      }
      else if(average-20 > noteDivision*3)
      
      {
         Serial.println("pop3");
        note1.noteOff();
        note2.noteOff();
        note3.noteOff();
        note4.noteOff();
        note5.noteOff();
        
        note7.noteOff();
        
        
        note6.noteOn();
          delay(200);
      }
      else if(average-20 > noteDivision*2)
      {
         Serial.println("pop2");
        note1.noteOff();
        note2.noteOff();
        note3.noteOff();
        note4.noteOff(); 
        note7.noteOff();
        note6.noteOff();
        note5.noteOn();
        
          delay(200);
      }
      else if(average-20 > noteDivision*1)
      {
         Serial.println("pop1");
        note1.noteOff();
        note2.noteOff();
        note3.noteOff(); 
        note7.noteOff();
        note6.noteOff();
        note5.noteOff();
        
        note4.noteOn();
        
          delay(200);
        
        
      }
     
     
     */
     
      if(average-20 > noteDivision*0 && average-20 < 3 && notePop==0){
        Serial.println("pop0");
        note4.noteOff();
        note5.noteOff();
        note3.noteOn();
        notePop2=0;
        notePop3=0;
        notePop=1;
      }
      else if(average-20 > 9){
         notePop=0;
         notePop2=0;
         notePop3=0;
         note3.noteOff();
         note4.noteOff();
         note5.noteOff();
      }
      
     if(average-20 >= 3 && average-20 < 5 && notePop2==0){
        Serial.println("pop0");
         notePop=0;
         notePop3=0;
        note5.noteOff();
        note3.noteOff();
        note4.noteOn();
        
        notePop2=1;
      }
      
      if(average-20 >= 5 && average-20 < 8 && notePop3==0){
        Serial.println("pop0");
         notePop=0;
         notePop2=0;
         
         note3.noteOff();
         note4.noteOff();
         note5.noteOn();
         notePop3=1;
      }
   
   
  
  
  
  //attempt at altering cc parameter while playing notes
  //check how it effects the midi on off vals at a later date (make suer no conflicts ensue)
   if(y_mapped < 127){
     int value = map(y_mapped, 0, 127, 127, 0);
    

     
    
     Serial1.write(176);
     Serial1.write(79);//select which parameter cc to work with
     //86shift osc1
     //filterA
      //(81) kbd turn on/off malstrom
     //(80) env turn on/off malstrom
     
     //filterB
     //(82) env turn on/off malstrom
     //cc (79)(frequency on malstrom)
     Serial1.write(value);// set the value of param
     timerAnimationInterval=map(y_mapped, 3, 127, 20, 80);
     dimAmount=map(y_mapped, 3, 127, 1000, 4095);
     dimAmount=constrain(dimAmount, 0, 4095);
     //Serial.println(dimAmount);
     
   }
  //if thermin input is less than 400 and it is off then play the notes and set thermin boolean to on(object is within playing trigger range)  
  /*if(y < 41.0 && isOnTheremin == 0){
     note5.changeNoteOctave(-2);
     note5.noteOn();
     note7.noteOn();
     note2.noteOn();
     note4point5.noteOn();
    isOnTheremin =1; 
  }//if thermin input is greater than 400 and it is on then set boolean to off(if no object is within playing range) 
  else if(y > 41.0 &&isOnTheremin == 1){
       note5.noteOff();
       note7.noteOff();
       note2.noteOff();
       note4point5.noteOff();
       isOnTheremin = 0;
  }*/
  
  // if the object is within playing range and it has not been executing animation reset timer to current time
  //set execute animation to on
  if(y < 41.0 && executeAnimation == 0) {
      timerSetTwo = currentMillis;
      timerAnimationTimer = currentMillis;
      executeAnimation = 1;
  }
  //if object out of range turn off animation/ reset counter/ reset run through
  else if(y > 41.0) {
      executeAnimation = 0;
      count=countColor;//change 1,2,3 to start on r/g/b
      runThrough=0;
      //scrubs the tlc outputs again just in case lights get caught on 
       for(int i = 0; i < 30; i ++){
      Tlc.set(i, 0);
      Tlc.update();
      } 
  }
  if(executeAnimation == 1 && y < 41.0){
    if(currentMillis - timerAnimationTimer > timerAnimationInterval){
      //Serial.print("Execute: ");
      //Serial.println(count);
       timerAnimationTimer = currentMillis;
       
      if(runThrough == 0){
        
        Tlc.set(count, dimAmount);
       Tlc.set(count-1, dimAmount); 
       
        Tlc.update();
         count+=3; 
        
        if(count > 30){
          count = countColor;
          runThrough = 1;
        } 
      }
     else if(runThrough == 1){
       
       Tlc.set(count, 0);
       Tlc.set(count-1, 0);
       
       Tlc.update();
       count+=3;
       if(count > 30){
         count = countColor;
         runThrough = 0;
       }  
     }
    }   
  }
  //this scrubs the outputs turning off the leds after they are run through
  if(count > 0){
    count == 0; 
    for(int i = 0; i < 30; i ++){
      Tlc.set(i, 0);
      Tlc.update();
      }
  }  
}//end void loop
