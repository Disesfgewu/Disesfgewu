#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
int main ()
{
	vector <int> d ;
	int n ;
	while ( cin >> n )
	{
		if ( n == 0 )
			break ;
		d.push_back( n ) ;
	}
	vector <int> d2 ;
	for ( int i = 0 ; i < d.size() ; i++ )
	{
		if ( d[i] % 7 == 0 )
			d2.push_back( d[i] ) ;
	}
	if ( d2.empty() )
	{
		int ans = 78 , k = 0 , j = 0 ;
		for ( int i = 0 ; i < d.size() ; i++ )
		{
			k = d[i] % 77 ;
			if ( ans > k )
			{
				ans = k ;
				j = i ;
			}
		}
		cout << d[j] << endl ;
	}
	else
	{
		int ans = 0 , k = 0 , j = 0 ;
		for ( int i = 0 ; i < d2.size() ; i++ )
		{
			k = d2[i] % 70 ;
			if ( ans < k )
			{
				ans = k ;
				j = i ;
			}
		}
		cout << d2[j] << endl ;
	}
}
