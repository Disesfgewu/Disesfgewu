#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
int num[10] = {0} , min_number = 1000 ;
char space ;
char line[100] ;
int ans[3][100] = {0} ;
int min( int a , int b )
{
	if ( a > b )
		return b ;
	return a ;
}
int max( int a , int b )
{
	if ( a > b )
		return a ;
	else
		return b ;
}
bool check( int n , int k ) 
{
	for ( int i = 0 ; i < 100 ; ++i )
		if ( ans[k][i] == n )
			return false ;
	return true ;
}
struct Node
{
	int index ;
	int node[100] ; 	
}city[10000];
void DFS ( int start , int end , int n , int now  , int time )
{
	if ( city[now].node[end] != 0 )
	{
		ans[time][n] = end ;
		if ( min_number > n )
			min_number = n ;
		return ;
	}
	bool flag = false ;
	for ( int i = 1 ; i <= city[now].index ; ++i )
		if ( city[now].node[i] != 0 )
			if ( check( i , time ) )
			{
				ans[time][n] = i ;
				DFS( start , end , n+1 , i , time ) ;
			}
	return ;
}
int main ()
{
	for ( int i = 0 ; i < 10000 ; ++i )
	{
		memset( city[i].node , 0 , sizeof( city[i].node ) ) ;
		city[i].index = 0 ;
	}
	gets( line ) ;
	int j = 0 , k = 0 ;
	char number[100] = "" ;
	for ( int i = 0 ; i < strlen( line ) ; ++i )
	{
		if ( iswspace( line[i] ) )
		{
			for ( int h = k-1 ; h >= 0 ; --h )
				num[j] += ( number[h] - '0' ) * pow( 10 , k-h-1 ) ;
			k = 0 ;
			j++ ;
			continue ;
		}
		else
		{
			number[k] = line[i] ;
			k++ ;
		}
	}
	for ( int h = k-1 ; h >= 0 ; --h )
		num[j] += ( number[h] - '0' ) * pow( 10 , k-h-1 ) ;
	k = 0 ;
	j++ ;
	for ( int i = 0 ; i < num[0] ; ++i )
	{
		int a , b ;
		scanf( "%d%d" ,  &a , &b ) ;
		city[a].node[b]++ ;
		city[a].index = max( b , city[a].index ) ;
		city[b].node[a]++ ;
		city[b].index = max( a , city[b].index ) ;
	}
	ans[0][0] = num[1] ;
	if ( num[3] == 0 )
	{
		DFS( num[1] , num[2] , 1 , num[1]  , 0 ) ;
		if ( min_number >= 1000 )
		{
			printf( "NO\n" ) ; 
			return 0 ;
		}
		printf( "%d\n" , min_number ) ;
		for ( int i = 0 ; i <= min_number ; ++i )
			printf( "%d " , ans[0][i] ) ;
		printf( "\n" ) ;
	}
	else
	{
		DFS( num[1] , num[3] , 1 , num[1] ,0 ) ; 
		if ( min_number >= 1000 )
		{
			printf( "NO\n" ) ; 
			return 0 ;
		}
		int k = min_number ;
		min_number = 1000 ;
		ans[1][0] = num[3] ;
		DFS( num[3] , num[2] , 1 , num[3] , 1 ) ;
		if ( min_number >= 1000 )
		{
			printf( "NO\n" ) ; 
			return 0 ;
		}
		printf( "%d\n" , min_number+k ) ;
		for ( int i = 0 ; i <= k ; ++i )
			printf( "%d " , ans[0][i] ) ;
		for ( int i = 1 ; i <= min_number ; ++i )
			printf( "%d " , ans[1][i] ) ;
		printf( "\n" ) ;
	}
}
