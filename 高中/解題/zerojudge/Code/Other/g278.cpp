#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
vector <int> d , q ;
const int nmax = 100005 ;
int a[nmax] = {0} ;
int n , k ;
int f ( int a )
{
	for ( int i = 0 ; i < q.size() ; ++i )
	{
		if ( a == q[i] )
			return i ;
	}
	return q.size()+1 ;
}
int main ()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> k ;
	int k = 0 ;
	for ( int i = 0 ; i < n ; ++i )
	{
		cin >> a[i] ;
		int m = f(a[i] );
		if ( m == q.size()+1 )
		{
			q.push_back( a[i] ) ;
		} 
		else
		{
		 	d.push_back( q.size() - k ) ;
		 	for ( int j = 0 ; j <= m ; ++j )
		 		q[j] = -1 ;
		 	q.push_back( a[i] ) ;
		 	k = m+1 ;
		}
	}
	sort( d.begin() , d.end() ) ;
	cout << d[d.size()-1] << endl; 
	return 0 ;
}
