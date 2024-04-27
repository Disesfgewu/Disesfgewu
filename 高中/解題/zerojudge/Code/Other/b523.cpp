#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
int main ()
{
	vector <string> d ;
	string h ;
	while ( getline( cin , h ) ) 
	{
		int count = 0 ;
		for ( int i = 0 ; i < d.size() ; i++ )
		{
			if ( d[i] == h )
			{
				count = 1 ;
				cout << "YES" << endl ;
				break ;
			}
		}
		if ( count == 0 )
		{
			d.push_back( h ) ;
			cout << "NO" << endl ;
		}
	}
} 
