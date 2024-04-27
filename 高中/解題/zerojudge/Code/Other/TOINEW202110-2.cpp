#include <iostream>
#include <cmath>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	int a[n] = {0} ;
	for ( int i = 0 ; i < n ; ++i )
	{
		cin >> a[i] ; 
	}
	int count = 0 ;
	for ( int i = 0 ; i < n-1 ; ++i )
	{
		if ( a[i] < a[i+1] )
			count += 3*abs( a[i] - a[i+1] ) ;
		else
			count += 2*abs( a[i] - a[i+1] ) ;
	}
	cout << count+3*abs( a[0] - 1 ) << endl;
}
