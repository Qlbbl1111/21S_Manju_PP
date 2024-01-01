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
}

ASSET(drive_to_middle_txt);
ASSET(touch_bar_txt);
void far_2_ball_WP() {
    chassis.setPose(36, -55, 0); //current location
    chassis.follow(drive_to_middle_txt, 15, 3000, true); //current location 33.526, -14.332, 90
    chassis.waitUntilDone();
    //spit out ball twords goal - WORKS
    chassis.turnTo(48.4, -12.8, 1000);
    chassis.waitUntilDone();
    intakeMotor = -127;
    chassis.moveToOld(48.425, -12.853, 3000);
    chassis.waitUntilDone();
    //get mid
    chassis.moveToOld(36, -13, 3000, false);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.turnTo(23, 0, 1000);
    chassis.waitUntilDone();
    chassis.moveToOld(26, -5, 3000, true);
    chassis.waitUntilDone();
    //score in goal
    chassis.turnTo(1000, 0, 1000);
    chassis.waitUntilDone();
    intakeMotor = 0;
    wings.set_value(true);
    chassis.moveToOld(48, 0, 3000);
    chassis.waitUntilDone();
    chassis.moveToOld(35, 0, 3000, false);
    chassis.waitUntilDone();
    wings.set_value(false);
    pros::delay(250);
    /*
    //get bar
    chassis.turnTo(-1000, 0, 1000);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(11, 0, 3000);
    chassis.waitUntilDone();
    chassis.moveToOld(35, 0, 3000, false);
    chassis.waitUntilDone();
    intakeMotor = 0;
    //score
    chassis.turnTo(1000, 0, 1000);
    chassis.waitUntilDone();
    wings.set_value(true);
    chassis.moveToOld(48, 0, 3000);
    chassis.waitUntilDone();
    chassis.moveToOld(35, 0, 3000, false);
    chassis.waitUntilDone();
    wings.set_value(false);
    */


    /*
    //get mid ball - WORKS
    chassis.turnTo(23.5, 0, 500);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(23.5, 0, 1000); //current location
    chassis.waitUntilDone();
    pros::delay(500);
    intakeMotor = 0;
    //score balls - WORKS
    chassis.moveTo(47, -6, 90, 2000); //current location
    chassis.waitUntilDone();
    //drive to pipe - DOESNT WORK
    chassis.moveTo(30, -6, 90, 1000); //current location
    chassis.waitUntilDone();
    chassis.follow(touch_bar_txt, 12, 5000, true); //current location 6.789, -58.419, 270
    chassis.waitUntilDone();
    chassis.turnTo(-100000,60, 1000);
    chassis.waitUntilDone();
    */
}

ASSET(get_bar_ball_txt);
void far_5_ball() {
  //pre load - WORKS 90%
    chassis.setPose(48, -57, 325); //current location
    wings.set_value(true);
    pros::delay(200);
    wings.set_value(false);
    //mid bar ball - WORKS 90%
    intakeMotor = 127;
    chassis.moveToOld(10, -6, 2000); //current location
    chassis.waitUntilDone();

    //score 2 mid balls - WORKS 80%
    chassis.turnTo(10000, -4, 1000);
    chassis.waitUntilDone();
    wings.set_value(true);
    intakeMotor = -127;
    chassis.moveToOld(45, -4, 1000); //current location
    chassis.waitUntilDone();
    wings.set_value(false);

    //get lone bar ball - DOESNT WORK
    chassis.moveToOld(23, -4, 1500, false); //current location
    chassis.waitUntilDone();
    chassis.turnTo(4, -23, 1000);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(8, -19, 2000); //current location
    chassis.waitUntilDone();

    //drive to corner - KINDA WORKS 40%
    chassis.turnTo(47, -74, 1000);
    chassis.waitUntilDone(); 
    intakeMotor = 0;
    chassis.moveToOld(47, -47, 2500, true); //current location
    chassis.waitUntilDone();  

    //eject ball - BROKEN
    intakeMotor = -127;
    pros::delay(500);
    intakeMotor = 0;

    //get elevation bar ball -BROKEN
    /**/
    chassis.turnTo(38, -56, 1000);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveTo(6, -56, 270, 2500); //current location
    chassis.waitUntilDone();
    chassis.moveTo(40, -55, 40, 2000, false); //current location
    chassis.waitUntilDone();
    intakeMotor = 0;

    //score on side - BROKEN
    //chassis.turnTo(57, -24, 1000);
    //chassis.waitUntilDone();
    wings.set_value(true);
    intakeMotor = -127;
    chassis.moveToOld(59, -22, 0, 6000); //current location
    chassis.waitUntilDone();
}

