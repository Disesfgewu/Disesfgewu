#pragma once
#include <string>

class Stationery { //calculate price 
public:
    virtual double price() const
    {
        return 0;
    }

    virtual std::string name() const
    {
        return 0;
    }

};