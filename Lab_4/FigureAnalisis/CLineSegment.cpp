#include "ClineSegment.h"
#include <cmath>
#include <sstream>
#include <iomanip>
CLineSegment::CLineSegment(double x1, double y1, double x2, double y2, uint32_t outlineColor)
	:IShape(outlineColor)
	,m_startPoint(x1, y1)
	,m_endPoint(x2, y2)
{}

CPoint CLineSegment::GetStartPoint() const {
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const {
	return m_endPoint;
}

// Считаю отрезок как вырожденный случай прямоугольника
double CLineSegment::GetArea() const { return 0; } // => у отрезка нет площади
double CLineSegment::GetPerimeter() const // => периметр отрезка = его удвоенной длине
{ 
	return sqrt(pow(GetEndPoint().x - GetStartPoint().x, 2) + pow(GetEndPoint().y - GetStartPoint().y, 2)) * 2;
}

std::string CLineSegment::ToString() const 
{ 
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3);
	stream << "Line segment" << "\n";
	stream << "area is " << GetArea() << "\n" << "perimeter is " << GetPerimeter() << "\n";
	stream << "outline color: " << std::hex << GetOutlineColor() << std::dec << "\n";
	stream << "starts at " << GetStartPoint().ToString() << "; ends at " << GetEndPoint().ToString();
	return stream.str();
}