#include <bits/stdc++.h>
using namespace std;
int n ;
int s ( int a[] , int p )
{
	if ( p > 1 )
		return abs( ( a[p] - a[p-1])) + s( a , p-1 );
	else
		return abs( a[p] - a[p-1] );
}
int u ( int p )
{
	if ( p > 1 )
		return u( p-1 ) + p ;
	else
		return 1 ;
}
int main ()
{
	while ( cin >> n )
	{
		int a[n] = {0};
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		cout << ( ( s( a , n-1 ) == u(n-1) ) ? "Jolly" : "Not jolly" ) << endl; 
	} 
	return 0;
}
