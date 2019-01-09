#include <StandardCplusplus.h>
#include <serstream>
#include <avr/pgmspace.h>
#include "Bug.h"
using namespace std;

namespace std
{
  ohserialstream cout(Serial);
}


void setup(void){
  Serial.begin(57000);
  cout << "Queen says: ";
  MommaBug Queen;
  
  MommaBug::isOurRaceDead = 1;
  /*
  int * intPntr;
  intPntr = new int[6];
  */
  /*
  int * arrayIntsZ;
  
  arrayIntsZ = new int[5];
  */
}

void loop(void)
{
  cout << "Queen says: ";
  MommaBug Queen;
  Queen++;
  MommaBug Queen2;
  
  //Queen = Queen2;
  
  delay(10000);
  
  
}

