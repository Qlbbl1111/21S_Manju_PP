#include "main.h"

okapi::ControllerButton flywheelHold(okapi::ControllerDigital::L1);

bool toggleFW = false;
bool latchFW = false;

bool toggleFW2 = false;
bool latchFW2 = false;
/*
void setFlywheel() {
  flywheelMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  //FW Toggle (L2 Button)
  if (flywheelHold.isPressed() && shift()) {
    if (!latchFW) { // if latch false, toggle one time and set latch true
      toggleFW = !toggleFW;
      latchFW = true;
    } else {
      latchFW = false; // once button is released then release the latch too
    }
  }
  else if (flywheelHold.isPressed() && !shift()) {
        if (!latchFW2) { // if latch false, toggle one time and set latch true
      toggleFW2 = !toggleFW2;
      latchFW2 = true;
    } else {
      latchFW2 = false; // once button is released then release the latch too
    }
  }
    //FW Control
  if (toggleFW) {
    //set motors for toggle or press but Dont allow toggle and press
      flywheelMotor = 127;
  } else if (toggleFW2) {
      flywheelMotor = -127;
  } else {
    flywheelMotor = 0;
  }
}
*/

void setFlywheelMotors(double targetVelocity) {
  flywheelMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  //okapi::EmaFilter(1).filter
  double currentVelocity = flywheelMotor.get_actual_velocity();
  double error = targetVelocity - currentVelocity;
  //error = 500 - 450
  //error = -500 - -450
  if (error < 15 && error > 0) {
    flywheelMotor = 100;
  } else if (error >= 15) {
    flywheelMotor = 127;
  }

  if (error < -15 && error < 0) {
    flywheelMotor = -100;
  } else if (error <= -15) {
    flywheelMotor = -127;
  }
  if (targetVelocity == 0) {
    flywheelMotor = 0;
  }
  //pros::lcd::print(6, "Error: %lf\n", error);
}

//bool latch = false;
//bool toggle = false;
//bool latch2 = false;
//bool toggle2 = false;

void setFlywheel() {
  // flywheel
  if (toggleFW && !toggleFW2) {  // slow
    setFlywheelMotors(500);
  } else if (toggleFW2 && !toggleFW) {  // fast
    setFlywheelMotors(-500);
  } else {
    setFlywheelMotors(0);
  }

  if (flywheelHold.isPressed() && shift()) { 
    if (!latchFW) {
      // flip the toggle one time and set the latch
      toggleFW = !toggleFW;
      latchFW = true;
    }
  } else {
    // Once the BumperA is released then then release the latch too
    latchFW = false;
  }
  if (flywheelHold.isPressed() && !shift()) {
    if (!latchFW2) {
      // flip the toggle one time and set the latch
      toggleFW2 = !toggleFW2;
      latchFW2 = true;
    }
  } else {
    // Once the BumperA is released then then release the latch too
    latchFW2 = false;
  }
}
