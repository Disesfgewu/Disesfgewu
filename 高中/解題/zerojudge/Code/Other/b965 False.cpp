#include <iostream>
using namespace std;
int main ()
{
	int R , C , M ;
	while ( cin >> R >> C >> M )
	{
		int cube[R][C] = {0} ;
		for ( int i = 0 ; i < R ; i++ )
		{
			for ( int j = 0 ; j < C ; j++ )
				cin >> cube[i][j] ; 
		}
		int zreo = 0 , one = 0 ;
		for ( int i = 0 ; i < M ; i++ )
		{
			int u ;
			cin >> u ;
			if ( u == 0 )
				zero++ ;
			else if ( u == 1 )
				one++ ;
		}
		zero %= 4 ;
		one %= 2 ;
		if ( one == 1 )
		{
			for ( int i = 0 ; i < R/2 ; i++ )
			{
				for ( int j = 0 ; j < C ; j++ )
				{
					int u = cube[i][j];
					cube[i][j] = cube[R-1-i][j];
					cube[R-1-i][j] = u ;
				}
			}
		}
		int cube2[C][R] = {0} ;
		switch ( zero )
		{
			case 1 :
				for ( int i = 0 ; i < )
		}
	}
}
