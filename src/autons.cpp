#include "main.h"
#include "lemlib/api.hpp"


void nothing() {
  // do nothing
}
ASSET(drive_to_middle_txt);
ASSET(touch_bar_txt);
void far_2_ball_WP() {
    chassis.setPose(36, -55, 0);
    intakeMotor = 0;
    chassis.follow(drive_to_middle_txt, 15, 2000, true);
    chassis.waitUntilDone();
    chassis.turnTo(45, -7, 500);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(1000);
    chassis.turnTo(23.5, 0, 500);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(23.5, 0, 1000);
    chassis.waitUntilDone();
    pros::delay(750);
    intakeMotor = 0;
    chassis.moveTo(45, -6, 90, 2000);
    chassis.waitUntilDone();
    intakeMotor = -127;
    chassis.moveTo(20, -6, 90, 2000,false);
    chassis.waitUntilDone();
    intakeMotor = 0;
    chassis.turnTo(-55, -6, 1000);
    chassis.waitUntilDone();
    chassis.moveTo(47, -6, 270, 3000, false);
    intakeMotor = 127;
    chassis.waitUntilDone();
    chassis.follow(touch_bar_txt, 15, 5000, true);
    chassis.waitUntilDone();
}

void far_4_ball() {

}
ASSET(score_pre_wp_txt);
ASSET(descore_touch_close_txt);
void close_WP() {
  chassis.setPose(38.639, 54, 270);
  chassis.follow(score_pre_wp_txt, 15, 3000, false);
  //chassis.moveTo(57, 35, 180, 2000, false);
  //chassis.waitUntilDone();
  //chassis.moveTo(57, 30, 180, 2000, true);
  chassis.waitUntilDone();
  chassis.moveTo(57.162, 42.997, 0, 2000, true);
  chassis.waitUntilDone();
  controller.rumble(".");
  chassis.follow(descore_touch_close_txt, 15, 7000, true);
  chassis.waitUntil(21.69);
  controller.rumble("..");
  chassis.waitUntilDone();
}

void close_disrupt() {

}

void skills() {

}