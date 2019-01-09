#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;
 unsigned int num = 10000;
void setup() {

  Serial.begin(9600);

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  //start playing track 1
  MP3player.playTrack(2);
  
  //1 beatles
  //2radiohead
  //3 radiohead
  //12
  

  delay(2000);

  
}

//do something else now
void loop() {
  int time = MP3player.currentPosition();
Serial.println(time);
  Serial.println("I'm bored!");
  delay(2000);
  


}
