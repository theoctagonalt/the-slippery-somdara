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

//TODO: Make drivetrain stop @rpm drop

void opcontrol(){
  int game_time = 0;
  bool intake_off_next = false;
  while(true){
    Arm::arm_pid();
    int throttle = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    chassis.arcade(throttle, turn, false, 0.3f);
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
      Intake::toggle();
      Arm::set_state(ARM_0, 50);
    } else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){ //if we detect a new press of R2
      if(Intake::get_intake() == REV){ //if the intake is already outtaking
        Intake::set_intake(OFF); //turn the intake off
      }else{ //if the intake is not outtaking
        Intake::set_intake(REV); //set the intake to outtake
      }
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
      if(!Arm::pid_on()){
        Arm::score();
        if (Intake::get_intake() == OFF  || Intake::get_intake() == REV){
          Intake::set_intake(FWD);
          intake_off_next = true;
        }
      }
    }
    if(intake_off_next && !Arm::pid_on()){
      Intake::set_intake(OFF);
      intake_off_next = false;
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
      Lift::toggle();
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
      Wing::toggle();
    }
    // jams added here
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ // if L2 is held
      if(abs(left_motors.get_actual_velocity()) < 50){
        master.rumble("..."); // short rumble to indicate stop command received
        left_motors.move_velocity(0);
      }
      if(abs(right_motors.get_actual_velocity()) < 50){
        master.rumble("..."); // short rumble to indicate stop command received
        right_motors.move_velocity(0);
      }
    }
    // end of jams
    //game
    if(pros::competition::is_connected() && !pros::competition::is_autonomous()){
      game_time++;
    } 
    if(game_time == 19000){ //rumble controller at 10 seconds left
      master.rumble("--");
    }
    pros::delay(5);
  }
}