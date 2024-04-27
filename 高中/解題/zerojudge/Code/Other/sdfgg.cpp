#include <iostream>
#include <vector>
using namespace std ;
int n , m , k ;
vector <int> d ;
int main ()
{
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= n ; i++ )
		d.push_back(i) ;
	int j = 0 ;
	for ( int i = 0 ; i < k ; i++ )
	{
		j += m - 1 ;
		j %= d.size() ;
		d.erase( d.begin() + j ) ;
	}
	j %= d.size() ;
	cout << d[j] << endl ;
 }
