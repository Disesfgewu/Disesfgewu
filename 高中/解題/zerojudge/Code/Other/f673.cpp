#include <iostream>
#include <algorithm>
using namespace std;
const int nmax = 32 ;
int n , u ;
int h[nmax] = {0} ;
int pre[nmax] = {0} ;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> u ;
		int point ;
		for ( int j = 0 ; j < 2 ; j++ )
		{
			cin >> point ;
			pre[point] = u ;
		}
	}
	cout << pre[-1] << endl ;
	int height = 0 , ans = 0 ;
	for ( int i = 0 ; i < n ; i++ )
	{
		int tmp = pre[i] ;
		height = 1 ;
		int j = i ;
		while ( tmp != 0 )
		{
			height++ ;
			tmp = pre[ pre[j] ] ;
			j = pre[j] ;
		}
		ans = max( ans , height ) ;
	}
	cout << ans << endl ;
 } 
