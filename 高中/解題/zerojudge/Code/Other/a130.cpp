#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
int main ()
{
	int n , j = 1 ;
	cin >> n ;
	while ( j <= n )
	{
		vector <string> s ;
		vector <int> d ;
		string a ;
		int h ;
		for ( int i = 0 ; i < 10 ; i++ )
		{
			cin >> a >> h ;
			s.push_back( a ) ;
			d.push_back( h ) ;
		}
		int count = 0 ;
		cout << "Case #" << j << ":\n" ;
		for ( int i = 0 ; i < 10 ; i++ )
			count = max( count , d[i] ) ;
		for ( int i = 0 ; i < 10 ; i++ )
		{
			if ( d[i] == count )
				cout << s[i] << endl ;
		}
		j++ ;
	}
	return 0 ;
 } 
