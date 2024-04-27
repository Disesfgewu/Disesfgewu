#include <string>
#include <vector>
#include "./publication.h"

using namespace std;

class Library // : public Publication
{
private:
    vector <Publication *> _publication;
public:
    Library() {
    }

    Library(std::vector<Publication*> publications) 
    : _publication( publications )
    {
        for ( int i = 0 ; i < publications.size() ; ++i )
        {
            for ( int j = i+1 ; j < publications.size() ; ++j )
            {
                if ( *publications[i] == *publications[j]  )
                    throw std::string( "error" ) ;
            }
        }
    }
    
    std::vector<Publication*> publications() const {
        return _publication;
    }

    bool hasPublication(const Publication & publication) const {
        for ( int i = 0 ; i < _publication.size() ; ++i )
        {
            if ( publication == *_publication[i] )
                return true;
        }
        return false;
    }

    void addPublication(Publication * publication) {
        if ( !hasPublication( *publication ))
        {
            _publication.push_back( publication );
        }
        else
            throw std::string( "error" ) ;
    }

    void removePublication(Publication * publication) {
        if ( hasPublication( *publication))
        {
            for ( auto i = _publication.begin() ; i < _publication.end() ; ++i )
            {
                if( *i == publication )
                    _publication.erase( i );
            }
        }
        else
         throw std::string( "error" ) ;
    }
};
