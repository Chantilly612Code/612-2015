#include "ElevatorMoveToPosition.h"

ElevatorMoveToPosition::ElevatorMoveToPosition(uint32_t inPosition)
{
	Requires(elevator);
	targetPosition = inPosition;
	targetSpins = targetPosition * INTERVAL;
}

// Called just before this Command runs the first time
void ElevatorMoveToPosition::Initialize()
{
	printf("ElevatorMoveToPosition Initialized!");
}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveToPosition::Execute()
{
	int spins = elevator->getEncoder()->Get();

	//Moves down if the spins are more than the target spins
	if (spins > targetSpins)
	{
		elevator->move(-ELEV_SPEED_FLOAT);
	}
	// Moves up if the spins are less than the target spins
	else if (spins < targetSpins)
	{
		elevator->move(ELEV_SPEED_FLOAT);
	}
	//Doesn't move if (spins == targetSpins)
	static int count = 0;
	if (count % 60 == 0)
	{
		printf("ElevatorMoveToPosition Execution Called! Spins= %d", spins);
	}
	count++;
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMoveToPosition::IsFinished()
{
	int spins = elevator->getEncoder()->Get();

	//If the spins are at the target spins IsFinished() returns true
	return (targetSpins >= (spins - ELEVATOR_TOLERANCE) && (targetSpins <= (spins + ELEVATOR_TOLERANCE)));
}

// Called once after isFinished returns true
void ElevatorMoveToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMoveToPosition::Interrupted()
{
	elevator -> stop(); //make sure elevator doesn't go whacko
}
