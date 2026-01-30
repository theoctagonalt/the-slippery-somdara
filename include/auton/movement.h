#include "main.h"
#include "globals.h"
#include "devices.h"
#include "initialize.h"
#include "lemlib/api.hpp"
#include "./subsystems/intake.h"
#include "./subsystems/arm.h"
#include "./subsystems/lift.h"
#include "./subsystems/matchloader.h"
#include "./subsystems/wing.h"
#include "./subsystems/hood.h"

namespace Autonomous{
  void moveRelative(int dist, int timeout, lemlib::MoveToPointParams params);
  void turnRelative();
  void matchload();
  void moveToGoal(bool longGoal);
}

