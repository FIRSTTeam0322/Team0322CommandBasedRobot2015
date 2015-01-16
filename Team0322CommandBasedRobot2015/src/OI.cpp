#include "OI.h"
#include "Commands/BrakeControl.h"

OI::OI()
{
	// Process operator interface input here.

	// Create the three Joystick objects
	driveStick = new Joystick(1);
	manipulatorStick = new Joystick(2, NUMAXIS, NUMBUTTONS);

	// Create the Brake SubSystem controls
	brake = new JoystickButton(driveStick, 1);
	brake->WhileHeld(new BrakeControl());
}

Joystick* OI::getDriveStick() {
	return driveStick;
}

Joystick* OI::getManipulatorStick() {
	return manipulatorStick;
}
