#include "../src/math_vector.h"
#include "../src/gaussian_elimination.h"
TEST(GaussianEliminationTestCase, SwithchRowFunctionTest)
{
    vector<double> u_v = {1, 2, 3};
    MathVector u = {u_v};
    vector<double> v_v = {4, 6, 7};
    MathVector v = {v_v};
    switch_vector( &u, &v ) ;
    ASSERT_EQ(v.at(1), 1);
}

TEST(GaussianEliminationTestCase, UniqueAnswerTest1 )
{
    MathVector v1 = {{2, 1, -1, 8}};
    MathVector v2 = {{-3, -1, 2, -11}};
    MathVector v3 = {{-2, 1, 2, -3}};
    vector<MathVector> matrix = {v1, v2, v3};
    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[0].at(4) , 2 );
}

TEST(GaussianEliminationTestCase, UniqueAnswerTest2 )
{
    MathVector v1 = {{2, 1, -1, 8}};
    MathVector v2 = {{-3, -1, 2, -11}};
    MathVector v3 = {{-2, 1, 2, -3}};
    vector<MathVector> matrix = {v1, v2, v3};
    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[2].at(4) , -1 );
}

TEST(GaussianEliminationTestCase, InfiniteAnswerTestRow2Index1 )
{
    MathVector v1 = {{2, 4, 6, 10}};
    MathVector v2 = {{1, 2, 3, 5}};
    vector<MathVector> matrix = {v1, v2};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[1].at(1) , 0 );
}

TEST(GaussianEliminationTestCase, InfiniteAnswerTestRow2Index2 )
{
    MathVector v1 = {{2, 4, 6, 10}};
    MathVector v2 = {{1, 2, 3, 5}};
    vector<MathVector> matrix = {v1, v2};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[1].at(2) , 0 );
}

TEST(GaussianEliminationTestCase, InfiniteAnswerTestRow2Index3 )
{
    MathVector v1 = {{2, 4, 6, 10}};
    MathVector v2 = {{1, 2, 3, 5}};
    vector<MathVector> matrix = {v1, v2};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[1].at(3) , 0 );
}

TEST(GaussianEliminationTestCase, InfiniteAnswerTestRow2Index4 )
{
    MathVector v1 = {{2, 4, 6, 10}};
    MathVector v2 = {{1, 2, 3, 5}};
    vector<MathVector> matrix = {v1, v2};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[1].at(4) , 0 );
}

TEST(GaussianEliminationTestCase, NoAnswerTestRow2Index1 )
{
    MathVector v1 = {{1, 2, 3, 4}};
    MathVector v2 = {{4, 5, 6, 7}};
    MathVector v3 = {{7, 8, 9, 10}};

    vector<MathVector> matrix = {v1, v2, v3};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[2].at(1),0);

}

TEST(GaussianEliminationTestCase, NoAnswerTestRow2Index2 )
{
    MathVector v1 = {{1, 2, 3, 4}};
    MathVector v2 = {{4, 5, 6, 7}};
    MathVector v3 = {{7, 8, 9, 10}};

    vector<MathVector> matrix = {v1, v2, v3};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[2].at(2),0);

}

TEST(GaussianEliminationTestCase, NoAnswerTestRow2Index3 )
{
    MathVector v1 = {{1, 2, 3, 4}};
    MathVector v2 = {{4, 5, 6, 7}};
    MathVector v3 = {{7, 8, 9, 10}};

    vector<MathVector> matrix = {v1, v2, v3};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[2].at(3),0);

}

TEST(GaussianEliminationTestCase, NoAnswerTestRow2Index4 )
{
    MathVector v1 = {{1, 2, 3, 4}};
    MathVector v2 = {{4, 5, 6, 7}};
    MathVector v3 = {{7, 8, 9, 10}};

    vector<MathVector> matrix = {v1, v2, v3};

    vector<MathVector> result = gaussian_elimination(matrix);
    ASSERT_EQ( result[2].at(4),0);

}