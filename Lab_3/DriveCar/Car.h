#pragma once
#include <string>
#include <map>
#include <vector>
#include <cmath>

class Car
{
public:
	Car();
	~Car();

	bool IsTurnedOn() const;
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	int m_speed;
	int m_gear;
	bool m_isTurnedOn;
	std::map<int, std::vector<int>> m_gearSpeedMap;
};

