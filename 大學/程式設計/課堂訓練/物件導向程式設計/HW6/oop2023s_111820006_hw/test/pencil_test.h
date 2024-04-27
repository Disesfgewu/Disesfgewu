#include "../src/pencil.h"
TEST(PencilTestCase, NumberCase)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");

    ASSERT_EQ(p1.number(), 3.1);
    ASSERT_EQ(p2.number(), 2.0);
    ASSERT_EQ(p3.number(), 2.6);
}

TEST(PencilTestCase, LengthErrorCase)
{
    ASSERT_ANY_THROW(Pencil p1(-109, "H"));
    ASSERT_ANY_THROW(Pencil p1(52, "H"));
}

TEST(PencilTestCase, HardnessErrorCase)
{
    ASSERT_ANY_THROW(Pencil p1(1, "Wilson"));
    ASSERT_ANY_THROW(Pencil p1(1, "Willison"));
}

TEST(PencilTestCase, PriceCase)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");

    ASSERT_EQ(p1.price(), 3.1 * 18);
    ASSERT_EQ(p2.price(), 2.0 * 15);
    ASSERT_EQ(p3.price(), 2.6 * 12);
}

TEST(PencilTestCase, NameCase)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");

    ASSERT_EQ(p1.name(), "H Pencil");
    ASSERT_EQ(p2.name(), "2B Pencil");
    ASSERT_EQ(p3.name(), "2H Pencil");
}