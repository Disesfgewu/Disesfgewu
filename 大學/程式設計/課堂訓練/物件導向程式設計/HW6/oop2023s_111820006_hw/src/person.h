#pragma once
#include "./library.h"
using namespace std ;

class Person {
private:
    int ID;
    string Name;
    vector <Book> the_books;     
public:
    Person(int id, std::string name)
    : ID(id) , Name( name )
    {
    }

    int id() const {
        return ID;
    }

    std::string name() const {
        return Name;
    }

    std::vector<Book> books() const {
        return the_books;
    }

    bool hasBook(const Book & book) const {
        for ( int i = 0 ; i < the_books.size() ; ++i )
        {
            if ( book == the_books[i] )
                return true;
        }
        return false;
    }
    
    void addBook(const Book & book) {
        if ( the_books.size() >= 2 )
            throw std::string( "fail" );
        if ( hasBook( book ) )
            throw std::string( "fail" );
        for ( int i = 0 ; i < the_books.size() ; ++i )
        {
            if ( book.id() == the_books[i].id() )
                throw std::string( "fail" );
        }
        the_books.push_back( book );
    }

    void removeBook(Book book) {
        if ( !hasBook( book ) )
            throw std::string( "fail" );
        for ( auto i = the_books.begin() ; i != the_books.end() ; ++i )
        {
            if ( book == *i )
            {
                the_books.erase( i );
                return ;
            }
        }
    }

    bool operator== (const Person & p) const {
        if ( id() != p.id() )
            return false;
        else if ( name() != p.name() )
            return false;
        else
        {
            if ( the_books.size() != p.the_books.size() )
                return false; 
            for ( int i = 0 ; i < the_books.size() ; ++i )
            {
                if ( the_books[i] == p.the_books[i] )
                {}
                else
                    return false;
            }
            return true;
        }
    }
};
