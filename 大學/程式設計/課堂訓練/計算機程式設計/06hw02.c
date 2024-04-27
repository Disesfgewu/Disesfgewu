#include <stdio.h>
int main ()
{
	int begin , end , check = 0 ;
	printf( "Given a range [begin,end] : " ) ;
	scanf( "%d %d" , &begin , &end ) ;
	printf( "The prime numbers from %d to %d :\n" , begin , end ) ;
	for ( int i = begin ; i < end+1 ; ++i )
	{
		if ( i == 1 )
			continue ;
		int flag = 0 ; 
		for ( int j = 2 ; j < i ; ++j )
		{
			if ( i % j == 0 )
			{
				flag = 1 ;
				break ;
			}
		}
		if ( flag == 0 )
		{
			printf( "%d, " , i ) ;
		}
	}
	printf( "\n" ) ;
}
