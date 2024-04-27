#include "../src/publication.h"
#include "../src/magazine.h"
#include "../src/novel.h"
class PublicationTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}

    Magazine magazine {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Novel novel { 12 , "willison" , "wlison"};
};

TEST_F( PublicationTestCase , Magazine )
{
    Publication* p1 = &magazine ;
    ASSERT_EQ( p1 -> id() , 1 );
}

TEST_F( PublicationTestCase , Novel)
{
    Publication* p1 = &novel ;
    ASSERT_EQ( p1 -> id() , 12 );
}

TEST_F( PublicationTestCase , Introduction )
{
    Publication* p1 = &novel ;
    ASSERT_EQ( p1 -> introduction() , "A novel named willison" );
}

TEST_F( PublicationTestCase , OverLoad )
{
    Publication* p1 = &novel ;
    Publication* p2 = &magazine; 
    ASSERT_EQ( *p1 == *p2 , false );
}