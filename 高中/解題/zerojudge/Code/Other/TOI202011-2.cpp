#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int c[n+1] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> c[i] ;
		cin >> c[n] ;
		int a ;
		cin >> a ;
		int g[a] = {0};
		for ( int i = 0 ; i < a ; i++ )
		{
			cin >> g[i];
		}
		for ( int i = 0 ; i < a ; i++ )
		{
			for ( int j = 0 ; j < n ; j++ )
			{
				if ( c[j] == g[i] )
				{
					int x = c[j];
					c[j] = c[n];
					c[n] = x;
				
				}

			}
		}
		for ( int z = 0 ; z < n ; z++ )
			cout << c[z] << " ";
		cout << endl;
	}
	return 0 ;
 } 
