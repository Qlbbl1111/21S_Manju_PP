#include "main.h"

okapi::ControllerButton lockButton(okapi::ControllerDigital::down);

bool toggleLock = false;
bool latchLock = false;

void setLift() {
  liftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && shift()) {
        liftMotor = 127;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !shift()) {
        liftMotor = -127;
    } else {
        liftMotor = 0;
  }
}

void setHang() {
  if (toggleLock) {
    hang.set_value(true);
  } else {
    hang.set_value(false);
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
