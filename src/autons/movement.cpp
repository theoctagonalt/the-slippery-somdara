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
  //TODO: set params to optional, negative distance?
  void moveRelative(int dist, int timeout, lemlib::MoveToPointParams params) {
    int theta = 90 - chassis.getPose().theta;
    int x = chassis.getPose().x + dist * cos(theta * (M_PI / 180.0));
    int y = chassis.getPose().y + dist * sin(theta * (M_PI / 180.0));

    chassis.moveToPoint(x, y, timeout, params);
  }
  void turnRelative(){

  }

  void matchload(){

  }

  void moveToGoal(bool longGoal){
    while(true){
      auto objects = ai_sensor.get_all_objects();
      int objectX = 0;
      int objectY = 0;
      int objectW = 0;
      int objectH = 0;

      int largestArea = 0;

      for(auto &object : objects){
        if(pros::AIVision::is_type(object, pros::AivisionDetectType::color)){
          int thisX = (int) object.object.color.xoffset;
          int thisY = (int) object.object.color.yoffset;
          int thisW = (int) object.object.color.width;
          int thisH = (int) object.object.color.height;
          int thisArea = thisW*thisH;
          if(thisArea > largestArea){
            largestArea = thisArea;
            objectX = (thisX + (thisW/2));
            objectY = (thisY + (thisH/2));
            objectW = thisW;
            objectH = thisH;
            // printf("%i, %i, %i, %i\n", thisX, thisY, thisW, thisH);
            // printf("%i, %i, %i, %i\n=\n", objectX, objectY, objectW, objectH);

          }
        }
      }
      int error = objectX - 160;
      printf("%i\n", largestArea);
      int throttle = largestArea;
      int rotation = error;
      printf("%i,  %i, %d, %i\n", error, throttle, rotation, largestArea);
      printf("%i, %i, %i, %i\n", objectX, objectY, objectW, objectH);
      printf("=====\n");
      chassis.arcade(-75, rotation);
      // chassis.arcade(-throttle, rotation);
      pros::delay(100);
    }
    return;
  }

  void matchloadUntil(int colour){
    Intake::set_intake(FWD);    
    int current_colour = -1;
    bool cont = true;
    while(cont){
      if(matchloader_sensor.get_hue() < RED_HUE_MAX && matchloader_sensor.get_hue() > RED_HUE_MIN){ //if we see red
        current_colour = RED;
      }else if(matchloader_sensor.get_hue() < BLUE_HUE_MAX && matchloader_sensor.get_hue() > BLUE_HUE_MIN){ //if we see blue
        current_colour = BLUE;
      }
      if(current_colour != colour){
        cont = false;
      }
      pros::delay(100);
    }
    Intake::set_intake(REV);
    pros::delay(50);
    Intake::set_intake(OFF);
  }
}

