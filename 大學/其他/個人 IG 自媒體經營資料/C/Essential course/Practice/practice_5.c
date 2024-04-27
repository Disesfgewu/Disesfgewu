#include <stdio.h>

int main ()
{
	int M , D ;
	scanf( "%d%d" , &M , &D ) ;
	int S = ( M*2+D ) % 3 ;
	if ( S == 0 )
		printf( "´¶³q\n" ) ;
	else if ( S == 1 )
		printf( "¦N\n" ) ;
	else
		printf( "¤j¦N\n" ) ;
	return 0 ;
}
