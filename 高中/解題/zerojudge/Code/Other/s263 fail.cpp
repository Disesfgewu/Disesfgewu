#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int y[2] , m[2] , d[2] ;
	while ( cin >> y[0] >> m[0] >> d[0] >> y[1] >> m[1] >> d[1] )
	{
		long long int day[2] = {0};;
		for ( int i = 0 ; i < 2 ; i++ )
			day[i] = 365 * y[i] + 30 * m[i] + d[i] ;
		cout << abs( day[0] - day[1] ) << endl; 
	}
	return 0 ;
 } 
