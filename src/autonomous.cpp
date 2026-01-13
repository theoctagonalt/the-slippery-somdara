#include "main.h"
#include "globals.h"
#include "initialize.h"
#include "lemlib/api.hpp"
#include "devices.h"
#include "autonomous.h"
#include "./subsystems/arm.h"
#include "./subsystems/intake.h"
#include "./subsystems/lift.h"
#include "./subsystems/matchloader.h"
#include "./subsystems/wing.h"

void screen() {
	// loop forever
	while (true) {
		// get current position of bot and display on screen every 50ms; task 1
    lemlib::Pose pose = chassis.getPose();
    pros::lcd::print(1, "X: %f, Y: %f, Theta: %f\n", pose.x, pose.y, pose.theta);
    pros::delay(50);
	}
}
void update_subsystems() {
	while(pros::competition::is_autonomous()){
		Arm::arm_pid();
		
		pros::delay(5);
	}
}

//TODO: set params to optional, negative distance?
void move(int dist, int timeout, lemlib::MoveToPointParams params) {
	int theta = 90 - chassis.getPose().theta;
	int x = chassis.getPose().x + dist * cos(theta * (M_PI / 180.0));
	int y = chassis.getPose().y + dist * sin(theta * (M_PI / 180.0));

	chassis.moveToPoint(x, y, timeout, params);
}

void autonomous() {
	// start tasks; task 3
	pros::Task screen_task(screen);
	pros::Task subsystems_task(update_subsystems);
	if(get_routine() == LEFT_SIDE){
		chassis.setPose(0, 0, 0);
		// Lift::toggle();
		Intake::toggle();
		chassis.moveToPoint(-7, 30, 1000, {.maxSpeed=100});
		chassis.waitUntil(20);
		Matchloader::toggle();
		chassis.waitUntilDone();
		pros::delay(750);
		Matchloader::toggle();
		chassis.moveToPoint(-27, 47, 1000, {.maxSpeed=150});
		chassis.waitUntil(8);
		Matchloader::toggle();
		chassis.waitUntilDone();
		chassis.moveToPoint(-10, 33, 1000, {.forwards=false, .maxSpeed=150});
		chassis.waitUntilDone();
		chassis.turnToHeading(-135, 1000);
		chassis.waitUntilDone();
		chassis.moveToPose(1, 38, -135, 2000, {.forwards=false, .maxSpeed=100});
		chassis.waitUntilDone();
		pros::delay(250);
		Arm::set_state(4, 35);
		pros::delay(500);
		Lift::toggle();
		// Matchloader::toggle();
		pros::delay(750);
		chassis.moveToPoint(-32, 10, 1000);
		Arm::set_state(0);
		chassis.waitUntilDone();
		chassis.turnToHeading(180, 500);
		chassis.waitUntilDone();
		chassis.moveToPoint(-32, -8, 1000);
		chassis.waitUntilDone();
		chassis.moveToPoint(-32, -100, 750, {.maxSpeed=50});
		chassis.waitUntilDone();
		chassis.setPose(-31, -2, 180);
		chassis.moveToPose(-31, 40,180, 1000, {.forwards=false, .maxSpeed=100});
		chassis.waitUntilDone();
		pros::delay(750);
		Arm::score();
		pros::delay(100);
		Intake::set_intake(REV);
	}else if(get_routine() == SOLO_AWP){




		chassis.setPose(0, 0, 90);
		Matchloader::toggle();
		Lift::toggle();
		chassis.moveToPoint(37, 0, 1000);
		chassis.waitUntilDone();
		chassis.turnToHeading(180, 750);
		chassis.waitUntilDone();
		Intake::toggle();
		chassis.setPose(40, 0, 180);
		chassis.moveToPoint(40, -10, 1000);
		chassis.waitUntilDone();
		chassis.moveToPoint(40, -100, 1000, {.minSpeed=100});
		chassis.waitUntilDone();
		chassis.setPose(39, -10, 180);
		chassis.moveToPoint(39, 20, 1000, {.forwards=false, .maxSpeed=150});
		chassis.waitUntilDone();
		pros::delay(500);
		Arm::score();
		Matchloader::toggle();
		pros::delay(500);
		Intake::set_intake(REV);
		chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 1000, {.minSpeed=50});
		pros::delay(500);
		Arm::set_state(0);
		Intake::set_intake(FWD);
		chassis.waitUntilDone();
		chassis.moveToPoint(20, 20, 1000);
		chassis.waitUntilDone();
		// Matchloader::toggle();
		chassis.moveToPoint(-27, 27, 1500);
		// chassis.waitUntil(10);
		// Matchloader::toggle();
		chassis.waitUntil(32);
		Matchloader::toggle();
		chassis.waitUntilDone();
		Lift::toggle();
		chassis.turnToHeading(225, 1000);
		chassis.waitUntilDone();
		chassis.moveToPoint(-24, 33, 1000, {.forwards=false, .minSpeed=50});
		chassis.waitUntilDone();
		Arm::set_state(4, 35);
		pros::delay(500);
		chassis.moveToPoint(-55, 10, 1000);
		chassis.waitUntilDone();
		chassis.turnToHeading(180, 1000);
		chassis.waitUntilDone();
		Lift::toggle();
		chassis.moveToPoint(-55, 30, 1000, {.forwards=false});
		chassis.waitUntilDone();
		Arm::score();
	}
}