#include <stdio.h>
int main ()
{
	//The sum and the average
	int num1 , num2 , sum = 0 ;
	float avg ;
	printf( "Insert two integers , separated by a space : " ) ;
	scanf( "%d %d" , &num1 , &num2 ) ;
	sum = num1 + num2 ;
	avg = ( float )sum / 2 ;
	printf( "The sum is %d\n" , sum ) ;
	printf( "The average is %.2f" , avg ) ;
	return 0 ;
}
