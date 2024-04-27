#include <iostream>
using namespace std;
int main()
{
	int N , T ;
	while ( cin >> N >> T )
	{
		int chapter[N][2] = {0};
		for ( int i = 0 ; i < N ; i++ ) 
		{
			for ( int j = 0 ; j < 2 ; j++ )
			{
				cin >> chapter[i][j];
			}
		}
		int count = 0 ;
		while ( T > 0 )
		{
			int i , u = 0 , p;
			for ( i = 0 ; i < N ; i++ )
			{
				if ( chapter[u][0]< chapter[i][0] )
					u = i ;
			}
			count = count + chapter[u][0];
			chapter[u][0] -= chapter[u][1];
			if ( chapter[u][0] <= 0 )
				chapter[u][0] = 0 ;
			T--;
		}
		cout << count << endl;
	}
	return 0 ;
}
