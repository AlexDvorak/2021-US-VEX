#pragma once

#include <cmath>

class Vec2D {
  public:
    double x, y;
    Vec2D(double x, double y) : x(x), y(y) {}
    Vec2D() : x(0), y(0) {}

    Vec2D operator+(const Vec2D &other);
    Vec2D operator-(const Vec2D &other);
    Vec2D operator*(double factor);
    Vec2D operator/(double factor);

    Vec2D normalized();
    double get_magnitude();
    double dot(const Vec2D &other);
    double angle();
    double dist(const Vec2D &other);
};

using Position2D = Vec2D;
using Direction2D = Vec2D;

inline double Vec2D::get_magnitude() { return std::sqrt(x * x + y * y); }

inline double Vec2D::dot(const Vec2D &other) {
    return (this->x * other.x) + (this->y * other.y);
}

/**
 * degrees of vector from positive x axis in radians (-pi < theta <= pi)
 */
inline double Vec2D::angle() {
    // arccos[(a · b) / (|a| * |b|)]
    auto reference_angle = Vec2D(1, 0);
    double theta =
        std::acos(this->dot(reference_angle) /
                  (this->get_magnitude() * reference_angle.get_magnitude()));
    if (this->y < 0)
        return -theta;
    else
        return theta;
}
