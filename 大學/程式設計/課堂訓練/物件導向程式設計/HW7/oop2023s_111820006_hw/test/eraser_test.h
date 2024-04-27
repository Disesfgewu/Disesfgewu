#include "../src/eraser.h"
class EraserTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}
    Eraser e1{"Willison" , "Large", "MUJI"};
};
TEST_F(EraserTestCase, InvaildSizeCase)
{
    ASSERT_ANY_THROW(Eraser e("123", "MUJI"));
}

TEST_F(EraserTestCase, InvaildBrandCase)
{
    ASSERT_ANY_THROW(Eraser e("Large", "1233"));
}

TEST_F(EraserTestCase, SizeCase)
{
    ASSERT_EQ(e1.size(), 4);
}

TEST_F(EraserTestCase, NumberCase)
{
    ASSERT_EQ(e1.number(), 29);
}

TEST_F(EraserTestCase, PriceCase)
{
    ASSERT_EQ(e1.price(), 4 * 29);
}

TEST_F(EraserTestCase, IdCase )
{
    ASSERT_EQ(e1.id(), "Willison");
}

TEST_F(EraserTestCase, NameCase)
{
    ASSERT_EQ(e1.name(), "Large MUJI Eraser");
}