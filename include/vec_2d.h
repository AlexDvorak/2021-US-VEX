#ifndef VEC_2D_H
#define VEC_2D_H

#include <math.h>

class vec_2d {
  public:
    double x, y;
    vec_2d(double x, double y) : x(x), y(y) {}
    
    vec_2d operator+(const vec_2d &other);
    vec_2d operator-(const vec_2d &other);
    vec_2d operator*(double factor);
    vec_2d operator/(double factor);

    vec_2d normalized();
    double get_magnitude();
    double dot(const vec_2d &other);
  
};

inline double vec_2d::get_magnitude() {
  return sqrt(x*x + y*y);
}

inline double vec_2d::dot(const vec_2d &other) {
  return (this->x * other.x) + (this->y * other.y);
}

#endif