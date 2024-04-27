#include <iostream>
#include <algorithm>
using namespace std ;
int main ()
{
	int n , i = 1 ;
	cin >> n ;
	while ( i <= n )
	{
		int a[3] = {0} ;
		for ( int j = 0 ; j < 3 ; j++ )
			cin >> a[j] ;
		sort( a , a + 3 ) ;
		cout << "Case " << i << ": " << a[1] << endl ;
		i++ ; 
	 } 
}
