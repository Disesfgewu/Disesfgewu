#include "../src/tablet.h"
#include "../src/device.h"
TEST( TabletCase, CreateDefault ){
    Tablet T1 ;
    ASSERT_EQ( T1.name_of_type(), "tablet" );
}
TEST( TabletCase, inheritence )
{
    Tablet T1;
    Device *D1 = &T1;
    ASSERT_EQ( D1 -> name_of_type() , "tablet" );
}
TEST( TabletCase, create_size )
{
    Tablet T1;
    Device *D1 = &T1;
    ASSERT_EQ( D1 -> size() , 18 );
}
TEST( TabletCase, create_os )
{
    Tablet T1;
    Device *D1 = &T1;
    ASSERT_EQ( D1 -> os() , "iOS" );
}