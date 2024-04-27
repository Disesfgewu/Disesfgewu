#include <iostream>
#include <cmath>
using namespace std ;
int count1( int k , int k2 )
{
	int i = 0 ;
	while ( k != k2 )
	{
		i++ ;
		k2++ ;
		if ( k == 100 )
			k = 0 ;
	}
	return i ;
}
int count2( int k , int k2 )
{
	int i = 0 ;
	while ( k != k2 )
	{
		i++ ;
		k2-- ;
		if ( k == -1 )
			k = 99 ;
	}
	return i ;
}
int main ()
{
	int a , b ;
	while ( cin >> a >> b )
	{
		if ( a == -1 && b == -1)
			break ;
		/*if ( count1( a , b ) < count2( a , b ) )
			cout << count1( a , b ) << endl ;
		else
			cout << count2( a , b ) << endl ;*/
		if ( abs( b-a ) < 100-abs( a-b ) )
			cout << abs( b-a ) << endl ;
		else
			cout << 100 - abs( -b+a ) << endl ;
	}
	return 0 ;
}
