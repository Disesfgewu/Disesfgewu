#include <iostream> 
#include <cstring>
using namespace std;
const int mmax = 10 ;
int a[mmax][mmax] , b[mmax][mmax] ;

void ud ( int r , int c )
{
	for ( int i = 0 ; i < r ; i++ )
	{
		for ( int j = 0 ; j < c ; j++ )
		{
			b[ r - i - 1][j] = a[i][j] ;
		}
	}
	for ( int i = 0 ; i < r ; i++ )
	{
		for ( int j = 0 ; j < c ; j++ )
			a[i][j] = b[i][j] ;
	}
 } 
void circle( int r , int c  )
{
	for ( int i = 0 ; i < c ; i++ )
	{
		for ( int j = 0 ; j < r ; j++ )
		{
			b[c - i - 1 ][j] = a[j][i] ;
		 } 
	}
	for ( int i = 0 ; i < c ; i++ )
	{
		for ( int j = 0 ; j < r ; j++ )
			a[i][j] = b[i][j] ;
	}
}
int main ()
{
	int k[mmax] ;
	int r , c , m ;
	while ( cin >> r >> c >> m )
	{
		memset( a , 0 , sizeof(a) ) ;
		memset( b , 0 , sizeof(b) ) ;
		for ( int i = 0 ; i < r ; i++ )
		{
			for ( int j = 0 ; j < c ; j++ )
			{
				cin >> a[i][j] ;
			 } 
		}
		for ( int i = 0 ; i < m ; i++ )
			cin >> k[i] ;
		for ( int i = m-1 ; i >= 0 ; i-- )
		{
			if ( k[i] == 1 )
			{
				ud( r , c ) ;
			}
			else
			{
				circle( r , c ) ;
				int e = r ;
				r = c ;
				 c= e ;
			}
	 	}	 
	 	cout << r << " " << c << endl ;
	 	for ( int i = 0 ; i < r ; i++ )
		 {
	 		for ( int j = 0 ; j < c-1 ; j++ )
	 			cout << a[i][j] << " " ;
	 		cout << a[i][c-1] << endl;
	 	 }
	}	
	return 0 ;
 } 
