#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "GamePad.h"

//Setings
//#define IMU
#define GAMEPAD

//GYRO
const uint32_t GYRO_CHANNEL = 0; ///<The channel for the gyro

//ENCODER
const uint32_t ENCODER_LR_A = 0; ///<The channel for the left rear encoder
const uint32_t ENCODER_LR_B = 0; ///<The channel for the left rear encoder

const uint32_t ENCODER_LF_A = 0; ///<The channel for the left front encoder
const uint32_t ENCODER_LF_B = 0; ///<The channel for the left front encoder

const uint32_t ENCODER_RR_A = 0; ///<The channels for the right rear encoder
const uint32_t ENCODER_RR_B = 0; ///<Right rear encoder

const uint32_t ENCODER_RF_A = 0; ///<The channels for the right front encdoer
const uint32_t ENCODER_RF_B = 0; ///<Right front encoder

//MOTORS
const uint32_t MOTOR_FR = 2; ///< The channel for the rear left motor
const uint32_t MOTOR_FL = 1; ///< The channel for the front left motor
const uint32_t MOTOR_RR = 3; ///< The channel for the rear right motor
const uint32_t MOTOR_RL = 4; ///< The channel for the front right motor
//const uint32_t MOTOR_LEFT_FEED = 5; // The channel for the front right motor
//const uint32_t MOTOR_RIGHT_FEED = 6; // The channel for the front right motor

const float MOTOR_EXPIRATION = 1000.0f; ///< float measured in milliseconds
const float MOTOR_LOW = 0.4f; ///< If your using gamepad, used for bumper speeds
const float MOTOR_HIGH = 1.0f; ///< If your using gamepad, used for bumper speeds

//INFRARED TODO fix this number
const uint32_t INFRARED = 1; ///< The channel for infrared sensors

//ELEVATOR TODO fix these numbers
const uint32_t ELEVATOR_MOTOR_1 = 6; ///< The channel for the elevator motors
const uint32_t ELEVATOR_MOTOR_2 = -1;
const uint32_t ELEVATOR_TOP_SWITCH = 1; ///< The channel for the top switch of the elevator
const uint32_t ELEVATOR_BOTTOM_SWITCH = 1; ///< The channel for the bottom switch of the elevator
const uint32_t ELEVATOR_ENCODER_A = 1; ///< The channels for the elevator encoder
const uint32_t ELEVATOR_ENCODER_B = 2; ///< The channels for the elevator encoder
const uint32_t LEFT_FEED_MOTOR = 5;
const uint32_t RIGHT_FEED_MOTOR = 7;

const uint32_t LEFT_IR  = 1;
const uint32_t RIGHT_IR = 2;

//IMU
const uint32_t SERIAL_PORT = 0; ///< port for IMU
const uint8_t REFRESH_RATE = 50;

const float CRATE_HEIGHT = 12.0f; ///<Height of the crate
const float BUFFER       = 2.0f;

const uint32_t ELEVATOR_ULTRASONIC = 0;
const uint32_t ELEVATOR_IR = 3;

const float MAX_IR    = 60.0f; ///< Max IR value to stay accurate (this value (ironically) is inaccurate)
const float MIN_ULTRA = 20.0f; ///< Minimum value ultrasonic is accurate (this value is innacurate)

const float ELEV_SPEED_FLOAT = 0.8f; ///< Arbitrary speed that we used (float)
const double ELEV_SPEED_DOUBLE = 0.8; ///< Never used, just double version of ELEV_SPEED_FLOAT

const int ELEVATOR_TOLERANCE = 50;

//JOYSTICK
static const float DEADZONE = 0.1f; ///< The value for the joystick deadzone
static const float THROTTLE = 1.0f;  ///< The value for the joystick throttle

static const uint32_t DRIVER_JOY = 0; ///< The channels for the driver joystick
static const uint32_t GUNNER_JOY = 1; ///< The channels for the gunner joystick
#ifdef GAMEPAD
static const uint32_t LEFT_X  = 1; ///< port for left joystick, x axis IF GAMEPAD
static const uint32_t LEFT_Y  = 0; ///< port for left joystick, y axis IF GAMEPAD
static const uint32_t RIGHT_X = 4; ///< port for right joystick, x axis IF GAMEPAD
static const uint32_t RIGHT_Y = 5;

#else

static const uint32_t LEFT_X  = 0; ///< port for left joystick, x axis IF GAMEPAD
static const uint32_t LEFT_Y  = 1; ///< port for left joystick, y axis IF GAMEPAD
static const uint32_t RIGHT_X = 2; ///< port for right joystick, x axis IF GAMEPAD

static const uint32_t SLIDER = 3;
#endif

//TESTING
static const uint32_t BUTTON_A = 1; ///< port for A button on xbox controller
static const uint32_t BUTTON_B = 2; ///< port for B button on xbox controller
static const uint32_t BUTTON_X = 3; ///< port for X button on xbox controller
static const uint32_t BUTTON_Y = 4; ///< port for Y button on xbox controller
static const uint32_t BUTTON_LB = 5;///< port for Right Bumper
static const uint32_t BUTTON_RB = 6; ///< port for left bumper on xbox controller

const uint32_t SOLENOIDCHAN1 = 0; ///< Solenoid channel, innacurate
const uint32_t SOLENOIDCHAN2 = 1; ///< Other solenoid channel, innacurate
const uint32_t TIMER_VALUE = 1.1;

const uint32_t PCM = 0; ///< Value for new pneumatic (not necessary)

#endif
