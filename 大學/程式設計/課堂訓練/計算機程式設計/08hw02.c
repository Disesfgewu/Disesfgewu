#include <stdio.h>
int main ()
{
	printf( "Matrix 4 * 4, \n" ) ;
	
	int arr[5][5] = {0} ;
	for ( int i = 0 ; i < 4 ; ++i )
	{
		printf( "Enter the row %d: " , i+1 ) ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			scanf( "%d" , &arr[i][j] ) ;
			arr[i][4] += arr[i][j] ; 
			arr[4][j] += arr[i][j] ;
		}
	}
	printf( "Row totals = " ) ;
	for ( int i = 0 ; i < 4 ; ++i )
		printf( "%d " , arr[i][4] ) ;
	printf( "\nColumn totals = " ) ;
	for ( int i = 0 ; i < 4 ; ++i )
		printf( "%d " , arr[4][i] ) ; 
}
