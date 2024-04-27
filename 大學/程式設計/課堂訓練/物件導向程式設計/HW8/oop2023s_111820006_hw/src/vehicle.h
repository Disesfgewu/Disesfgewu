#pragma once

#include <string>

class Vehicle
{
protected:
    std::string _brand;

public:
    Vehicle() {}

    Vehicle(const std::string &brand) : _brand(brand)
    {
    }

    // destructor
    virtual ~Vehicle()
    {
    }

    // return brand of vehicle
    std::string brand() const
    {
        return _brand;
    }
};