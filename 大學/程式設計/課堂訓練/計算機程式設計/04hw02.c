#include <stdio.h>
int main ()
{
	int num1 , num2 , num3 ;
	printf( "Enter three integer num1, num2, num3 : " ) ;
	scanf ( "%d %d %d" , &num1 , &num2 , &num3 ) ;
	if( num1%num3 == 0 && num2%num3 == 0 )
		printf( "%d is a common factor of %d and %d\n" , num3 ,num1 , num2 ) ;
	else
		printf( "%d is not a common factor of %d and %d\n" , num3 , num1 , num2 ) ;
	return 0 ;
}
