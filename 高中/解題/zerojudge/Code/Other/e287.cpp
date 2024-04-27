#include <iostream>
using namespace std;
int main ()
{
	int n , m ;
	while ( cin >> n >> m )
	{
		int p[n][m] = {0};
		int a = 1000001 , b = 0 , c = 0 ;
		for ( int i = 0; i < n ; i++ )
		{
			for ( int j = 0 ; j < m ; j++ )
			{
				cin >> p[i][j];
				if ( p[i][j] < a )
				{
					a = p[i][j];
					b = i ;
					c = j ;
				}
			}
		}
		int count = a ;
		while ( true )
		{
			int y = 1000001 , B = 0 , C = 0 ;
			if ( y > p[b+1][c] && b+1 < n )
			{
				y = p[b+1][c];
				B = 1;
				C = 0;
			}
			if ( y > p[b-1][c] && b-1 >= 0)
			{
				y = p[b-1][c];
				B = -1;
				C = 0;
			}
			if ( y > p[b][c+1] && c+1 < m )
			{
				y = p[b][c+1];
				B = 0 ;
				C = 1 ;
			}
			if ( y > p[b][c-1] && c-1 >= 0 )
			{
				y = p[b][c-1];
				B = 0 ;
				C = -1 ;
			}
			b += B ;
			c += C ;
			if ( B == 0 && C == 0 )
				break;
			else
			{
				count += p[b][c];
			}
		}
		cout << count << endl;
	}
	return 0 ;
}
