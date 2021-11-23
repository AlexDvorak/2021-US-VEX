#pragma once

#include "Vec2D.h"
#include "units.h"
#include <cmath>
using namespace units::length;
using namespace units::velocity;
using namespace units::angular_velocity;

typedef struct {
    inch_t track_width;
    inch_t wheel_diameter;
    feet_per_second_t v_max;
    degrees_per_second_t v_max_rotational() {
        return (degrees_per_second_t) (v_max / (wheel_diameter / 2.0));
    }
} Robot;