#include <iostream>
#include <algorithm>
using namespace std ;
const int nmax = 200000 , mmax = 20000;
int p[nmax] = {0} , q[mmax] = {0} , p2[nmax] = {0} ;
int n , m ;
int main ()
{
	cin >> n >> m ;
	cin >> p2[0] ;
	p[0] = p2[0] ;
	for ( int i = 1 ; i < n ; i++ )
	{
		cin >> p2[i] ;
		p[i] = p2[i] + p[i-1] ;
	}
	for ( int i = 0 ; i < m ; i++ )
		cin >> q[i] ;
	int ans = 0 , ch = 0 ;
	for ( int i = 0 ; i < m ; i++ )
	{
		while ( 1 )
		{
			int find = lower_bound( p , p+n , q[i] + ch ) - p ;
			if ( find != n )
			{
				ans = find ;
				ch = p[find] ;
				break ;
			}
			else
			{
				ch = p[n-1] - p[ans] ;
				ans = 0 ;
				int find2 = lower_bound( p , p+n , q[i] - ch ) - p ; 
				ans = find2 ;
				ch = p[ find2 ] ;
			}
		}
	}
	ans++ ;
	cout << ans%n << endl;
}
