#include <bits/stdc++.h>
using namespace std ;
const int nmax = 101 , mmax = 2001 , wmax = 2001 ;
int a[nmax][2] = {0} ;
int c[nmax][10005] = {0} ;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		memset( a , 0 , sizeof(a) ) ;
		memset( c , 0 , sizeof(c) ) ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i][0] >> a[i][1] ;
		int count , g = 0 ;
		cin >> count ;
		for ( int i = 0; i < n ; i++ )
		{
			for ( int j = 0 ; j <= count ; j++ )
			{
				if ( j - a[i][0] < 0 )
					c[i+1][j] = c[i][j] ;
				else
				{
					if ( c[i][j] <= c[i][ j - a[i][0] ] + a[i][1] )
					{
						c[i+1][j] = c[i][ j - a[i][0] ] + a[i][1] ;
					}
					else
						c[i+1][j] = c[i][j] ;
				}

			}
		 }
		 cout << c[n][count] << endl ;
	}
}
