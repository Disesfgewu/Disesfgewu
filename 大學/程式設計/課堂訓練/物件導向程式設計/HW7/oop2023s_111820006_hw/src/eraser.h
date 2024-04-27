#pragma once
#include <string>
#include "./stationery.h"

using namespace std;

class Eraser : public Stationery
{
private:
    string eraser_size;
    string brand;

public:
    string s = "error";
    Eraser(const string _size, const string _brand)
        : eraser_size(_size), brand(_brand)
    {
        if (_size != "Small" && _size != "Medium" && _size != "Large")
            throw s;
        if (_brand != "Staedtler" && _brand != "MUJI" && _brand != "Pentel")
            throw s;
    }
    Eraser(const string _id, const string _size, const string _brand)
        : eraser_size(_size), brand(_brand), Stationery(_id)
    {
        if (_size != "Small" && _size != "Medium" && _size != "Large")
            throw s;
        if (_brand != "Staedtler" && _brand != "MUJI" && _brand != "Pentel")
            throw s;
    }
    double size() const
    {
        if (eraser_size == "Small")
            return 1;
        else if (eraser_size == "Medium")
            return 2;
        else
            return 4;
    }
    double number() const
    {
        if (brand == "Staedtler")
            return 15;
        else if (brand == "MUJI")
            return 29;
        else
            return 39;
    }
    double price() const
    {
        return size() * number();
    }
    string name() const
    {
        return eraser_size + " " + brand + " " + "Eraser";
    }
};
