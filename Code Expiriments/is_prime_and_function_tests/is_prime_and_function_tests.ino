void setup(){
  
  Serial.begin(9600);
  
  
}


void loop(){
  

  int x = 12;
  
  if(myFunction(x))
    Serial.print("TRUE! \n");
   else
     Serial.print("FALSE \n");
  
  
  String var1 = "hello";
  
  //Serial.println(x);
  
  
 delay(100);
  
  
  
}



boolean myFunction(int & x){
  boolean prime;
  if(x%2 == 0)
     prime = false; 
  else
    prime = true;
    
    return prime;
  
  
}
