#include "pch.h"

class MatrixAdditionTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};


TEST_P(MatrixAdditionTests, MatrixAdditionTest){
	Matrix a = get<0>(GetParam());
	Matrix b = get<1>(GetParam());
	Matrix matrix_exp = get<2>(GetParam());

	Matrix add_a_b = a + b;

	ASSERT_TRUE(add_a_b == matrix_exp);
}

INSTANTIATE_TEST_CASE_P(MatrixAdditionTest, MatrixAdditionTests, ::testing::Values(
	make_tuple(
		Matrix(1, 1.0),
		Matrix(1, 1.0),
		Matrix(1, 2.0)
	),
	make_tuple(
		Matrix(2,vector<double>({1.0,0.0,0.0,1.0})),
		Matrix(2,vector<double>({0.0,1.0,1.0,0.0})),
		Matrix(2,vector<double>({1.0,1.0,1.0,1.0}))
	),
	make_tuple(
		Matrix(2,3,vector<double>({3.0,5.0,10.0,
			1.0,2.0,15.0})),
		Matrix(2, 3, vector<double>({ 2.0,5.0,-2.0,
			4.0,-4.0,5.0 })),
		Matrix(2, 3, vector<double>({ 5.0,10.0,8.0,
			5.0,-2.0,20.0 }))
	),
	make_tuple(
		Matrix(3,2,vector<double>({1.0,5.0,
			4.0,8.0,
			5.0,2.0})),
		Matrix(3, 2, vector<double>({ 2.0,5.0,
			6.0,10.0,
			7.0,12.0 })),
		Matrix(3, 2, vector<double>({ 3.0,10.0,
			10.0,18.0,
			12.0,14.0 }))
	)
));