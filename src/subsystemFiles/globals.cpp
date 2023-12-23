#include "main.h"

// DRIVETRAIN
pros::Motor left_front_motor(10, pros::E_MOTOR_GEARSET_06, true); 
pros::Motor left_back_motor(9, pros::E_MOTOR_GEARSET_06, true); 
pros::Motor left_top_motor(8, pros::E_MOTOR_GEARSET_18, true); 
pros::Motor right_front_motor(3, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor right_back_motor(2, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor right_top_motor(1, pros::E_MOTOR_GEARSET_18, false); 

pros::MotorGroup left_side_motors({left_front_motor, left_back_motor, left_top_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor, right_top_motor});

// MOTORS
pros::Motor flywheelMotor(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeMotor(4, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftMotor(7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);
pros::Rotation liftRot(11);

// PNUEMATICS
pros::ADIDigitalOut hang('C');
pros::ADIDigitalOut wings('B');

// LIGHTS
sylib::Addrled leftDriveLights(6,7,43);
sylib::Addrled rightDriveLights(6,8,43);
sylib::Addrled leftWingLights(6,1,20);
sylib::Addrled rightWingLights(6,2,20);
sylib::Addrled intakeLights(6,6,32);

//GLOABALS
bool shift() {
  return controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}