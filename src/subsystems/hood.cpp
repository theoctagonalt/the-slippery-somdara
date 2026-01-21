#include "./subsystems/hood.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Hood{
  bool hood_state = false;

  void toggle(){
    hood_state = !hood_state;
    hood.set_value(hood_state);
  }
  void set(bool state){
    hood_state = state;
    hood.set_value(hood_state);
  }
  bool get(){
    return hood_state;
  }
}