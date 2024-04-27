#pragma once
#include <cstring>
#include <iostream>
#include "./book.h"
#include <vector>
#include <algorithm>
// #include <set>
using namespace std ;

class Library {
private:
    vector <Book> element;
public:
    Library(std::vector<Book> books) 
    : element( books )
    {   
    }
    
    std::vector<Book> books() const {
        return element;
    }
    Book at( int i ) const{
        return element[i] ;
    }
    bool hasBook(const Book & book) const {
        for ( int i = 0 ; i < element.size() ; ++i )
        {
            if ( book == element[i] )
                return true;
        }
        return false;
    } 

    void addBook(const Book & book) {
        if ( !hasBook(book) )
        {
            for ( int i = 0 ; i < element.size() ; ++i )
            {
                if ( element[i].id() == book.id() )
                    throw std::string( "fail" );
            }
            element.push_back( book ) ;
        }
        else  
        {
            throw std::string( "fail" );
        }
    }

    void removeBook(const Book & book) {
        if ( !hasBook( book ) )
            throw std::string( "fail" );
        for ( auto i = element.begin() ; i != element.end() ; ++i )
        {
            if ( book == *i )
            {
                element.erase( i );
                return ;
            }
        }
    }
};
