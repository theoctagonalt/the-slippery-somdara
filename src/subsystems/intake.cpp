#include "./subsystems/intake.h"
#include "./subsystems/doublepark.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Intake{
  int intake_state = OFF;
  bool parking = false;
  void toggle(){
    if(intake_state == FWD){
      set_intake(OFF);
    }else{
      set_intake(FWD);
    }
  }
  void set_intake(int state){
    Doublepark::set(RETRACTED);
    if(state == FWD){
      intake_state = FWD;
      intake_motor.move_velocity(600);
    } else if (state == REV){
      intake_state = REV;
      intake_motor.move_velocity(-600);
    } else{
      intake_state = OFF;
      intake_motor.move_velocity(0);
    }
  }

  int get_intake(){
    return intake_state;
  }
  void double_park(){
    parking = true;
    intake_state = REV;
    intake_motor.move_velocity(-200);
  }
  void update_intake(){
    if(parking){
      if(distance.get() < 35){
        intake_state = OFF;
        intake_motor.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
        intake_motor.brake();
        Doublepark::toggle();
        parking=false;

      }
    }
  }
}