#ifndef ARM__H__
#define ARM__H__

namespace Arm{
  void score(int vel=100, int state=6, bool hoodP=true);
  void set_state(int state, int vel = 100);
  int get_state();
  void set_pid(int state);
  void arm_pid();
  bool pid_on();
}

#endif
