#include "main.h"
#include "lemlib/api.hpp"

#define INTAKE_MOTOR 9
#define ARM_MOTOR -1

#define LEFT_FRONT_MOTOR -18
#define LEFT_BACK_MOTOR 19
#define LEFT_TOP_BACK_MOTOR -17

#define RIGHT_FRONT_MOTOR 8
#define RIGHT_BACK_MOTOR -3
#define RIGHT_TOP_BACK_MOTOR 20

#define MATCHLOADER 3
#define LIFT 1
#define WING 2
#define HOOD 4

#define INERTIAL 15
#define MATCHLOADER_SENSOR 13
#define PARK_SENSOR 14
#define ARM_SENSOR 16
#define AI_SENSOR 4

//sensors: colour sensor, inertial sensor, auton selector?

pros::Controller master (pros::E_CONTROLLER_MASTER);

//motors

pros::MotorGroup left_motors ({LEFT_FRONT_MOTOR, LEFT_BACK_MOTOR, LEFT_TOP_BACK_MOTOR}, pros::MotorGear::blue);
pros::MotorGroup right_motors ({RIGHT_FRONT_MOTOR, RIGHT_BACK_MOTOR, RIGHT_TOP_BACK_MOTOR}, pros::MotorGear::blue);
pros::Motor intake_motor (INTAKE_MOTOR, pros::MotorGear::blue);
pros::Motor arm_motor (ARM_MOTOR, pros::MotorGear::red);


//pistons
pros::adi::DigitalOut matchloader (MATCHLOADER);
pros::adi::DigitalOut lift (LIFT);
pros::adi::DigitalOut wing (WING);
pros::adi::DigitalOut hood (HOOD);

//sensors
pros::Imu inertial (INERTIAL);
pros::Optical park_sensor (PARK_SENSOR);
pros::Optical matchloader_sensor (MATCHLOADER_SENSOR);
pros::Rotation arm_sensor (ARM_SENSOR);
pros::Vision ai_sensor (AI_SENSOR);


//lemlib objects
lemlib::Drivetrain drivetrain (&left_motors, &right_motors, 10.428, lemlib::Omniwheel::NEW_325, 450, 2);

//drive curve
lemlib::ExpoDriveCurve throttle_curve(10, // joystick deadband out of 127
                                     15, // minimum output where drivetrain will move out of 127
                                     1 // expo curve gain
);
lemlib::ExpoDriveCurve turn_curve(10, // joystick deadband out of 127
                                     5, // minimum output where drivetrain will move out of 127
                                     1.045 // expo curve gain
);

//rotational
lemlib::ControllerSettings angular_controller(2.2, //kP
                                              0.2, //kIx
                                              15, //kD
                                              7, //anti-windup
                                              0.1, //small error range (in)
                                              1000, //small error timeout (ms)
                                              0, //large error range (in)
                                              500, //large error timeout(ms)
                                              0  //maximum accel
                                              ); 

//front-back OLD
// lemlib::ControllerSettings lateral_controller(6.5,
//                                              0, 
//                                              5.5, 
//                                              5, 
//                                              1, 
//                                              100, 
//                                              0, 
//                                              500, 
//                                              0 //TODO: TUNE SLEW
//                                              );
lemlib::ControllerSettings lateral_controller(6,
                                             .5, 
                                             5.5, 
                                             5, 
                                             1, 
                                             100, 
                                             0, 
                                             500, 
                                             0 //TODO: TUNE SLEW
                                             );

lemlib::ControllerSettings arm_controller(1,
                                          0, 
                                          0.1, 
                                          0, 
                                          0, 
                                          0, 
                                          50, 
                                          0, 
                                          30
                                          );

lemlib::TrackingWheel left_side_imes (&left_motors, lemlib::Omniwheel::NEW_325, -5.8525, 450);
lemlib::TrackingWheel right_side_imes (&right_motors, lemlib::Omniwheel::NEW_325, 5.8525, 450);
lemlib::OdomSensors sensors (&left_side_imes, &right_side_imes, nullptr, nullptr, &inertial);

lemlib::Chassis chassis (drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve, &turn_curve);