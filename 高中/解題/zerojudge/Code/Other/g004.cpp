#include <iostream>
using namespace std ;
const int rmax = 100 , cmax = 100 ;
int a[rmax][cmax] = {0} ;
int b[rmax][cmax] = {0} ;
int main ()
{
	int r , c ;
	cin >> r >> c ;
	for ( int i = 1 ; i <= r ; i++ )
		for ( int j = 1 ; j <= c ; j++ )
			cin >> a[i][j] ;
	for ( int i = 1 ; i <= r ; ++i )
	{
		for ( int j = 1 ; j <= c ; ++j ) 
		{
			b[i][j] = a[i][j] ;
			if ( a[i][j] == 0 )
			{
				int count = 0 , count2 = 0 ;
				if ( a[i-1][j] != 0 )
				{
					count++ ;
					count2 += a[i-1][j] ;
				}
				if ( a[i+1][j] != 0 )
				{
					count++ ;
					count2 += a[i+1][j] ;
				}
				if ( a[i][j-1] != 0 )
				{
					count++ ;
					count2 += a[i][j-1] ;
				}
				if ( a[i][j+1] != 0 )
				{
					count++ ;
					count2 += a[i][j+1] ;
				}
				if ( count != 0 )
					b[i][j] = count2 / count ;
			}
		}
	}
	for ( int i = 1 ; i <= r ; i++ )
	{
		for ( int j = 1 ; j <= c ; j++ )
			cout << b[i][j] << " ";
		cout << endl;
	} 
 } 
