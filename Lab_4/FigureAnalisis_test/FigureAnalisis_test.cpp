#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../FigureAnalisis/Utils.h"

SCENARIO("CPoint test") {
	CPoint p(0, 0);
	GIVEN("point") {
		CHECK((p.x == 0 && p.y == 0));
		CHECK(p.ToString() == "(0.000, 0.000)");
	}
}

SCENARIO("Line segment test") {
	CLineSegment s(0, 0, 0, 10, 0xff0000);
	GIVEN("line segment") {
		CHECK(s.GetArea() == 0);
		CHECK(s.GetOutlineColor() == 0xff0000);
		CHECK(s.GetPerimeter() == 20);
	}
}

SCENARIO("Triangle test") {
	CTriangle t(0, 0, 0, 4, 3,0, 0xff0000, 0xff0000);
	GIVEN("line segment") {
		CHECK(t.GetArea() == 6);
		CHECK(t.GetFillColor() == 0xff0000);
		CHECK(t.GetPerimeter() == 12);
	}
}

SCENARIO("Rectangle test") {
	CRectangle r(0, 0, 4, 3, 0xff0000, 0xff0000);
	GIVEN("line segment") {
		CHECK(r.GetArea() == 12);
		CHECK(r.GetFillColor() == 0xff0000);
		CHECK(r.GetPerimeter() == 14);
	}
}

SCENARIO("Circle test") {
	CCircle c(0, 0, 1, 0xff0000, 0xff0000);
	GIVEN("line segment") {
		CHECK_THAT(c.GetArea(), Catch::Matchers::WithinAbs(3.1415, 0.001));
		CHECK(c.GetFillColor() == 0xff0000);
		CHECK_THAT(c.GetPerimeter(), Catch::Matchers::WithinAbs(3.1415*2, 0.001));
	}
}

SCENARIO("readShapeFromStringToVector test") {
	std::unique_ptr<IShape> p = readShapeFromStringToVector("circle 0 0 1 0xfafafa 0xbc14a7");
	GIVEN("pointer to circle") {
		CHECK(p->ToString() == "Circle\narea is 3.142\nperimeter is 6.283\nfill color: bc14a7\noutline color: fafafa\ncenter at (0.000, 0.000)\nradius: 1.000");
	}
}

SCENARIO("getMaxAreaShapeIdx test") {
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.emplace_back(readShapeFromStringToVector("circle 0 0 1 0xfafafa 0xbc14a7"));
	shapes.emplace_back(readShapeFromStringToVector("triangle 0 0 0 3 4 0 0xff0000 0x0000ff"));
	shapes.emplace_back(readShapeFromStringToVector("rectangle 0 10 20 15 0xf0f0f0 0xffffff"));
	auto maxAreaShapeIt = getMaxAreaShapeIdx(shapes);
	GIVEN("Vector of shapes") {
		CHECK(std::distance(shapes.begin(),maxAreaShapeIt) == 2);
	}
}

SCENARIO("getMinPerimeterShapeIdx test") {
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.emplace_back(readShapeFromStringToVector("circle 0 0 1 0xfafafa 0xbc14a7"));
	shapes.emplace_back(readShapeFromStringToVector("triangle 0 0 0 3 4 0 0xff0000 0x0000ff"));
	shapes.emplace_back(readShapeFromStringToVector("rectangle 0 10 20 15 0xf0f0f0 0xffffff"));
	auto maxAreaShapeIt = getMinPerimeterShapeIdx(shapes);
	GIVEN("Vector of shapes") {
		CHECK(std::distance(shapes.begin(), maxAreaShapeIt) == 0);
	}
}
