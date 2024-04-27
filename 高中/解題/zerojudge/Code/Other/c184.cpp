#include <iostream>
using namespace std;
int c ( int n )
{
	int count = 0 ; 
	for ( int i = 1 ; i < n ; i++ )
	{
		if ( n % i == 0 )
			count += i ;
	}
	return count ;
}
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	int n ;
	while ( 1 )
	{
		cin >> n ;
		if ( n == 0 )
			break ; 
		int count = c( n ) ;
		if ( count == n )
		{
			cout << "=" << n << endl ;
		}
		else
		{
			int count2 = c( count ) ;
			if ( n == count2 )
				cout << count << endl ;
			else
				cout << "0" << endl ; 
		}
	}
 } 
