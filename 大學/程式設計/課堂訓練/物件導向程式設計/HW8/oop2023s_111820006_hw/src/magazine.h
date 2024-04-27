#pragma once
#include <string>
#include "./publication.h"

using namespace std;

class Magazine : public Publication
{
private:
    int _id;
    string _name;
    string _editor;
    string _issue; 
public:
    Magazine( int id, string name, string editor, string issue)
    :  _editor(editor), _issue(issue), _id(id), _name(name) , Publication( id, name)
    {

    }

    std::string editor() const{
        return _editor;
    }

    std::string issue() const{
        return _issue;
    }

    std::string name_of_type() const override
    {
        return "magazine" ;
    }
};
