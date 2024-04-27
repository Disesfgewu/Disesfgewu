#include "../src/math_vector.h"
#include <vector>
#define dim dimension
TEST(MathVectorTestCase, TheAtFuction)
{
    vector<double> vec = {1, 1, 3, 3, 4};
    MathVector u = {vec};
    ASSERT_EQ(u.at(3), 3);
}
TEST(MathVectorTestCase, TheDimFunction)
{
    vector<double> vec = {1, 2, 3, 12, 1231, 1231412, 32};
    MathVector u = {vec};
    ASSERT_EQ(u.dim(), vec.size());
}
TEST(MathVectorTestCase, TheAddtionFunction)
{
    vector<double> vec = {1, 2, 3, 12, 1231, 1231412, 32};
    vector<double> vec2 = {2, 3, 4, 5, 6, 7, 8};
    vector<double> ans;
    for (int i = 0; i < vec.size(); ++i)
    {
        ans.push_back(vec[i] + vec2[i]);
    }
    MathVector u = {vec};
    MathVector v = {vec2};
    MathVector ans_result = {ans};
    ASSERT_EQ(u.addition(v).at(5), ans_result.at(5));
}