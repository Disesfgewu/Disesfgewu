#include <stdio.h>
#include <stdbool.h>
#define nmax 1000 
#define mmax 1000 
int n , m ;
int ans[nmax][nmax] = {0} ;
int people[2][nmax][nmax] = {0};
int map[2][2][nmax] = {0} ;
void play ( int instruct ) 
{
	for ( int z = 0 ; z < 2 ; ++z )
	{
		people[z][map[0][z][instruct]][map[1][z][instruct]] = 0 ;
		people[z][map[0][z][instruct]][n] -= instruct ;
		people[z][n][map[1][z][instruct]] -= instruct ;
		if ( map[0][z][instruct] == map[1][z][instruct] )
			people[z][n][n] -= instruct ;
		if ( ( map[0][z][instruct]+map[1][z][instruct] ) == n-1 )
			people[z][n+1][n+1] -= instruct ;
	}
}
int win1 ( )
{
	for ( int z = 0 ; z < 1 ; ++z )
	{
		for ( int i = 0 ; i < n ; ++i )
			if ( people[z][i][n] == 0 )
				return 1 ;
		for ( int i = 0 ; i < n ; ++i )
			if ( people[z][n][i] == 0 )
				return 1 ;
		if ( people[z][n][n] == 0 )
			return 1 ;
		if ( people[z][n+1][n+1] == 0 )
			return 1 ;
	}
	return 0 ;
}
int win2 ( )
{
	for ( int z = 1 ; z < 2 ; ++z )
	{
		for ( int i = 0 ; i < n ; ++i )
			if ( people[z][i][n] == 0 )
				return z+1 ;
		for ( int i = 0 ; i < n ; ++i )
			if ( people[z][n][i] == 0 )
				return z+1 ;
		if ( people[z][n][n] == 0 )
			return z+1 ;
		if ( people[z][n+1][n+1] == 0 )
			return z+1 ;
	}
	return 0 ;
}
int main ()
{
	scanf( "%d%d" , &n , &m ) ;
	for ( int z = 0 ; z < 2 ; ++z )
	{
		for ( int i = 0 ; i < n ; ++i )
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				int a ;
				scanf( "%d" , &a ) ;
				map[0][z][a] = i ;
				map[1][z][a] = j ;
				people[z][i][j] = a ;
				people[z][i][n] += a ;
				people[z][n][j] += a ;
				if ( i == j )
					people[z][n][n] += a ;
				if ( (i+j) == (n-1) )
					people[z][n+1][n+1] += a ;
			}
		}
	}
	int winner1 = 0 , winner2 = 0 ;
	for ( int i = 0 ; i < m ; ++i )
	{
		int instruct ;
		char space ;
		scanf( "%d" , &instruct ) ;
		if ( winner1 != 0 || winner2 != 0 )
			continue ;
		play( instruct ) ;
		winner1 = win1() ;
		winner2 = win2() ;
	}
	if ( ( winner1 == 0 && winner2 == 0 ) || winner1*winner2 != 0 )
		printf( "Tie\n" ) ;
	else
	{
		if ( winner1 != 0 )
			printf( "A Win\n" ) ;
		else
			printf( "B Win\n" ) ;
	}
}
