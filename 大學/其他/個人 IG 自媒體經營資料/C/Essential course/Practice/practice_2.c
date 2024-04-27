#include <stdio.h>

int main ()
{
	int m , n ;
	printf( "Please input m and n : ") ;
	scanf( "%d%d" , &m , &n ) ;
	int a = m+n ;
	int b = m-n ;
	int c = m*n ;
	printf( "m+n = %d\n" , a ) ;
	printf( "m-n = %d\n" , b ) ;
	printf( "m*n = %d\n" , c ) ;
	return 0 ;
}


