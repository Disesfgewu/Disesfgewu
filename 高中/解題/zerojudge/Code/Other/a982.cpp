#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std ;
const int nmax = 102 ;
char mazz[nmax][nmax] ;
int n , ans = 100000 ;
void BFS( int x , int y , int a )
{
	if ( mazz[x][y] == '#' || a > ans )
		return ;
	if ( x == n-2 && y == n-2 )
	{
		ans = a ;
		return ;
	}
	else
	{
		mazz[x][y] = '#' ;
		BFS( x+1 , y , a+1 ) ;
		BFS( x-1 , y , a+1 ) ;
		BFS( x , y+1 , a+1 ) ;
		BFS( x , y+1 , a+1 ) ;
		mazz[x][y] = '.' ;
	}
}
int main ()
{
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; i < n ; ++i )
		scanf( "%s" , mazz[i] ) ;
	BFS( 1 , 1 , 1 ) ;
	if ( ans != 100000 )
		printf( "%d\n" , ans ) ;
	else
		printf( "No solution!\n" ) ;
	return 0 ;
 } 
