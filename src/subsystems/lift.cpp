#include "./subsystems/lift.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Lift{
  bool lift_state = false;

  void toggle(){
    lift_state = !lift_state;
    lift.set_value(lift_state);
  }
  void set(bool state){
    lift_state = state;
    lift.set_value(lift_state);
  }
  bool get(){
    return lift_state;
  }
}