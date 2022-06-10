#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle :
    public ISolidShape
{
public:
    CCircle(double x, double y, double r, uint32_t outlineColor = 0, uint32_t fillColor = 0);
    CPoint GetCenter() const;
    double GetRadius() const;

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
private:
    CPoint m_center;
    double m_radius;
};
