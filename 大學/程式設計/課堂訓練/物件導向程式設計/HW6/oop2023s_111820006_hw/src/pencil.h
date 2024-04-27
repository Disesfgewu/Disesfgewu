#pragma once
#include <cstring>
#include "./stationery.h"

using namespace std;

class Pencil : public Stationery
{
private:
    double length;
    string hardness;

public:
    string s = "error";
    Pencil(const double _length, const string _hardness)
        : length(_length), hardness(_hardness)
    {
        if (_length > 50 || _length <= 0)
            throw s;

        if (_hardness != "H" && _hardness != "B" && _hardness != "2B" && _hardness != "HB" && _hardness != "2H")
            throw s;
    }
    double number() const
    {
        if (hardness.size() == 1)
        {
            if (hardness == "H")
                return 3.1;
            else if (hardness == "B")
                return 2.5;
            else
                throw s;
        }
        else
        {
            if (hardness == "2H")
                return 2.6;
            else if (hardness == "HB")
                return 1.9;
            else if (hardness == "2B")
                return 2.0;
            else
                throw s;
        }
    }
    double price() const
    {
        return length * number();
    }
    string name() const
    {
        return hardness + " " + "Pencil";
    }
};