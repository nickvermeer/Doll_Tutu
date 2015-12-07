#ifndef POINT_H
#define POINT_H
#include <math.h>

class Point {
  public:
    Point();
    Point(uint16_t nx,uint16_t ny);
    float distance(Point p);
    uint16_t x,y;
};
Point::Point(){
  x=0;
  y=0;
}
Point::Point(uint16_t nx,uint16_t ny){
  x=nx;
  y=ny;
}
float Point::distance(Point p){
  int dx2=pow(p.x-x,2);
  int dy2=pow(p.y-y,2);
  return sqrt(dx2+dy2);
}

#endif
