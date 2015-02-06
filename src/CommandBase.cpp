#include "CommandBase.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
Elevator* CommandBase::elevator = NULL;
DriveTrain* CommandBase::drivetrain = NULL;
Vision* CommandBase::vision = NULL;
DriveEncoder* CommandBase::encoder = NULL;
Ultrasonic612* CommandBase::ultrasonic612 = NULL;


CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	oi = new OI();
	elevator = new Elevator();
	drivetrain = new DriveTrain(MOTOR_LR, MOTOR_LF, MOTOR_RR, MOTOR_RF);
	encoder = new DriveEncoder();
	ultrasonic612 = new Ultrasonic612();
}
