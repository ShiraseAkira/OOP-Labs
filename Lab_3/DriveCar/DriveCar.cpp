#include <iostream>
#include "Car.h"
#include <string>

using namespace std;

void EngineControl(Car& car, bool state = false) {
	if (state) {
		car.TurnOnEngine();
		return;
	}
	if (!car.TurnOffEngine()) {
		cout << "Command failed because\n";
		if (car.GetSpeed()) {
			cout << "Speed is not zero\n";
		}
		if (car.GetGear()) {
			cout << "Gear is not zero\n";
		}
	}
}

void GearControl(Car& car) {
	int gear;
	cin >> gear;
	if (!car.SetGear(gear)) {
		cout << "Command failed because\n";
		if (gear == -1) {
			cout << "Switch to reverse only with zero speed\n";
		}
		else if (gear != 1) {
			cout << "Speed is not in limits for desired gear\n";
		}
		else {
			cout << "Can not go forward before stop\n";
		}
	}
}
void SpeedControl(Car& car) {
	int speed;
	cin >> speed;
	
	if (!car.SetSpeed(speed)) {
		cout << "Command failed because\n";
		if (car.GetGear() == 0) {
			cout << "Can not increase speed on neutral gear\n";
		}
		else {
			cout << "Speed is not in limits for current gear\n";
		}
	}
}

int main()
{
	Car myCar;
	string s;
	bool opSuccess;
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
			cout << "The engine is turned " << (myCar.IsTurnedOn() ? "on" : "off") << "\n"
				<< "The direction is " << myCar.GetDirection() << "\n"
				<< "The speed is " << myCar.GetSpeed() << "\n"
				<< "The gear is " << myCar.GetGear() << endl;
		}
	}
	return 0;
}
