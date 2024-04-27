#include <stdio.h>
#define PI 3.14 

int main ()
{
	float length = 8.0f , height = 5.5f , radius = 2.0f ;
	char shape ;
	printf( "Which shape: " ) ;
	scanf( "%c" , &shape ) ;
	switch ( shape )
	{
		case 'r' :
			printf( "Answer:%.2f\n" , ( length+height ) * 2 ) ;
			break ;
		case 'c' :
			printf( "Answer:%.2f\n" , 2*PI*radius ) ;
			break ;
		default :
			printf( "Wrong option!\n" ) ;
			break ;
	}
	return 0 ;
}
