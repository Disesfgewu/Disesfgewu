#include <iostream>
using namespace std;
int main ()
{
	int K;
	int N , M ;
	while ( cin >> K )
	{
		cin >> M >> N ;
		int i , j ;
		int hunt[M][N] = {0};
		for ( i = 0 ; i < M ; i++ )
		{
			for ( j = 0 ; j < N ; j++ )
				cin >> hunt[i][j];
		}
		int H[M*N] = {0} , count, l = 0 ;
		for ( i = 0 ; i < M ; i++ )
		{
			for ( j = 0 ; j < N ; j++ )
			{
				int y = hunt[i][j];
				hunt[i][j] = 0 ;
				count = 0 ;
				for ( int u = 0 ; u < M; u++ )
				{
					for ( int k = 0 ; k < N ; k++ )
					{
						if ( y+hunt[u][k] <= K && count < y+hunt[u][k] )
							count = y + hunt[u][k];
					}
				}
				H[l] = count ;
				l++;
			}
		}
		int y = 0 , p = M*N ;
		while ( p > 0 )
		{
			int z ;
			for ( i = 0 ; i < p ; i++ )
			{
				if ( y < H[i] )
				{
					y = H[i];
					z = i ;
				}
			}
			int a = H[p-1];
			H[z] = a ;
			H[p-1] = y ;
			p--;
		}
		for ( i = M*N-1 ; i >= 0 ; i-- )
		{
			if ( H[i] <= K )
			{
				cout << H[i] << endl;
				break;
			} 
		}
	}
	return 0 ;
}
