#include "ProcessVector.h"
#include <algorithm>
#include <vector>

void ProcessVector(std::vector<double>& numbers)
{
	if (numbers.size()) {
		auto minVal = *std::min_element(numbers.begin(), numbers.end());

		std::transform(numbers.begin(), numbers.end(), numbers.begin(), [&minVal](double elem) {return elem *= minVal; });
	}	
}