#pragma once
#include "math_vector.h"
using namespace std;
string s = "exception";
class Matrix 
{
private:
    vector<MathVector> elements;
    
public:
    // Constructor here
    Matrix ( const vector <MathVector> & v )
    : elements( v )
    {
        int count = elements[0].dimension();
        for ( int i = 0 ; i < elements.size() ; ++i )
        {
            if ( elements[i].dimension() != count )
                throw s;
        }
    }

    // return number of rows
    int rows() const 
    {
        return elements.size();
    }

    // return number of columns
    int columns() const 
    {
        return elements[0].dimension();
    }

    // return matrix column as MathVector
    MathVector at_column(int col) const 
    {
        vector <double> reg_result;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            reg_result.push_back( elements[i].at(col) );
        }
        MathVector result { { reg_result } };
        return result;
    }

    // Return matrix row as MathVector
    MathVector at_row(int row) const
    {
        return elements.at(row-1);
    }

    // Here are tamplate methods, you can use it or define by yourself
    Matrix add(Matrix & mv) const 
    {
        if ( rows() != mv.rows() || columns() != mv.columns() )
            throw s;
        vector <MathVector> reg_result;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            vector <double> register_result;   
            for ( int j = 1 ; j <= columns() ; ++j )
            {
                register_result.push_back( elements[i].at(j) + mv.at_row(i+1).at(j) );
            }
            MathVector reg { { register_result } };
            reg_result.push_back( reg );
        }
        Matrix result = { reg_result } ;
        return result;
    }

    Matrix minus(Matrix & mv) const 
    {
        if ( rows() != mv.rows() || columns() != mv.columns() )
            throw s;
        vector <MathVector> reg_result;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            vector <double> register_result;   
            for ( int j = 1 ; j <= columns() ; ++j )
            {
                register_result.push_back( elements[i].at(j) - mv.at_row(i+1).at(j) );
            }
            MathVector reg { { register_result } };
            reg_result.push_back( reg );
        }
        Matrix result = { reg_result } ;
        return result;
    }

    Matrix scalar_multiply(double scalar) const 
    {
        vector <MathVector> reg_result;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            vector <double> register_result;   
            for ( int j = 1 ; j <= columns() ; ++j )
            {
                register_result.push_back( elements[i].at(j) * scalar );
            }
            MathVector reg { { register_result } };
            reg_result.push_back( reg );
        }
        Matrix result = { reg_result } ;
        return result;
    }

    Matrix product(Matrix & mv) const 
    {
        if ( columns() != mv.rows() )
            throw s;
        vector <MathVector> reg;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            vector <double> reg_result;
            for ( int j = 0 ; j < mv.columns() ; ++j )
            {
                double count = 0 ;
                for ( int k = 0 ; k < columns() ; ++k )
                {
                    count += elements[i].at(k+1) * mv.at_row(k+1).at(j+1);
                }
                reg_result.push_back( count );
            }
            MathVector result1 = { reg_result };
            reg.push_back( result1 );
        }
        Matrix result { { reg } } ;
        return result;

    }

    // Return transposed matrix
    Matrix transpose() const 
    {
        vector <MathVector> reg_result;
        for ( int i = 0 ; i < columns() ; ++i )
        {
            reg_result.push_back( at_column(i+1) );
        }
        Matrix result { { reg_result } };
        return result;
    }

    // Return transformed MathVector
    MathVector transform(MathVector & v) const 
    {
        if ( v.dimension() != columns() )
            throw s;
        vector <double> reg;
        for ( int i = 0 ; i < rows() ; ++i )
        {
            double count = 0 ;
            for ( int j = 0 ; j < columns() ; ++j )
            {
                count += elements[i].at(j+1) * v.at(j+1);   
            }
            reg.push_back( count );
        }
        MathVector result { { reg } };
        return result;
    }

    // Operator overloading can either be here or outside the class
};

Matrix operator+ ( Matrix & m , Matrix & n )
{
    return m.add( n ) ;
}
Matrix operator- ( Matrix & m , Matrix & n )
{
    return m.minus( n ) ;
}
Matrix operator* ( Matrix & m , Matrix & n )
{
    return m.product( n ) ;
}
Matrix operator* ( double a, Matrix & n )
{
    return n.scalar_multiply( a ) ;
}
Matrix operator* ( Matrix & n, double a)
{
    return n.scalar_multiply( a ) ;
}