#include <stdio.h>

int main ()
{
	int score ;
	printf( "Input a score : " ) ;
	scanf( "%d" , &score ) ;
	switch ( score )
	{
		case 90 ... 100 :
			printf( "A\n" ) ;
			break ;
		case 80 ... 89 :
			printf( "B\n" ) ;
			break ;
		case 70 ... 79 :
			printf( "C\n" ) ;
			break ;
		case 60 ... 69 :
			printf( "D\n" ) ;
			break ;
		default :
			printf( "F\n" ) ;
			break ;
	}
}


