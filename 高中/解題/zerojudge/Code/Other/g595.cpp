#include <iostream>
#include <algorithm>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	int a[n] = {0} ;
	for ( int i = 0 ; i < n ; ++i )
		cin >> a[i] ;
	int count = 0 ;
	for ( int i = 0 ; i < n ; ++i )
	{
		if ( a[i] == 0 )
		{
			if ( i != 0 && i != n-1 )
			{
				count += min( a[i-1] , a[i+1] ) ;
			}
			else 
			{
				if ( i == 0 )
					count += a[i+1] ;
				else
					count += a[i-1] ;
			}
		}
	}
	cout << count << endl;
}
