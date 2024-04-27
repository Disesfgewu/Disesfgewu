#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int a[n] = {0} , count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> a[i] ;
		
		}
		for ( int i = 0 ; i < n ; i++ )	
		{
			if ( a[i] <= 25 )
				count++;
			if ( count == 5 )
				break;
		}
		cout << count << endl; 
	}
	return 0 ;
 } 
