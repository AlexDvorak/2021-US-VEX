#include "Robot.h"
#include <cmath>

int orientation(Vec2D p1, Vec2D p2, Vec2D p3) {
    double val =
        ((p2.y - p1.y) * (p3.x * p2.x)) - ((p2.x - p1.x) * (p3.y - p2.y));
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

double delta_theta(Vec2D dir1, Vec2D dir2) {
    double theta =
        acos(dir1.dot(dir2) / (dir1.get_magnitude() * dir2.get_magnitude()));
    return theta * orientation(Vec2D(0, 0), dir1, dir2);
}

double Robot::v_max_rotational() {
    double radians_per_sec = (v_max / (wheel_diameter / 2.0));
    return (180 / M_PI) * radians_per_sec;
}

std::vector<Vec2D> Robot::get_path_wheel_distances(std::vector<Pose> path) {
    std::vector<Vec2D> path_distances;
    Pose prev_pose, pose;
    for (size_t i = 1; i < path.size() - 1; i++) {
        pose = path.at(i);
        prev_pose = path.at(i - 1);

        /* Cosine rule: c^2 = 2(a^2) -2(a^2)(cos C)
         * c*c = (2*a*a)(1-(cos C))
         * (c*c) / (1 - cos C) = 2*a*a
         * sqrt(((c*c) / (1-cos C))/2) = a
         * sqrt( (c*c) / 2(1-cos C) ) = a
         */
        double path_straight_dist = prev_pose.position.dist(pose.position);

        double theta_dot = delta_theta(pose.direction(), prev_pose.direction());
        double turn_radius = sqrt((path_straight_dist * path_straight_dist) /
                                  (2 * (1 - cos(theta_dot))));
        double right_dist, left_dist;
        // ccw positive, cw negative
        if (theta_dot > 0) { // right further
            right_dist = theta_dot * (turn_radius + (this->track_width / 2));
            left_dist = theta_dot * (turn_radius - (this->track_width / 2));
        } else if (theta_dot < 0) { // left further
            right_dist = theta_dot * (turn_radius - (this->track_width / 2));
            left_dist = theta_dot * (turn_radius + (this->track_width / 2));
        } else {
            right_dist = path_straight_dist;
            left_dist = path_straight_dist;
        }
        path_distances.push_back(Vec2D(left_dist, right_dist));
    }
    return path_distances;
}

/* theta_dot is diff in angle between first and second direction
 * positive theta is clockwise, neg is counterclockwise
 * theta_dot is in radians
 */
Vec2D Robot::wheel_speeds_linear(double theta_dot) {
    // r = track width / 2; theta = theta_dot
    // arc length = r * theta
    double arc_path_len = (0.5 * this->track_width) * theta_dot;

    double v_max = this->v_max;
    // calculate the ratio between left and right wheel speeds
    double speed_left = 1;
    double speed_right = 1;
    if (theta_dot > 0) {
        speed_right = (v_max - arc_path_len) / (v_max + arc_path_len);
    } else if (theta_dot < 0) {
        speed_left = (v_max + arc_path_len) / (v_max - arc_path_len);
    }

    // scale the ratio between speeds to v_max
    return Vec2D(speed_left, speed_right) * v_max;
}
