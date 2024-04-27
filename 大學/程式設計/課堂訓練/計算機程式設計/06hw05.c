#include <stdio.h>
void f1 ( int a )
{
	for ( int i = 1 ; i < a+1 ; ++i )
	{
		printf( "%d" , i ) ;
	 } 
}
void f2 ( int a )
{
	for ( int i = a ; i > 0 ; --i )
	{
		printf( "%d" , i ) ;
	}
}
void f3 ( int a , int b )
{
	for ( int i = 1 ; i < b-a ; ++i )
		printf( "_" ) ; 
}
void f4 ( int a )
{
	for ( int i = a ; i > 1 ; --i )
		printf( "%d" , i ) ;
}
void f5 ( int a )
{
	for ( int i = a ; i > 0 ; --i )
		printf( "%d" , i ) ;
}
int main ()
{
	int a , b ;
	scanf( "%d\n%d" , &a , &b ) ;
	if ( a == 1 )
	{
		for ( int i = 1 ; i < b+1 ; ++i )
		{
			f1( i ) ;
			printf( "\n" ) ;
		}
		for ( int i = b ; i > 0 ; --i )
		{
			f2( i ) ;
			printf( "\n" ) ;
		}
	}
	else if ( a == 2 )
	{
		for ( int i = 1 ; i < b ; ++i )
		{
			f3( i , b ) ;
			//printf( "\n" ) ;
			f4( i ) ;
			//printf( "\n" ) ;
			f1( i ) ;
			//printf( "\n" ) ;
			f3( i , b ) ;
			printf( "\n" ) ;
		}
		for ( int i = b-1 ; i > 0 ; --i )
		{
			f3( i , b ) ;
			//printf( "\n" ) ;
			f4( i ) ;
			//printf( "\n" ) ;
			f1( i ) ;
			//printf( "\n" ) ;
			f3( i , b ) ;
			printf( "\n" ) ;
		}
	}
	else if ( a == 3 )
	{
		for ( int i = 1 ; i < b+1 ; ++i )
		{
			f1( i ) ;
			f5( i-1 ) ;
			printf( "\n" ) ;
		}
	}
	else
		printf( "ERROR\n" ) ;
}
