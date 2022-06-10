#pragma once
#include <string>

class IShape
{
public:
	IShape(uint32_t outlineColor = 0);
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	uint32_t GetOutlineColor() const;

private:
	uint32_t m_OutlineColor;
};

