#include "CPoint.h"
#include <sstream>
#include <iomanip>
CPoint::CPoint(double x, double y)
	:x(x)
	,y(y)
{}
std::string CPoint::ToString() const
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3);
	stream << "(" << x << ", " << y << ")";
	return stream.str();
}