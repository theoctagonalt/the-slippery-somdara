#ifndef MOVEMENT__H__
#define MOVEMENT__H__

namespace Autonomous{
  void moveRelative(int dist, int timeout, lemlib::MoveToPointParams params);
  void turnRelative();
  void matchload();
  void moveToGoal(bool longGoal);
}

#endif
