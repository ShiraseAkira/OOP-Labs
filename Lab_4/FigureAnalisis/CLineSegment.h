#pragma once
#include <string>
#include "IShape.h"
#include "CPoint.h"
class CLineSegment :
    public IShape
{
public:
    CLineSegment(double x1, double y1, double x2, double y2, uint32_t outlineColor = 0);
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
};

