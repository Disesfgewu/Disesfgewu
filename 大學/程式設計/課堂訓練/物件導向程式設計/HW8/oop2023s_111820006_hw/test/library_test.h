#include "../src/library.h"
#include "../src/publication.h"
#include "../src/magazine.h"
#include "../src/novel.h"
using namespace std;

class LibraryTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}

    Magazine magazine {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Novel novel { 12 , "willison" , "wlison"};

};
TEST_F( LibraryTestCase, LibraryConstructor){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 , p2 }};
    ASSERT_EQ( lib.hasPublication(*p1) , true );
}

TEST_F( LibraryTestCase, AddPublication){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 }};
    
    lib.addPublication( p2 );
    ASSERT_EQ( lib.hasPublication(*p2) , true );
}

TEST_F( LibraryTestCase, AddSamePublicationIdThrowException){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 }};
    
    ASSERT_ANY_THROW( lib.addPublication( p1 ));
}

TEST_F( LibraryTestCase, HasPublication){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 }};
    
   ASSERT_EQ( lib.hasPublication(*p1) , true );
}

TEST_F( LibraryTestCase, RemovePublication){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 }};
    lib.removePublication(p1) ;
    ASSERT_EQ( lib.hasPublication(*p1) , false );
}
TEST_F( LibraryTestCase, RemoveNotExistPublicationThrowException){
    Publication* p1 = &magazine;
    Publication* p2 = &novel;
    Library lib = {{ p1 }};
   
    
    ASSERT_ANY_THROW( lib.removePublication(p2) );
}