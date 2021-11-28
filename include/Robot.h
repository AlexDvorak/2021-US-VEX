#pragma once

#include "Pose.h"
#include "Vec2D.h"
#include <vector>

struct __Robot {
    double track_width;                          // in
    double wheel_diameter;                       // in
    double v_max;                                // in per sec
    double v_max_rotational();                   // degrees per sec
    Vec2D wheel_speeds_linear(double theta_dot); // (left, right) in per sec
    std::vector<Vec2D> get_path_wheel_distances(
        std::vector<Pose> path); // (left, right) in per sec
};
typedef __Robot Robot;
