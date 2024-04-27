#include "../src/laptop.h"
#include "../src/device.h"
TEST( LaptopCase, CreateDefault )
{
    Laptop L1 ;
    ASSERT_EQ( L1.keyboard_size() , 1.0 );
}
TEST( LaptopCase, Create )
{
    Laptop L1{14,"iOS",123} ;
    ASSERT_EQ( L1.keyboard_size() , 123 );
}
TEST( LaptopCase, CreateWithKeyboardSize )
{
    Laptop L1{123} ;
    ASSERT_EQ( L1.keyboard_size() , 123 );
}
TEST( LaptopCase, CopyConstructor )
{
    Laptop L2{14,"iOS",123} ;
    Laptop L1(L2);
    ASSERT_EQ( L1.keyboard_size() , 123 );
}
TEST( LaptopCase, CopyAssignment )
{
    Laptop L2{14,"iOS",123} ;
    Laptop L1 = L2;
    ASSERT_EQ( L1.keyboard_size() , 123 );
}
