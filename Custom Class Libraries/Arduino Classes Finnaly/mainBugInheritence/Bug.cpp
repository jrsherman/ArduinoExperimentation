

#include "Bug.h"


MommaBug::MommaBug():population(80000){
  
 cout << "I am alive" << endl;
 //intPntr = new int[];
  
}
MommaBug::~MommaBug(){
  cout << "Alas, I'm dead" << endl;
  
}

void MommaBug::attack(){
 cout << "attack"; 
  
}

ostream operator<<(ostream, MommaBug){
  
  
};

void MommaBug::operator++(int){
 cout << "Post fix overloaded" << endl; 
  
}
MommaBug MommaBug::operator=(const MommaBug rightObject){
 cout << "Operator = overloaded" << endl; 
 return rightObject;
}





bool MommaBug::isOurRaceDead = 0;
