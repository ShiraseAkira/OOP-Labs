#pragma once
#include <string>
class CPoint
{
public:
	CPoint(double x, double y);
	std::string ToString() const;
	double x;
	double y;
};

