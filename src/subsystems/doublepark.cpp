#include "./subsystems/doublepark.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Doublepark{
  bool park_state = false;

  void toggle(){
    park_state = !park_state;
    double_park.set_value(park_state);
  }
  void set(bool state){
    park_state = state;
    double_park.set_value(park_state);
  }
  bool get(){
    return park_state;
  }
}