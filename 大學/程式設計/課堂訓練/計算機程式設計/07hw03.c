#include <stdio.h>
#include <string.h>
int main()
{
	char input_char[30] ;
	int i = 0 ;
	printf( "input:" ) ;
	while ( i < 30 && ( input_char[i] = getchar() ) != '\n' )
	{
		i++ ;
	}
	printf( "Secret Code: " ) ;
	char num[123] ;
	int j = 0 ;
	for ( i = 0 ; i < strlen( input_char ) ; ++i )
	{
		int a = (int)input_char[i] ;
		//printf( "%d\n" , a) ;
		char y[123] ;
		int h = 0 ;
		while ( a > 0 )
		{
			if ( a % 16 > 9 )
			{
				y[h] = a%16 - 10 + 'a' ;
			}
			else
				y[h] = a%16 + '0' ;
			a /= 16 ;
			++h ;
		}
		h-- ;
		while ( h >= 0 )
		{
			num[j] = y[h] ;
		//	printf( "%c" , num[j] ) ;
			j++ ;
			h-- ; 
		}
	}
	for ( i = 0 ; i < j-1 ; ++i )
		printf( "%c" , num[i] ) ;
	
}
