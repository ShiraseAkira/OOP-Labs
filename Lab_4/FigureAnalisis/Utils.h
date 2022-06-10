#pragma once
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <vector>
#include <string>
#include <memory>

std::unique_ptr<IShape> readShapeFromStringToVector(std::string const& s);
int getMaxAreaShapeIdx(std::vector<std::unique_ptr<IShape>>& vec);
int getMinPerimeterShapeIdx(std::vector<std::unique_ptr<IShape>>&  vec);
