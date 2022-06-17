#pragma once
#include "Car.h"

class CarController
{
public:
	void control(std::string const& command);
private:
	void EngineControl(bool state = false);
	void GearControl();
	void SpeedControl();
	void PrintInfo();

	Car m_car;
};

