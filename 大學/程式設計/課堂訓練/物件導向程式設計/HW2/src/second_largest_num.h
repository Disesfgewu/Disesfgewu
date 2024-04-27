#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
    return a > b;
}

int second_largest_num(int *array, int dim)
{
    if (dim <= 0)
        throw "InvaildArray";
    sort(array, array + dim, cmp);
    int count = array[0];
    for (int i = 0; i < dim; ++i)
    {
        if (count != array[i])
            return array[i];
    }
    throw "exception";
}