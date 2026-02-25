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

  // PARK ZONE BLOCKS
  // chassis.setPose(0, 0, 180);
  // Lift::set(EXTENDED);
  // Intake::set_intake(FWD);
  // chassis.moveToPoint(0, -15, 1000, {.minSpeed=100});
  // chassis.waitUntilDone();
  // chassis.setPose(0, -10, 180);
  // chassis.moveToPoint(0, 0, 1000, {.forwards=false});
  // chassis.waitUntilDone();

  
  // chassis.setPose(0, 0, 180);
  // chassis.moveToPoint(0, -13, 1000);
  // chassis.waitUntilDone();
  // chassis.setPose(0, -13, 180);
  // chassis.moveToPoint(0, 0, 1000, {.forwards=false});
  // chassis.waitUntilDone();

  
  // chassis.setPose(0, 0, 180);
  // chassis.moveToPoint(0, -15, 1000);
  // chassis.waitUntilDone();
  // chassis.setPose(0, -13, 180);
  // chassis.moveToPoint(0, 0, 1000, {.forwards=false});
  // chassis.waitUntilDone();

  // chassis.setPose(0, 0, 180);
  // chassis.moveToPoint(0, -15, 1000);
  // chassis.waitUntilDone();
  // chassis.setPose(0, -13, 180);
  // chassis.moveToPoint(0, 0, 1000, {.forwards=false});
  // chassis.waitUntilDone();

  // //RESETTING
  // chassis.moveToPoint(0, -20, 1000);
  // chassis.waitUntilDone();
  // chassis.setPose(0, -13, 180);
  // chassis.moveToPoint(0, 15, 1000, {.forwards=false, .maxSpeed=100,.minSpeed=75});
  // chassis.waitUntilDone();

  // chassis.setPose(0, 15, 180);
  // chassis.moveToPoint(0, 0, 1000, {.maxSpeed=50});
  // chassis.waitUntilDone();
  // pros::delay(1000);

// REST OF RUN

  chassis.setPose(0, 0, 180);
  Lift::set(RETRACTED);
  Intake::set_intake(FWD);

  chassis.moveToPoint(0, 8, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(315, 1000);
  chassis.waitUntilDone();


  chassis.moveToPoint(-20, 25, 1000);
  chassis.waitUntilDone();
  chassis.turnToHeading(225, 1000);
  chassis.waitUntilDone();

//MIDDLE GOAL
  chassis.moveToPoint(-14, 36, 1500, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();
  Hood::toggle();
  Arm::score(70, 6, false);
  pros::delay(1000);

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
  // return;
  //MATCHLOADING

  chassis.moveToPoint(-50, 0, 2000, {.maxSpeed=100});
  pros::delay(200);
  Hood::toggle();
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);
  Intake::set_intake(FWD);
  Matchloader::toggle();
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

  chassis.moveToPoint(-48, 90, 1000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();
  chassis.turnToHeading(0, 1000);
  chassis.waitUntilDone();

  chassis.moveToPoint(-48, 78, 1000, {.forwards=false});
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

  chassis.moveToPoint(-48, 120, 1000, {.maxSpeed=100});
  chassis.waitUntilDone();
  chassis.moveToPoint(-48, 140, 200, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(-48, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  Autonomous::moveRelative(-5, 200, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();

  chassis.moveToPoint(-48, 140, 1000, {.maxSpeed=50});
  chassis.waitUntilDone();
  

  // scoring again
  chassis.moveToPoint(-48, 78, 1000, {.forwards=false});
  chassis.waitUntilDone();
  // chassis.setPose(-49, 83, 0);
  Arm::score(30);
  pros::delay(1000);
  Matchloader::toggle();


  // clear park zone
  chassis.moveToPoint(-49, 91, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-19, 121, 1000, {.minSpeed=75});
  chassis.waitUntil(25);
  Matchloader::toggle();
  chassis.waitUntilDone();
//actually celearing it

  chassis.moveToPoint(23, 123, 4000, {.maxSpeed=100, .minSpeed=75});
  chassis.waitUntilDone();
  chassis.moveToPoint(7, 123, 1000, {.forwards=false, .maxSpeed=50});
  chassis.waitUntilDone();
  chassis.turnToHeading(90, 1000);
  chassis.waitUntilDone();
  chassis.setPose(19, 123, 90);
  Matchloader::set(RETRACTED);
  Lift::set(EXTENDED);

//move to goal

  chassis.moveToPoint(48, 110, 1000);
  chassis.waitUntilDone();
  chassis.turnToHeading(0, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(48, 80, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Arm::score(50);
  pros::delay(500);
  chassis.turnToHeading(0, 1000);

  // chassis.setPose(50, 83, 0);
  Matchloader::set(EXTENDED);
  Lift::set(EXTENDED);
  Intake::set_intake(FWD);
  pros::delay(500);

// matchloading

  chassis.moveToPoint(48, 140, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(48, 200, 1400, {.maxSpeed=50});
  chassis.waitUntilDone();

//go to other side

  chassis.moveToPoint(50, 100, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Matchloader::set(RETRACTED);


  chassis.moveToPoint(64, 100, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.moveToPoint(64, 20, 4000, {.forwards=false, .maxSpeed=100});
  chassis.waitUntilDone();

  //align to long goal

  chassis.moveToPoint(48, 15, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(48, 30, 1000, {.forwards=false});
  chassis.waitUntilDone();
  chassis.turnToHeading(180, 1000);

//scoring
  // chassis.setPose(50, 19, 180);
  Arm::score(50);
  pros::delay(1000);
  Matchloader::set(EXTENDED);

//matchloading
  chassis.moveToPoint(50, -15, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(50, -30, 2000, {.maxSpeed=50});
  chassis.waitUntilDone();

  //scoring again

  chassis.moveToPoint(50, 19, 1000, {.forwards=false});
  chassis.waitUntilDone();
  Arm::score(30);
  pros::delay(1000);

  chassis.setPose(50, 19, 180);
  Matchloader::set(RETRACTED);
  chassis.moveToPoint(50, 9, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(19, -19, 1000);
  chassis.waitUntilDone();
//park

  chassis.moveToPoint(0, -23, 10000, {.maxSpeed=100});
  chassis.waitUntilDone();
}