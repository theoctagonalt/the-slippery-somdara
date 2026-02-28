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

void skills(){

// REST OF RUN

  chassis.setPose(0, 0, 180);
  Lift::set(RETRACTED);
  Intake::set_intake(FWD);

  chassis.moveToPoint(0, 8, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(315, 1000);
  chassis.waitUntilDone();


  chassis.moveToPoint(-25, 25, 1000);
  chassis.waitUntil(11);
  Matchloader::toggle();
  chassis.waitUntilDone();
  chassis.turnToHeading(225, 1000);
  chassis.waitUntilDone();

//MIDDLE GOAL
  chassis.moveToPoint(-14, 36, 1500, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();
  Hood::toggle();
  Arm::score(20, 6, false);
  pros::delay(1250);

  // Intake::set_intake(FWD);
  // chassis.moveToPoint(-25, 26, 1000);
  // chassis.waitUntilDone();
  // chassis.moveToPoint(-14, 36, 1500, {.forwards=false, .maxSpeed=100});
  // chassis.waitUntilDone();
  // Hood::toggle();
  // Arm::score(10, 6, false);
  // pros::delay(2500);
  
  Lift::toggle();
  Intake::set_intake(OFF);
  //MATCHLOADING

  chassis.moveToPoint(-50, 0, 2000, {.maxSpeed=150});
  pros::delay(200);
  Hood::toggle();
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);
  Intake::set_intake(FWD);
  Matchloader::set(EXTENDED);
  chassis.waitUntilDone();

//ACTUALLY MATCHLOADING

  chassis.moveToPoint(-50, -10, 1000, {.minSpeed=40});
  chassis.waitUntilDone();
  chassis.moveToPoint(-50, -30, 200, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();
  
  chassis.moveToPoint(-50, -30, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();
  
  chassis.moveToPoint(-50, -30, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();

  //going to otehr side
  chassis.moveToPoint(-50, 0, 1000, {.forwards=false});
  chassis.waitUntilDone();

  Matchloader::set(RETRACTED);
  chassis.moveToPoint(-59, 10, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.moveToPoint(-59, 90, 4000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();

//aligning to long goal

  chassis.moveToPoint(-49, 90, 1000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();
  chassis.turnToHeading(0, 1000);
  chassis.waitUntilDone();

  chassis.moveToPoint(-49, 77, 1250, {.forwards=false});
  chassis.waitUntilDone();

// scoring & resetting pos

  pros::delay(100);
  // chassis.setPose(-49, 83, 0);
  Intake::set_intake(FWD);
  Matchloader::set(EXTENDED);
  Lift::set(EXTENDED);
  Arm::score(50);
  pros::delay(500);

// matchloading

  chassis.moveToPoint(-49, 120, 1000, {.maxSpeed=75});
  chassis.waitUntilDone();
  chassis.moveToPoint(-49, 140, 200, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(-49, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(-49, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  

  // scoring again
  chassis.moveToPoint(-49, 78, 1000, {.forwards=false});
  chassis.waitUntilDone();
  // chassis.setPose(-49, 83, 0);
  Arm::score(30);
  pros::delay(1000);
  Matchloader::toggle();


  // clear park zone
  chassis.moveToPoint(-49, 90, 1000);
  chassis.waitUntilDone();
//   chassis.moveToPoint(-19, 118, 1000, {.minSpeed=75});
//   chassis.waitUntil(25);
//   // Matchloader::toggle();
//   chassis.waitUntilDone();
// //actually celearing it

//   chassis.moveToPoint(23, 118, 4000, {.maxSpeed=100, .minSpeed=75});
//   chassis.waitUntilDone();
//   chassis.moveToPoint(4, 122, 1000, {.forwards=false, .maxSpeed=50});
//   chassis.waitUntilDone();
//   chassis.turnToHeading(90, 1000);
//   chassis.waitUntilDone();
//   chassis.setPose(19, 123, 90);
  Matchloader::set(RETRACTED);
  Lift::set(EXTENDED);

//move to goal

  chassis.moveToPoint(50, 95, 3000);
  chassis.waitUntilDone();
  chassis.turnToHeading(0, 1000);
  chassis.waitUntilDone();
  // chassis.moveToPoint(48, 80, 1000, {.forwards=false});
  // chassis.waitUntilDone();
  // Arm::score(50);
  // pros::delay(500);

  // chassis.setPose(50, 83, 0);
  Matchloader::set(EXTENDED);
  Lift::set(EXTENDED);
  Intake::set_intake(FWD);
  pros::delay(500);

// matchloading

  chassis.moveToPoint(49, 120, 1000, {.maxSpeed=75});
  chassis.waitUntilDone();
  chassis.moveToPoint(49, 140, 200, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(49, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(49, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();

//go to other side

  chassis.moveToPoint(50, 110, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Matchloader::set(RETRACTED);


  chassis.moveToPoint(64, 100, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.moveToPoint(64, 20, 4000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();

  //align to long goal

  chassis.moveToPoint(52, 15, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(52, 30, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);

//scoring
  // chassis.setPose(50, 19, 180);
  Arm::score(50);
  pros::delay(1000);
  Matchloader::set(EXTENDED);

//matchloading

  chassis.moveToPoint(52, -10, 1000, {.minSpeed=40});
  chassis.waitUntilDone();
  chassis.moveToPoint(52, -30, 200, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();
  
  chassis.moveToPoint(52, -30, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();
  
  chassis.moveToPoint(52, -30, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  //scoring again

  chassis.moveToPoint(52, 19, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Arm::score(30);
  pros::delay(1000);

  chassis.setPose(52, 19, 180);
  Matchloader::set(RETRACTED);
  chassis.moveToPoint(52, 9, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(19, -19, 1000);
  chassis.waitUntilDone();
//park

  chassis.moveToPoint(0, -23, 10000, {.maxSpeed=100});
  chassis.waitUntilDone();
}