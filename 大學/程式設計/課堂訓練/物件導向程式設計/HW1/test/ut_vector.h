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
}

TEST(InnerProductTestCase, JudgeVectorLengthTest)
{
    double u[] = {1, 2, 3};
    double v[] = {0};
    ASSERT_EQ(vector_length(u, 3), 3);
    ASSERT_ANY_THROW(vector_length(v, -1));
}
