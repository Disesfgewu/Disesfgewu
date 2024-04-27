#include <stdio.h>
#include <math.h>
int ans ( int t )
{
	int i = 0 , sum = 0 ;
	while ( t > 0 )
	{
		sum += t%10*pow( 2 , i ) ;
		i++ ;
		t /= 10 ;
	}
	return sum ;
}
int main ()
{
	int binary , decimal ;
	printf( "Enter a binary number : " ) ;
	scanf( "%d" , &binary ) ;
	decimal =  ans( binary ) ;
	printf( "The decimal number is %d" , decimal ) ;
}
