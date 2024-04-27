#include <stdio.h>
int F ( int num )
{
	if ( num == 1 || num == 2 )
		return 1 ;
	else
		return F( num - 1 ) + F( num - 2 ) ;
}
int main ()
{
	int num ;
	printf( "Input number: " ) ;
	scanf( "%d" , &num ) ;
	printf( "The Fibanacci number F(%d) = %d.\n" , num , F(num) ) ;
}
