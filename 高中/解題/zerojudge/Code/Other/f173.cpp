#include <bits/stdc++.h>
using namespace std ;
int m , t ;
const int mmax = 10005 ;
bool r[mmax] ;
pair <int,int> d[mmax] ;
int cmp ( pair<int,int> a , pair<int,int> b )
{
	return a.first < b.first ;
}
int main ()
{
	memset( r , true , sizeof(r) ) ;
	cin >> m >> t ;
	int count[10005] = {0} ;
	for ( int i = 0 ; i < t ; ++i )
		cin >> d[i].first >> d[i].second ;
	sort( d , d+t , cmp ) ;
	for ( int i = 0 ; i < t ; ++i )
	{
		int f = d[i].second - d[i].first ;
		int len = count[d[i].first] + f ;
		for ( int j = d[i].second ; j <= m ; ++j )
		{
			if ( len < count[j] )
				break ;
			count[j] = len ;
		}
	}
	cout << count[m] << '\n' ;
}
