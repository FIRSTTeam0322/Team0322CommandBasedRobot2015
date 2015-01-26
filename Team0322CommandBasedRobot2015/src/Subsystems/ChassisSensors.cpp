#include "ChassisSensors.h"
#include "../Robotmap.h"

ChassisSensors::ChassisSensors() : Subsystem("ChassisSensors") {
	// Create an Encoder object for each transmission
	frontLeftEncoder = new Encoder(4,5,true, frontLeftEncoder->k4X);
	rearLeftEncoder = new Encoder(6,7,true, rearLeftEncoder->k4X);
	frontRightEncoder = new Encoder(8,9,false, frontRightEncoder->k4X);
	rearRightEncoder = new Encoder(10,11,false, rearRightEncoder->k4X);
	
	// Create a Gyro(scope) object on AnalogInput 0
	gyro = new Gyro(0);
	
	// Create the Accelerometer object for the Built-in Accelerometer
	accel = new BuiltInAccelerometer(BuiltInAccelerometer::kRange_8G);
}
    
void ChassisSensors::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void ChassisSensors::resetEncoders() {
	frontLeftEncoder->Reset();
	rearLeftEncoder->Reset();
	frontRightEncoder->Reset();
	rearRightEncoder->Reset();
}

double ChassisSensors::getFrontLeftDistance() {
	return frontLeftEncoder->GetDistance();
}

double ChassisSensors::getRearLeftDistance() {
	return rearLeftEncoder->GetDistance();
}

double ChassisSensors::getFrontRightDistance() {
	return frontRightEncoder->GetDistance();
}

double ChassisSensors::getRearRightDistance() {
	return rearRightEncoder->GetDistance();
}

void ChassisSensors::resetGyro() {
	gyro->Reset();
}

double ChassisSensors::getGyroAngle() {
	return gyro->GetAngle();
}

double ChassisSensors::getAccelerometerXData() {
	return accel->GetX();
}

double ChassisSensors::getAccelerometerYData() {
	return accel->GetY();
}

double ChassisSensors::getAccelerometerZData() {
	return accel->GetZ();
}

Encoder* ChassisSensors::getEncoder(int type) {
	switch(type) {
		case 0:
			return frontLeftEncoder;
		break;
		
		case 1:
			return rearLeftEncoder;
		break;

		case 2:
			return frontRightEncoder;
		break;

		case 3:
			return rearRightEncoder;
		break;
		
		default:
			return NULL;
		break;
	}
}

Gyro* ChassisSensors::getGyro() {
	return gyro;
}

BuiltInAccelerometer* ChassisSensors::getAccelerometer() {
	return accel;
}
