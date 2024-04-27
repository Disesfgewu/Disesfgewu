#include <bits/stdc++.h>
using namespace std ;
int x[15] = {0} ;
vector <int> X ;
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
	if ( t > n )
	{
		ans++ ;
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= n ; j++ )
			{
				if ( j == x[i] )
					cout << "Q" ;
				else
					cout << "x" ;
			}
			cout << endl ;
		}
		cout << endl;
	}
	else
	{
		for ( int i = t ; i <= n ; ++i )
		{
			sort( x+i+1 , x+n+1 ) ;
			swap( x[t] , x[i] ) ;
			if ( place(t) )
			{
				dfs( t+1 ) ;
			}
			swap( x[t] , x[i] ) ;
		}
	}
 } 
int main ()
{
	while ( cin >> n )
	{			
		cout << endl;
		ans = 0 ;
		if ( n == 0 )
			break ;
		for ( int i = 1 ; i <= n ; ++i )
			x[i] = i ;
		dfs(1) ;
		cout << ans << endl ;
		cout << endl;
	}
	return 0 ;
 } 
