#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n ;
	while ( cin >> n )
	{
		long long int a , b ;
		long long int d[n] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> a >> b ;
			d[i] = a*100000 + b ;
		}
		sort( d , d+n );
		for ( int i = 0 ; i < n ; i++ )
		{
			cout << d[i]/100000 << " " << d[i]%100000 << endl; 
		}
	}
	return 0 ;
 }
