#ifndef VEC_2D_H
#define VEC_2D_H

#include <math.h>

class Vec2D {
  public:
    double x, y;
    Vec2D(double x, double y) : x(x), y(y) {}
    
    Vec2D operator+(const Vec2D &other);
    Vec2D operator-(const Vec2D &other);
    Vec2D operator*(double factor);
    Vec2D operator/(double factor);

    Vec2D normalized();
    double get_magnitude();
    double dot(const Vec2D &other);
  
};

inline double Vec2D::get_magnitude() {
  return sqrt(x*x + y*y);
}

inline double Vec2D::dot(const Vec2D &other) {
  return (this->x * other.x) + (this->y * other.y);
}

using Position2D = Vec2D;
using Direction2D = Vec2D;

#endif