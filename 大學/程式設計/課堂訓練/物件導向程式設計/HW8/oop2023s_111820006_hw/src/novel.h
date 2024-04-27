#pragma once
#include <string>
#include "./publication.h"
using namespace std;

class Novel : public Publication
{
    public:
        Novel( int id, string name, string author)
        : Publication( id , name), _author(author) , _id(id), _name(name)
        {

        }
        string author() const{
            return _author;
        }

        std::string name_of_type() const override
        {
            return "novel" ;
        }
    private:
        int _id;
        string _name;
        string _author;
};