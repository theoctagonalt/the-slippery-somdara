#include "./subsystems/arm.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "initialize.h"

namespace Arm{
  int target_state = ARM_0;
  int target_next_state = ARM_0;
  int target_pos;

  int arm_state_values[] = {ARM_0, ARM_1, ARM_2, ARM_3, ARM_4, ARM_5, ARM_6};

  bool pid_enabled = false;
  int max_velocity = 200;

  void score(int vel){
    set_state(6, vel);
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
          arm_motor.brake();
          arm_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }
      }
    }
  }
}