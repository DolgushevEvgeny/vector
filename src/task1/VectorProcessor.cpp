#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void ProcessVector(vector<double> & numbers)
{
	auto minelementposition = min_element(numbers.begin(), numbers.end());
	if (minelementposition != numbers.end())
	{
		double minresult = *minelementposition;
		for_each(numbers.begin(), numbers.end(), [minresult](double &number){ return number *= minresult; });
	}
}