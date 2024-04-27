#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int m , n ;
vector <int> d ;
int main ()
{
	cin >> m >> n ;
	for ( int i = 1 ; i <= m ; i++ )
		d.push_back(i) ;
	int j = 0 , count = 0 ;
	for ( int i = 0 ; ; i++ )
	{
		j += n - 1 ;
		j %= d.size() ;
		count++ ;
		d.erase( d.begin() + j ) ;
		if ( d.size() < n )
			break ;
	}
	sort( d.begin() , d.end() ) ;
	for ( int i = 0 ; i < d.size() ; i++ )
		cout << d[i] << " " ; 
 } 
