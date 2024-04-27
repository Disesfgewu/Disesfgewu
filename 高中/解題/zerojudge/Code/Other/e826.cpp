#include <iostream>
#include <algorithm>
using namespace std ;
const int nmax = 100001 ;
pair <int , int> d[nmax] ;
bool cmp( pair< int , int > a , pair< int , int > b )
{
	if ( a.second == b.second )
		return a.first < b.first ;
	else
		return a.second > b.second ;
}
int main ()
{
	int n , m , i;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> m ;
	for ( i = 0 ; i < n ; ++i )
		d[i].first = i , d[i].second = 0 ;
	for ( i = 0 ; i < m ; ++i )
	{
		int a , b ;
		cin >> a >> b ;
		d[a].second += b ; 
	}
	sort( d , d+n , cmp ) ;
	for ( i = 0 ; i < n ; ++i )
		cout << d[i].first << " " << d[i].second << '\n' ;
	return 0 ;
 } 
