#include "../src/math_vector.h"
#include "../src/gaussian_elimination.h"
// TEST(GaussianEliminationTestCase, SwithchRowFunctionTest)
// {
//     vector<double> u_v = {1, 2, 3};
//     MathVector u = {u_v};
//     vector<double> v_v = {4, 6, 7};
//     MathVector v = {v_v};
//     switch_vector( &u, &v ) ;
//     ASSERT_EQ(v.at(1), 1);
// }
using namespace std;

TEST(GaussianEliminationTestCase, UniqueAnswerTest1 )
{
    MathVector v1 = {{2, 1, -1, 8}};
    MathVector v2 = {{-3, -1, 2, -11}};
    MathVector v3 = {{-2, 1, 2, -3}};
    vector<MathVector> matrix = {v1, v2, v3};
    vector<MathVector> result = gaussian_elimination(matrix);
    MathVector v11 = {{1, 0, 0, 2}};
    MathVector v22 = {{0, 1, 0, 3}};
    MathVector v33 = {{0, 0, 1, -1}};
    vector<MathVector> answer = {v11,v22,v33};
    cout << "TEST\n" ;
    for ( int i = 0 ; i < result.size() ; ++i )
    {
        for ( int j = 1 ; j <= result[i].dimension() ; ++j )
        {
            cout << result[i].at(j) << " " ;
            ASSERT_EQ( result[i].at(j) , answer[i].at(j) );
        }
        cout << endl;
    }
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