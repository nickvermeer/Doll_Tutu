#ifndef EFFECTS_H
#define EFFECTS_H
void setOuterHeart(int r,int g,int b){
  for (int i = 0; i < OUTERHEART_COUNT; i++) {
      outerheart[i].setClr(r,g,b);

  }
}
void setInnerHeart(int r,int g,int b){
  for (int i = 0; i < INNERHEART_COUNT; i++) {
    innerheart[i].setClr(r,g,b);
  }
}
void setJewelHeart(int r,int g,int b){
  for (int i = 0; i < JEWELHEART_COUNT; i++) {
    jewelheart[i].setClr(r,g,b);

  }
}
void setBodice(int r,int g,int b){
  for (int i = 0; i < BODICE_COUNT; i++) {
      bodice[i].setClr(r,g,b);
  }
}
void stripOutput(){
     for (int i = 0; i < 6; i++) {
      strips[i].show();
     } 
}

void heartSleepThrob(int bright,int maxVal,int intervalVal,float rbal,float gbal, float bbal){
  int inbright,outbright,jbright;
  
  inbright = bright;
  if (inbright > maxVal) {
      inbright = maxVal;
  }
  if (bright > intervalVal) {
      outbright = bright - intervalVal;
      if (outbright > maxVal) {
    outbright = maxVal;
      }
  } else
      outbright = 0;
  if (bright > intervalVal*2) {
      jbright = bright - (intervalVal*2);
      if (jbright > maxVal) {
    jbright = maxVal;
      }
  } else
    jbright = 0;

    setOuterHeart(outbright*rbal,outbright*gbal,outbright*bbal);
    setInnerHeart(inbright*rbal,inbright*gbal,inbright*bbal);
    setJewelHeart(jbright*rbal,jbright*gbal,jbright*bbal);

}
void heartSleepThrob2(int bright,int maxVal,int intervalVal,float rbal,float gbal, float bbal){
  int inbright,outbright,jbright;
  
  jbright = bright;
  if (jbright > maxVal) {
      jbright = maxVal;
  }
  if (bright > intervalVal) {
      inbright = bright - intervalVal;
      if (inbright > maxVal) {
    inbright = maxVal;
      }
  } else
      inbright = 0;
  if (bright > intervalVal*2) {
      outbright = bright - (intervalVal*2);
      if (outbright > maxVal) {
    outbright = maxVal;
      }
  } else
    outbright = 0;
  
    setOuterHeart(outbright*rbal,outbright*gbal,outbright*bbal);
    setInnerHeart(inbright*rbal,inbright*gbal,inbright*bbal);
    setJewelHeart(jbright*rbal,jbright*gbal,jbright*bbal);

}

void heartSleepThrob3(int bright,int maxVal,int intervalVal,float rbal,float gbal, float bbal){
  int inbright,outbright,jbright;
  
  outbright = bright;
  if (outbright > maxVal) {
      outbright = maxVal;
  }
  if (bright > intervalVal) {
      inbright = bright - intervalVal;
      if (inbright > maxVal) {
    inbright = maxVal;
      }
  } else
      inbright = 0;
  if (bright > intervalVal*2) {
      jbright = bright - (intervalVal*2);
      if (jbright > maxVal) {
    jbright = maxVal;
      }
  } else
    jbright = 0;
  
    setOuterHeart(outbright*rbal,outbright*gbal,outbright*bbal);
    setInnerHeart(inbright*rbal,inbright*gbal,inbright*bbal);
    setJewelHeart(jbright*rbal,jbright*gbal,jbright*bbal);

}
void bodiceWave(int effect_position,int startpos,int totalcount,float balance){
  for (int i = 0; i < BODICE_COUNT; i++) {
        int effect_rg = 0;
        int effect_b = 0;
        int rampup=totalcount*balance;
        int rampdown=totalcount-rampup;
        float curpos=float(effect_position-startpos)-(float)bodice[i].delta_heart/(float)(255.0/(float)totalcount);
        if (curpos >= 0.0 && curpos < rampup) {  
          effect_rg=(255 - bodice[i].delta_heart)*(curpos/(float)rampup);
          effect_b=255*(curpos/(float)rampup);
        }
        if (curpos >= rampup && curpos <=totalcount ) {  
          effect_rg=(255 - bodice[i].delta_heart)*(1.0-((float)(curpos-rampup)/(float)rampdown));
          effect_b=255*(1.0-((float)(curpos-rampup)/(float)rampdown));
       }
        bodice[i].setClr( effect_rg, effect_rg, effect_b);
  }
}
void bodiceWave2(int effect_position,int startpos,int totalcount,float balance){
  for (int i = 0; i < BODICE_COUNT; i++) {
        int effect_r = 0;
        int effect_g = 0;
        int effect_b = 0;
        int rampup=totalcount*balance;
        int rampdown=totalcount-rampup;
        float curpos=float(effect_position-startpos)-(float)bodice[i].delta_heart/(float)(255.0/(float)totalcount);
        if (curpos >= 0.0 && curpos < rampup) {  
          effect_g=(255 - bodice[i].delta_heart)*(curpos/(float)rampup);
          effect_r=255*(curpos/(float)rampup);
          effect_b=255*(curpos/(float)rampup);
        }
        if (curpos >= rampup && curpos <=totalcount ) {  
          effect_g=(255 - bodice[i].delta_heart)*(1.0-((float)(curpos-rampup)/(float)rampdown));
          effect_b=255*(1.0-((float)(curpos-rampup)/(float)rampdown));
          effect_r=255*(1.0-((float)(curpos-rampup)/(float)rampdown));
       }
        bodice[i].setClr( effect_r, effect_g, effect_b);
  }
}
#endif //EFFECTS_H
