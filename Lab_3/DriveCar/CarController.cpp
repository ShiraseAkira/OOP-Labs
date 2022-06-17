#include "CarController.h"
#include <string>
#include <iostream>

using namespace std;

const string COMMAND_FAILED_MSG = "Command failed because";
const string ERROR_SPEED_NOT_ZERO = "Speed is not zero";
const string ERROR_GEAR_NOT_ZERO = "Gear is not zero";
const string ERROR_SWITCH_REVERSE_ONLY_ZERO_SPEED = "Switch to reverse only with zero speed";
const string ERROR_GEAR_SPEED_LIMIT = "Speed is not in limits for desired gear";
const string ERROR_FWD_BEFORE_STOP = "Can not go forward before stop move back";
const string ERROR_SPEED_UP_ON_NEUTRAL = "Can not increase speed on neutral gear";

const string COMMAND_ON = "EngineOn";
const string COMMAND_OFF = "EngineOff";
const string COMMAND_SET_SPEED = "SetSpeed";
const string COMMAND_SET_GEAR = "SetGear";
const string COMMAND_GET_INFO = "Info";

const string MSG_ENGINE_STATUS = "The engine is turned ";
const string MSG_ON = "on";
const string MSG_OFF = "off";
const string MSG_DIRECTION = "The direction is ";
const string MSG_NOT_MOVING = "Car is not moving";
const string MSG_SPEED = "The speed is ";
const string MSG_GEAR = "The gear is ";


void CarController::EngineControl(bool state) {
	if (state) {
		m_car.TurnOnEngine();
		return;
	}
	if (!m_car.TurnOffEngine()) {
		cout << COMMAND_FAILED_MSG << endl;
		if (m_car.GetSpeed()) {
			cout << ERROR_SPEED_NOT_ZERO << endl;
		}
		else if (m_car.GetGear()) {
			cout << ERROR_GEAR_NOT_ZERO << endl;
		}
	}
}

void CarController::GearControl() {
	int gear;
	cin >> gear;
	if (!m_car.SetGear(gear)) {
		cout << COMMAND_FAILED_MSG << endl;
		if (gear == -1) {
			cout << ERROR_SWITCH_REVERSE_ONLY_ZERO_SPEED << endl;;
		}
		else if (gear != 1) {
			cout << ERROR_GEAR_SPEED_LIMIT << endl;;
		}
		else {
			cout << ERROR_FWD_BEFORE_STOP << endl;;
		}
	}
}
void CarController::SpeedControl() {
	int speed;
	cin >> speed;

	if (!m_car.SetSpeed(speed)) {
		cout << COMMAND_FAILED_MSG << endl;;
		if (m_car.GetGear() == 0) {
			cout << ERROR_SPEED_UP_ON_NEUTRAL << endl;;
		}
		else {
			cout << ERROR_GEAR_SPEED_LIMIT << endl;;
		}
	}
}

void CarController::PrintInfo() {
	cout << MSG_ENGINE_STATUS << (m_car.IsTurnedOn() ? MSG_ON : MSG_OFF) << "\n"
		<< (m_car.GetSpeed() 
			? MSG_DIRECTION + m_car.GetDirection()
			: MSG_NOT_MOVING)
		<< "\n"
		<< MSG_SPEED << m_car.GetSpeed() << "\n"
		<< MSG_GEAR << m_car.GetGear() << endl;
}

void CarController::control(string const& s) {
	if (s == COMMAND_ON) {
		EngineControl(true);
	}
	else if (s == COMMAND_OFF) {
		EngineControl();
	}
	else if (s == COMMAND_SET_GEAR) {
		GearControl();
	}
	else if (s == COMMAND_SET_SPEED) {
		SpeedControl();
	}
	else if (s == COMMAND_GET_INFO) {
		PrintInfo();
	}
}