#include "../src/car.h"

#include <gtest/gtest.h>

TEST(CarTestCase, Constructor)
{
    Car c1{"Porsche", 2022};
    ASSERT_EQ(*(c1.year()), 2022);
}

TEST(CarTestCase, ConstructorFailedWithInvalidbrand)
{
    try
    {
        Car c1{"Willison", 2022};
        FAIL();
    }
    catch (const std::string &e)
    {
        ASSERT_EQ(e, "Invalid Brand: Willison");
    }
}

TEST(CarTestCase, ConstructorFailedWithInvalidYear)
{
    try
    {
        Car c1{"Porsche", 2500};
        FAIL();
    }
    catch (const int &e)
    {
        ASSERT_EQ(e, 2500);
    }
}

TEST(CarTestCase, Destructor)
{
    Car c1{"Porsche", 2022};
    c1.~Car();

    ASSERT_EQ(c1.year(), nullptr);
}

TEST(CarTestCase, CopyConstructor)
{
    Car c1{"Porsche", 2022};
    Car c2(c1);

    ASSERT_EQ(*(c2.year()), 2022);
}

TEST(CarTestCase, CopyAssignment)
{
    Car c1{"Porsche", 2022};
    Car c2 = c1;

    ASSERT_EQ(*(c2.year()), 2022);
}

TEST(CarTestCase, CreateSuccess)
{
    Car c1 = Car::create("Porsche", 2022);

    ASSERT_EQ(*(c1.year()), 2022);
}

TEST(CarTestCase, CreateFailedWithInvalidYear)
{
    try
    {
        Car c1 = Car::create("Porsche", 2050);
        FAIL();
    }
    catch (const int &e)
    {
        ASSERT_EQ(e, 2050);
    }
}

TEST(CarTestCase, CreateFailedWithInvalidBrand)
{
    try
    {
        Car c1 = Car::create("Willison", 2022);
        FAIL();
    }
    catch (const std::string &e)
    {
        ASSERT_EQ(e, "Invalid Brand: Willison");
    }
}