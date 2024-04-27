
#include <iostream>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	while ( n-- )
	{
		int a[2][7] = {0} ;
		for ( int i = 0 ; i < 2 ; ++i )
			for ( int j = 0 ; j < 7 ; ++j )
				cin >> a[i][j] ;
		int c[3] = {0} , count = 0 ;
		if ( a[0][1] != a[0][3] && a[0][1] == a[0][5] && a[1][1] != a[1][3] && a[1][1] == a[1][5] )
			c[0] = 1 , count++ ;
		if ( a[0][6] == 1 && a[1][6] == 0 )
			c[1] = 1 , count++ ;
		if ( a[0][1] != a[1][1] && a[0][3] != a[1][3] && a[0][5] != a[1][5] )
			c[2] = 1 , count++ ;
		if ( c[0] == 0 )
			cout << "A" ;
		if ( c[1] == 0 )
			cout << "B" ;
		if ( c[2] == 0 )
			cout << "C" ;
		if ( count == 3 )
		 	cout << "None" ;
		cout << '\n' ;
	}
 }
