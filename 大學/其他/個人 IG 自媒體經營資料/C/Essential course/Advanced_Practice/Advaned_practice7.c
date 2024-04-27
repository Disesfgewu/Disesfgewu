#include <stdio.h>

int main ()
{
	int n ;
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; n != 0 ; ++i )
	{
		for ( int j = 0 ; j < n ; ++j )
		{
			for ( int z = 0 ; z < n-j-1 ; ++z )
			{
				printf( "_" ) ;
			}
			for ( int z = 0 ; z <= j ; ++z )
			{
				printf( "+" ) ; 
			}
			printf( "\n" ) ;
		}
		scanf( "%d" , &n ) ; 
	}
	return 0 ;
}


