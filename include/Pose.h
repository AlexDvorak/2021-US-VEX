#pragma once

#include "Vec2D.h"

struct __Pose {
    double theta;   // radians
    Vec2D position; // (in, in)
    Vec2D direction() { return Vec2D(cos(theta), sin(theta)); }
};
typedef __Pose Pose;
