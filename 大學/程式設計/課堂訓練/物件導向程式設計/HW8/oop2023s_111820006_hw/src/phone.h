#pragma once
#include <string>
#include "./device.h"
class Phone : public Device {
    private:
        std::string _number ;
    public:
        void create( std::string number ){
            if ( number == "" )
                throw std::string("Invalid Operation: Lack of phone number");
        }
        Phone( int size, std::string os ,std::string number = "" )
        {
            create(number);
            this -> _number = number;
            this -> _size = size;
            this -> _os =  os ;
        }
        Phone( std::string os , std::string number )
        {
            create(number);
            this -> _number = number;
            this -> _size = 16;
            this -> _os =  os ;
        }
        Phone(std::string number = "")
        {
            create(number);
            this -> _number = number;
            this -> _size = 16;
            this -> _os = "iOS" ;
        }
        std::string name_of_type() const override{
            return std::string( "phone" ) ;
        }
        std::string number() const{
            return _number;
        }
};