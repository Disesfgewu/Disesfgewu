#include "../src/person.h"
#include "../src/library.h"
#include "../src/publication.h"
#include "../src/magazine.h"
#include "../src/novel.h"
using namespace std;

class PersonTestCase : public :: testing :: Test
{
    protected:
        void SetUp() override {}

    Magazine magazine {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Novel novel { 12 , "willison" , "wlison"};

};