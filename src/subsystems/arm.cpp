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
  int error_timeout = 0;

  void score(int vel){
    set_state(6, vel);
    target_next_state = 0;
  }
  int counter = 0;
  void set_state(int state, int vel){
    target_state = state;
    max_velocity = vel;
    target_pos = arm_state_values[state];
    pros::lcd::clear_line(1);
    pros::lcd::print(1, "target: %i, pos: %i", target_state, target_pos);
    pid_enabled = true;
    pros::lcd::print(5, "hi, %i", counter);
    counter++;
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


      pros::lcd::clear_line(2);
      pros::lcd::print(2, "%f, %f, %i", current_pos, error, counter); // print info to lcd
      error_timeout = 0; // timeout for error
      double p = error; 

      double vel = arm_controller.kP * p; // sets final motor velocity

      if(vel > max_velocity) vel = max_velocity; // cap velocity to max

      arm_motor.move_velocity(vel); // run motor at calculated velocity

      // pros::lcd::clear_line(0);
      // pros::lcd::print(0, "%f, %f", current_pos, error); // print info to lcd

      if(fabs(error) < 5){
        pid_enabled=false;
        arm_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        arm_motor.brake();
        if(target_next_state != -1){
          set_state(target_next_state, 100);
          target_next_state = -1;
        }
      }
    }
  }
}