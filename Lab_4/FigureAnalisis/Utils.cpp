#include "Utils.h"
#include <algorithm>
#include <sstream>

using namespace std;

unique_ptr<IShape> readShapeFromStringToVector(string const& s)
{
	istringstream ss(s);
	string type;
	ss >> type;
	if (type == "segment") {
		double x1, y1, x2, y2;
		uint32_t line;
		ss >> x1 >> y1 >> x2 >> y2 >> line;
		return make_unique<CLineSegment>(x1, y1, x2, y2, line);
	}
	else if (type == "triangle") {
		double x1, y1, x2, y2, x3, y3;
		uint32_t line, fill;
		ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> line >> fill;
		return make_unique<CTriangle>(x1, y1, x2, y2, x3, y3, line, fill);
	}
	else if (type == "rectangle") {
		double x1, y1, w, h;
		uint32_t line, fill;
		ss >> x1 >> y1 >> w >> h >> line >> fill;
		return make_unique<CRectangle>(x1, y1, w, h, line, fill);
	}
	else {
		double x1, y1, r;
		uint32_t line, fill;
		ss >> x1 >> y1 >> r >> line >> fill;
		return make_unique<CCircle>(x1, y1, r, line, fill);
	}
}

int getMaxAreaShapeIdx(vector<unique_ptr<IShape>>& const vec)
{
	vector<unique_ptr<IShape>>::iterator result = max_element(vec.begin(), vec.end(),
		[](unique_ptr<IShape>& const a, unique_ptr<IShape>& const b)
		{
			return a->GetArea() < b->GetArea();
		});
	return distance(vec.begin(), result);
}

int getMinPerimeterShapeIdx(vector<unique_ptr<IShape>>& const vec)
{
	vector<unique_ptr<IShape>>::iterator result = min_element(vec.begin(), vec.end(),
		[](unique_ptr<IShape>& const a, unique_ptr<IShape>& const b)
		{
			return a->GetPerimeter() < b->GetPerimeter();
		});
	return distance(vec.begin(), result);
}