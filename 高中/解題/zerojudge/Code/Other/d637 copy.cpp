#include <bits/stdc++.h>
using namespace std;
int n , a , b ;
const int nmax = 10000 ;
int v[nmax] = {0} , f[nmax] = {0} ;
int main ()
{
	cin.tie( 0 );
	cout.tie( 0 ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> v[i] >> f[i] ;
	}
	int ans = 0 , c[101] = {0} ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 100 ; j >= 0 ; j-- )
		{
			c[j] = max( c[j] , c[ j - v[i] ] + f[i] ) ;
		}
	}
	cout << c[100] << endl ;
 } 
