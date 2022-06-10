#pragma once
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <vector>
#include <string>
#include <memory>

std::unique_ptr<IShape> readShapeFromStringToVector(std::string const& s);
std::vector<std::unique_ptr<IShape>>::iterator getMaxAreaShapeIdx(std::vector<std::unique_ptr<IShape>>& vec);
std::vector<std::unique_ptr<IShape>>::iterator getMinPerimeterShapeIdx(std::vector<std::unique_ptr<IShape>>&  vec);
