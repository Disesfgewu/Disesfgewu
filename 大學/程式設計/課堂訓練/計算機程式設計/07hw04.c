#include <stdio.h>
#include <string.h>
int main ()
{
	char input_char[20] ;
	char use_case ;
	int i = 0 ;
	printf( "Input:" ) ;
	while ( i < 20 && ( input_char[i] = getchar() ) != '\n' )
	{
		i++ ;
	}
	use_case = input_char[0] ;
	int j = i ;
	printf( "Result: " ) ;
	if ( use_case <= 'Z' )
	{
		for ( i = 0 ; i < j ; ++i )
		{
			if ( input_char[i] == ' ' )
			{
				printf( " " ) ;
				continue ;
			}
			input_char[i] &= 223 ;
			printf( "%c" , input_char[i] ) ; 
		}
	}
	else
	{
		for ( i = 0 ; i < j ; ++i )
		{
			if ( input_char[i] == ' ' )
			{
				printf( " " ) ;
				continue ;
			}
			input_char[i] |= 32 ;
			printf( "%c" , input_char[i] ) ; 
		}
	}
}
