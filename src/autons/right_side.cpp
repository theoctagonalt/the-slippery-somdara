#include "main.h"
#include "globals.h"
#include "devices.h"
#include "initialize.h"
#include "lemlib/api.hpp"
#include "./subsystems/intake.h"
#include "./subsystems/arm.h"
#include "./subsystems/lift.h"
#include "./subsystems/matchloader.h"
#include "./subsystems/wing.h"
#include "./subsystems/hood.h"
#include "./auton/movement.h"
bool middle_right = false;
void right_side(){
  chassis.setPose(0, 0, 0);
  Intake::toggle();
  Lift::toggle();
  chassis.moveToPoint(8, 30, 1000);
  chassis.waitUntil(24);
  // Matchloader::toggle();
  chassis.waitUntilDone();
  chassis.moveToPoint(32, 47, 1000);
  pros::delay(250);
  // Matchloader::toggle();
  chassis.waitUntilDone();
  pros::delay(250);
  chassis.moveToPoint(24, 10, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.moveToPoint(39, 20, 1000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 500);
  chassis.waitUntilDone();
  Autonomous::moveRelative(-15, 500, {.forwards=false});
  chassis.waitUntilDone();
  pros::delay(50);
  Arm::score(50);
  pros::delay(500);
  if(!middle_right){
    Autonomous::moveRelative(5, 500, {});
    chassis.waitUntilDone();
    chassis.moveToPoint(52, 15, 1000, {.maxSpeed=75});
    chassis.waitUntilDone();
    chassis.turnToHeading(180, 500);
    chassis.waitUntilDone();
    Autonomous::moveRelative(-33, 3000, {.forwards=false, .maxSpeed=75});
  }


}

//TODO: TO CHAGNE TO RIGHT SIDE
void right_side_middle(){
  middle_right = true;
  right_side();
  Matchloader::toggle();
  Arm::set_state(0);
  Intake::set_intake(FWD);
  chassis.moveToPoint(-35, -5, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-35, -100, 750, {.maxSpeed=50});
  Autonomous::matchload();
  chassis.waitUntilDone();
  chassis.moveToPoint(-35, 10, 500, {.forwards=false});
  Lift::toggle();
  chassis.waitUntilDone();
  chassis.turnToHeading(225, 500);
  chassis.waitUntilDone();
  chassis.moveToPoint(-2, 45, 1500, {.forwards=false});
  chassis.waitUntilDone();
  pros::delay(100);
  Arm::score(50, 6, false);
  Hood::toggle();
  pros::delay(1000);
  Lift::toggle();
  chassis.moveToPoint(-15, 31, 1000);
  pros::delay(500);
  Hood::toggle();
}