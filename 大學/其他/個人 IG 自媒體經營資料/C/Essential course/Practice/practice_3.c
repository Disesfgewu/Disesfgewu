#include <stdio.h>

int main ()
{
	int a , b ;
	printf( "Please input a and b : " ) ;
	scanf( "%d%d" , &a , &b ) ;
	int c = a%b ;
	printf( "The answer is %d\n" , c ) ;
	return 0 ;
}


