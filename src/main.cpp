#include "main.h"
#include "globals.h"
#include "devices.h"
#include "initialize.h"
#include "lemlib/api.hpp"
#include "autonomous.h"
#include "./subsystems/intake.h"
#include "./subsystems/arm.h"
#include "./subsystems/lift.h"
#include "./subsystems/matchloader.h"
#include "./subsystems/wing.h"
#include "./subsystems/hood.h"
#include "./subsystems/doublepark.h"

//TODO: Make drivetrain stop @rpm drop
void opcontrol(){
  // printf("\n");
  bool check = false; //jams
  int game_time = 0;
  pros::Task screen_task(screen);
  while(true){
    Arm::arm_pid();
    Intake::update_intake();
    int throttle = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    chassis.arcade(throttle, turn, false, 0.3f);
    
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
      Intake::toggle();
      Arm::set_state(0);
    } else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){ //if we detect a new press of R2
      if(Intake::get_intake() == REV){ //if the intake is already outtaking
        Intake::set_intake(OFF); //turn the intake off
      }else{ //if the intake is not outtaking
        Intake::set_intake(REV); //set the intake to outtake
      }
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
      Hood::toggle();
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
      Arm::score(50);
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){
      Arm::score(30);
    }
    if(master.get_digital_new_release(pros::E_CONTROLLER_DIGITAL_X)){
      Arm::set_state(0);
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
      Arm::score(100);
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
      Lift::toggle();
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
      Wing::toggle();
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
      Intake::double_park();
      Matchloader::set(false);
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
      Matchloader::toggle();
    }
    if(pros::competition::is_connected() && !pros::competition::is_autonomous()){
      game_time++;
    } 
    if(game_time == 19000){ //rumble controller at 10 seconds left
      master.rumble("--");
    }
    pros::delay(5);
  }
}