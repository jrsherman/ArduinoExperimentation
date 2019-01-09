#include "Tlc5940.h"
//channel (0-15), value (0-4095))
class Note{
  public:
  
    friend void validateTest();
    Note(char noteInput);
    Note(char noteInput, int MIDIvelocity);
    Note(char noteInput, int MIDIvelocity, int octave);
    Note(char noteInput, char sharpFlat, int MIDIvelocity, int octave);
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
  Serial3.write(noteState);//send note on or note off command 
  Serial3.write(noteInput);//send pitch data
  Serial3.write(MIDIvelocity);//send velocity data  
}
void Note::augmentNote(){ 
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
int delayRate = 60;
//Note note1('a', 40); note,velocity

//Note note1('a', 40, 2); note,velocity,octave

//.changeNoteOctave(2)
//Note(char noteInput, char sharpFlat,int MIDIvelocity, int octave) note, # or b , velocity, octave
  Note note1('a', 24);
  //Note note1point5('a','#', 40, 1);
  Note note2point5('b','b', 40, 0);
  Note note2('b', 80);
  
  Note note3('c', 23);
  Note note4('d', 18);
  Note note5('e', 30);
  Note note6('f', 14);
  Note note7('g', 20);

void setup() {
  Serial3.begin(31250);
  Serial.begin(9600);
  
  pinMode(IRpin, INPUT); 
  
  Tlc.init(500);
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


long timerSetTwo = 10000;// set timer to start at 10 seconds after program start
long timerTwoInterval = 10000; // set timer to start at 10 seconds
boolean executeAnimation = 0;

long timerAnimationTimer = 1000;
long timerAnimationInterval = 60;



int count = 0;
 
 
int delayAmount = 40;
int dimAmount = 4095;

int cycle = 0;
boolean isOn = false;


boolean runThrough = 0;

 boolean isOnTheremin = 0;

void loop() {
  
  unsigned long currentMillis = millis();
  
  float volts = analogRead(IRpin)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  float distance = (65*pow(volts, -1.10));          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk
  float y = map(distance, 20, 90, 1, 4095); 
  //Serial.println(y);   



if(y < 400 && isOnTheremin == 0){
   note1.noteOn();
   note3.noteOn();
   note5.noteOn();
  isOnTheremin =1; 
  
}
else if(y > 400 &&isOnTheremin == 1){
     note1.noteOff();
     note3.noteOff();
     note5.noteOff();
     isOnTheremin = 0;
}



if(y < 400 && executeAnimation == 0) {
    timerSetTwo = currentMillis;
    timerAnimationTimer = currentMillis;
    executeAnimation = 1;
}
else if(y > 400) {
    executeAnimation = 0;
}

if(executeAnimation == 1 && y < 400){
  
  if(currentMillis - timerAnimationTimer > timerAnimationInterval){
    Serial.print("Execute: ");
    Serial.println(count);
     timerAnimationTimer = currentMillis;
   
   
   if(runThrough == 0){
    Tlc.set(count, 4000); 
    Tlc.update();
     count+=3; 
     
     if(count > 10){
       count = 0;
       runThrough = 1;
   }
     
     
   }
   else if(runThrough == 1){
      Tlc.set(count, 0); 
    Tlc.update();
     count+=3;
    
    if(count > 10){
       count = 0;
       runThrough = 0;
   }  
   }
  }   
}




  if(count > 0){
    count == 0;
    
    for(int i = 0; i < 15; i ++){
     Tlc.set(i, 0);
     Tlc.update();
    }
  }


  
}
