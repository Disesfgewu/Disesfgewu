/*#include <iostream>
#include <cmath>

using namespace std;
int b , n ;
int count ( int c , int i )
{
    if ( c > 0 )
        return c%10 * pow( b , i ) + count( c/10 , i+1 ) ;
    else
        return 0 ;
}
int o ( int c )
{
    if ( c > 0 )
        return 1 + o( c/10 );
    else
        return 0 ;
}
int count2 ( int c , int k )
{
    if ( c > 0 )
        return count2( c/10 , k ) + pow( c%10 , k ) ;
    else
        return 0 ;
}
int main ()
{
    while ( scanf( "%d %d" , &b , &n ) )
    {
        int k = o( n );
        int c1 = count( n , 0 ) , c2 = count2( n , k ) ;
        if ( c1 == c2 )
            printf( "YES\n" );
        else
            printf( "NO\n") ;
    }
    return 0 ;
}*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
const int nmax = 10000 , mmax = 50 ;
int a[mmax][nmax] ;
int m , n ;
int main ()
{
	memset( a , 0 , sizeof( a ) ) ;
 } 
