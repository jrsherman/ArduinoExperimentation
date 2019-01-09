void setup(){
  
  Serial.begin(9600);
  
  
}


void loop(){
  

  int x = 100;
  
  if(myFunction(x))
    Serial.print("TRUE! \n");
   else
     Serial.print("FALSE \n");
  
  
  String var1 = "hello";
  
  //Serial.println(x);
  
  
 delay(500);
  
  
  
}



boolean myFunction(int & x){
  boolean prime;
  
  for(int i = 0; i < x; i++){
    Serial.print(i);
    
    
    if(i%2 == 0)
     Serial.print(" Is even \n"); 
  else
    Serial.print(" Is not even \n"); 
    
    
    
  }
  if(x%2 == 0)
     prime = false; 
  else
    prime = true;
    
    return prime;
  
  
}
