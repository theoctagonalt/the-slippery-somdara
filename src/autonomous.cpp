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
#include "./auton/movement.h"

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

void autonomous() {
  ai_sensor.reset();
  ai_sensor.enable_detection_types(pros::AivisionModeType::colors);
  ai_sensor.set_color(goal_colour);
	// start tasks; task 3
	pros::Task screen_task(screen);
	pros::Task subsystems_task(update_subsystems);
	chassis.setPose(0, 0, 0);
	Autonomous::moveToGoal(true);
}