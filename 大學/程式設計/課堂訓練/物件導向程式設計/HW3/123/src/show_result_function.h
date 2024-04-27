#include <vector>
using namespace std;
double show_result(vector<double> u, vector<double> v)
{
    double product = 0;
    for (int i = 1; i < u.size(); ++i)
    {
        product += u[i] * v[i];
    }
    cout << "\nThe inner product is: " << product << endl;
    return product;
}