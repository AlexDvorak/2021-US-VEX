#include "vec_2d.h"

Vec2D Vec2D::normalized() {
    double vec_len = get_magnitude();
    this->x = this->x / vec_len;
    this->y = this->y / vec_len;
    return Vec2D(x, y);
}

Vec2D Vec2D::operator+(const Vec2D &other) {
    double x = this->x + other.x;
    double y = this->y + other.y;

    return Vec2D(x, y);
}

Vec2D Vec2D::operator-(const Vec2D &other) {
    double x = this->x - other.x;
    double y = this->y - other.y;

    return Vec2D(x, y);
}

Vec2D Vec2D::operator*(double factor) {
    return Vec2D(this->x * factor, this->y * factor);
}

Vec2D Vec2D::operator/(double factor) {
    return Vec2D(this->x / factor, this->y / factor);
}