#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	static const int NUMAXIS = 4;
	static const int NUMBUTTONS = 12;

	Joystick *driveStick, *manipulatorStick;

	JoystickButton *brake;

public:
	OI();
	Joystick* getDriveStick();
	Joystick* getManipulatorStick();
};

#endif
