#include <iostream>
using namespace std;
void reverse ( int a[] , int b )
{
	int y ;
	for ( int i = 0 ; i < b ; i++ )
	{
		y = 0 ;
		while ( a[i] > 0 )
		{
			y = y * 10 + ( a[i]%10 ) ;
			a[i] /= 10 ;
		}
		a[i] = y ;
	}
}
int max ( int a [] , int b )
{
	int count = 0 ;
	for ( int i = 0 ; i < b ; i++ )
	{
		if ( count < a[i] )
			 count = a[i] ;
	}
	return count ;
 } 
int main ()
{
	int n ;
	cin >> n ;
	int a[n] = {0} ;
	for ( int i = 0 ; i < n ; i++ )
		cin >> a[i] ;
	reverse( a , n ) ;
	cout << max( a , n ) << endl ;
} 
