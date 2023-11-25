#include "main.h"

void setIntake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !shift()) {
    intakeMotor = 127;
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && shift()) {
    intakeMotor = -127;
  } else {
    intakeMotor = 0;
  }
}