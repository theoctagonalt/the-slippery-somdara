#include "main.h"
#include "globals.h"
#include "devices.h"
#include "initialize.h"

int routine = SKILLS;
int colour = RED;

void initialize(){
	pros::lcd::initialize();
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("\n");
  chassis.calibrate(true);
}
void on_auton_route_cycle(){
  // if last option
  if(routine == SKILLS){
    // go back to first option
    routine = LEFT_SIDE;
  }else{
    // cycle through options
    routine++;
  }
  std::string route_name;
  if(routine == LEFT_SIDE){
    route_name = "Left Side";
  }else if(routine == RIGHT_SIDE){
    route_name = "Right Side";
  }else if(routine == LEFT_SIDE_MIDDLE){
    route_name = "left side middle";
  }else if(routine == RIGHT_SIDE_MIDDLE){
    route_name = "RIGHT side middle";
  }else if(routine == RIGHT_SIDE){
    route_name = "right side";
  }else if(routine == SOLO_AWP){
    route_name = "solo awp";
  }else if(routine == SKILLS){
    route_name = "Skills";
  }
  // show updated option on lcd
  pros::lcd::print(1, "Auton Route: %s", route_name);
}
// colour sort
void on_colour_cycle(){
  colour = !colour;
  pros::lcd::print(2, "Colour: %s", colour == RED ? "Red" : "Blue");
}

void competition_initialize(){
  pros::lcd::register_btn0_cb(on_auton_route_cycle);
  pros::lcd::register_btn1_cb(on_colour_cycle);
  // show options/selectors on lcd display
  std::string route_name;
  if(routine == LEFT_SIDE){
    route_name = "Left Side";
  }else if(routine == RIGHT_SIDE){
    route_name = "Right Side";
  }else if(routine == LEFT_SIDE_MIDDLE){
    route_name = "left side middle";
  }else if(routine == RIGHT_SIDE_MIDDLE){
    route_name = "RIGHT side middle";
  }else if(routine == SOLO_AWP){
    route_name = "solo awp";
  }else if(routine == SKILLS){
    route_name = "Skills";
  }
  pros::lcd::print(1, "Auton Route: %s", route_name);
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