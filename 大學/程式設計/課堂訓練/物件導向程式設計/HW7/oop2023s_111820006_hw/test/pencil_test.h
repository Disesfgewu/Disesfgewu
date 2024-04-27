#include "../src/pencil.h"
class PencilTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}
    Pencil p1{"Willison",18, "H"};
    Pencil p2{"Wilson",15, "2B"};
    Pencil p3{"Oscar",12, "2H"};
};
TEST_F(PencilTestCase, NumberCase)
{
    ASSERT_EQ(p1.number(), 3.1);
    ASSERT_EQ(p2.number(), 2.0);
    ASSERT_EQ(p3.number(), 2.6);
}

TEST_F(PencilTestCase, LengthErrorCase)
{
    ASSERT_ANY_THROW(Pencil p4(-109, "H"));
    ASSERT_ANY_THROW(Pencil p5(52, "H"));
}

TEST_F(PencilTestCase, HardnessErrorCase)
{
    ASSERT_ANY_THROW(Pencil p4(1, "Wilson"));
    ASSERT_ANY_THROW(Pencil p5(1, "Willison"));
}

TEST_F(PencilTestCase, PriceCase)
{
    ASSERT_EQ(p1.price(), 3.1 * 18);
    ASSERT_EQ(p2.price(), 2.0 * 15);
    ASSERT_EQ(p3.price(), 2.6 * 12);
}

TEST_F(PencilTestCase, NameCase)
{
    ASSERT_EQ(p1.name(), "H Pencil");
    ASSERT_EQ(p2.name(), "2B Pencil");
    ASSERT_EQ(p3.name(), "2H Pencil");
}

TEST_F(PencilTestCase, IdCase)
{
    ASSERT_EQ(p1.id(), "Willison");
    ASSERT_EQ(p2.id(), "Wilson");
    ASSERT_EQ(p3.id(), "Oscar");
}