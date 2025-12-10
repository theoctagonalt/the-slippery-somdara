#ifndef ARM__H__
#define ARM__H__

namespace Arm{
  void score(int vel=50);
  void set_state(int state, int vel = 50);
  int get_state();
  void set_pid(int state);
  void arm_pid();
  bool pid_on();
}

#endif
