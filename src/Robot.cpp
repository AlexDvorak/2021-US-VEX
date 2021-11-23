#include "Robot.h"
using namespace units::angle;
using namespace units::length;

/* theta_dot is diff in angle between first and second direction
 * positive theta is clockwise, neg is counterclockwise
 * theta_dot is in radians
 */
Vec2D wheel_speeds_linear(degreet_t theta_dot, Robot robot) {
    // r = track width / 2; theta = theta_dot
    // arc length = r * theta
    inch_t arc_path_len = (0.5 * robot.track_width) * theta_dot;

    // calculate the ratio between left and right wheel speeds
    double speed_left = speed_right = 1;
    if (theta_dot > 0) {
        speed_right = (v_max - arc_path_len) / (v_max + arc_path_len);
    } else if (theta_dot < 0) {
        speed_left = (v_max + arc_path_len) / (v_max - arc_path_len);
    }

    // scale the ratio between speeds to v_max
    return Vec2D(speed_left, speed_right) * v_max;
}
