#include<iostream>
using namespace std;
const int nmax = 11 ;
int n ;
int ans[nmax] = {0} ;
int check[nmax] = {0} ;
void dfs ( int n , int i ) ;
int main ()
{
	cin.tie(0) ;
	while ( cin >> n )
	{
		dfs( n , 1 ) ;
	}
	return 0 ;
}
void dfs ( int n , int i )
{
	if ( i == n+1)
	{
		for ( int j = 1 ;  j <= n ; j++ )
		{
			printf( "%d " , ans[j] ) ;
		}
		printf( "\n" ) ;
		return ;
	}
	for ( int j = 1 ; j <= n ; j++ )
	{
		if ( check[j] == 0 )
		{
			ans[i] = j ;
			check[j] = 1 ;
			dfs( n , i+1 ) ;
			check[j] = 0 ;
		}
	}
	return ;
}
