#include <iostream>
#include <algorithm>
using namespace std;
int n ;
int find ( int e , int u[] )
{
	for ( int i = 0 ; i < n ; i++ )
	{
		if ( u[i] == e )
		{
			return i+1 ;
			break;
		}
	}
}
int main ()
{
	while ( cin >> n )
	{
		int a[n][3] = {0}, b[n] = {0} , count[n] = {0};
		for ( int i = 0 ; i < n ; i++ )
		{
			for ( int j = 0 ; j < 3 ; j++ )
			{
				cin >> a[i][j];
				b[i] += a[i][j];
			}
			count[i] = b[i];
		}
		sort( b , b + n );
		int p[n] = {0};
		for ( int i = n-1 ; i >= n-5 ; i-- )
		{
			p[i] = find( b[i] , count );
			count[p[i]-1] = -1000;
			cout << p[i] << " " << b[i] << endl;
		}
	}
	return 0 ;
 } 
