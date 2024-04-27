#include "../src/second_largest_num.h"

TEST(SecondLargestNumberTestCase, CorrectAns1)
{

    int array[] = {5, 2, 4, 8, 6};
    ASSERT_EQ(second_largest_num(array, 5), 6);
}

TEST(SecondLargestNumberTestCase, CorrectAns2)
{
    int array[] = {5, 8, 3, 5, 1};
    ASSERT_EQ(second_largest_num(array, 5), 5);
}

TEST(SecondLargestNumberTestCase, RepeatedNumberException)
{
    int array[] = {1, 1, 1};
    ASSERT_ANY_THROW(second_largest_num(array, 3));
}

TEST(SecondLargestNumberTestCase, OnlyOneElement)
{
    int array[] = {100};
    ASSERT_ANY_THROW(second_largest_num(array, 1));
}

TEST(SecondLargestNumberTestCase, InvaildArray)
{
    int array[] = {0};
    ASSERT_ANY_THROW(second_largest_num(array, -123));
}