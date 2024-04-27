#pragma once
#include <string>
using namespace std;

class Publication {
public:
    Publication(int id=0, std::string name="") 
    : _id(id), _name(name)
    {
    }

    int id() const {
        return _id;
    }
    
    std::string name() const {
        return _name;
    }

    virtual std::string name_of_type() const = 0;

    std::string introduction() const {
        return "A " + name_of_type() + " named " + _name;
    }
    bool operator== (const Publication & publication) const {
        if ( id() == publication.id() )
            return true;
        return false;
    }
private:
    int _id;
    string _name;

};
