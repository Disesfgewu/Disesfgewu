#pragma once
#include "./math_vector.h"
#include <iostream>
using namespace std;
#define add addition
#define scalar_multiply scalar_mul
#include <typeinfo>

void print( std::vector<MathVector> matrix )
{
    for ( int i = 0 ; i < matrix.size() ; ++i )
    {
        for ( int j = 1 ; j <= matrix[i].dimension() ; ++j )
        {
            std::cout << matrix[i].at(j) << " " ; 
        }
        std::cout << endl;
    }
}
std::vector<MathVector> gaussian_elimination(std::vector<MathVector> matrix)
{
    int registerA = 0 ;
    for ( int i = 1; i <= matrix[0].dimension() ; i++ )
    {
        if ( registerA >= matrix.size() )
            break;
        for(int j = 0 ; j < matrix.size() ; ++j )
        {
            if ( j == registerA )
            {
                if ( matrix[j].at(i) != 0 ) 
                    matrix[j] = matrix[j].scalar_multiply( 1/matrix[j].at(i) ) ;
                continue;
            }
            if(matrix[j].at(i) == 0)
                continue;
            else
            {
                double x = matrix[j].at(i);
                if ( x != 0 )
                    matrix[j] = matrix[j].scalar_multiply(1/x);
            }
            double r;
            if ( matrix.at(registerA).at(i) != 0 )
                r = matrix[j].at(i) / matrix[registerA].at(i);
            else
                continue;
            //matrix[j] -= matrix.at(i).scalar_multiply(r);
            MathVector t = matrix[registerA].scalar_multiply(-r);
            matrix[j] = matrix[j].addition(t);
            // for(int z = i + 1; z <= matrix[0].dimension(); z++)
            // {
            // }
        }
        registerA++;
    }
    // doing scalaring
    if ( 2 == double( int(matrix[0].at(4)) ) )
        cout << "new_check\n" ;
    for ( int i = 0 ; i < matrix.size(); ++i)
    {
        for ( int j = 1 ; j <= matrix[i].dimension() ; ++j )
        {
            if ( matrix[i].at(j) != 0 )
            {
                if ( matrix[i].at(j) == 1 )
                    break;
                matrix[i] = matrix[i].scalar_multiply( 1/matrix[i].at(j) );
                matrix[i] = matrix[i].check_minus_zero();
                print( matrix );
                if ( matrix[0].at(4) == 2 )
                    cout << "check\n" ;
                else
                {
                    cout << "NO\n" ;   
                }
                break;
            }
        }
    }
    // int size = 0;

    // if(matrix.at(0).dimension() == 2){
    //     size = 2;
    // }
    // else size = 4;

    // for(int i = 1; i <= matrix[0].dimension() ; i++)
    // {
    //     if(matrix[i-1].at(i) == 0)
    //         continue;
    //     else
    //     {
    //         double x = matrix.at(i-1).at(i);
    //         matrix[i-1] = matrix.at(i-1).scalar_multiply(1/x);
    //     }
    //     print( matrix );
    //     for(int j = i + 1; j <= matrix[0].dimension(); j++)
    //     {
    //         double r = matrix.at(j).at(i) / matrix.at(i).at(i);\
    //             //matrix[j] -= matrix.at(i).scalar_multiply(r);
    //             MathVector t = matrix.at(i).scalar_multiply(-r);
    //             matrix[j].add(t);
    //     }
    //     print( matrix );
    // }

    // for(int i = matrix[0].dimension(); i > 1; i--)
    // {
    //     if(matrix.at(i).at(i) == 1)
    //     {
    //         for(int j = i - 1; j > 0; j--)
    //         {
    //             if(matrix.at(j).at(i) != 0){
    //                 double y = matrix.at(j).at(i);
    //                 //matrix.at(j).at(k) -= matrix.at(i).at(k) * y;
    //                 MathVector p = matrix.at(i).scalar_multiply(-y);
    //                 matrix[j].add(p);                    
    //             }
    //         }
    //     }
    //     print( matrix );
    // }
    return matrix;
}
