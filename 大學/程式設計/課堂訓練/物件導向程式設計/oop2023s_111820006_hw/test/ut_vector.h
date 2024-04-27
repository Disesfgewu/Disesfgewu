#include "../src/vector.h"

TEST(InnerProductTestCase, TwoUnitVectorsTest)
{
    double u[] = {1, 0};
    double v[] = {0, 1};

    double product = inner_product(u, 2, v, 2);
    ASSERT_EQ(product, 0.0);
}

TEST(InnerProductTestCase, TwoDThreeDTest)
{
    double u[] = {1, 0};
    double v[] = {1, 0, 0};

    ASSERT_ANY_THROW(inner_product(u, 2, v, 3));
}

TEST(InnerProductTestCase, IsZeroVectorTest)
{
    double u[] = {0};
    ASSERT_EQ(is_zero_vector(u, 1), true);
    double v[] = {0, 0, 0, 0};
    ASSERT_EQ(is_zero_vector(v, 4), true);
    double u2[] = {1, 0, 0};
    double v2[] = {0, 1, 123};
    ASSERT_EQ(is_zero_vector(u2, 3), false);
    ASSERT_EQ(is_zero_vector(v2, 3), false);
    ASSERT_ANY_THROW(is_zero_vector(u, -12));
}

TEST(InnerProductTestCase, JudgeVectorLengthTest)
{
    double u[] = {1, 2, 2};
    double v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    ASSERT_EQ(vector_length(u, 3), 3);
    ASSERT_EQ(vector_length(v, 25), 70);
    ASSERT_ANY_THROW(vector_length(v, -1));
}
