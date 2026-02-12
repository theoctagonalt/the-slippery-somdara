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
#include "./auton/left_side.h"
#include "./auton/sawp.h"
#include "./auton/skills.h"



void screen() {
	
	// loop forever
	while (true) {
		// if(chassis.isInMotion()){
			// get current position of bot and display on screen every 50ms; task 1
			lemlib::Pose pose = chassis.getPose();
			printf("X: %f, Y: %f, Theta: %f\n", pose.x, pose.y, pose.theta);
			pros::lcd::print(1, "X: %f, Y: %f, Theta: %f\n", pose.x, pose.y, pose.theta);
			pros::delay(100);
		}
	// }
}
void update_subsystems() {
	while(pros::competition::is_autonomous()){
		Arm::arm_pid();
		
		pros::delay(5);
	}
}

void autonomous() {
  ai_sensor.reset();
	int route = get_routine();
  ai_sensor.enable_detection_types(pros::AivisionModeType::colors);
  ai_sensor.set_color(goal_colour);
	// start tasks; task 3
	pros::Task screen_task(screen);
	pros::Task subsystems_task(update_subsystems);
	// Autonomous::moveToGoal(true);

	if(route == LEFT_SIDE){
		left_side();
	}else if(route == LEFT_SIDE_MIDDLE){
		left_side_middle();
	}else if(route == SOLO_AWP){
		sawp();
	}else if(route == SKILLS){
		skills();
	}
}