#pragma config(Sensor, port2,  LightSensor,    sensorVexIQ_ColorHue)
#pragma config(Sensor, port3,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor4,          rightGroundMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor5,          middleSquareMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          dumpMotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10,         rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor11,         leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int LOADBLUE = 60;
int LOADGREEN = 180;
int LOADRED = 300;

int SCORERED = 0;
int SCOREBLUE = 120;
int SCOREGREEN = 240;

int SPEED = 75;

task groundget()
{
	if(getColorName(LightSensor) == colorRed){
		setMotorTarget(middleSquareMotor, LOADRED, SPEED);
		waitUntil(getMotorEncoder(middleSquareMotor) >= LOADRED);
 }
	if(getColorName(LightSensor) == colorBlue) {
		setMotorTarget(middleSquareMotor, LOADBLUE, SPEED);
		waitUntil(getMotorEncoder(middleSquareMotor) >= LOADBLUE);
 }
	if(getColorName(LightSensor) == colorGreen) {
		setMotorTarget(middleSquareMotor, LOADGREEN, SPEED);
		waitUntil(getMotorEncoder(middleSquareMotor) >= LOADGREEN);
 }


}

task main()
{
	startTask(groundget);
}
