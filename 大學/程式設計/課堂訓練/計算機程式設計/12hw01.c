#include <stdio.h>
int main ()
{
	int num[5] = { 1 , 2 , 3 , 4 , 5 } ;
	printf( "insert position, insert value: " ) ;
	int pos , ins ;
	scanf( "%d%d" , &pos , &ins ) ;
	for ( int i = 4 ; i >= pos ; --i )
		*( num+i ) = *( num+i-1 ) ;
	*( num+pos-1 ) = ins ;
	printf( "array = " ) ;
	for ( int i = 0 ; i < 5 ; ++i )
		printf( "%d " , *( num+i ) ) ; 
} 
