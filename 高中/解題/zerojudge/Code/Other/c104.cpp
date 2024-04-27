#include <bits/stdc++.h>
using namespace std ;
int mazz[10][10] = {0} ;
int x[13] = {0} ;
int n , ans = 0 ;
bool place ( int t )
{
	for ( int i = 1 ; i < t ; i++ )
	{
		if ( t - i == abs( x[t] - x[i] ) )
			return 0 ;
	}
	return 1 ;
}
void dfs ( int t )
{
	if ( t > 8 )
	{
		int a = 0 ;
		for ( int i = 1 ; i <= 8 ; i++ )
		{
			for ( int j = 1 ; j <= 8 ; j++ )
			{
				if ( j == x[i] )
					a += mazz[j][i];
			}
		}
		ans = max( ans , a ) ;
	}
	else
	{
		for ( int i = t ; i <= 8 ; ++i )
		{
			swap( x[t] , x[i] ) ;
			if ( place(t) )
				dfs( t+1 ) ;
			swap( x[t] , x[i] ) ;
		}
	}
 } 
int main ()
{
	while ( cin >> n )
	{			
		while (n--){
			for ( int i = 1 ; i <= 8 ; ++i )
				for ( int j = 1 ; j<= 8 ; ++j )
					cin >> mazz[i][j] ;
			for ( int i = 1 ; i <= 8 ; ++i )
				x[i] = i ;
			dfs(1) ;
			cout << ans << endl ;
			ans = 0 ;
		}
	}
	return 0 ;
 }
