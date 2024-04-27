#include <stdio.h>
int main ()
{
	int mat1[3][3] = {0} , mat2[3][3] = {0} , ans[3][3] = {0} ;
	printf( "Matrix A * B,\n" ) ;
	printf( "Enter A: (2*3)\n" ) ;
	for ( int i = 0 ; i < 2 ; ++i )
	{
		printf( "Enter the row %d: " , i+1 ) ;
		for ( int j = 0 ; j < 3 ; ++j )
			scanf( "%d" , &mat1[i][j] ) ;
	}
	printf( "Enter B: (3*2)\n" ) ;
	for ( int i = 0 ; i < 3 ; ++i )
	{
		printf( "Enter the row %d: " , i+1 ) ;
		for ( int j = 0 ; j < 2 ; ++j )
			scanf( "%d" , &mat2[i][j] ) ;
	}
	for ( int i = 0 ; i < 2 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 0 ; j < 3 ; ++j )
			sum += mat1[i][j]*mat2[j][0] ; 
		ans[i][0] = sum ;
		sum = 0 ;
		for ( int j = 0 ; j < 3 ; ++j )
			sum += mat1[i][j]*mat2[j][1] ;
		ans[i][1] = sum ; 
	}
	printf( "A * B =\n" ) ;
	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			printf( "%d " , ans[i][j] ) ;
		 } 
		printf( "\n" ) ; 
	}
}
