#include <bits/stdc++.h>
using namespace std;
int n ;
int main ()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	while ( cin >> n )
	{
		int  a[n] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		sort( a , a+n ) ;
		for ( int i = 0 ; i < n ; i++ )
			cout << a[i] << " ";
		cout << '\n';
	}
	return 0 ;
 } 
