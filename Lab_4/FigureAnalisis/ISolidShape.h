#pragma once
#include "IShape.h"
class ISolidShape :
    public IShape
{
public:
    ISolidShape(uint32_t outlineColor = 0, uint32_t fillColor = 0);
    virtual ~ISolidShape() = default;
    uint32_t GetFillColor() const;
private:
    uint32_t m_FillColor;
};

