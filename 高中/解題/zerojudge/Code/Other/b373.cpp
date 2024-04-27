#include <iostream>
#include <algorithm>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	int a[n] = {0} ;
	for ( int i = 0 ; i < n ; ++i )
	{
		cin >> i[a] ;
	}
	int count = 0 ;
	for ( int i = 0 ; i < n ; ++i )
	{
		for ( int j = 0 ; j < n-i-1 ; ++j )
		{
			if ( a[j] > a[j+1] )
			{
				swap( a[j] , a[j+1] ) ;
				count++ ;
			}	
		}
	}
	cout << count << endl; 
 } 
