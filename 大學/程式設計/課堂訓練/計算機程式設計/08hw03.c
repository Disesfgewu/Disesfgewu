#include <stdio.h>
#include <string.h>
int main ()
{
	char num[10000] ;
	printf( "Enter a number: " ) ;
	scanf( "%s" , &num ) ;
	for ( int i = 0 ; i < strlen( num ) ; ++i )
	{
		if ( num[i] == '2' )
			num[i] = 'T' ;
		else
			num[i] = 'F' ;
	}
	printf( "Converted string: %s\n" , num ) ;
}
