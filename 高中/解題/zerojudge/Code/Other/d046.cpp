#include <iostream>
using namespace std;
int main ()
{
	int N ;
	while ( cin >> N )
	{
		int u = 0 ;
		for ( int i = 0 ; i < N ; i++ )
		{
			int y;
			cin >> y ;
			if ( y <= 10 )
				u++;
		}
		cout << u << endl; 
	}
	return 0 ;
 } 
