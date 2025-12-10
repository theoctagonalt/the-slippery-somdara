#include "main.h"
#include "globals.h"
#include "initialize.h"
#include "lemlib/api.hpp"
#include "devices.h"
#include "autonomous.h"

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
		// update auton subsystems every 5ms; task 2
		pros::delay(5);
	}
}

void autonomous() {
	// start tasks; task 3
	pros::Task screen_task(screen);
	pros::Task subsystems_task(update_subsystems);
}