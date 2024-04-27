#include <stdio.h>

int main ()
{
	int a, b , c ;
	while ( scanf( "%d%d%d" , &a , &b , &c ) != EOF )
	{
		int count = 0 ;
		if ( c == 0 )
		{
			if ( a == 0 || b == 0 )
			{
				printf( "AND\n" ) ;
				count ++;
			}
			if ( a == 0 && b == 0 )
			{
				printf( "OR\n" ) ;
				count++;
			}
			if ( ( a == 0 && b == 0 ) || ( a != 0 && b != 0 ) )
			{
				printf( "XOR\n" ) ;
				count++;
			}
		}
		else
		{
			if ( a != 0 && b != 0 )
			{
				printf( "AND\n" ) ;
				count++;
			}
			if ( a != 0 || b != 0 )
			{
				printf( "OR\n" ) ;
				count++;
			}
			if ( ( a == 0 && b != 0 ) || ( a == 1 && b == 0 ))
			{
				printf( "XOR\n" ) ;
				count++;
			}
		}
		if ( count == 0 )
			printf( "IMPOSSIBLE\n" ) ;
	}
	return 0 ;
}
