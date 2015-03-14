// task1_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task1/VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyVectorProducesEmptyVector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(VectorWithOneElementMultiplyItselfs)
{
	vector<double> numbers = { -2 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 4 }));
}

BOOST_AUTO_TEST_CASE(VectorWithEqualElementsProduceSquareVector)
{
	vector<double> numbers = { 3, 3, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 3 * 3, 3 * 3, 3 * 3 }));
}

BOOST_AUTO_TEST_CASE(VectorWithOneMinElement)
{
	vector<double> numbers = { -2, 0, -3, 5, 11 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -2 * -3, 0 * -3, -3 * -3, 5 * -3, 11 * -3 }));
}

BOOST_AUTO_TEST_CASE(VectorWithPositiveElementsProducePositiveVector)
{
	vector<double> numbers = { 2, 6, 13, 5, 28 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 2 * 2, 6 * 2, 13 * 2, 5 * 2, 28 * 2 }));
}

BOOST_AUTO_TEST_CASE(VectorWithUnpositiveElementsProducePositiveVector)
{
	vector<double> numbers = { -2, -6, -13, -5, -28 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -2 * -28, -6 * -28, -13 * -28, -5 * -28, -28 * -28 }));
}

BOOST_AUTO_TEST_CASE(VectorWithMinZeroElementProduceVectorWithZeroElements)
{
	vector<double> numbers = { 2, 6, 0, 5.5, 28 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 2 * 0, 6 * 0, 0 * 0, 5.5 * 0, 28 * 0 }));
}