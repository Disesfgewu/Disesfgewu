#pragma once

using namespace std;

class Stationery
{
public:
    Stationery(){}
    Stationery( const string & id )
    : _id(id)
    {
    }
    virtual double price() const = 0;
    virtual string name() const = 0;
    string id() const
    {
        return _id;
    }
private:
    const string _id;
};