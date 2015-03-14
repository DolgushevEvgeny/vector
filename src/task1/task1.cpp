// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
	cout << "\nSize of vector: " << numbers.size() << "\n";
	system("pause");
	return 0;
}

