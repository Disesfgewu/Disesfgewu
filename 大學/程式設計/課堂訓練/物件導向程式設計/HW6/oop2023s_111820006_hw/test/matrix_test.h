#include "../src/matrix.h"
#include "../src/math_vector.h"
TEST( MatrixTestCase, AdditionTestIndex11 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu + mv;
    ASSERT_EQ( result.at_row(1).at(1) , 3 );
}

TEST( MatrixTestCase, AdditionTestIndex12 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu + mv;
    ASSERT_EQ( result.at_row(1).at(2) , 2 );
}

TEST( MatrixTestCase, AdditionTestIndex21 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu + mv;
    ASSERT_EQ( result.at_row(2).at(1) , -3 );
}

TEST( MatrixTestCase, AdditionTestIndex22 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu + mv;
    ASSERT_EQ( result.at_row(2).at(2) , -2 );
}

TEST( MatrixTestCase, MinusTestIndex11 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu - mv;
    ASSERT_EQ( result.at_row(1).at(1) , 1 );
}

TEST( MatrixTestCase, MinusTestIndex12 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu - mv;
    ASSERT_EQ( result.at_row(1).at(2) , 0 );
}

TEST( MatrixTestCase, MinusTestIndex21 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu - mv;
    ASSERT_EQ( result.at_row(2).at(1) , -3 );
}

TEST( MatrixTestCase, MinusTestIndex22 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};
    Matrix mu = { { u1, u2}};
    Matrix mv = { { v1, v2}};
    Matrix result = mu - mv;
    ASSERT_EQ( result.at_row(2).at(2) , 0 );
}


TEST( MatrixTestCase, ScalarMulTestIndex11 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};

    Matrix mu = { { u1, u2}};

    Matrix result = 2 * mu;

    ASSERT_EQ( result.at_row(1).at(1) , 4 );
}

TEST( MatrixTestCase, ScalarMulTestIndex12 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};

    Matrix mu = { { u1, u2}};

    Matrix result = 2 * mu;

    ASSERT_EQ( result.at_row(1).at(2) , 2 );
}

TEST( MatrixTestCase, ScalarMulTestIndex21 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};

    Matrix mu = { { u1, u2}};

    Matrix result = 2 * mu;

    ASSERT_EQ( result.at_row(2).at(1) , -6 );
}

TEST( MatrixTestCase, ScalarMulTestIndex22 )
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};

    Matrix mu = { { u1, u2}};

    Matrix result = 2 * mu;

    ASSERT_EQ( result.at_row(2).at(2) , -2 );
}

TEST( MatrixTestCase, TransposeTestIndex11 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(1).at(1) , 1 );
}

TEST( MatrixTestCase, TransposeTestIndex12 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(1).at(2) , 0 );
}

TEST( MatrixTestCase, TransposeTestIndex21 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(2).at(1) , 2 );
}

TEST( MatrixTestCase, TransposeTestIndex22 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(2).at(2) , -6 );
}

TEST( MatrixTestCase, TransposeTestIndex31 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(3).at(1) , 3 );
}

TEST( MatrixTestCase, TransposeTestIndex32 )
{
    MathVector v1 = {{1, 2, 3}};
    MathVector v2 = {{0, -6, 7}};

    Matrix mv = {{v1, v2}};

    Matrix transpose = mv.transpose();

    ASSERT_EQ( transpose.at_row(3).at(2) , 7 );
}

TEST( MatrixTestCase,MulMatrixTestIndex11 )
{
    MathVector u1 = {{2, 3, 4}};
    MathVector u2 = {{1, 0, 0}};
    MathVector v1 = {{0, 1000}};
    MathVector v2 = {{1, 100}};
    MathVector v3 = {{0, 10}};

    Matrix mu = {{u1, u2}};
    Matrix mv = {{v1, v2, v3}};

    Matrix result = mu * mv;

    ASSERT_EQ( result.at_row(1).at(1) , 3 );
}

TEST( MatrixTestCase,MulMatrixTestIndex12 )
{
    MathVector u1 = {{2, 3, 4}};
    MathVector u2 = {{1, 0, 0}};
    MathVector v1 = {{0, 1000}};
    MathVector v2 = {{1, 100}};
    MathVector v3 = {{0, 10}};

    Matrix mu = {{u1, u2}};
    Matrix mv = {{v1, v2, v3}};

    Matrix result = mu * mv;

    ASSERT_EQ( result.at_row(1).at(2) , 2340 );
}

TEST( MatrixTestCase,MulMatrixTestIndex21 )
{
    MathVector u1 = {{2, 3, 4}};
    MathVector u2 = {{1, 0, 0}};
    MathVector v1 = {{0, 1000}};
    MathVector v2 = {{1, 100}};
    MathVector v3 = {{0, 10}};

    Matrix mu = {{u1, u2}};
    Matrix mv = {{v1, v2, v3}};

    Matrix result = mu * mv;

    ASSERT_EQ( result.at_row(2).at(1) , 0 );
}

TEST( MatrixTestCase,MulMatrixTestIndex22 )
{
    MathVector u1 = {{2, 3, 4}};
    MathVector u2 = {{1, 0, 0}};
    MathVector v1 = {{0, 1000}};
    MathVector v2 = {{1, 100}};
    MathVector v3 = {{0, 10}};

    Matrix mu = {{u1, u2}};
    Matrix mv = {{v1, v2, v3}};

    Matrix result = mu * mv;

    ASSERT_EQ( result.at_row(2).at(2) , 1000 );
}

TEST( MatrixTestCase, LinearTestIndex11 )
{
    MathVector u1 = {{1, 3}};
    MathVector u2 = {{-2, 0}};
    MathVector v = {{-1, 2}};

    Matrix mu = {{u1, u2}};

    MathVector result = mu.transform(v);
    ASSERT_EQ( result.at(1) , 5 ) ;
}

TEST( MatrixTestCase, LinearTestIndex12 )
{
    MathVector u1 = {{1, 3}};
    MathVector u2 = {{-2, 0}};
    MathVector v = {{-1, 2}};

    Matrix mu = {{u1, u2}};

    MathVector result = mu.transform(v);
    ASSERT_EQ( result.at(2) , 2 ) ;
}