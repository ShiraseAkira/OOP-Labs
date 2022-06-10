#include "CTriangle.h"
#include <sstream>
#include <iomanip>
CTriangle::CTriangle(double x1, double y1, double x2, double y2, double x3, double y3, uint32_t outlineColor, uint32_t fillColor)
	:ISolidShape(outlineColor, fillColor)
	, m_v1(x1, y1)
	, m_v2(x2, y2)
	, m_v3(x3, y3)
{}

CPoint CTriangle::GetVertex1() const {
	return m_v1;
}

CPoint CTriangle::GetVertex2() const {
	return m_v2;
}

CPoint CTriangle::GetVertex3() const {
	return m_v3;
}

double CTriangle::GetArea() const 
{ 
	return abs((GetVertex1().x*(GetVertex2().y - GetVertex3().y) +
		GetVertex2().x * (GetVertex3().y - GetVertex1().y) +
		GetVertex3().x * (GetVertex1().y - GetVertex2().y)) / 2);
}
double CTriangle::GetPerimeter() const
{
	return sqrt(pow(GetVertex1().x - GetVertex2().x, 2) + pow(GetVertex1().y - GetVertex2().y, 2))
		+ sqrt(pow(GetVertex2().x - GetVertex3().x, 2) + pow(GetVertex2().y - GetVertex3().y, 2))
		+ sqrt(pow(GetVertex3().x - GetVertex1().x, 2) + pow(GetVertex3().y - GetVertex1().y, 2));
}

std::string CTriangle::ToString() const
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3);
	stream << "Triangle" << "\n";
	stream << "area is " << GetArea() << "\n" << "perimeter is " << GetPerimeter() << "\n";
	stream << "fill color: " << std::hex << GetFillColor() << std::dec << "\n";
	stream << "outline color: " << std::hex << GetOutlineColor() << std::dec << "\n";
	stream << "vertices at " << GetVertex1().ToString() << ", " << GetVertex2().ToString() << ", " << GetVertex3().ToString();
	return stream.str();
}