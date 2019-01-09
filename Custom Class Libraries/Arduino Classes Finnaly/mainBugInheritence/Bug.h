
#include <Arduino.h>

#include <StandardCplusplus.h>
#include <serstream>
#include <avr/pgmspace.h>
using namespace std;


#define num 5
// can not overload . and ::, the sizeof


class MommaBug{
  public:
    virtual void attack();
    friend ostream operator<<(ostream, MommaBug);
    void operator++(int);
    
    MommaBug operator=(const MommaBug rightObject);
    
    MommaBug();
    MommaBug(const MommaBug &);
    ~MommaBug();
    static bool isOurRaceDead;
  
  private:
    const int population;
    static const int test = 0;
    //int * intPntr;
    
};

class Worker:public MommaBug{
  
  
  
};

class thinker:public MommaBug{
  
  
  
};

class babies:public MommaBug{
  
  
  
};



