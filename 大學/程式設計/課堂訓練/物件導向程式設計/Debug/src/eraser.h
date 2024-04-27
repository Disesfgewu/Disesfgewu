#pragma once
#include "./stationery.h"
#include <string>
using namespace std;

class Eraser : public Stationery 
{
private:
    string _size;
    string _brand;
    double _size_num;
    double _brand_num;
public:
    Eraser(string size, string brand){

        if (size == "Small"){
            _size_num = 1;
        }else if(size == "Medium"){
            _size_num = 2;
        }else if(size == "Large"){
            _size_num = 4;
        }else {
            throw string("Invalid input size");
        }

        if(brand == "Staedtler"){
            _brand_num = 15;
        }else if(brand == "MUJI"){
            _brand_num = 29;
        }else if(brand == "Pentel"){
            _brand_num = 39;
        }else {
            throw string("Invalid input brand");
        }

        this->_brand = brand;
        this->_size = size;
    }

    string name() const{
        return _size + ' ' + _brand + " Eraser";
    }

    double price() const{
        return _size_num * _brand_num;
    }

};