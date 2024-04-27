#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	vector <int> d ;
	int n , m , k ;
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= n ; i++ )
		d.push_back( i ) ;
	int del = 0 ;
	while ( k-- )
	{
		del = del + m - 1  ;
		del %= d.size() ;
		d.erase( d.begin() + del ) ; // change del into del's pointer

	}
	del %= d.size() ;
	cout << d[del] << endl;
}
