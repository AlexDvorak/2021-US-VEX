#ifndef VEC_2D_H
#define VEC_2D_H

#include <math.h>

class vec_2d{
  double x,y;

  public:
    double get_magnitude {return sqrt(x*x + y*y)}


  
};

vec_2d vec_2d::operator+(const vec_2d &other) {
  double x = this.x + other.x;
  double y = this.y + other.y;

  return vec_2d(x, y)
}
#endif