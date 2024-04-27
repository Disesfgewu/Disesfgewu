#include "./math_vector.h"
#include <vector>
#define dim dimension

using namespace std;
void switch_vector(MathVector *A, MathVector *B)
{
    MathVector tmp = *A;
    *A = *B;
    *B = tmp;
}
vector<MathVector> gaussian_elimination(vector<MathVector> matrix)
{
    vector <MathVector> result = matrix;
    int register1 = 0 ;
    int register2 = 1 ;
    for ( int i = 0 ; i < matrix.size() ; ++i )
    {
        for ( int j = register1 ; j < matrix.size()-1 ; ++j )
        {
            if ( matrix[j].at(register2) == 0 )
                switch_vector( &matrix[j] , &matrix[j+1] );
            else 
                break ;
        }
        for ( int z = 0 ; z < matrix.size() ; ++z )
        {
            if ( z == register1 )
                continue;
            if ( matrix[register1].at(register2) == 0 ) 
                continue ;
            double mul = -matrix[z].at(register2)/matrix[register1].at(register2) ;
            if ( mul == 0 )
                continue;
            matrix[z] = matrix[z].addition( matrix[register1].scalar_mul( mul ) ) ;
        }
        register1++;
        register2++;
    }
    for ( int i = 0 ; i < matrix.size() ; ++i )
        for ( int j = 1 ; j <= matrix[i].dim() ; ++j )
            if ( matrix[i].at(j) != 0 )
            {
                matrix[i] = matrix[i].scalar_mul( 1/matrix[i].at(j) );
                matrix[i].check_minus_zero();
                break;
            }
    return matrix;
}