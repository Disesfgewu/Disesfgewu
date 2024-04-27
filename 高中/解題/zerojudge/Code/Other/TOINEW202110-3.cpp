#include <iostream>
#include <algorithm>
using namespace std ;
int main ()
{
	int n , m , d ;
	cin >> n >> m >> d ;
	int f = max( n , m ) , s = min( n , m ) ;
	int fmax = d/f ;
	bool flag = false ;
	while ( fmax >= 0 )
	{
		if ( ( d - fmax*f ) % s == 0 )
		{
			cout << "YES\n" ;
			flag = true ;
			break ;
		}
		else
		{
			fmax-- ;
		}
	}
	if ( !flag )
		cout << "NO\n" ;
 } 
