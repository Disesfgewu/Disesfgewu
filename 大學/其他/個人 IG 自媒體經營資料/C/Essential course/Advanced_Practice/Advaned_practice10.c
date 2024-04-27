#include <stdio.h>
#include <string.h> // 為了使用 strlen() 函數  
int main () 
{
	char s[1000] ;
	int a[27] ;
	for ( int i = 0 ; i < 27 ; ++i )
	{
		a[i] = 0 ;
	}
	gets( s ) ;
	for ( int i = 0 ; i < strlen(s) ; ++i )
	{
		int b = (int)s[i] - 64;
		a[b]++ ;
	}
	int j = strlen( s ) ; 
	while ( j )
	{
		int flag = 0 ;
		for ( int i = 1 ; i <= 26 ; i++ )
		{
			if ( a[flag] < a[i] )
			{
				flag = i ;
			}
		}
		if ( flag == 0 )
		{
			break ;
		}
		else
		{
			printf( "%c" , (char)(flag+64 ) ) ;
			a[flag] = 0 ;
		}
	}
	printf( "\n" ) ;
	return 0 ; 
}
