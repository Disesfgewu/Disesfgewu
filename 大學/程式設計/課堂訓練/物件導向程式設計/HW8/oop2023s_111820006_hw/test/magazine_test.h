#include "../src/magazine.h"
class MagazineTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}

    Magazine m1 {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Magazine m2 { 12 , "willison" , "wlison" , "12345"};
};

TEST_F( MagazineTestCase, create )
{
    ASSERT_EQ( m1.editor() , "Sam Jacobs") ;
    ASSERT_EQ( m1.issue() , "May 26, 2016");
}