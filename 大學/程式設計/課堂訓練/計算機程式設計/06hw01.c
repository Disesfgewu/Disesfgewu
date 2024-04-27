#include <stdio.h>
int main ()
{
	int begin , end , sum = 0 ;
	printf( "Give a range [begin,end] : " ) ;
	scanf( "%d %d" , &begin , &end ) ;
	for ( int i = begin ; i < end+1 ; ++i )
	{
		if ( i % 2 == 0 )
			sum += i ;
	 }
	printf( "Even sum : %d\n" , sum ) ;
 } 
