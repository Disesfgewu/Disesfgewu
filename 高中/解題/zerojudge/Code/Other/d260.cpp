#include <iostream>
#include <algorithm>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	while ( n-- )
	{
		int a[4] = {0} ;
		for ( int i = 0 ; i < 4 ; i++ )
			cin >> a[i] ;
		sort( a , a+4 ) ;
		int count = a[0] + a[1] + a[2] ;
		if ( a[0] == a[1] && a[2] == a[3] && a[1] == a[2] && a[0] == a[3] )
			cout << "square" << endl ;
		else if ( a[0] == a[1] && a[2] == a[3] )
			cout << "rectangle" << endl ;
		else if ( count > a[3] )
			cout << "quadrangle" << endl ;
		else
			cout << "banana" << endl ;
	}
 } 
