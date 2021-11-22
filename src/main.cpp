// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftDriveMotors      motor_group   1, 10
// RightDriveMotors     motor_group   11, 13
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Vec2D.h"
#include "vex.h"
#include <vector>

vex::competition Competition;

using namespace vex;


/*                        Pre-Autonomous Functions
 *
 * You may want to perform some actions before the competition starts.
 * Do them in the following function.  You must return from this function
 * or the autonomous and usercontrol tasks will not be started.  This
 * function is only called once after the V5 has been powered on and
 * not every time that the robot is disabled.
 */

void pre_auton(void) {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();

    // All activities that occur before the competition starts
    // Example: clearing encoders, setting servo positions, ...
}

void autonomous_drive() {
    // 1 rev ~= 10.2"
    std::vector<std::pair<Position2D, Direction2D>>
        poses; // doubles represent inches
}

void autonomous(void) {}

void usercontrol(void) {
    /* This is the main execution loop for the user control program.
     * Each time through the loop your program should update motor + servo
     * values based on feedback from the joysticks.
     */
    while (1) {
        /* Insert user code here. This is where you use the joystick values to
         * update your motors, etc.
         */
        double rotate = Controller1.Axis1.position(percent);
        double straight = Controller1.Axis3.position(percent);
        spin_(LeftDriveMotors, straight + rotate, percent);
        spin_(RightDriveMotors, straight - rotate, percent);

        wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
    }
}

/* Main will set up the competition functions and callbacks. */
int main() {
    // Set up callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Prevent main from exiting with an infinite loop.
    while (true) {
    }
}

