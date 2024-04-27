#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int t , n ;
int m[200001] = {0};
int T[200001] = {0};
char job[200001][100];
int main ()
{
	cin >> t >> n ;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> job[i] >> m[i] >> T[i] ;
	} 
	int dp[t+1] = {0} ;
	memset(dp, 0, sizeof(dp));
	dp[0] = 0 ;
	int best_job = 0 ;
	float hour_pay = (float)m[0] / T[0];
	for ( int i = 0 ; i < n ; i++ )
	{
		for ( int j = t ; j >= T[i] ; j-- )
		{
			dp[j] = max( dp[j] , dp[j - T[i] ]+ m[i] ) ;
			float pay = ( float ) m[i] / T[i] ;
			if( pay > hour_pay ) 
			{
				hour_pay = pay ;
				best_job = i ;
			}
		}
	}
	cout << dp[t] << endl;
	cout << job[best_job] << endl;
	return 0 ;
}
