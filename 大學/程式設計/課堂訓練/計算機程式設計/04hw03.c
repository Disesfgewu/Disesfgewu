#include <stdio.h>
int main ()
{
	int num , sum ;
	printf( "Enter a three-digit number : " ) ;
	scanf( "%d" , &num ) ;
	sum = num%10 + (num/10)%10 + (num/100)%10 ;
	if ( sum % 3 == 0 )
		printf( "%d is a multiple of 3\n" , num ) ;
	else 
		printf( "%d is not a multiple of 3\n" , num ) ;
		return 0 ;
 } 
