#include <iostream>
#include <algorithm>
using namespace std ;
const int nmax = 502 ;
int n , i , j , mazz2[nmax][nmax];
char mazz[nmax][nmax];
void a( int i , int j )
{
	if ( mazz2[n-1][n-1] != 10000 || mazz[i][j] == 'E' )
		return ;
	else
	{
		mazz[i][j] = '#' ;
		if ( j+1 != n && mazz[i][j+1] != '#' )
		{
			mazz2[i][j+1] = min( mazz2[i][j+1] , mazz2[i][j]+1 ) ;
			a( i , j+1 ) ;
		}
		if ( i+1 != n && mazz[i+1][j] != '#' )
		{
			mazz2[i+1][j] = min( mazz2[i+1][j] , mazz2[i][j]+1 ) ;
			a( i+1 , j ) ;
		}
		mazz[i][j] = '0' ;
	}
	return ;
}
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	ios::sync_with_stdio(false) ;
	cin >> n ;
	for ( i = 0 ; i < n ; i++ )
	{
		cin >> mazz[i] ;
		for ( j = 0 ; j < n ; j++ )
			mazz2[i][j] = 10000 ;
	}
	mazz2[0][0] = 0 ;
	a( 0 , 0 ) ;
	if ( mazz2[n-1][n-1] != 10000 )
		cout << mazz2[n-1][n-1] << '\n' ;
	else 
		printf("-1\n") ;
	return 0 ;
 } 
