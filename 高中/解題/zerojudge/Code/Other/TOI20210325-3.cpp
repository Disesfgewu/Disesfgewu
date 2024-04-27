#include <iostream>
using namespace std ;
int main ()
{
	int m , n ;
	cin >> m >> n ;
	int ant[m] = {0} , p[n] = {0} , an = 0 , pp = 0 ;
	for ( int i = 0 ; i < m ; i++ )
	{
		cin >> ant[i] ;
		an += ant[i] ;
	}
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> p[i] ;
		pp += p[i] ;
	}
	if ( m <= n )
		cout << "No" << endl ;
	else 
	{
		if ( an <= pp )
			cout << "No" << endl ;
		else
			cout << "Yes" << endl ;
	 } 
 }
