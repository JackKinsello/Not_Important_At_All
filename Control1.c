#pragma config(Sensor, port2,  LightSensor,    sensorVexIQ_ColorHue)
#pragma config(Sensor, port3,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor4,          rightGroundMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor5,          middleSquareMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          dumpMotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor9,          middleDriveMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10,         rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor11,         leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int SPEED = 100;

task loadRings()
{
	string cp = "blue"; //set the "current position" (cp) to blue
	repeat(forever)
  {
// Red Ring ########################################################################
  	if (getColorHue(port2) >= 212) { //if the color is red
  		if (cp == "blue") {
    		moveMotorTarget(middleSquareMotor, 360, 100);
    	}
    	else {
    		if (cp == "green") {
    			moveMotorTarget(middleSquareMotor, -360, -100);
    		}
    	}
  		cp = "red";
  	}
// Green Ring #######################################################################
  	else {
    	if (getColorHue(port2) <= 127) { // if the color is green
    		if (cp == "blue") {
    			moveMotorTarget(middleSquareMotor, -360, -100);
    		}
    		else {
    			if (cp == "red") {
	    			moveMotorTarget(middleSquareMotor, 360, 100);
    			}
    		}
  		cp = "green";
    	}
// Blue Ring #######################################################################
    	else { // if the color is blue
    		if (cp == "red") {
 		   		moveMotorTarget(middleSquareMotor, -360, -100);
    		}
    		else {
    			if (cp == "green") {
    				moveMotorTarget(middleSquareMotor, 360, 100);
    			}
    		}
  			cp = "blue";
    	}
  	}
  }
}


task main() {
	resetMotorEncoder(leftDriveMotor);
	resetMotorEncoder(rightDriveMotor);
	resetMotorEncoder(middleDriveMotor);
	resetMotorEncoder(middleSquareMotor);

	repeat (forever) {
		displaySensorValues(line1, LightSensor);

	tankControl(ChD, ChA, 10);
	armControl(dumpMotor, BtnLUp, BtnLDown, 75);
	armControl(middleSquareMotor, BtnRUp, BtnRDown, 75);
	armControl(middleDriveMotor, BtnEUp, BtnEDown, 75);
	if(getJoystickValue(BtnFUp) == 1) {
		setMotor(rightGroundMotor);
		startTask(loadRings);
	}

	if(getJoystickValue(BtnFDown)== 1) {
		stopMotor(rightGroundMotor);
		stopTask(loadRings);
		}
	}
}
