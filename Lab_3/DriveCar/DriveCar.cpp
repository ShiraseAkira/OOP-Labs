#include <iostream>
#include "Car.h"
#include <string>

using namespace std;

const string COMMAND_FAILED_MSG = "Command failed because";
const string ERROR_SPEED_NOT_ZERO = "Speed is not zero";
const string ERROR_GEAR_NOT_ZERO = "Gear is not zero";
const string ERROR_SWITCH_REVERSE_ONLY_ZERO_SPEED = "Switch to reverse only with zero speed";
const string ERROR_GEAR_SPEED_LIMIT = "Speed is not in limits for desired gear";
const string ERROR_FWD_BEFORE_STOP = "Can not go forward before stop move back";
const string ERROR_SPEED_UP_ON_NEUTRAL = "Can not increase speed on neutral gear";

void EngineControl(Car& car, bool state = false) {
	if (state) {
		car.TurnOnEngine();
		return;
	}
	if (!car.TurnOffEngine()) {
		cout << COMMAND_FAILED_MSG << endl;
		if (car.GetSpeed()) {
			cout << ERROR_SPEED_NOT_ZERO << endl;
		}
		if (car.GetGear()) {
			cout << ERROR_GEAR_NOT_ZERO << endl;
		}
	}
}

void GearControl(Car& car) {
	int gear;
	cin >> gear;
	if (!car.SetGear(gear)) {
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
void SpeedControl(Car& car) {
	int speed;
	cin >> speed;
	
	if (!car.SetSpeed(speed)) {
		cout << COMMAND_FAILED_MSG << endl;;
		if (car.GetGear() == 0) {
			cout << ERROR_SPEED_UP_ON_NEUTRAL << endl;;
		}
		else {
			cout << ERROR_GEAR_SPEED_LIMIT << endl;;
		}
	}
}

void PrintInfo(Car& const car) {
	cout << "The engine is turned " << (car.IsTurnedOn() ? "on" : "off") << "\n"
		<< "The direction is " << car.GetDirection() << "\n"
		<< "The speed is " << car.GetSpeed() << "\n"
		<< "The gear is " << car.GetGear() << endl;
}

int main()
{
	Car myCar;
	string s;
	while (cin >> s) {
		if (s == "EngineOn") {
			EngineControl(myCar, true);
		} 
		else if (s == "EngineOff") {
			EngineControl(myCar);
		} 
		else if (s == "SetGear") {
			GearControl(myCar);
		} 
		else if (s == "SetSpeed") {
			SpeedControl(myCar);
		}
		else if (s == "Info") {
			PrintInfo(myCar);
		}
	}
	return 0;
}
