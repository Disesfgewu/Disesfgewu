#include <stdio.h>
#define PI 3.14 

int main ()
{
	float length = 7.5f , height = 4.0f , radius = 3.0f ;
	char shape ;
	printf( "Which shape: " ) ;
	scanf( "%c" , &shape ) ;
	if ( shape == 'r' )
	{
		printf( "Answer: " ) ;
		printf( "%.2f\n" , ( length+height ) * 2 ) ;
	}
	else if ( shape == 'c' )
	{		
		printf( "Answer: " ) ;
		printf( "%.2f\n" , ( 2 * radius ) * PI ) ;
	}
	else
	{
		printf( "Wrong option!\n" ) ;
	}
}
