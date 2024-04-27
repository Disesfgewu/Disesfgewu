#include "../src/library.h"

TEST( LibraryTestCase, HasBookTrueTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    Library n1 { { B1 , B2 } };
    ASSERT_EQ( n1.hasBook(B1) , true) ;
}

TEST( LibraryTestCase, HasBookFalseTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Library n1 { { B1 , B2 } };
    ASSERT_EQ( n1.hasBook(B3) , false) ;
}

TEST( LibraryTestCase, AddBookTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Library n1 { { B1 , B2 } };
    n1.addBook( B3 );
    ASSERT_EQ( n1.hasBook(B3) , true) ;
}

TEST( LibraryTestCase, RemoveBookTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Library n1 { { B1 , B2 , B3 } };
    n1.removeBook( B3 );
    ASSERT_EQ( n1.hasBook(B3) , false) ;
}

TEST( LibraryTestCase, ExceptionTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Library n1 { { B1 , B3 } };
    ASSERT_ANY_THROW( n1.removeBook( B2 ) ) ;
}