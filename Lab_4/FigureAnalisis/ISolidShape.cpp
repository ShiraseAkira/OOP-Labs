#include "ISolidShape.h"
ISolidShape::ISolidShape(uint32_t outlineColor, uint32_t fillColor)
	:IShape(outlineColor)
	,m_FillColor(fillColor)
{}

uint32_t ISolidShape::GetFillColor() const {
	return m_FillColor;
}