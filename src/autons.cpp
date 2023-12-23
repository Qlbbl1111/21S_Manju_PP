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
    chassis.follow(drive_to_middle_txt, 15, 2000, true); //current location 33.526, -14.332, 90
    chassis.waitUntilDone();
    //spit out ball twords goal - WORKS
    chassis.turnTo(45, -7, 500); 
    chassis.waitUntilDone();
    intakeMotor = -127;
    pros::delay(500);
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

ASSET(score_pre_wp_txt);
ASSET(descore_touch_close_txt);
void close_WP() {
  chassis.setPose(34, 54, 270); //current location
  //Score preload in goal
  chassis.follow(score_pre_wp_txt, 15, 3000, false); //current location = 56.408, 24.223, 0
  chassis.waitUntilDone();
  //try to knock out ball
  chassis.moveToOld(42.257, 53.346, 5000); //current location
  chassis.waitUntil(15);
  wings.set_value(true);
  chassis.waitUntilDone(); 
  chassis.moveToOld(34.864, 58.89, 5000, true, false, 85); //current location
  chassis.waitUntilDone();
  wings.set_value(false);
  //turn to bar and drive to touch
  chassis.turnTo(-10000, 60, 1000); //current location
  chassis.waitUntilDone();
  intakeMotor = -127;
  chassis.moveToOld(7.477, 58.554, 5000); //current location
  chassis.waitUntilDone();

}

void close_disrupt() {
  chassis.setPose(36, 55, 180); //current location
  //Flick Ball twords goal
  wings.set_value(true);
  pros::delay(500);
  wings.set_value(false);
  pros::delay(500);
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
//.......
}