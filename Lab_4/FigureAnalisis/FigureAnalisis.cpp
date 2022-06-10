#include <iostream>
#include <string>
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "Utils.h"

using namespace std;

int main()
{
	std::vector<std::unique_ptr<IShape>> shapes;
	string str;
	while (getline(cin, str)) {
		shapes.emplace_back(readShapeFromStringToVector(str));
	}

	if (shapes.size() == 0) {
		cout << "no shapes to analize" << endl;
		return 0;
	}
	else if (shapes.size() == 1) {
		cout << "only one shape is present, no analize required" << endl;
		cout << shapes[0]->ToString() << endl;
		return 0;
	}

	int maxAreaIdx = getMaxAreaShapeIdx(shapes);
	int minPerimeterIdx = getMinPerimeterShapeIdx(shapes);

	cout << "This is the shape with the max area:\n" << shapes[maxAreaIdx]->ToString() << endl;
	cout << "This is the shape with the least perimeter:\n" << shapes[minPerimeterIdx]->ToString() << endl;

	return 0;
}
