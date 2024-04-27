#include <string>
#include <vector>
#include "./publication.h"
using namespace std;

class Person 
{
private:
    int _id;
    string _name;
    vector <Publication *> _borrowed;
public:
    Person(int id, std::string name)
    : _id(id), _name(name)
    {
    }

    int id() const {
        return _id;
    }

    std::string name() const {
        return _name;
    }

    std::vector<Publication*> publicationsBorrowed() const {
        return _borrowed;
    }

    bool isBorrowed(const Publication & publication) const {
        for ( int i = 0 ; i < _borrowed.size() ; ++i )
        {
            if( _borrowed[i] -> id() == publication.id())
                return true;
        }
        return false;
    }
    
    void borrowPublication(Publication * publication) {
        if (_borrowed.size() >= 2  )
            throw std::string( "error" ) ;
        if( !isBorrowed( *publication ) )   
        _borrowed.push_back( publication );
        else    
            throw std::string( "error" ) ;
    }

    void returnPublication(Publication * publication) {
        bool f = true;
        for ( auto i = _borrowed.begin() ; i < _borrowed.end() ; ++i)
        {
            if ( *i == publication )
            {
                _borrowed.erase( i) ;
                return;
            }
        }
        throw std::string( "error" ) ;
    }

    bool operator== (const Person & p) const {
        if ( p.id() == id() )
            return true;
        return false;
    }
};
