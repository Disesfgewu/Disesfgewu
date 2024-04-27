#include <bits/stdc++.h> 
using namespace std;
const int nmax = 50 ;
const int mmax = 50 ;
int main ()
{
	int n , m , k ;
	cin >> n >> m >> k ;
	int a[nmax][mmax] = {0} , x[k][n] = {0}  ;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ )
			cin >> a[i][j] ;
	int count2 = INT_MAX ;
	for ( int i = 0 ; i < k ; i++ )
	{
		int a2[nmax][mmax] = {0} ;
		int count1 = 0 , p ;
		for ( int j = 0 ; j < n ;j++ )
		{
			cin >> p ;
			//long long count1 = 0 ;
			for ( int z = 0 ; z < m ; z++ )
			{
				a2[p][z] += a[j][z] ;
			}
		}
		for ( int j = 0 ; j < m ; j++ )
		{
			for ( int z = 0 ; z < m ; z++ )
			{
				if ( z == j )
					count1 += a2[j][z] ;
				else if ( a2[j][z] >= 1000 )
					count1 += 3000 + ( a2[j][z] - 1000 ) * 2 ;
				else
					count1 += a2[j][z]*3 ; 
			}
		}
	//	cout << count1 << " " << count2 << endl;
		count2 = min( count1 , count2 ); 
	}
	cout << count2 << endl;
}
