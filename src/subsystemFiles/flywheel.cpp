#include "main.h"

okapi::ControllerButton flywheelHold(okapi::ControllerDigital::L1);

bool toggleFW = false;
bool latchFW = false;

void setFlywheel() {
  flywheelMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  //FW Toggle (L2 Button)
  if (flywheelHold.isPressed()) {
    if (!latchFW) { // if latch false, toggle one time and set latch true
      toggleFW = !toggleFW;
      latchFW = true;
    } else {
      latchFW = false; // once button is released then release the latch too
    }
  }
    //FW Control
  if (toggleFW) {
    //set motors for toggle or press but Dont allow toggle and press
    flywheelMotor = 127;
  } else {
    flywheelMotor = 0;
  }
}
