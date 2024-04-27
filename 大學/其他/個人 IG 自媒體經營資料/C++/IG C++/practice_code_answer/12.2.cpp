#include <iostream>
#include <vector>
using namespace std ;

int main ()
{
	ios::sync_with_stdio( false ) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m , k ;
	vector <int> d ;
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		d.push_back(i) ;
	}
	int j = 0 ;
	for ( int i = 0 ; i < k ; i++ )
	{
		j += m - 1 ;
		j %= d.size() ;
		d.erase( d.begin() + j ) ;
	}
	j %= d.size() ;
	cout << d[j] << endl ;
	return 0 ;
 }
