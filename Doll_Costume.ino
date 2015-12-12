#include <Adafruit_NeoPixel.h>
#include "hardware.h"
#include "config.h"
#include "Led.h"
#include "effects.h"
#include "Sequence.h"
Heartbeat heartbeatSeq;
uint32_t lastTick;
uint32_t lastStateChange;

int touchCount;
int touchLatch=0;
int touchAvg,touchNoise;
int state;
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
    heartbeatSeq.request_start();
    state=0;
    calibTouch(15);
    lastTick=millis();
    lastStateChange=millis();
    heartbeatSeq.up_color=LEDColor(30,0,0);
    heartbeatSeq.down_color=LEDColor(30,0,0);
    heartbeatSeq.pulse1_color=LEDColor(0,0,0);
    heartbeatSeq.pulse2_color=LEDColor(30,30,30);
    heartbeatSeq.rampup_time=220*1.5;
    heartbeatSeq.rampdown_time=330*1.5;
    heartbeatSeq.pulse1_time=10;
    heartbeatSeq.pulse2_time=50;
    heartbeatSeq.wait_time=220*2;
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
    if(state != 1){
      heartbeatSeq.tick();
      effect_position=((millis()%4000)/10);
      bodiceWave(effect_position,0,40,0.3,0.5);
    }
/*    if (getTouch(15)){
      if (millis() > lastTick){
        lastTick=millis();
        touchCount++;
        if (touchCount > 10)
          touchCount=10;
          //Serial.println("Touch");
        }
      }else{
          //Serial.println("No Touch");
          touchCount=0;
          touchLatch=0;
      }
    if (state==0 && touchCount==10 && touchLatch != 1){
        lastStateChange=millis();
        touchLatch=1;
        state++;
        setHeart(0,0,0);
        setBodice(0,0,0);
        stripOutput();
    }
    if (state==1 && touchCount==10 && touchLatch !=1){
        lastStateChange=millis();
        state++;
        touchLatch=1;
    }
    if (state==2 && touchCount==10 && touchLatch != 1){
      state=3;
      lastStateChange=millis();
      touchLatch=1;
      heartbeatSeq.up_color=LEDColor(30,0,0);
      heartbeatSeq.down_color=LEDColor(30,0,0);
      heartbeatSeq.pulse1_color=LEDColor(0,0,0);
      heartbeatSeq.pulse2_color=LEDColor(90,90,90);
      heartbeatSeq.rampup_time=220*1.5;
      heartbeatSeq.rampdown_time=330*1.5;
      heartbeatSeq.pulse1_time=10;
      heartbeatSeq.pulse2_time=50;
      heartbeatSeq.wait_time=220*2;
    }*/
    /*
    for (int bright = 0; bright < 120; bright+=4) {
    heartSleepThrob3(bright,30,30,1.0,0.9,0.9);
    bodiceWave(effect_position,0,70,0.3); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)

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
  setOuterHeart(0,0,0);
  setInnerHeart(0,0,0);
  setJewelHeart(0,0,0);
  stripOutput();
  
  if (effect_position != -1){
      effect_position+=2;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
  delay(20);
  setOuterHeart(90,90,90);
  setInnerHeart(90,90,90);
  setJewelHeart(90,90,90);
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
    heartSleepThrob3(bright,30,15,1.0,0.9,0.9);

  bodiceWave(effect_position,0,70,0.3); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)
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
  bodiceWave(effect_position,0,70,0.3); //bodiceWave(int effect_position,int startpos,int totalcount,float balance)
  stripOutput();
	if (effect_position != -1){
      effect_position++;
      effect_position %= (2 << 17);
      if(effect_position > 400){
        effect_position=-1;
      }
  }
	delay(10);
    } */
}

void calibTouch(int pin){
    touchAvg=touchRead(pin);
    delay(4);
    touchNoise=abs(touchAvg-touchRead(pin));
    for (int i=0; i<1000;i=i+1){
      int reading=touchRead(pin);
      touchAvg=(touchAvg*.9)+(reading*.1);
      int touchnoise_reading=abs(touchAvg-reading);
      touchNoise=(touchNoise*.9)+(touchnoise_reading*.1);
      delay(1);
    }
}

int getTouch (int pin){
    int reading=touchRead(pin);
    touchAvg=(touchAvg*.99)+(reading*.01);
    if(reading > (touchAvg+100)){
        return(1);
    }else{
        return(0);
    }
}

