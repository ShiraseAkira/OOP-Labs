#define _USE_MATH_DEFINES
#include "CCircle.h"
#include <sstream>
#include <iomanip>
#include <cmath>

CCircle::CCircle(double x, double y, double r, uint32_t outlineColor, uint32_t fillColor)
	:ISolidShape(outlineColor, fillColor)
	, m_center(x, y)
	, m_radius(r)
{}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}


double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

std::string CCircle::ToString() const
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3);
	stream << "Circle" << "\n";
	stream << "area is " << GetArea() << "\n" << "perimeter is " << GetPerimeter() << "\n";
	stream << "fill color: " << std::hex << GetFillColor() << std::dec << "\n";
	stream << "outline color: " << std::hex << GetOutlineColor() << std::dec << "\n";
	stream << "center at " << GetCenter().ToString() << "\n";
	stream << "radius: " << GetRadius();
	return stream.str();
}