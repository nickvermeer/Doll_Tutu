#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "Led.h"
#include "effects.h"

class Sequence {
  public:
    Sequence();
    int8_t isrunning;
    uint32_t start_time;
};

Sequence::Sequence(){
  isrunning=0;
  start_time=millis();
}

class Heartbeat: public Sequence{
  public:
    Heartbeat();
    void init();
    void request_stop();
    void request_start();
    void tick();

    LEDColor up_color,down_color,pulse1_color,pulse2_color;
    int rampup_time,rampdown_time,pulse1_time,pulse2_time,wait_time;
    float upsplit,downsplit;
  private:
    uint32_t last_time;
    
    
};
Heartbeat::Heartbeat(){
  start_time=millis();
  isrunning=0;
  last_time=0;
  up_color=LEDColor(30,30,30);
  down_color=LEDColor(30,30,30);
  pulse1_color=LEDColor(0,0,0);
  pulse2_color=LEDColor(90,90,90);
  rampup_time=220;
  rampdown_time=330;
  pulse1_time=10;
  pulse2_time=50;
  wait_time=220;
  
}
void Heartbeat::init(){
  start_time=millis();
  last_time=0;
}
void Heartbeat::request_stop(){
  if(isrunning!=0){
    isrunning=0;
  }
}
void Heartbeat::request_start(){
   if(isrunning==0){
      this->init();
      isrunning=1;
   }
}
void Heartbeat::tick(){
    if(isrunning==1&&(millis() != last_time)){
      last_time=millis();
      float progress;
      int running_time=millis()-start_time;
      if (running_time < rampup_time){
        progress=(float)running_time/(float)rampup_time;
        setHeart(up_color.r*progress,up_color.g*progress,up_color.b*progress);
      }else if (running_time < (rampup_time+pulse1_time)){
        setHeart(pulse1_color.r,pulse1_color.g,pulse1_color.b);
      }else if (running_time < (rampup_time+pulse1_time+pulse2_time)){
        setHeart(pulse2_color.r,pulse2_color.g,pulse2_color.b);
      }else if (running_time < (rampup_time+pulse1_time+pulse2_time+rampdown_time)){
        progress=(float)(running_time-(rampup_time+pulse1_time+pulse2_time))/(float)(rampdown_time);
        progress=1.0-progress;
        setHeart(down_color.r*progress,down_color.g*progress,down_color.b*progress);
      }else if (running_time > (rampup_time+pulse1_time+pulse2_time+rampdown_time+wait_time)){
        setHeart(0,0,0);
        this->request_stop();
        this->request_start();  
      }
      stripOutput();
  }
}
/*  if(isrunning==1){
      int running_time=millis()-start_time;
      float progress;
      if (running_time < rampup_time){
        progress=(float)running_time/(float)rampup_time;
        
      }else if (running_time < (rampup_time+pulse1_time)){
        //setHeart(pulse1_color.r,pulse1_color.g,pulse1_color.b);
      }else if (running_time < (rampup_time+pulse1_time+pulse2_time)){
        //setHeart(pulse2_color.r,pulse1_color.g,pulse2_color.b);
      }else if (running_time < (rampup_time+pulse1_time+pulse2_time+rampdown_time)){
        //progress=(float)(running_time-(rampup_time+pulse1_time+pulse2_time))/(float)(rampdown_time);
        
      }else if (running_time > (rampup_time+pulse1_time+pulse2_time+rampdown_time+wait_time){
        setHeart(0,0,0);
        this->request_stop();
        this->request_start();  
      }
      
  }*/
#endif //SEQUENCE_H
