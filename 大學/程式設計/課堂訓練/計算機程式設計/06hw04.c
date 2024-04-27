#include <stdio.h>
int main ()
{
	int score , count = 3 ;
	do 
	{
		printf( "Enter score : " ) ;
		scanf( "%d" , &score ) ;
		switch ( score )
		{
			case 90 ... 100 :
				printf( "켹 A\n" ) ;
				break ;
			case 80 ... 89 :
				printf( "켹 B\n" ) ;
				break ;
			case 70 ... 79 :
				printf( "켹 C\n" ) ;
				break ;
			case 60 ... 69 :
				printf( "켹 D\n" ) ;
				break ;
			default :
				printf( "켹 F\n" ) ;
				break ;
		}
		count-- ;
	}while ( count > 0 ) ;
}
