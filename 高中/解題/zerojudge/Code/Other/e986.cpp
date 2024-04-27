#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int take[n] = {0};
		int c[3] = {0};
		cin >> c[0] >> c[1] >> c[2];
		take[c[0]-1] = 1 ;
		take[c[1]-1] = 1 ;
		take[c[2]-1] = 1 ;
		for ( int i = n ; i > 0 ; i-- )
		{
			if ( take[i-1] == 1 )
				continue;
			else
				cout << "No. " << i << endl;
		}
	}
	return 0 ;
}
