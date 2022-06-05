#include "Car.h"

Car::Car()
	:m_gear(0)
	,m_speed(0)
	,m_isTurnedOn(false)
	,m_gearSpeedMap{
						{-1, {-20, 0}},
						{0, {-20, 150}},
						{1, {0, 30}},
						{2, {20, 50}},
						{3, {30, 60}},
						{4, {40, 90}},
						{5, {50, 150}}		
		}
{
}

Car::~Car()
{
}

bool Car::IsTurnedOn() const
{
	return m_isTurnedOn;
}

std::string Car::GetDirection() const
{
	if (m_speed > 0) {
		return std::string("forward");
	}
	if (m_speed < 0) {
		return std::string("back");
	}
	return std::string("not moving");
}

int Car::GetSpeed() const
{
	return std::abs(m_speed);
}

int Car::GetGear() const
{
	return m_gear;
}

bool Car::TurnOnEngine()
{
	m_isTurnedOn = true;
	return true;
}

bool Car::TurnOffEngine()
{
	if (m_gear == 0 && m_speed == 0) {
		m_isTurnedOn = false;
		return true;
	}
	return false;
}

bool Car::SetGear(int gear)
{
	if (auto it = m_gearSpeedMap.find(gear); it == m_gearSpeedMap.end()) {
		return false;
	}

	if (!m_isTurnedOn) {
		if (gear == 0) {
			return true;
		}
		return false;
	}

	if (gear == -1) {
		if (m_speed == 0) {
			m_gear = -1;
			return true;
		}
		return false;
	}

	if (m_gearSpeedMap[gear][0] <= m_speed && m_speed <= m_gearSpeedMap[gear][1]) {
		m_gear = gear;
		return true;
	}
	return false;
}

bool Car::SetSpeed(int speed) 
{
	if (m_gearSpeedMap[m_gear][0] <= speed && speed <= m_gearSpeedMap[m_gear][1]) {
		if (m_gear == 0 && std::abs(speed) > std::abs(m_speed)) {
			return false;
		}
		m_speed = (m_gear == -1) ? -speed : speed;
		return true;
	}
	return false;
}