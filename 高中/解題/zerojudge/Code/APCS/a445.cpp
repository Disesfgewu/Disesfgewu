#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
struct dp
{
	int p1 ;
	int p2 ;
};
int cmp ( dp a , dp b )
{
	return a.p2 < b.p2 ;
}
bool find( vector <int> f , int k )
{
	for ( int i = 0 ; i < f.size() ; ++i )
	{
		if ( f[i] == k )
			return true ;
	}
	return false ;
}
int main ()
{
	int n , m , q ;
	cin >> n >> m >> q ;
	dp d[m] ;
	for ( int i = 0 ; i < m ; ++i )
	{
		int a , b ;
		cin >> a >> b ;
		d[i].p1 = max( a , b ) ;
		d[i].p2 = min( a , b ) ;
	}
	sort( d , d+m , cmp ) ;
	vector <int> f[n] ;
	int u =  d[0].p2 ;
	for ( int i = 0 ; i < m ; ++i )
	{
		/*if(*/  u = d[i].p2 ;
		//{
			f[u].push_back( d[i].p1 );
			f[d[i].p1].push_back( u ) ;
			if ( !f[d[i].p1].empty() )
				for ( int j = 0 ; j < f[d[i].p1].size() ; ++j )
					f[u].push_back( f[d[i].p1][j] ) ;
			if ( !f[d[i].p2].empty() )
				for ( int j = 0 ; j < f[d[i].p2].size() ; ++j )
					f[u].push_back( f[d[i].p2][j] ) ;
		//}
	/*	else
		{
			u = d[i].p2 ;
			f[u].push_back( d[i].p1 ) ;
			f[d[i].p1].push_back( u ) ;
		}*/
	}
	for ( int i = 0 ; i < q ; ++i )
	{
		int a , b;
		cin >> a >> b ;
		int it = find( f[min(a,b)] , max( a , b ) );
		if ( it == false )
			cout << ":(\n" ;
		else
			cout << ":)\n" ;
	}
 } 
