#include "pch.h"

class MatrixMultiplicationByMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};

TEST_P(MatrixMultiplicationByMatrixTests, MatrixMultiplicationByMatrixTest) {
	Matrix a = get<0>(GetParam());
	Matrix b = get<1>(GetParam());
	Matrix matrix_exp = get<2>(GetParam());

	Matrix a_b_prod = a * b;
	ASSERT_TRUE(matrix_exp == a_b_prod);
}

INSTANTIATE_TEST_CASE_P(MatrixMultiplicationByMatrixTest, MatrixMultiplicationByMatrixTests, ::testing::Values(
	make_tuple(Matrix(1, 0.0), Matrix(1,1.0), Matrix(1,0.0)),
	make_tuple(Matrix(1, 1.0), Matrix(1,1.0), Matrix(1,1.0)),
	make_tuple(Matrix(1, 1.0), Matrix(1,2.0), Matrix(1,2.0)),
	make_tuple(Matrix(1, 2.0), Matrix(1,1.0), Matrix(1,2.0)),
	make_tuple(Matrix(1,1.0), Matrix(1, 3, 1.0), Matrix(1,3,1.0)),
	make_tuple(Matrix(3,1, 1.0), Matrix(1, 1.0), Matrix(3, 1, 1.0)),
	make_tuple(Matrix(2, 3, vector<double>({2.0,1.0,3.0,
		-1.0,2.0,4.0})),
		Matrix(3,2,vector<double>({1.0,3.0,
			2.0,-2.0,
			-1.0,4.0})),
		Matrix(2, vector<double>({1.0,16.0,
			-1.0,9.0})))
));
