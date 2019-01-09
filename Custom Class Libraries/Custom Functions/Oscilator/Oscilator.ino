//Bounce values ^^

void setup() {
  Serial.begin(9600);

}

void loop() {
  int upperBound = 7;
  int lowerBound = 0;


  for(int k = upperBound; k>=(lowerBound+1); k--){
    Serial.println(k);
    delay(5);
  }

  
  for(int k=lowerBound;k<=(upperBound-1);k++){
    Serial.println(k);
    delay(5);
  }
  } 
