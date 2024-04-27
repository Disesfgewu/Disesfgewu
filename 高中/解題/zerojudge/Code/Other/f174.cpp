#include <iostream>
using namespace std;
int main ()
{
	int n , k ;
	while ( cin >> n >> k )
	{
		int cake[n] = {0};
		int count = 0;
		for ( int i = 0 ; i < n ; i++ )
			cin >> cake[i];
		int i = 0 , j = k-1 ;
		int c ;
		int u = 0 ;
		while ( i < j && j < n )
		{
			c = 0 ;
			for ( int h = i ; h <= j ; h++ )
				c += cake[h];
			if ( u < c )
				u = c ;
			i++;
			j++;
		}
		if ( u >= 0 )
			cout << u << endl;
		else
			cout << "0" << endl;
	}
	return 0 ;
}
