#include "main.h"
#include "pros/adi.hpp"

// DRIVETRAIN
extern pros::Motor left_front_motor;
extern pros::Motor left_back_motor;
extern pros::Motor left_top_motor;
extern pros::Motor right_front_motor;
extern pros::Motor right_back_motor;
extern pros::Motor right_top_motor;

extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

// MOTORS
extern pros::Motor flywheelMotor;
extern pros::Motor liftMotor_a;
extern pros::Motor liftMotor_b;
extern pros::Motor intakeMotor;

// CONTROLLER
extern pros::Controller controller;

// SENSORS
extern pros::Imu inertial;
extern pros::ADIDigitalIn liftLimit;

// PNUEMATICS
extern pros::ADIDigitalOut wings;
extern pros::ADIDigitalOut liftLock;

// LIGHTS
extern sylib::Addrled leftDriveLights;
extern sylib::Addrled rightDriveLights;
extern sylib::Addrled leftWingLights;
extern sylib::Addrled rightWingLights;

// GLOBALS
bool shift();