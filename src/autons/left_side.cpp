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

void left_side(){
  chassis.setPose(0, 0, 0);
  Intake::toggle();
  Lift::toggle();
  chassis.moveToPoint(-8, 30, 1000);
  chassis.waitUntil(24);
  Matchloader::toggle();
  chassis.waitUntilDone();
  chassis.moveToPoint(-31, 48, 1000);
  pros::delay(100);
  Matchloader::toggle();
  chassis.waitUntilDone();
  chassis.moveToPoint(-20, 30, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.swingToPoint(-29, 30, lemlib::DriveSide::LEFT, 1000, {.forwards=false});
  chassis.waitUntilDone();
  pros::delay(50);
  Arm::score(50);
  pros::delay(500);
  chassis.moveToPoint(-18, 20, 1000);
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 500);
  chassis.waitUntilDone();
  Autonomous::moveRelative(-24, 1500, {.forwards=false, .maxSpeed=50});
}