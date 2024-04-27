#include <iostream>
using namespace std ;
int t , arr[15] = {0} , n , p = 0 ;
void DFS( int a , int b )
{
	if ( a == n )
	{
		cout << "{" ;
		cout << arr[0] ;
		for ( int i = 1 ; i < p ; ++i )
			cout << "," << arr[i] ;
		cout << "}\n" ;
		return ; 
	}
	if ( b )
	{
		arr[p] = a+1 ; 
		p++ ;
		DFS( a+1 , b-1 ) ;
		p-- ;
	}
	if ( n - a > b )
		DFS( a+1 , b ) ; 
}
int main ()
{
	cin >> t ;
	for ( int i = 0 ; i < t ; ++i )
	{
		cin >> n ;
		cout << "{0}\n" ;
		for ( int j = 1 ; j <= n ; ++j )
			DFS( 0 , j ) ;
		printf( "\n" ) ;
	}
 } 
