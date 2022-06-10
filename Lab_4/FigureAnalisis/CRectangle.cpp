#include "CRectangle.h"
#include <sstream>
#include <iomanip>
CRectangle::CRectangle(double x, double y, double w, double h, uint32_t outlineColor, uint32_t fillColor)
	:ISolidShape(outlineColor, fillColor)
	,m_leftTop(x, y)
	,m_width(w)
	,m_height(h)
{}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const 
{
	return CPoint(GetLeftTop().x + GetWidth(), GetLeftTop().y - GetHeight());
}

double CRectangle::GetWidth() const 
{ 
	return m_width; 
}

double CRectangle::GetHeight() const 
{ 
	return m_height; 
}


double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * 2;
}

std::string CRectangle::ToString() const
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3);
	stream << "Rectangle" << "\n";
	stream << "area is " << GetArea() << "\n" << "perimeter is " << GetPerimeter() << "\n";
	stream << "fill color: " << std::hex << GetFillColor() << std::dec << "\n";
	stream << "outline color: " << std::hex << GetOutlineColor() << std::dec << "\n";
	stream << "top left corner at " << GetLeftTop().ToString() << ", bottom right corner at " << GetRightBottom().ToString() << "\n";
	stream << "width: " << GetWidth() << ",  height: " << GetHeight();
	return stream.str();
}