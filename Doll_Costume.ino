#include <Adafruit_NeoPixel.h>
#include "hardware.h"
#include "config.h"
#include "Led.h"
#include "effects.h"
int8_t readyval;
int effect_position;
uint32_t tstart;
void setup()
{
    readyval = 0;
    Serial.begin(115200);
    delay(2000);
    Serial.println("OK");
    for (int i = 0; i < 6; i++) {
	strips[i].begin();
    }
    effect_position = -1;
    tstart=millis();
    readyval=0;
}

void loop()
{
    int readchar;
    // put your main code here, to run repeatedly:
    while ((readyval == -1 || (readyval == 0 && ((millis()-tstart) < 4000)))) {
	if (Serial.available()) {
	    readchar = Serial.read();
	    if (readchar == 'x') {
		  readyval = 1;

	    } else if (readchar == 't') {
    readyval = -1;
	  Serial.println("Lamp Test");
    setOuterHeart(20,20,20);
    setInnerHeart(20,20,20);
    setJewelHeart(20,20,20);
    setBodice(20,20,20);
    stripOutput();
	    }else if (readchar == 'O') {
   Serial.println("Lamp Off");
    readyval = -1;
    setOuterHeart(0,0,0);
    setInnerHeart(0,0,0);
    setJewelHeart(0,0,0);
    setBodice(0,0,0);
    stripOutput();
    }else {
		Serial.println("Huh?");
		//readyval=0; 
	    }
	}
    }
    if (readyval==1 || readyval==0){
      Serial.println("Running!");
      readyval=2;
    }
    for (int bright = 0; bright < 90; bright+=5) {
    heartSleepThrob3(bright,30,30,1.0,0.1,0.1);
    bodiceWave2(effect_position,0,70,0.2); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)

	for (int i = 0; i < 6; i++) {
	    strips[i].show();
	}
	if (effect_position != -1){
      effect_position++;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
  delay(10);
 }
  setOuterHeart(10,10,10);
  setInnerHeart(10,10,10);
  setJewelHeart(10,10,10);
  stripOutput();
  delay(10);
  if (effect_position != -1){
      effect_position++;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
  setOuterHeart(120,120,120);
  setInnerHeart(120,120,120);
  setJewelHeart(120,120,120);
  stripOutput();
  if (effect_position == -1){
    effect_position=0;
  } else {
      effect_position+=5;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
  delay(50);
    for (int bright = 90; bright >= 0; bright=bright-2) {
    heartSleepThrob3(bright,30,15,1.0,1.0,1.0);

  bodiceWave1(effect_position,0,70,0.2); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)
  stripOutput();
	if (effect_position != -1){
	    effect_position++;
	    effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
	}
	delay(10);
    }
    for (int i = 0; i < 20; i++) {
  bodiceWave1(effect_position,0,70,0.2); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)
  stripOutput();
	if (effect_position != -1){
      effect_position++;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
	delay(10);
    }
}
