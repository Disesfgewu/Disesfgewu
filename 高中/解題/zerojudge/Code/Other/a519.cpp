#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std ;
const int nmax = 100 ;
unsigned long F[nmax] = {0};
unsigned long Fi( int i )
{
	if ( i <= 1 )
		return 1 ;
	else 
	{
		if ( F[i] != 0 )
			return F[i] ;
		else
			return F[i] = Fi( i - 1 )+ Fi( i - 2 ) ;
	}
}
int main ()
{
	F[0] = 1 ;
	F[1] = 1 ;
	int n ;
	while ( cin >> n )
	{
		if ( n == 0 )
			break ;
		cout << Fi( n ) << endl ;
	}
	return 0 ;
 } 
