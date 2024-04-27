#include <stdio.h>
int power3 ( int num )
{
	if ( num == 1 )
		return 1 ;
	else if ( num%3 == 0 )
		return power3( num/3 );
	else
		return 0 ;
 } 
int main ()
{
	int input_num ;
	printf( "Input number: " ) ;
	scanf( "%d" , &input_num ) ;
	int result = power3( input_num ) ;
	if ( result == 0 )
		printf( "The input number %d is not a power of 3.\n" , input_num ) ;
	else
		printf( "The input number %d is a power of 3.\n" , input_num ) ;
	
}
