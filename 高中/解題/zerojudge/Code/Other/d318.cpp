#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
vector <int> d ;
int main ()
{
	long long n ;
	while ( cin >> n )
	{
		if ( n < 0 )
			break;
		d.clear();
		do
		{
			d.push_back( n%3 ) ;
			n/=3 ;
		}while ( n > 0 ) ;
		reverse( d.begin() , d.end() );
		for ( int i = 0 ; i < d.size(); ++i )
			cout << d[i] ;
		cout << '\n' ;
	}
	
 } 
