#pragma once
#include <cstring>
#include <iostream>
using namespace std ;

class Book {
private:
    int ID;
    string Name;
    string Author;
public:
    Book(int id, std::string name, std::string author) 
    : ID(id) , Name( name ) , Author( author )
    {
    }

    int id() const {
        return ID;
    }
    
    std::string name() const {
        return Name;
    }
    
    std::string author() const {
        return Author;
    }

    bool operator== (const Book & book) const {
        if ( id() != book.id() )
            return false;
        else if ( name() != book.name() )
            return false;
        else if ( author() != book.author() )
            return false;
        return true;
    }
};
