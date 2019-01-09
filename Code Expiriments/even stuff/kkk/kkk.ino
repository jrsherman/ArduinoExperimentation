void setup(){

  Serial.begin(9600);

}


//
//int function_one(int num_range){
//  int accum = 0;
//  char my_Array[] ="arduino";
//  for (int i = 0; num_range > i; i++){
//    
//    if(i%2 == 0){
//       //Serial.println(i);
//       accum+=i ;
//       }
//    
//  }
//  return my_Array[0].length();
//
//
//
//
//  }





int return_even() {
  
  int count = 0;
  int num = 100;
  int my_array[] = {};

  for (int i= 0; i< 100; i++){
     if(i%2 == 0){
        my_array[count] = i;
        count++;
        Serial.println(my_array[count-1]);
         }
    //Serial.println(my_array[5]);
    delay(20)  ;
  }
  
}













void loop()

{





  //
  //  for (int i= 0; i<= 4; i ++){
  //    Serial.println(my_array[i]);
  //    delay(30);
  //  }
  //  Serial.print("\n");
  //
  //
  Serial.println("yo");
  //Serial.println(my_array[4]);

  //    new_size = function_one(100);
  //    Serial.println(strl(new_size));

}



