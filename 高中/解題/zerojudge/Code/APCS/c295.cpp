#include <iostream>
using namespace std;
int main ()
{
	int m , n ;
	while ( cin >> n >> m )
	{
		int num[n][m] = {0} , nu[n] = {0} ;
		int s = 0 , c ;
		for ( int i = 0 ; i < n ; i++ )
		{
			c = 0 ;
			for ( int j = 0 ; j < m ; j++ )
			{
				cin >> num[i][j];
				if ( c < num[i][j] )
					c = num[i][j]; 
			}
			nu[i] = c ;
			s += c ;
		}
		cout << s << endl;
		int count[n] = {0} ;
		c = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			if ( s % nu[i] == 0 ) 
			{
				cout << nu[i] << " ";
				c++;
			}
		}
		if ( c == 0 )
			cout << "-1" << endl;
		else
			cout << endl; 
	}
	return 0 ;
 }