void far_3_ball() {
  //pre load - WORKS
    chassis.setPose(36, -55, 0);
    intakeMotor = 0;
    chassis.follow(drive_to_middle_txt, 15, 2000, true);
    chassis.waitUntilDone();
    chassis.turnTo(10000, 0, 1000, true, 100);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(750);

    //close middle - WORKS
    chassis.turnTo(23.5, 0, 750);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(23.5, 0, 1000);
    chassis.waitUntilDone();
    pros::delay(500);
    intakeMotor = 0;
    chassis.turnTo(10000, 0, 750);
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(750);
    intakeMotor = 0;

    //far middle - WORKS
    chassis.moveToOld(23, 0, 2000);
    chassis.waitUntilDone();
    chassis.turnTo(9, 0,0, 750);
    chassis.waitUntilDone();
    intakeMotor = 127;
    chassis.moveToOld(9, 0, 2500);
    chassis.waitUntilDone();
    pros::delay(750);
    intakeMotor = 0;
    chassis.moveToOld(23, -4, 2000, false);
    chassis.waitUntilDone();

    //score - PROB WORKS
    chassis.turnTo(10000, -4, 750);
    chassis.waitUntilDone();
    intakeMotor = -127;
    wings.set_value(true);
    chassis.moveToOld(47, -4, 1500);
    chassis.waitUntilDone();
    chassis.moveToOld(30, -4, 1000, false);
    chassis.waitUntilDone();
}

ASSET(scoreprenew_txt);
ASSET(touch_bar_comp_txt);
void close_WP() {
  chassis.setPose(44, 55, 315); //current location
  intakeMotor = 127;
  chassis.moveToOld(51, 48, 5000, false);
  chassis.waitUntilDone();
  intakeMotor = 0;
  wings.set_value(true);
  chassis.moveToOld(44, 55, 5000);
  chassis.waitUntilDone();
  pros::delay(500);
  wings.set_value(false);
  //chassis.follow(scoreprenew_txt, 15, 5000, false);
  //chassis.waitUntilDone();
  intakeMotor = -127;
  chassis.follow(touch_bar_comp_txt, 15, 5000, true);
  chassis.waitUntilDone();
  chassis.turnTo(-1000, 59, 1000);
  chassis.waitUntilDone();
}

void close_disrupt() {
  chassis.setPose(36, 55, 180); //current location
  //Flick Ball twords goal
  wings.set_value(true);
  pros::delay(250);
  wings.set_value(false);
  //Drive halfway to middle ball
  chassis.moveToOld(27, 23, 3000, true); //current location
  chassis.waitUntilDone();
  //drive to mid ball and intake and open Wings
  wings.set_value(true);
  intakeMotor = 127;
  chassis.moveToOld(23, 10, 7000, true); //current location
  chassis.waitUntilDone();
}

void skills() {
  chassis.setPose(-37, -53, 90);
  chassis.moveToOld(-51.834, -53.514, 5000, false);
  chassis.waitUntilDone();
  chassis.turnTo(42.929, 39.232, 1000);
  chassis.waitUntilDone();
  chassis.moveToOld(-56.834, -56.514, 5000, false);
  chassis.waitUntilDone();
  liftMotor = -127;
  setFlywheelMotors(500);
}