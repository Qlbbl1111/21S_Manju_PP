#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"

int curve(int input) {
    double t = 7;
    return (exp(-(t/10))+exp((abs(input)-127)/10)*(1- exp(-(t/10))))*input;
}

void reset_drive_sensor(){
    left_front_motor.tare_position();
    right_front_motor.tare_position();  
}
void set_tank(int left, int right) {
    left_side_motors = left;
    right_side_motors = right;
}

float active_brake_kp = 2;
void driveControl(int l_stick, int r_stick) {
        //left side
        if (abs(l_stick) > 5) { // Threshold if joysticks don't come back to perfect 0
            left_side_motors = curve(l_stick);
            if (active_brake_kp != 0) left_front_motor.tare_position();
        }
        //When joys are released, run active brake (P) on drive left
        else {
            left_side_motors = (0 - left_front_motor.get_position()) * active_brake_kp;
        }
        //right side
        if (abs(r_stick) > 5) { // Threshold if joysticks don't come back to perfect 0
            right_side_motors = curve(r_stick); 
            if (active_brake_kp != 0) right_front_motor.tare_position(); 
        }
        //When joys are released, run active brake (P) on drive right
        else {
            right_side_motors = (0 - right_front_motor.get_position()) * active_brake_kp;
        }
}

lemlib::Drivetrain drivetrain {
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    10.5, // track width
    lemlib::Omniwheel::OLD_275, // wheel diameter
    450, // wheel rpm
    2
};

// odometry struct
lemlib::OdomSensors sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial // inertial sensor
};
 
// lateral motion controller
lemlib::ControllerSettings linearController(
    50, // proportional gain (kP)
    37, // derivative gain (kD)
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    10 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(
    3, // proportional gain (kP)
    23, // derivative gain (kD)
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);
 
 
// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);