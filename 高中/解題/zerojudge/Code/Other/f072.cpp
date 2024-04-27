#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n ;
	cin >> n ;
	int a[n+2] = {0} ;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> a[i] ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( a[i] == 9 )
		{
			a[i] = 3 ;
			if ( a[i+1] == 0 )
				a[i+1] = 3 ;
			if ( a[i-1] == 0 )
				a[i-1] = 3 ;
		}
	}
	int j = 0 ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( a[i] == 1 )
		{
			j = i ;
			break ;
		}
	}
	int k = 0 ;
	for ( int i = n ; i >= 1 ; i-- )
	{
		if ( a[i] == 1 )
		{
			k = i ;
			break ;
		}
	}
//	cout << endl ;
//	cout << j << " " << k << endl;
	int count = 0 ;
	for ( int i = j+1 ; i < k ; i++ )
	{
//		cout << count << endl;
		if ( a[i] == 0 )
			count++ ;
	}
	cout << count << endl; 
 } 
