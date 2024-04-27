#include <stdio.h>
#include <string.h>
int main ()
{
    int n, m ;
    while ( scanf( "%d%d" , &n , &m ) )
    {
        int a[n][m] ;
        memset( a , 0 , sizeof( a ) ) ;
        for ( int i = 0 ; i < n ; ++i )
        {
            for ( int j = 0 ; j < m ; ++j )
            {
                scanf( "%d" , &a[i][j] ) ;
            }
        }
        for ( int i = 0 ; i < m ; ++i )
        {
            for ( int j = 0 ; j < n ; ++j )
            {
                printf( "%d " , a[j][i] ) ;
            }
            printf( "\n" ) ;
        }
    }
}
