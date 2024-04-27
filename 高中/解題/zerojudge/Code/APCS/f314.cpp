#include <bits/stdc++.h>
using namespace std;
int a[52][10000] ;
int b[52][10000] ;

int main ()
{
	cin.tie(0);
	int n , m ;
	ios_base::sync_with_stdio(false);
	cin >> m >> n ;
	int i , j ;
	for ( i = 1 ; i <= m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
			cin >> a[i][j];
	}
	for ( i = 0 ; i <= m ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
			b[i+1][j] = INT_MIN;
		int sum = INT_MIN;
		for ( j = 0 ; j < n ; j++ )
		{
			sum = max( b[i][j] , sum ) + a[i][j] ;
			b[i+1][j] = max( b[i+1][j] ,sum );
		}
		for ( j = n ; j >= 0 ; j-- )
		{
			sum = max( b[i][j] , sum ) + a[i][j] ;
			b[i+1][j] = max( b[i+1][j] ,sum );
		}
	}
	int x = INT_MIN;
	for ( i = 0 ; i < n ; i++ )
	{
		x = max( x , b[m+1][i]);
	}  
	cout << x << endl;
	return 0 ;
}
