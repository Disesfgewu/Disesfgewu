#include <stdio.h>
int num[100] = {0} ;
int* next( void )
{
	for ( int i = 0 ; i < 100 ; ++i )
		if ( *(num+i) == 0 )
			return num+i ;
}
int* end()
{
	for ( int i = 99 ; i >= 0 ; --i )
		if ( *(num+i) != 0 )
		{
			return num+i ;
		}
}
int* begin( )
{
	return num ;
}
void PrintArray()
{
	printf( "array = " ) ;
	for ( int* i = begin() ; i <= end() ; ++i )
	{
		if ( *i == -1 )
			printf( "0 " ) ;
		else
			printf( "%d " , *i  ) ;
	}
}

int main ()
{
	int b_v , e_v ;
	int n ;
	int i = 0 ;
	while ( i < 5 )
	{
		printf( "Enter the number: " ) ;
		scanf( "%d" , &n ) ;
		if ( n <= -1 )
			break ;
		if ( n == 0 )
			*next() = -1 ;
		else
			*next() = n ;
		++i ;
	}
	if ( i == 0 )
	{
		printf( "begin value = " ) ;
		printf( "%d\n" , 0 ) ;
		printf( "end value = " ) ;
		printf( "%d\n" , 0 ) ;
		printf( "array = \n" ) ;
	}
	else
	{
		printf( "begin value = " ) ;
		if ( *begin() == -1 )
			printf( "0\n" ) ;
		else
			printf( "%d\n" , *begin() ) ;
		printf( "end value = " ) ;
		if ( *end() == -1 )
			printf( "%d\n" , 0 ) ;
		else
			printf( "%d\n" , *end() ) ;
		PrintArray() ;
	}
 } 
