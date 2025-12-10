#include "./subsystems/intake.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Intake{
  int intake_state = OFF;
  void toggle(){
    if(intake_state == FWD){
      set_intake(OFF);
    }else{
      set_intake(FWD);
    }
  }
  void set_intake(int state){
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

}