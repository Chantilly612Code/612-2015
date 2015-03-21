#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <AnalogInput.h>
#include <CANTalon.h>
#include <include/IMU.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	//bool useIR = false;

	AnalogInput* ir;
	//Ultrasonic* ultra;
	//AnalogInput* infrared;

	//Encoder* encoderLR;
	//Encoder* encoderLF;
	//Encoder* encoderRR;
	//Encoder* encoderRF;

	bool useIR = false;
	//bool SwitchSensor(float distance); // Called in CheckSensor

public:
	Drivetrain(CANTalon* fl, CANTalon* fr, CANTalon* rf,CANTalon* rr, AnalogInput* infrared);
	void InitDefaultCommand();

	//void CheckSensor(float distance);
	void move(float x, float y, float rotation);
	void stop();
	int16_t getir();

	//Encoder Methods
	enum MotorLocation {LEFT_FRONT, LEFT_REAR, RIGHT_FRONT, RIGHT_REAR}; //For use in getDistance
	//void resetEncoders(); //Resets ALL encoders
	int32_t getDistance(MotorLocation location); //Gets the distance of a specific  motor
	void SetRightFeedWheel(float speed);
	void SetLeftFeedWheel(float speed);

	CANTalon* fl;
	CANTalon* rl;
	CANTalon* fr;
	CANTalon* rr;
	CANTalon* leftFeedWheel;
	CANTalon* rightFeedWheel;

	float motor_power;

	IMU* imu;
};

#endif
