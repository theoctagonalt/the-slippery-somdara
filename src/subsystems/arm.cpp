#include "./subsystems/arm.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "initialize.h"
#include "./subsystems/intake.h"
#include "./subsystems/hood.h"

namespace Arm{
  int target_state = ARM_0;
  int target_next_state = ARM_0;
  int target_pos;
  bool intake_rev_next = false;
  bool intake_fwd_next = false;

  int arm_state_values[] = {ARM_0, ARM_1, ARM_2, ARM_3, ARM_4, ARM_5, ARM_6};

  bool pid_enabled = false;
  int max_velocity = 200;
  bool scoring = false;
  bool hood;

  void score(int vel, bool hood){
    set_state(6, vel);
    hood = hood;
    scoring = true;
    Intake::set_intake(FWD);
    intake_rev_next = true;
    if(hood){
      Hood::set(EXTENDED);
    }
  }


  void set_state(int state, int vel){
    target_state = state;
    target_pos = arm_state_values[state];
    max_velocity = vel;
    pid_enabled = true;
  }
  int get_state(){
    return target_state;
  }
  void set_pid(int state){
    pid_enabled = state;
  }
  bool pid_on(){
    return pid_enabled;
  }
  void set_max_velocity(int velocity){
    max_velocity = velocity;
  }
  void arm_pid(){
    if(pid_enabled){
      double current_pos = arm_sensor.get_angle() / 100.0; // convert to degrees
      double error = target_pos - current_pos; // calculate error - how far from target we are

      double vel = error * arm_controller.kP; // P term

      if(vel > max_velocity) vel = max_velocity;
      if(vel < -max_velocity) vel = -max_velocity;

      arm_motor.move_velocity(vel);

      if(fabs(error) < 5){
        if(target_state != 0){
          set_state(0);
        }else{
          pid_enabled = false;
          scoring = false;
          arm_motor.brake();
          arm_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
          if(hood){
            Hood::set(RETRACTED);
          }
        }
      }
    }
    if(scoring && intake_rev_next && arm_sensor.get_angle() < 12000){
      intake_rev_next = false;
      intake_fwd_next = true;
      Intake::set_intake(REV);
    }
    if(scoring && intake_fwd_next && arm_sensor.get_angle() > 12000){
      Intake::set_intake(FWD);
      intake_fwd_next = false;
    }
  }
}