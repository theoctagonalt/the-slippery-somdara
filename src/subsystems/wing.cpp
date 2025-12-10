#include "./subsystems/wing.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Wing{
  bool wing_state = false;

  void toggle(){
    wing_state = !wing_state;
    wing.set_value(wing_state);
  }
  void set(bool state){
    wing_state = state;
    wing.set_value(wing_state);
  }
  bool get(){
    return wing_state;
  }
}