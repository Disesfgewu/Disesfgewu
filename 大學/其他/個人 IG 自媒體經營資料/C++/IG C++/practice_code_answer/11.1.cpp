#include <iostream>
#include <algorithm>
using namespace std ;

int main ()
{
	int n ;
	while ( cin >> n )
	{
		int array[n] ;
		for ( int i = 0 ; i < n ; ++i )
		{
			cin >> array[i] ;
		}
		reverse( array , array+n ) ;
		for ( int i = 0 ; i < n ; ++i )
		{
			cout << array[i] << " " ;
		}
		cout << endl ;
	}
	return 0 ;
 } 
