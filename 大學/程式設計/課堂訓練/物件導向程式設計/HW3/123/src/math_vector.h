#pragma once
#include <vector>
using namespace std;

class MathVector
{
public:
    vector<double> u;
    double at(int i)
    {
        return u[i - 1];
    }
    int dimension(void)
    {
        return u.size();
    }
    MathVector addition(MathVector v)
    {
        vector<double> result;
        for (int i = 1; i <= dimension(); ++i)
        {
            result.push_back(at(i) + v.at(i));
        }
        MathVector the_result = {result};
        return the_result;
    }
    MathVector scalar_mul(double a)
    {
        vector<double> result;
        for (int i = 1; i <= dimension(); ++i)
        {
            result.push_back(at(i) * a);
        }
        MathVector the_result = {result};
        return the_result;
    }
    MathVector check_minus_zero()
    {
        vector <double> result;
        for ( int i = 1 ; i <= dimension() ; ++i )
        {
            if ( at(i) == -0 )
                result.push_back(0);
            else
                result.push_back(at(i));
            printf( "%f " , at(i) );
        }
        printf( "\n" );
        MathVector the_result = {result};
        return the_result;
    }
};