#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

namespace std
{
  ohserialstream cout(Serial);
}



void setup(){
  
  
 Serial.begin(9600); 
  
}


void loop(){
  
  
  
int myints[] = {16,2,77,29, 67, 97, 660};

  
vector<int> vectorNums(myints, myints + sizeof(myints) / sizeof(int) );

//vectorNums[2] = 245;
//Serial.print(vectorNums[1]);

//cout << vectorNums[2] << endl;

//vectorNums[4] = 45;

for(int i = 0; i < 7; i ++){
    
cout << vectorNums[i] << endl;

delay(50);


}






  
}
