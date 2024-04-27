#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int compare( char* a , char* b )
{
	int count = 0 ;
	for ( int i = 0 , j = 0; i < strlen( a ) ; ++i )
	{
		if ( a[i] == b[j] )
		{
			j++ ;
			count = i ;
		}
		else
		{
			j = 0; 
			count = 0 ;
		}
		if ( strlen(b)-1 == j )
		{
			return 1 ;
		}
	}
	return 2 ;
}
int main ()
{
	char keyword[4][10] = {
		"bye\n",
		"hello\n",
		"program\n" , 
		"christmas\n"
	} ;
	char line[100] ;
	bool flag = true ;
	int count = 0 ;
	while ( 1 )
	{
		printf( "Input message: " ) ;
		fgets( line , 100 , stdin ) ;
		count = 1000 ;
		int index = -1 ;
		for ( int i = 0 ; i < 4 ; ++i )
		{
			if ( compare( line , keyword[i] ) == 1 )
			{
				index = i ;
				break ;
			}
		}
		switch ( index )
		{
			case 0 :
				printf( "Bye~\n" ) ;
				return 0 ;
			case 1 :
				printf( "Hi, how are you?\n" ) ;
				break ;
			case 2 :
				printf( "Programming is fun!\n" ) ;
				break ;
			case 3 :
				printf( "Merry Christmas!\n" ) ;
				break ;
			default :
				printf( "I don't know what you're talking about.\n" ) ;
				break ;
		}
	}
}


