#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main ()
{
	string s ;
	getline( cin , s ) ;
	int y , a = 0 , b = 0 ;
	for ( int i = 0 ; i < 9 ; i++ )
	{
		y = s[i] - '0' ;
		if ( y > a )
		{
			b = i ;
			a = y ; 
		}
	}
	int a2 = 0 ;
	for ( int i = 0 ; i < 9 ; i++ )
	{
		y = s[i] - '0' ;
		if ( y > a2 && i != b )
			a2 = y ;
	}
	a = pow( a , 2 ) + pow( a2 , 2 ) ;
	b = ( s[8] - '0' ) + ( s[7] - '0' )*10 + ( s[6] - '0' )*100 ;
	//cout << a << " " << b << endl;
	if ( a == b )
	{
		cout << "Good Morning!\n" ;
	}
	else
	{
		cout << "SPY!\n" ; 
	 } 
 } 
