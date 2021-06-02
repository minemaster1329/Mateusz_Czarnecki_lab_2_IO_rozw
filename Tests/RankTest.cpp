#include "pch.h"

class RankTests : public ::testing::TestWithParam<tuple<Matrix, int>> {

};

TEST_P(RankTests, RankTest) {
	Matrix a = get<0>(GetParam());
	double rank_exp = get<1>(GetParam());

	double rank_a = a.rank();
	EXPECT_TRUE(rank_exp == rank_a)<<rank_a<<" : "<<rank_exp;
}

INSTANTIATE_TEST_CASE_P(RankTest, RankTests, ::testing::Values(
	make_tuple(Matrix(1, 0.0), 0),
	make_tuple(Matrix(1, 1.0), 1),
	make_tuple(Matrix(1, 5.0), 1),
	make_tuple(Matrix(2, vector<double>({ 9.0,6.0,8.0,1.0 })), 2),
	make_tuple(Matrix(2, vector<double>({ 2.0,1.0,2.0,1.0 })), 1),
	make_tuple(Matrix(3, vector<double>({ 2.0,1.0,1.0,
		2.0,1.0,1.0,
		2.0,1.0,1.0 })), 1),
	make_tuple(Matrix(3, vector<double>({ 2.0,1.0,1.0,
		2.0,2.0,1.0,
		2.0,1.0,1.0 })), 2),
	make_tuple(Matrix(3, vector<double>({ 2.0,1.0,0.0,
		2.0,1.0,0.0,
		2.0,1.0,0.0 })), 1),
	make_tuple(Matrix(3, vector<double>({ 2.0,1.0,8.0,
		6.0,1.0,8.0,
		2.0,1.0,7.0 })), 3),
	make_tuple(Matrix(4, vector<double>({ 1.0,1.0,8.0,1.0,
		6.0,1.0,8.0,1.0,
		2.0,1.0,1.0,1.0,
		1.0,1.0,1.0,1.0 })), 3),
	make_tuple(Matrix(4, vector<double>({ 0.0,1.0,8.0,1.0,
		6.0,0.0,8.0,1.0,
		2.0,1.0,0.0,1.0,
		1.0,1.0,1.0,0.0 })), 4),
	make_tuple(Matrix(4, vector<double>({1.0,0.0,0.0,0.0,
		0.0,1.0,0.0,0.0, 
		0.0,0.0,1.0,0.0, 
		0.0,0.0,0.0,1.0 })), 4),
	make_tuple(Matrix(4, vector<double>({ 1.0,0.0,0.0,1.0,
		0.0,1.0,1.0,0.0,
		0.0,1.0,1.0,0.0,
		1.0,0.0,0.0,1.0 })), 2),
	make_tuple(Matrix(4, 3, vector<double>({1.0,3.0,0.0,
		4.0,5.0,7.0,
		1.0,-1.0,4.0,
		2.0,4.0,2.0})), 2),
	make_tuple(Matrix(2, 3, vector<double>({0.0,0.0,0.0,
		0.0 ,0.0 ,0.0})),0)
));
