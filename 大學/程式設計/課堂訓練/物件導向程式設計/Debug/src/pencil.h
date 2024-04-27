#pragma once
#include "./stationery.h"
#include <string>
using namespace std;

class Pencil :  public Stationery {
private:
    double _length;
    double _num_hard;
    string _hardness;
public:
    Pencil(double length, string hardness){

        if (length <= 0 || length > 50){
            throw string("length invalid input");
        }

        if(hardness == "2H"){
            _num_hard = 2.6;
        }else if (hardness == "H"){
            _num_hard = 3.1;
        }else if(hardness == "HB"){
            _num_hard = 1.9;
        }else if(hardness == "B"){
            _num_hard = 2.5;
        }else if(hardness == "2B"){
            _num_hard = 2.0;
        }else {
            throw string("hardness invalid input");
        }

        this->_length = length;
        this->_hardness = hardness;
    }

    string name() const{
        return _hardness + ' ' + "Pencil";
    }

    double price() const{
        return _length * _num_hard;
    }

};