#include "../src/get_vector_function.h"
#include "../src/show_result_function.h"
#include "../src/continue_or_quit_function.h"
#include <vector>
#include <string>
using namespace std;
TEST(InnerProductTestCase, InputTest)
{
    string s = "1 1.908";
    vector<double> u;
    u = get_vector(s);
    ASSERT_EQ(u[0], 1);
    ASSERT_EQ(u[1], 1.908);
}

TEST(InnerProductTestCase, IPtest)
{
    vector<double> u = {2, 1.0, 1.0};
    vector<double> v = {2, 0, 9.123};
    double product = show_result(u, v);
    ASSERT_EQ(product, 9.123);
}