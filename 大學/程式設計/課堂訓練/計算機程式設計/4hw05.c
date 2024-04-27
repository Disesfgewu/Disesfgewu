#include <stdio.h>
#include <string.h>
char num[15] ;
int pre_num , aft_num ;
int numk[100][100] = {0} , numb[1000] = {0} , nk[1000] = {0} , ans0[1000] = {0} , ans1[1000] = {0} ;
void swap ( int *a , int *b )
{
	int c = *a ;
	*a = *b ;
	*b = c ;
 } 
void copy_array ( int i , int j , int k )
{
	memset( nk , 0 , sizeof( nk ) ) ;
	if ( i == 1 && j == 2 )
	{
		for ( int z = 0 ; z <= k ; ++z )
			nk[z] = numk[16][z] ;
	 } 
	else if ( i == 1 && j == 3 )
	{
		for ( int z = 0 ; z < k ; ++z )
			nk[z] = ans0[z] ;
	}
	memset( ans0 , 0 , sizeof( ans0 ) ) ;
}
int right_swift( int i )
{
	int k = 1 ;
	while ( nk[0] == 0 )
	{
		k++ ;
		for ( int j = 0 ; j < i ; ++j )
		{
			swap( &nk[j] , &nk[j+1] ) ; 
		}
	}
	return k ;
}
void reverse_array ( int i , int y )
{
	if ( i == 1 )
	{
		for ( int j = 0 ; j < y-1 ; ++j )
			for ( int z = 0 ; z < y-1-j ; ++z )
				swap( &numb[z] , &numb[z+1] ) ;
	}
	else if ( i == 2 )
	{
		for ( int j = 0 ; j < y-1 ; ++j )
		{
			for ( int z = 0 ; z < y-j-1 ; ++z )
				swap( &nk[z], &nk[z+1] ) ;
		}
	}
}
int find ( int i )
{
	for ( int j = 0 ; j <= i ; ++j )
		if ( nk[j] != 0 )
			return 1 ;
	return 0 ;
} 
int main ()
{
	scanf( "%s\n%d\n%d" , &num , &pre_num , &aft_num ) ;
	int i = 0 ;
	for ( i = 0 ; num[i] ; ++i )
	{
		numb[i] = num[i] - '0' ;
		if ( numb[i] > 10 )
			numb[i] -= 7 ;
		if ( numb[i] >= pre_num )
		{
			printf( "ERROR\n" ) ;
			//break ;
		}
	}
	for ( int j = 0 ; j < i ; ++j )
		printf( "%d " , numb[j] ) ;
	printf( "1234\n" ) ;
	/// enter number 
	reverse_array( 1 , i ) ; // numb_reverse
	for ( int j = 0 ; j < i ; ++j )
		printf( "%d " , numb[j] ) ;
	printf( "1234\n" ) ;
	for ( int j = 0 ; j < i ; ++j )
	{
		numk[j][0] = 1 ;
	}
	int f = 0 , io = 0 ;
	for ( int j = 0 ; j < i ; ++j )
	{
		numk[j][0] *= numb[j] ;
		printf( "%d\n" , numk[j][0] ) ;
		if ( io < f )
			io = f ;
		f = 0 ;
		for ( int z = 0 ; z < j ; ++z )
		{
			for ( int h = 0 ; h <= f ; ++h )
			{
			 	numk[j][h] *= pre_num ;
			}
			for ( int h = 0 ; h <= f ; ++h )
			{
				while ( numk[j][h] >= 10 )
				{
					numk[j][h+1] += numk[j][h]/10 ;
			 		numk[j][h] %= 10 ;
			 		f = h+1 ;
				}
			}
		}
	}
	for ( int z = 0 ; z <= i ; ++z  )
	{
		for ( int q = 0 ; q <= f ; ++q )
			printf( "%d " , numk[z][q] ) ;
		printf( "\n" ) ;
	}
	// each number convert to 10
	printf( "%d\n" , f ) ;
	int j = 0 ;
	for ( j = 0 ; j <= f ; ++j )
	{
		for ( int z = 0 ; z < i ; ++z )
		{
			numk[16][j] += numk[z][j] ;
		}
		while ( numk[16][j] >= 10 )
		{
			numk[16][j+1] += numk[16][j]/10 ;
			numk[16][j]   %= 10 ; 
		}
	}
	while ( numk[16][j] >= 10 )
	{
		numk[16][j+1] += numk[16][j]/10 ;
		numk[16][j]   %= 10 ;
		j++ ; 
	}
	for ( int z = 0 ; z < j ; ++z  )
		printf( "%d " , numk[16][z] ) ;
	printf( "\n" ) ;
	// sum of these numbers 
	copy_array ( 1 , 2 , j-1 ) ;
	printf("jhyuikjik\n" ) ;
	int h = 0 ;
	io = 0 ;
	reverse_array( 2 , j ) ;
	
	for ( int z = 0 ; z < j ; ++z  )
		printf( "%d " , nk[z] ) ;
	printf( "\n" ) ;
	do
	{
		io = 0 ;
		while ( io < j )
		{
			if ( nk[io] < aft_num )
			{
				nk[io] *= 10 ;
				nk[io+1] += nk[io] ;
				nk[io] = 0 ;
				io++ ;
				//printf( "%d\n" , nk[io] ) ;
			}
			else
			{
				ans0[io] = nk[io] / aft_num ;
				nk[io] %= aft_num ;
				printf( "%d\nffffffffffff\n" , ans0[io] ) ;
			}
		}
		for ( int z = 0 ; z <= io ; ++z )
		{
			printf( "%d " , nk[z] ) ;
		}
		printf( "\n" ) ;
		ans1[h] = nk[io]%aft_num ; 
		printf( "%d\ndfghjkl\n" , ans1[h] ) ;
		for ( int z = 0 ; z <= io ; ++z )
		{
			printf( "%d " , ans0[z] ) ;
		}
		printf( "\n" ) ;
		h++ ;
		copy_array( 1 , 3 , io ) ; 
		int k = right_swift( io ) ;
		printf( "%d\nmmmmmmmm\n" , j ) ;
		j -= k ;
	} while ( j > 0 ) ;
	for ( int z = 0 ; z <= h ; ++z )
		printf( "%d " , ans1[z] ) ;
	printf( "\n" ) ;
 } 
