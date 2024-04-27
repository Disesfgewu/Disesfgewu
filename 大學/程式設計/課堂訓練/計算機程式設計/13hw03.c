#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main ()
{
	char str1[30] , str2[30] ;
	printf( "Input message1: " ) ;
	fgets( str1 , 30 , stdin ) ;
	printf( "Input message2: " ) ;
	fgets( str2 , 30 , stdin ) ;
	int sum = 0 ;
	bool flag = true ;
	for ( int i = 0 , j = 0 ; i < strlen( str1 ) ; ++i )
	{
		if ( str1[i] == str2[j] )
		{
			j++ ;
			sum++ ;
		}
		else
		{
			j = 0 ;
			sum = 0 ;
		}
		//printf( "%d %d\n" , j , strlen( str2 ) ) ;
		if ( j+1 == strlen(str2) )
		{
			printf( "Substring found.\n" ) ;
			flag = false ;
			break ;
		}
	}
	if ( flag )
	{
		printf( "No substring found.\n" ) ;
	}
}


