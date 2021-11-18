#include "vec_2d.h"

vec_2d vec_2d::normalized() {
  double vec_len = get_magnitude();
  this->x = this->x / vec_len;
  this->y = this->y / vec_len;
  return vec_2d(x,y);
}

vec_2d vec_2d::operator+(const vec_2d &other) {
  double x = this->x + other.x;
  double y = this->y + other.y;

  return vec_2d(x, y);
}

vec_2d vec_2d::operator-(const vec_2d &other) {
  double x = this->x - other.x;
  double y = this->y - other.y;

  return vec_2d(x, y);
}

vec_2d vec_2d::operator*(double factor) {
  return vec_2d(this->x * factor, this->y * factor);
}

vec_2d vec_2d::operator/(double factor) {
  return vec_2d(this->x / factor, this->y / factor);
}