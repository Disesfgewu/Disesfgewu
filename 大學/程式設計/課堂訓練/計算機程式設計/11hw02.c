#include <stdio.h>
int di ( int a , int b , int* re1 , int* re2 )
{
	if ( b == 0 )
	{
		return -1 ;
	}
	else
	{
		*re1 = a/b ;
		*re2 = a%b ;
		return 1 ;
	}
}
int main ()
{
	int a , b ;
	printf( "Dividend: " ) ;
	scanf( "%d" , &a ) ;
	printf( "Divisor: " ) ;
	scanf( "%d" , &b ) ;
	int ans1 , ans2 ;
	int f = di( a , b , &ans1 , &ans2 ) ;
	if ( f == -1 )
	{
		printf( "Error!\n" ) ;
	}
	else
	{
		printf( "Quotient: %d\nDivision: %d\n" , ans1 , ans2 ) ; 
	}
 } 
