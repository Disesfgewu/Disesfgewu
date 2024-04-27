#include <iostream>
#include <set>
#include <algorithm>
using namespace std ;
const int nmax = 200000 ;
int n , l ;
int L[nmax] ;
int main ()
{
	cin >> n >> l ;
	int x , k ;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> x >> k ;
		L[k-1] = x ;
	}
	set <int> d{ 0 , l } ;
	int ans = 0 ;
	for ( int i = 0 ; i < n ; i++ )
	{
		auto it = d.insert( L[i] ).first ;
		ans += *next(it) - *prev(it) ;
	}
	cout << ans << endl ;
 } 
