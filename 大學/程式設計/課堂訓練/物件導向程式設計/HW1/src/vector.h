#include <cmath>
using namespace std;
double inner_product(double u[], int u_dim, double v[], int v_dim)
{
    // please check the input dimension should greater than 0
    if (u_dim != v_dim)
    {
        throw "unequal dimension";
    }

    double product = 0;
    for (int i = 0; i < u_dim; i++)
    {
        product += u[i] * v[i];
    }
    return product;
}

bool is_zero_vector(double u[], int dim)
{
    if (dim < 0)
        return false;
    if (dim == 0)
        return true;
    for (int i = 0; i < dim; ++i)
        if (u[i] != 0)
            return false;
    return true;
}

double vector_length(double u[], int dim)
{
    int count = 0;
    if (dim < 0)
    {
        throw "Undefined Vector";
    }
    else if (dim == 0)
    {
        return 0;
    }
    return dim;
}
