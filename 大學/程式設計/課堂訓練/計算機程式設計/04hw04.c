#include <stdio.h>
int main ()
{
	int num , last_digits ;
	printf( "Enter a integer : " ) ;
	scanf( "%d" , &num ) ;
	last_digits =  num % 100 ;
	if ( last_digits % 4 == 0 )
		printf( "%d is a multiple of 4\n" , num ) ;
	else 
		printf( "%d is not a multiple of 4\n" , num ) ;
	return 0 ; 
 } 
