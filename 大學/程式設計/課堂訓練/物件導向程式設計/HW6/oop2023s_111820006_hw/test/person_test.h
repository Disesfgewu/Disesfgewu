#include "../src/person.h"

TEST( PersonTestCase, HasBookFalseTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820016 , "Wilson" };
    ASSERT_EQ( p1.hasBook( B1 ) , false );
}

TEST( PersonTestCase, AddBookTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820016 , "Wilson" };
    p1.addBook( B1 );
    ASSERT_EQ( p1.hasBook( B1 ) , true );
}

TEST( PersonTestCase, RemoveBookTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820016 , "Wilson" };
    p1.addBook( B1 );
    p1.addBook( B2 );
    p2.addBook( B1);
    p2.addBook( B3) ;
    p1.removeBook( B1 );
    ASSERT_EQ( p1.hasBook( B1 ) , false );
}

TEST( PersonTestCase, OperatorFalseTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820016 , "Wilson" };
    p1.addBook( B1 );
    p1.addBook( B2 );
    p2.addBook( B1);
    p2.addBook( B3) ;
    p1.removeBook( B1 );
    ASSERT_EQ( p1 == p2 , false );
}

TEST( PersonTestCase, OperatorTrueTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  12 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820006 , "Martin" };
    p1.addBook( B1 );
    p1.addBook( B3 );
    p2.addBook( B1 );
    p2.addBook( B3 );
    ASSERT_EQ( p1 == p2 , true );
}

TEST( PersonTestCase, ExceptionTest )
{
    Book B1 = {  10 , "wiki" , "internet" } ;
    Book B2 = {  10 , "wiki" , "me" } ; 
    Book B3 = {  1123 , "was" , "wilson" } ; 
    Person p1 = { 111820006 , "Martin" };
    Person p2 = { 111820006 , "Martin" };
    p1.addBook( B1 );
    ASSERT_ANY_THROW( p1.addBook( B2 ) );
}