#include "../src/eraser.h"
TEST(EraserTestCase, InvaildSizeCase)
{
    ASSERT_ANY_THROW(Eraser e1("123", "MUJI"));
}

TEST(EraserTestCase, InvaildBrandCase)
{
    ASSERT_ANY_THROW(Eraser e1("Large", "1233"));
}

TEST(EraserTestCase, SizeCase)
{
    Eraser e1("Large", "MUJI");
    ASSERT_EQ(e1.size(), 4);
}

TEST(EraserTestCase, NumberCase)
{
    Eraser e1("Large", "MUJI");
    ASSERT_EQ(e1.number(), 29);
}

TEST(EraserTestCase, PriceCase)
{
    Eraser e1("Large", "MUJI");
    ASSERT_EQ(e1.price(), 4 * 29);
}

TEST(EraserTestCase, NameCase)
{
    Eraser e1("Large", "MUJI");
    ASSERT_EQ(e1.name(), "Large MUJI Eraser");
}