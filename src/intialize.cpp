#include "main.h"
#include "globals.h"
#include "devices.h"
#include "initialize.h"

int routine = LEFT_SIDE_QUALS;
int colour = RED;

void initialize(){
	pros::lcd::initialize();
  pros::Rotation rotation_sensor(rotation_sensor);
  chassis.calibrate(true);
}
void on_auton_route_cycle(){
  // if last option
  if(routine == SKILLS){
    // go back to first option
    routine = LEFT_SIDE_QUALS;
  }else{
    // cycle through options
    routine++;
  }
  
  // show updated option on lcd
  pros::lcd::print(1, "Auton Route: %s", (routine == LEFT_SIDE_QUALS) ? "Left Side Quals" : (routine == RIGHT_SIDE_QUALS) ? "Right Side Quals" : (routine == LEFT_SIDE_ELIMS) ? "Left Side Elims" : (routine == RIGHT_SIDE_ELIMS) ? "Right Side Elims" : "SKILLS");
}
// colour sort
void on_colour_cycle(){
  colour = !colour;
  pros::lcd::print(2, "Colour: %s", (colour == RED) ? "Red" : "Blue");
}

void competition_initialize(){
  pros::lcd::register_btn0_cb(on_auton_route_cycle);
  pros::lcd::register_btn1_cb(on_colour_cycle);
  // show options/selectors on lcd display
  pros::lcd::print(1, "Auton Route: %s", (routine == LEFT_SIDE_QUALS) ? "Left Side Quals" : (routine == RIGHT_SIDE_QUALS) ? "Right Side Quals" : (routine == LEFT_SIDE_ELIMS) ? "Left Side Elims" : "Right Side Elims");
  pros::lcd::print(0, "Autonomous Selector");  
  pros::lcd::print(2, "Colour: %s", (colour == RED) ? "Red" : "Blue");
}
//troubleshooting
int get_routine(){
  return routine;
}
//troubleshooting
int get_colour(){
  return colour;
}