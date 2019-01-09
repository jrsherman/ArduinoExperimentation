#include <StandardCplusplus.h>
//#include <system_configuration.h>
//#include <unwind-cxx.h>
//#include <utility.h>
#include <vector>

using namespace std;
int vectorSize = 3;
vector<int> countInterval;

void setup(){
  Serial.begin(9600);
}
void loop(){
  int x = 7;
  int * ptr;
  ptr = &x;
  *ptr *= 5;
  
  countInterval.push_back(2);
  countInterval.push_back(5);
  countInterval.push_back(7);

  for(int i = 0; i < vectorSize; i ++){
    Serial.println(countInterval[i]);
    delay(1000);
  }
  
  Serial.println("size");
  Serial.println(countInterval.size());
  vectorSize = countInterval.size();
}
