#include <iostream>
using namespace std;
int main ()
{
	int n , m ;
	while ( cin >> n >> m )
	{
		int p[n] , w[m], p2[n] = {0};
		for ( int i = 0 ; i < n ; i++ )
			p[i] = i+1  ;
		for ( int j = 0 ; j < m ; j++ )
		{
			cin >> w[j];
			p2[w[j]-1]++;
		}
		int count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			if ( p2[i] != 2 )
				count++;
		}
		cout << count << endl;
	}
	return 0 ;
 } 
