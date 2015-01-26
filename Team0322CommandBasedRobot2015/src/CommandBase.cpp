#include "CommandBase.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/ChassisSensors.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
Chassis* CommandBase::chassis = NULL;
ChassisSensors* CommandBase::chassisSensors = NULL;
OI* CommandBase::oi = NULL;

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
	chassis = new Chassis();
	chassisSensors = new ChassisSensors();
	oi = new OI();
}
