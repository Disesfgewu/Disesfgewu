#include <stdio.h>
#include <string.h>
int numa1[10000] = {0} , numa2[10000] = {0} , numb1[10000] = {0} , numb2[10000] = {0} ;
int plus[2][10000] = {0} , sub[2][10000] = {0} , po[2][100000] = {0} ; 
int main ()
{
	char numa[1000] , numb[1000] ;
	scanf( "%s\n%s" , &numa , &numb ) ;
	if ( numa[0] == '-' )
		numa1[0] = -1 ;
	else
		numa1[0] = 1 ;
	if ( numb[0] == '-' )
		numb1[0] = -1 ;
	else
		numb1[0] = 1 ;
	int i = 1 ; 
	int index_pointa1 = 0 , index_pointa2 = 0 , index_pointb1 = 0 , index_pointb2 = 0 ;
	while ( numa[i] != '.' )
	{
		numa1[i] = numa[i] - '0' ;
		i++ ;
	}
	index_pointa1 = i ;
	i++ ;
	while ( i < strlen( numa ) )
	{
		numa2[i-index_pointa1-1] = numa[i] - '0' ;
		i++ ;
	}
	index_pointa2 = i ;
	i = 1 ;
	while ( numb[i] != '.' )
	{
		numb1[i] = numb[i] - '0' ;
		i++ ;
	}
	index_pointb1 = i ;
	i++ ;
	while ( i < strlen( numb ) )
	{
		numb2[i-index_pointb1-1] = numb[i] - '0' ;
		i++ ;
	}
	index_pointb2 = i ;
	int max_index = 0 ;
	if ( index_pointa1 < index_pointb1 )
	{
		for ( int j = index_pointb1-1 , h = index_pointa1-1 ; h > 0 ; --j , --h )
		{
			numa1[j] = numa1[h] ;
			numa1[h] = 0 ;
		}
		max_index = index_pointb1 ;
	}
	else
	{
		for ( int j = index_pointa1-1 , h = index_pointb1-1 ; h > 0 ; --j , --h )
		{
			numb1[j] = numb1[h] ;
			numb1[h] = 0 ;
		}
		max_index = index_pointa1 ;
	}
	if ( numa1[0] > 0 && numb1[0] > 0 )
	{
		for ( int j = 1 ; j <= max_index ; ++j )
		{
			plus[0][j] = numa1[j] + numb1[j] ;
		}
		int j ;
		for ( j = 0 ; j < index_pointa2 || j < index_pointb2 ; ++j )
		{
			plus[1][j] = numa2[j] + numb1[j] ;
		}
		int g = j ;
		for ( j ; j > 0 ; --j )
		{
			if ( plus[1][j] > 9 )
			{
				plus[1][j] %= 10 ;
				plus[1][j-1] ++ ;
			}
		}
		if ( plus[1][0] > 9 )
		{
			plus[1][0] %= 10 ;
			plus[0][max_index] ++ ;
		}
		for ( j = max_index ; j > 1 ; --j )
		{
			if ( plus[0][j] > 9 )
			{
				plus[0][j] %= 10 ;
				plus[0][j+1]++ ;
			}
		}
		printf( "max : %d\n" , max_index ) ;
		for ( j = 1 ; j <= max_index ; ++j )
		{
			printf( "%d" , plus[0][j] ) ;
		}
		printf( "." ) ;
		for ( j = 0 ; j < g ; ++j )
		{
			printf( "%d" , plus[1][j] ) ;
		}
	}
 } 
