#include <bits/stdc++.h>
using namespace std ;
const int nmax = 10000 ;
vector <int> s[nmax+1] ;
vector <int> ans ;
//int an[100001] = {0} ;
int n , m , l , q , a , b , x , y ;
void fin( int n )
{
	if ( !ans.empty() && ( find( ans.begin() , ans.end() , n ) != ans.end() ) )
		return ;
	else
	{
		ans.push_back( n ) ;
		for ( auto i = s[n].begin() ; i != s[n].end() ; ++i )
			fin( *i );
		return ;
	}
}
int main ()
{
	cin >> n >> m >> l >> q ;
	for ( int i = 0 ; i < m ; i++ )
	{
		cin >> a >> b ;
		s[a].push_back( b ) ;
	}
	for ( int i = 0 ; i < l ; i++ )
	{
		cin >> x ;
		fin( x ) ;
	}
	for ( int i = 0 ; i < q ; i++ )
	{
		cin >> y ;
		if ( find( ans.begin() , ans.end() , y ) == ans.end() )
			cout << "YA~~\n" ;
		else
			cout << "TUIHUOOOOOO\n" ;
	}
 } 
