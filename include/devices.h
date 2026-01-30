#include "main.h"
#include "lemlib/api.hpp"

#ifndef DEVICES_H_
#define DEVICES_H_

extern pros::Controller master;

extern pros::Motor intake_motor;
extern pros::Motor redirect_motor;
extern pros::Motor exit_motor;
extern pros::Motor arm_motor;
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

extern pros::adi::DigitalOut matchloader;
extern pros::adi::DigitalOut lift;
extern pros::adi::DigitalOut wing;
extern pros::adi::DigitalOut hood;

extern pros::Optical park_sensor;
extern pros::Optical matchloader_sensor;
extern pros::Imu inertial;  
extern pros::AIVision ai_sensor;
extern pros::Rotation arm_sensor;
extern pros::AIVision::Color goal_colour;

extern lemlib::Chassis chassis;
extern lemlib::ControllerSettings arm_controller;
#endif