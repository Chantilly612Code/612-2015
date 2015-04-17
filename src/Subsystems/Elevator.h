#ifndef LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_
#define LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_

#include "WPILib.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>
#include <TalonSRX.h>

class Elevator : public Subsystem {
private:
	CANTalon* elevTalon;
	CANTalon* test;
	//DigitalInput* topSwitch;
	//DigitalInput* bottomSwitch;
	//Encoder* elevEncoder;
	//AnalogInput* leftIR;
	//AnalogInput* rightIR;
	//float voltageToDistance(float val);
	/*typedef enum _MainSensor
	{
		ULTRASONIC, 
		IR
	} MainSensor;*/
	//MainSensor elevSensor;
	//const float SWITCH_TO_ULTRASONIC = 12.0f;
	//const float SWITCH_TO_IR = 6.0f;
	AnalogInput* middleUS;
	AnalogInput* middleIR;
	AnalogInput* leftIR;
	AnalogInput* rightIR;
	//MainSensor switchSensor(float IRDistance, float UDistance);
	DoubleSolenoid* latchSol;
	Preferences* prefs;
	float USVoltageToDistance(float val);
	float IRVoltageToDistance(float val);
public:
	Elevator();
	virtual ~Elevator();
	void move(float speed);
	void stop();
	void InitDefaultCommand();
	//Encoder* getEncoder();
	bool isLeftAligned();
	bool isRightAligned();
	float getElevatorSensorHeight();
	float getElevatorEncoderHeight();
	float getElevatorHeight();
	DoubleSolenoid* getSolenoid();
	void ResetSensors();
};

#endif /* LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_ */
