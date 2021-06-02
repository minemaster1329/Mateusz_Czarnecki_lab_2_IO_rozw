#include "pch.h"

#include <Windows.h>
#include <stdio.h>
#include <excpt.h>


//this test will crash and throw SEH exceptions if function has not protection from invalid data input
//when SEH crash happened, test is automatically interrupted
TEST(LoadData_From2DDoubleArray, CheckLoadDataFrom2DDoubleArray){
	const int matrix_rows = 3;
	const int matrix_cols = 4;
	
	double** numbers = new double* [matrix_rows];
	vector<double> data({ 4.0,1.0,3.0,99.0,
		4.0,1.0,3.0,99.0,
		4.0,1.0,3.0,99.0,
		4.0,1.0,3.0,99.0 });
	for (int i = 0; i < matrix_rows; i++) {
		numbers[i] = new double[matrix_cols]{4.0,1.0,3.0,99.0};
	}

	double** numbers_inv = new double* [matrix_rows - 1];
	for (int i = 0; i < matrix_rows - 1; i++) {
		numbers_inv[i] = new double[matrix_cols - 1]{ 4.0,1.0,3.0 };

	}

	double** numbers_inv2 = new double* [2];
	for (int i = 0; i < 2; i++) {
		numbers_inv2[i] = new double[6]{ 1.0,2.0,3.0,4.0,5.0,6.0 };
	}

	Matrix a(matrix_rows, matrix_cols);

	//loading data from 2d array with less dimensions than expected (expected: false)
	std::cout << "loading data from 2d array with less dimensions than expected (line 42)\n";
	bool res_1 = a.load_data(numbers_inv);
	ASSERT_FALSE(res_1);
	std::cout << "loading data passed with no exception and with false result\ntrying to load data from 2d array with the same elements count but different dimensions (line 46)\n";
	//loading data from 2d array with the same elements count, but different dimensions (expected: false)
	bool res_2 = a.load_data(numbers_inv2);
	ASSERT_FALSE(res_2);
	std::cout << "loading data passed with no exception and with false result\ntrying to load data from uninitialized 2d (line 51)\n";
	//loading data from uninitialized 2d array (expected: false)
	double** numbers_inv3 = nullptr;
	bool res_3 = a.load_data(numbers_inv3);
	ASSERT_FALSE(res_3);
	
	std::cout << "loading data passed with no exception and with false result\ntrying to make safer testing stuff";

	a.load_data(numbers);

	Matrix b(matrix_rows, matrix_cols, data);
	EXPECT_TRUE(a == b);

	Matrix c(matrix_cols, matrix_rows, data);

	EXPECT_FALSE(a == c);

	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_rows; j++) {
			EXPECT_EQ(a(i, j), numbers[i][j]);
		}
	}

	for (int i = 0; i < matrix_rows; i++) {
		delete[] numbers[i];
	}

	for (int i = 0; i < matrix_rows - 1; i++) {
		delete[] numbers_inv[i];
	}

	for (int i = 0; i < 2; i++) {
		delete[] numbers_inv2[i];
	}

	delete[] numbers_inv;
	delete[] numbers_inv2;
	delete[] numbers;
}

//when running test crashes with error "vector subsript out of range", failure was on 104 line
TEST(LoadDataWithDataVector, CheckLoadDataWithDataVector) {
	const int cols = 2;
	const int rows = 5;

	const vector<double> data({ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0});

	Matrix a(rows, cols);
	Matrix c(3, 4);

	std::cout << "loading data from vector with invalid dimensions specified (greater than ones given on initialization) (line 98)\n";
	bool result = a.load_data(data, 3, 4);
	ASSERT_FALSE(result);

	std::cout << "loading data from vector with invalid dimensions test passed and returned false\nloading data from vector with too few elements (line 102)\n"<<endl;
	
	/*bool result2 = c.load_data(data, 3, 4);
	ASSERT_FALSE(false);

	std::cout << "loading data from vector with too few elements test passed and function returned false\ntime to try less risky things\n";*/

	a.load_data(data, rows, cols);

	Matrix b(rows, cols, data);

	EXPECT_TRUE(a == b);
}

TEST(LoadDataWithInitializerFunc, CheckLoadDataWithInitializerFunc){
	Matrix a(2, 3);
	Matrix c(2, 3);
	Matrix e(2, 3);
	a.load_data([](int, int col) {return (double)col; });
	c.load_data([](int row, int) {return (double)row; });
	e.load_data([](int row, int col) {return (double)row * col; });

	Matrix b(2, 3);
	Matrix d(2, 3);
	Matrix f(2, 3);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			b(i, j) = (double)j;
			d(i, j) = (double)i;
			f(i, j) = (double)i * j;
		}
	}
	EXPECT_TRUE(a == b);
	EXPECT_TRUE(c == d);
	EXPECT_TRUE(e == f);
}




