#include <iostream>
using namespace std ;
int main ()
{
	cin.tie(0) ;
	cout.tie( 0 ) ;
	ios::sync_with_stdio( false ) ; 
	int n , c;
	while ( cin >> n )
	{
		int a[n+2] = {0} ;
		for ( int i = 1 ; i < n+1 ; ++i ) cin >> a[i] ;
		a[0] = 110000 ;
		a[n+1] = 110000 ;
		cin >> c ;
		while ( c >= 1 && c <= n )
		{
			if ( a[c-1] > a[c+1] && a[c] >= a[c+1] ) c++ ;
			else if ( a[c-1] < a[c+1] && a[c] >= a[c-1] ) c-- ;
		 	else break ;
		 } 
		 cout << c << endl ;
 	}
 	return 0 ;
}
