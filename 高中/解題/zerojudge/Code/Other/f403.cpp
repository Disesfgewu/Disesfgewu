#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int n , k , q ;
	cin.tie(0);
	ios::sync_with_stdio(false);
	while ( scanf( "%d %d %d" , &n , &k , &q ) )
	{
		vector <int> d[n];
		for ( int i = 0 ; i < k ; i++ )
		{
			int a , b ;
			cin >> a >> b ;
			d[b-1].push_back( a );
		}
		int day[q][2];
		for ( int i = 0 ; i < q ; i++ )
			cin >> day[i][0] >> day[i][1] ;	
		for ( int i = 0 ; i < q ; i++ )
		{
			int count = 0 ;
			for ( int j = 0 ; j < d[day[i][0]-1].size() ; j++ )
			{
				for ( int z = 0 ; z < d[day[i][1]-1].size() ; z++ )
					count += min( d[day[i][0]-1][j] , d[day[i][1]-1][z] );
			}
			cout << count << endl;
		}
	}
	return 0 ;
}
