#include "lemlib/asset.hpp"
#include "main.h"
#include "lemlib/api.hpp"

void turnDegrees(double theta, int timeout){
  // sin and cos are reversed here because lemlib treats y as forward 
  double x = 1000000 * (sin(theta * (M_PI / 180.0)) + chassis.getPose().x);
  double y = 1000000 * (cos(theta * (M_PI / 180.0)) + chassis.getPose().y);
  chassis.turnTo(x, y, timeout);
}

void nothing() {
  turnDegrees(90,1000);
  pros::delay(2000);
  turnDegrees(180,1000);
  pros::delay(2000);
  turnDegrees(0,1000);
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
    chassis.moveTo(48, -6, 270, 3000, false);
    intakeMotor = 127;
    chassis.waitUntilDone();
    chassis.follow(touch_bar_txt, 15, 5000, true);
    chassis.waitUntilDone();
    chassis.turnTo(-100000,60, 1000);
    chassis.waitUntilDone();
}

void far_4_ball() {
  //pre load
    chassis.setPose(36, -55, 0);
    intakeMotor = 0;
    chassis.follow(drive_to_middle_txt, 15, 2000, true);
    chassis.waitUntilDone();
    chassis.turnTo(10000, 0, 500);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(500);
    //close middle
    chassis.turnTo(23.5, 0, 500);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(23.5, 0, 1000);
    chassis.waitUntilDone();
    pros::delay(500);
    intakeMotor = 0;
    chassis.turnTo(10000, 0, 1000);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(500);
    intakeMotor = 0;

    //far middle
    chassis.moveToOld(23, 0, 2000);
    chassis.waitUntilDone();
    chassis.turnTo(9, 0,0, 500);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(9, 0, 3000);
    chassis.waitUntilDone();
    pros::delay(500);
    intakeMotor = 0;
    chassis.moveToOld(23, 0, 2000, false);
    chassis.waitUntilDone();
    chassis.turnTo(10000, 0, 1000);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(500);
    intakeMotor = 0;

    //lone ball
    chassis.turnTo(23, -10000, 500);
    chassis.waitUntilDone();
    chassis.moveToOld(23, -23, 1000);
    chassis.waitUntilDone();
    chassis.turnTo(-10000, -23, 1000);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(9, -23, 1000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToOld(23, -23, 1000, false);
    chassis.waitUntilDone();
    intakeMotor = 0;
    chassis.moveToOld(23, -4, 2000);

    //score
    chassis.turnTo(10000, -4, 1000);
    //wings.set_value(true);
    chassis.moveToOld(46, -4, 3000);
    chassis.waitUntilDone();
    chassis.moveToOld(25, -4, 2000, false);
    chassis.waitUntilDone();
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
  //wings.set_value(true);
  chassis.follow(descore_touch_close_txt, 15, 7000, true);
  chassis.waitUntil(21.69);
  //wings.set_value(false);
  chassis.waitUntilDone();
}

void close_disrupt() {

}

void skills() {

}