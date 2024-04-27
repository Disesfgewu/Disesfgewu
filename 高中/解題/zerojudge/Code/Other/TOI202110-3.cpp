#include <bits/stdc++.h>
using namespace std ;
const int mmax = 1000005 ;
pair <int ,int> p[mmax] ;
vector <int> d ;
int n , m ;
int cmp ( pair <int,int> a , pair <int,int> b )
{
	return a.first < b.first ;
}
int main ()
{
	cin >> n >> m ;
	for ( int i = 0 ; i < m ; ++i )
	{
		int a , b ;
		cin >> a >> b ;
		if ( a < b )
			p[i].first = a , p[i].second = b ;
		else
			p[i].first = b , p[i].second = a ;
	}
	sort( p , p+m , cmp ) ;
	bool flag = true ;
	for ( int i = 0 ; i < m ; ++i )
	{
		const int e = p[i].first , e2 = p[i].second ;
		int k = find( d.begin() , d.end() , e ) , k2 = find( d.begin() , d.end() , e2 )  ;
		if ( k == 0 && k2 == 0 )
		{
			cout << "No\n" ;
			flag = false ;
		}
		else
		{
			if ( k != 0 && k2 != 0 )
				continue ;
			else if ( k == 0 )
			{
				d.push_back( p[i].first ) ;
			}
			else
			{
				d.push_back( p[i].second ) ;
			}
		}
	}
	if ( flag )
		cout << "Yes\n" ; 
}
