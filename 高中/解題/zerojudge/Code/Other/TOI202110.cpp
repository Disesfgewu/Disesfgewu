#include <iostream>
#include <algorithm>
using namespace std ;
const int nmax = 1000005 ;
int a[2][nmax] = {0} , n , k ; 
int count ( int i , int p )
{
	if ( i > n-1 )
		return 0 ;
	if ( p != a[1][i] )
	{
		return max( a[0][i] + count( i+1 , a[1][i] ) , count( i+1 , p ) ) ; 
	}
	else
		return count( i+1 , p ) ;
}
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	ios::sync_with_stdio( false ) ;
	cin >> n >> k ;
	for ( int i = 0 ; i < 2 ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			cin >> a[i][j] ;
	int p = 0 ;
	if ( k != 1 )
		cout << count( 0 , 0 ) << '\n' ;
	else 
	{
		sort( a[0] , a[0]+n ) ;
		cout << a[0][n-1] << endl ;
	}
	return 0 ;
}
