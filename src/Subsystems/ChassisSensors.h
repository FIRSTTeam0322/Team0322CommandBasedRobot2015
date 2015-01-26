#ifndef CHASSIS_SENSORS_H
#define CHASSIS_SENSORS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class ChassisSensors: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder *frontLeftEncoder, *rearLeftEncoder, *frontRightEncoder, *rearRightEncoder;
	Gyro *gyro;
	BuiltInAccelerometer *accel;
public:
	ChassisSensors();
	void InitDefaultCommand();
	void resetEncoders();
	double getFrontLeftDistance();
	double getFrontRightDistance();
	double getRearLeftDistance();
	double getRearRightDistance();
	void resetGyro();
	double getGyroAngle();
	double getAccelerometerXData();
	double getAccelerometerYData();
	double getAccelerometerZData();
	Encoder* getEncoder(int);
	Gyro* getGyro();
	BuiltInAccelerometer* getAccelerometer();
};

#endif
