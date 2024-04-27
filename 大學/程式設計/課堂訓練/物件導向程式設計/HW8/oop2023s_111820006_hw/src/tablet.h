#pragma once
#include <string>
#include "./device.h"
class Tablet : public Device {
    public:
        Tablet( int size = 18 , std::string os = "iOS" )
        {
            this -> _size = size;
            this -> _os = os;
        }
        std::string name_of_type() const {
            return std::string( "tablet" );
        } 
};