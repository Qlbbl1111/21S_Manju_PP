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
pros::Motor liftMotor_a(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftMotor_b(7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);
pros::Rotation liftRot(11);

// PNUEMATICS
pros::ADIDigitalOut wings('B');
pros::ADIDigitalOut liftLock('E');
pros::ADIDigitalOut PTO('C');

// LIGHTS
sylib::Addrled leftDriveLights(16,7,43);
sylib::Addrled rightDriveLights(16,8,43);
sylib::Addrled leftWingLights(16,1,20);
sylib::Addrled rightWingLights(16,2,20);

//GLOABALS
bool shift() {
  return controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}

okapi::ControllerButton PTOButton(okapi::ControllerDigital::down);
bool latchPTO = false;
bool togglePTO = false;

bool PTOon() {
  //FW Toggle (L2 Button)
  if (PTOButton.isPressed()) {
    if (!latchPTO) {
      togglePTO = !togglePTO;
      latchPTO = true;
    } else {
      latchPTO = false;
    }
  }
  if (togglePTO) {
    return true;
  } else {
    return false;
  }
}