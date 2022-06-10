#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
class CTriangle :
    public ISolidShape
{
public:
    CTriangle(double x1, double y1, double x2, double y2, double x3, double y3, uint32_t outlineColor = 0, uint32_t fillColor = 0);
    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
private:
    CPoint m_v1, m_v2, m_v3;
};

