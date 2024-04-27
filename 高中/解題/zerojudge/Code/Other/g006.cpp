#include <iostream>
#include <string>
#include <algorithm> 
using namespace std ;
int main () 
{
	string s ;
	int a[27] = {0} ;
	getline( cin , s ) ;
	for ( int i = 0 ; i < s.size() ; ++i )
	{
		int b = int( s[i] ) - 64;
		a[b]++ ;
	}
	int j = s.size() ; 
	while ( j )
	{
		int flag = 0 ;
		for ( int i = 1 ; i <= 26 ; i++ )
		{
			if ( a[flag] < a[i] )
				flag = i ;
		}
		if ( flag == 0 )
			break ;
		else
		{
			cout << char( flag + 64 ) ;
			a[flag] = 0 ;
		}
	}
	cout << endl;
}
