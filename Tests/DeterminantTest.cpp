#include "pch.h"

class DeterminantCalculationTests : public ::testing::TestWithParam<tuple<Matrix, double>> {

};

INSTANTIATE_TEST_CASE_P(DeterminantCalculationTest, DeterminantCalculationTests, ::testing::Values(
	make_tuple(Matrix(2, 1.0), 0.0),
	make_tuple(Matrix(3, 1.0), 0.0),
	make_tuple(Matrix(2, 3, 1.0), 0.0),
	make_tuple(Matrix(3, 2, 0.0), 0.0),
	make_tuple(Matrix(3, vector<double>({ 4.0,1.0,9.0,1.0,5.0,1.0,4.0,1.0,8.0 })), -19.0),
	make_tuple(Matrix(3, vector<double>({ 1.0,0.0,0.0,
		0.0,1.0,0.0,
		0.0,0.0,1.0 })), 1.0),
	make_tuple(Matrix(4, vector<double>({ 1.0,3.0,0.0,-1.0,0.0,2.0,1.0,3.0,3.0,1.0,2.0,1.0,-1.0,2.0,0.0,3.0 })), 14.0),
	make_tuple(Matrix(5, vector<double>({ 2.0,7.0,-1.0,3.0,2.0,
		0.0,0.0,1.0,0.0,1.0,
		-2.0,0.0,7.0,0.0,2.0,
		-3.0,-2.0,4.0,5.0,3.0,
		1.0,0.0,0.0,0.0,1.0 })), 123.0),
	make_tuple(Matrix(1, vector<double>({ 5.0 })), 5.0),
	make_tuple(Matrix(1, vector<double>({ -1.0 })), -1.0)
));

TEST_P(DeterminantCalculationTests, CheckDeterminantCalculationTest) {
	Matrix a = get<0>(GetParam());
	double expected_value = get<1>(GetParam());

	if (a.columns != a.rows) {
		EXPECT_THROW(a.determinant(), InvalidShapeDeterminant);
	}
	else {
		double det = a.determinant();
		EXPECT_TRUE(det == expected_value);
	}
}
