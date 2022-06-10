#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle :
    public ISolidShape
{
public:
    CRectangle(double x, double y, double w, double h, uint32_t outlineColor = 0, uint32_t fillColor = 0);
    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
private:
    CPoint m_leftTop;
    double m_width, m_height;
};

