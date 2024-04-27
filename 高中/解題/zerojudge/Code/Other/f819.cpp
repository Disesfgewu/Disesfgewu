#include <iostream>
#include <algorithm>
using namespace std ;
bool cmp ( int a , int b ){
	return a > b ;
}
int main ()
{
	int n , count = 0 ;
	cin >> n ;
	int s[n] = {0} , d[n] = {0} , c[n] = {0} ; 
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> s[i] >> d[i] ;
		if ( d[i] > 100 )
		{
			c[i] = s[i] ;
			count += ( d[i] - 100 ) * 5 ;
		}
	}
	int h = 0 ;
	sort( c , c + n  ) ;
	for ( int i = 0 ; i < n ; i++ )
	{
		if ( c[i] > 0 )
		{
			cout << c[i] << " " ;
			h = 1 ;
		}
	}
	if ( h == 0 )
		cout << "0\n" ;
	else
		cout << endl << count << endl ; 
 } 
