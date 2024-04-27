#include <stdio.h>
#include <string.h>
int main ()
{
	int a , sum = 0 ;
	printf( "n = " ) ;
	scanf( "%d" , &a ) ;
	while ( a > 0 )
	{
		sum += a%10 ; 
		a /= 10 ; 
	}
	printf( "f(n) = %d\n" , sum ) ;
}
