#include "./math_vector.h"
#include <vector>

using namespace std;
void switch_vector(MathVector *A, MathVector *B)
{
    MathVector tmp = *A;
    *A = *B;
    *B = tmp;
}
vector<MathVector> gaussian_elimination(vector<MathVector> matrix)
{
    int register1 = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i].at(1) == 0)
            register1++;
        else
            break;
    }
    switch_vector(&matrix[0], &matrix[register1]);
    register1 = 0;
    if (matrix.size() > 0)
        for (int i = 1; i <= matrix[0].dim(); ++i)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                if (j == register1)
                    continue;
                if (matrix[register1].at(i) == 0)
                    break;
                double mul = matrix[j].at(i) / matrix[register1].at(i);
                for (int z = 1; z <= matrix[j].dim(); ++z)
                {
                    matrix[j].at(z) -= mul * matrix[register1].at(z);
                }
                register1++;
                break;
            }
            
        }
    return matrix;
}
