#pragma once
#include <string>
#include "device.h"
class Laptop : public Device {
private:
    double * _keyboardSize = nullptr;
public:
    // constructors
    Laptop( int size , std::string os , double keyboardSize ) 
    {
        this -> _size = size;
        this -> _os = os;
        _keyboardSize = new double( keyboardSize );
    }
    
    Laptop( double keyboardSize = 1.0) 
    {
        this -> _size = 16;
        this -> _os = "Windows";
        _keyboardSize = new double( keyboardSize );
    }
    Laptop( Laptop & other )
    {
        if ( this -> _keyboardSize != nullptr )
        {
            *(this -> _keyboardSize) = other.keyboard_size(); 
        }
        else
        {
            this -> _keyboardSize = new double( other.keyboard_size() );
        }
        this -> _size = other._size;
        this -> _os = other._os;
    }
    // Returns size of the keyboard
    double keyboard_size() const {
        return *_keyboardSize;
    }

    // Overrides the method name_of_type()
    std::string name_of_type() const override {
        return "laptop";
    }
    // copy assignment operator
    Laptop& operator=( Laptop & other )
    {
        if ( this -> _keyboardSize != nullptr )
        {
            *(this -> _keyboardSize) = other.keyboard_size(); 
        }
        else
        {
            this -> _keyboardSize = new double( other.keyboard_size() );
        }
        this -> _size = other._size;
        this -> _os = other._os;
        return *this;
    }
    // destructor
    ~Laptop()
    {
        delete _keyboardSize;
        _keyboardSize = nullptr;
    }
};
