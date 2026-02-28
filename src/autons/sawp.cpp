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
  chassis.waitUntilDone();
  chassis.moveToPoint(40, -15, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(40, -100, 850, {.maxSpeed=50});
  
  Autonomous::matchload();
  chassis.waitUntilDone();
  chassis.moveToPoint(40, 30, 1000, {.forwards=false, .maxSpeed=75});
  Matchloader::toggle();
  chassis.waitUntilDone();
  pros::delay(100);
  Arm::score(60);
  pros::delay(500);
  chassis.moveToPoint(38, 10, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(10, 25, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-35, 25, 1500);
  chassis.waitUntil(32);
  Matchloader::toggle();
  Lift::toggle();
  chassis.waitUntilDone();
  chassis.moveToPoint(-25, 35, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Arm::score(30, 4);
  pros::delay(750);
  Lift::toggle();
  pros::delay(100);
  chassis.moveToPoint(-63, 0, 1000);
  pros::delay(300);
  Intake::set_intake(FWD);
  chassis.waitUntilDone();
  chassis.moveToPoint(-63, -15, 750);
  chassis.waitUntilDone();
  chassis.moveToPoint(-63, -100, 1000, {.maxSpeed=50});
  
  Autonomous::matchload();
  chassis.waitUntilDone();
  chassis.moveToPoint(-63, 30, 1000, {.forwards=false, .maxSpeed=75});
  chassis.waitUntilDone();
  pros::delay(100);
  Arm::score(60);
  pros::delay(500);

}