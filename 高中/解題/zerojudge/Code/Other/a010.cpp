#include <iostream>
#include <vector>
using namespace std ;
bool c ( int n )
{
	int count = 1 ;
	for ( int i = 2 ; i < n ; i++ )
	{
		if ( n % i == 0 )
			return false ;
	}
	return true ;
 } 
int main ()
{
	int n  ;
	while ( cin >> n ) {
	vector <int> d[2] ;
	int i = 2 ;
	while ( n != 1  )
	{
		int count = 0 ;
		if ( n % i == 0 )
			if ( c( i ) )
			{
				while ( n % i == 0 )
				{
					n /= i ;
					count++ ;
				}
				d[0].push_back( i ) ;
				d[1].push_back( count ) ;
				count = 0 ;
			}
		i++ ;
	}
	for ( i = 0 ; i < d[0].size() ; i++ )
	{
		if( d[1][i] > 1 && i+1 != d[0].size())
		{
			cout << d[0][i] << "^" << d[1][i] << " * " ;
		}
		else if ( d[1][i] > 1 && i+1 == d[0].size())
		{
			cout << d[0][i] << "^" << d[1][i] << endl ;
		}
		if ( d[1][i] == 1 && i+1 != d[0].size() )
		{
			cout << d[0][i] << " * " ;
		}
		else if ( d[1][i] == 1 && i+1 == d[0].size())
		{
			cout << d[0][i] << endl ;
		}
	}
	}
 } 
