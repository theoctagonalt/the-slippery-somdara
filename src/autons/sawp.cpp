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

void sawp(){
  chassis.setPose(0, 0, 90);
  chassis.moveToPoint(38, 0, 1000);
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 750);
  Matchloader::toggle();
  Lift::toggle();
  Intake::set_intake(FWD);
  chassis.moveToPoint(38, -15, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(38, -100, 500, {.maxSpeed=20});
  Autonomous::matchload();
  chassis.waitUntilDone();
  chassis.moveToPoint(38, 30, 1000, {.forwards=false, .maxSpeed=75});
  Matchloader::toggle();
  chassis.waitUntilDone();
  pros::delay(100);
  Arm::score(90);
  pros::delay(500);
  chassis.moveToPoint(38, 10, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(10, 25, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-35, 25, 1500);
  chassis.waitUntil(25);
  Matchloader::toggle();
  Lift::toggle();
  chassis.waitUntilDone();
  chassis.moveToPoint(-25, 35, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Arm::score(20, 4);
  pros::delay(1200);
  chassis.moveToPoint(-60, 0, 1000);
  chassis.waitUntilDone();
    chassis.moveToPoint(-60, -15, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-60, -100, 750, {.maxSpeed=40});
  Autonomous::matchload();
  chassis.waitUntilDone();
  Lift::toggle();
  chassis.moveToPoint(-60, 30, 1000, {.forwards=false, .maxSpeed=75});
  Matchloader::toggle();
  chassis.waitUntilDone();
  pros::delay(100);
  Arm::score();
  pros::delay(500);

}