#include <iostream>
#include <cmath> 
using namespace std ;
int reverse ( int i )
{
	int count = 0 , j = 0 ;
	while ( i > 0 )
	{
		count += 
		i /= 10 ; 
	}
	return count ;
	
}
int main ()
{
	int n ;
	cin >> n ;
	while ( n-- )
	{
		int a , b ;
		cin >> a >> b ;
		int ans = reverse( a ) + reverse( b ) ;
		cout << ans << endl ;
		cout << reverse( ans ) << endl ;
	}
}
