#pragma once

using namespace std;

class Stationery
{
public:
    virtual double price() const
    {
        return 0;
    }
    virtual double number() const
    {
        return 0;
    }
    virtual string name() const
    {
        return "";
    }
    virtual double size() const
    {
        return 0;
    }
};