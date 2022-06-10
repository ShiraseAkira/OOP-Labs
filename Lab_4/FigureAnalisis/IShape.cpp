#include "IShape.h"
IShape::IShape(uint32_t outlineColor)
	:m_OutlineColor(outlineColor)
{}

 uint32_t IShape::GetOutlineColor() const {
	 return m_OutlineColor;
}