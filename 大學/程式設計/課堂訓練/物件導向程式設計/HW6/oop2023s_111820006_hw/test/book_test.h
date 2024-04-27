#include "../src/book.h"

TEST( BookTestCase, IDTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    ASSERT_EQ( B1.id() , 10 );
}

TEST( BookTestCase, NameTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    ASSERT_EQ( B1.name() , "wiki" );
}

TEST( BookTestCase, AuthorTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    ASSERT_EQ( B1.author() , "internet" );
}

TEST( BookTestCase, OperatorOverloadTrueTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "internet" } ; 
    ASSERT_EQ( B1 == B2 , true );
}


TEST( BookTestCase, OperatorOverloadFalseTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    ASSERT_EQ( B1 == B2 , false );
}
