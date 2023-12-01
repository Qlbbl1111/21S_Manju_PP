#include "main.h"

okapi::ControllerButton lockButton(okapi::ControllerDigital::X);

bool toggleLock = false;
bool latchLock = false;

void setLift() {
  liftMotor_b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  liftMotor_a.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::lcd::print(5, "Lift: %f", liftRot.get_position());
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && shift()) {
        liftMotor_b = 127;
        liftMotor_a = 127;
        if (PTOon()) {
        //left_side_motors = -127;
       // right_side_motors = -127;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !shift()) {
        liftMotor_b = -127;
        liftMotor_a = -127;

        if (PTOon()) {
        //left_side_motors = 127;
        //right_side_motors = 127;
        }
    } else {
        liftMotor_b = 0;
        liftMotor_a = 0;
        if (PTOon()) {
        //left_side_motors = 0;
        //right_side_motors = 0;
        }
  }
}

void setLock() {
  if (toggleLock) {
    liftLock.set_value(false);
    leftDriveLights.gradient(0x03fcfc, 0xfc03ec, 0, 0, false, true);
    rightDriveLights.gradient(0x03fcfc, 0xfc03ec, 0, 0, false, true);
  } else {
    liftLock.set_value(true);
  }

  if (lockButton.isPressed()) {
    if (!latchLock) { // if latch false, toggle one time and set latch true
      toggleLock = !toggleLock;
      latchLock = true;
    }
  } else {
    latchLock = false; // once button is released then release the latch too
  }
}

void setPTO() {
  if (PTOon()) {
    PTO.set_value(true);
  } else {
    PTO.set_value(false);
  }

}

