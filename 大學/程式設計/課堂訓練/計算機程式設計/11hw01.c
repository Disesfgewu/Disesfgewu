#include <stdio.h>
int adder( int a , int b , int* re1 ,int* re2 )
{
	int k = a+b ;
	if ( k > 19 || k < 0 )
		return -1 ;
	else if ( k >= 0 && k <= 9 )
	{
		*re1 = 0 ;
		*re2 = k ;
		return k ;
	}
	else
	{
		*re1 = 1 ;
		*re2 = k ;
		return k ;
	}
}
int main ()
{
	int a , b ;
	printf( "Summand: " ) ;
	scanf( "%d" , &a ) ;
	printf( "Addend: " ) ;
	scanf( "%d" , &b ) ;
	int *result1 , *result2 ;
	int carry , sum ;
	int sub = adder( a , b , &carry , &sum ) ;
	if ( sub != -1 )
	{
		printf( "Carry: %d\nSum: %d\n" , carry , sum%10  ) ;
	}
	else
		printf( "Error!\n") ;
}
