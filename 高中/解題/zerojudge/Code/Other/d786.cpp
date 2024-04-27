#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		double count[n] = {0};
		int a ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> a ;
			int h[a] = {0};
			for ( int j = 0 ; j < a ; j++ )
			{
				cin >> h[j];
				count[i] += h[j];
			}
			count[i] = count[i] / a ;
		}
		for ( int i = 0 ; i < n ; i++ )
			cout << fixed << setprecision(2) << count[i] << endl;
	}
	return 0 ;
}
