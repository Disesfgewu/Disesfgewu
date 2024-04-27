#include <stdio.h>
int main ()
{
	int table[6] = {0} ;
	for ( int i = 0 ; i < 6 ; ++i )
	{
		printf( "Enter the number %d: " , i+1 ) ;
		int n ;
		scanf( "%d" , &n ) ;
		int j = 0 ;
		while ( *( table+( (n+j)%6 ) ) != 0 )
			j++ ;	
		if ( *( table+n%6 ) != 0 )
			*( table+( n+j )% 6 ) = n ;
		else
			*( table+( n%6 ) ) = n ;
	 } 
	 printf( "table: \n" ) ;
	for ( int* i = table ; i < ( table+6 ) ; ++i )
	{
		printf( "[%d] = %d\n" , i-table , *i ) ;
	}
}
