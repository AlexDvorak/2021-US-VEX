#pragma once

#include "Vec2D.h"
#include <cmath>

struct __Robot {
    double track_width;    // in
    double wheel_diameter; // in
    double v_max;          // in per sec
    double v_max_rotational() {
        double radians_per_sec = (v_max / (wheel_diameter / 2.0));
        return (180 / M_PI) * radians_per_sec;
    }
};
typedef __Robot Robot;
