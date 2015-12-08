#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>
#include "Point.h"
class LEDColor {
  public:
  LEDColor();
  LEDColor(int,int,int);
  int r,g,b;
};
LEDColor::LEDColor(){
  r=0;
  g=0;
  b=0;
}
LEDColor::LEDColor(int nr,int ng,int nb){
  r=nr;
  g=ng;
  b=nb;
}

class LED {
  public:
    LED(Adafruit_NeoPixel*,int);
    void setClr(int r,int g,int b);  
    int index;
    Adafruit_NeoPixel *strip;

};
LED::LED(Adafruit_NeoPixel *nstrip,int nindex){
  strip=nstrip;
  index=nindex;
}

void LED::setClr(int r,int g,int b){
  strip->setPixelColor(index,strip->Color(r,g,b));
}

class BodiceLED : public LED {
  public:
    BodiceLED(Point,uint16_t,Adafruit_NeoPixel*,int);
    Point location;
    uint16_t delta_heart;
    
};
BodiceLED::BodiceLED(Point p,uint16_t ndelta_heart,Adafruit_NeoPixel *nstrip,int nindex): LED::LED(nstrip,nindex) 
{
  location=p;
  delta_heart=ndelta_heart;
}



#endif //LED_H
