#include <iostream>
#include <algorithm>
using namespace std;
const int mmax = 10000 ;
int a[mmax] , b[mmax] , c[mmax] , n , m ,i ;
long long op ( void )
{
	long long count = 0 ;
	for ( int i = 0 ; i < n ; i++ )
		count += a[i] ;
	return count ;
}
int main ()
{
	int p = 0 ;
	scanf( "%d %d" , &n , &m ) ;
		for ( i = 0 ; i < n ; i++ )
			cin >> a[i] ;
		for ( i = 0 ; i < m ; i++ )
			cin >> b[i] ;
		long long l = op() ;
		for ( i = 0 ; i < m ; i++ )
		{
			sort( a , a+n ) ;
			c[i] = a[n-1] ;
			a[n-1] -= b[i] ;
			l -= b[i] ;
			if ( a[n-1] < 0 )
			{
				a[n-2] += a[n-1] ;
				a[n-1] = 0 ;
			}
			if ( l < 0 )
			{
				cout << "Oh My God\n" ;
				p = 1 ;
				break ;
			}
		}
		c[m-1] = a[n-1] ;
		if ( p == 0 )
			cout << c[0] << " " << c[m-1] << '\n' ;
	}
