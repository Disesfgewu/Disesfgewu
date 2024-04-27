#include <stdio.h>
#include <string.h>
int main ()
{
	char a[100] = "" , c[100] = "" ;
	for ( int i = 0 ; i < 5 ; ++i )
	{
		printf( "Input word %d: " , i+1 ) ;
		gets( a ) ;
		if ( i != 0 )
			strcat( c , " " ) ;
		strcat( c , a ) ;
	}
	printf( "Sentence: %s.\n" , c ) ;
}


