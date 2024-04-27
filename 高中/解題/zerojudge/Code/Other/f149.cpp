#include <iostream>
#include <cmath>
using namespace std ;
const int Rmax = 17 , Cmax = 17 ;
int a[Rmax][Cmax] = {0} ;
int R , C ;
int search ( int i , int j )
{
	for ( int q = 1 ; q <= R ; q++ )
	{
		for ( int w = 1 ; w <= C ; w++ )
		{
			if ( ( pow( q-i , 2 ) + pow( w-j , 2 ) ) <= 2 && a[q][w] == 1 )
				return 1 ;
		}
	}
	return 0 ;
}
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> R >> C ;
	for ( int i = 1 ; i <= R ; i++ )
		for ( int j = 1 ; j <= C ; j++ )
			cin >> a[i][j] ;
	int b[Rmax][Cmax] = {0} ;
	int ans = 0 , ans2 = 0 ;
	for ( int i = 1 ; i <= R ; i++ )
		for ( int j = 1 ; j <= C ; j++ )
		{
			if ( search( i , j ) == 1 )
				ans++ ;
			else
				ans2++ ;
		}
	cout << ans << " " << ans2 << endl ;
 } 
