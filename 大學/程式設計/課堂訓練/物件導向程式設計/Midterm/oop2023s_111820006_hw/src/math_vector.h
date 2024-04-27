#pragma once
#include <vector>
using namespace std;

class MathVector
{
private:
    vector<double> u;

public:
    MathVector(const std::vector<double> &v) : u(v){};
    MathVector(std::vector<double> &&v) : u(v){};

    MathVector operator=(std::vector<double> &&v)
    {
        this->u = v;

        return *this;
    }

    double at(int i) const
    {
        return u[i - 1];
    }
    int dimension(void) const
    {
        return u.size();
    }
    double inner_product(MathVector & v ) 
    {
        double product = 0 ;
        for ( int i = 1 ; i <= this->dimension() ; ++i )
            product += v.at(i) * this->at(i);
        return product;
    }
    MathVector add(const MathVector &v) const
    {
        vector<double> result;
        for (int i = 1; i <= dimension(); ++i)
        {
            result.push_back(this->at(i) + v.at(i));
        }
        MathVector the_result = result;
        return the_result;
    }

    MathVector minus(const MathVector &v) const
    {
        vector<double> result;
        for (int i = 1; i <= dimension(); ++i)
        {
            result.push_back(this->at(i) - v.at(i));
        }
        MathVector the_result = result;
        return the_result;
    }

    MathVector scalar_multiply(double a) const
    {
        vector<double> result;
        for (int i = 1; i <= dimension(); ++i)
        {
            result.push_back(at(i) * a);
        }
        MathVector the_result = {result};
        return the_result;
    }


};
MathVector scalar_multiply( double a , MathVector & v )
{
    return v.scalar_multiply(a);
}

MathVector scalar_multiply( MathVector & v , double a )
{
    return v.scalar_multiply(a);
}

MathVector operator *(double a, MathVector v)
{
    
    return v.scalar_multiply(a);
}

MathVector operator *(MathVector v, double a)
{
    
    return v.scalar_multiply(a);
}

double operator *( MathVector v , MathVector u )
{
    return v.inner_product(u);
}