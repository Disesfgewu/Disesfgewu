#include "../src/novel.h"
class NovelTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}

    Novel novel { 12 , "willison" , "wlison"};
};

TEST_F( NovelTestCase, create )
{
    ASSERT_EQ( novel.id() , 12 ) ;
}