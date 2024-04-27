#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int a[n] = {0} , b[n] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		for ( int i = 0 ; i < n ; i++ )
			cin >> b[i];
		int i = 0 ;
		int q = -2 , e = -2 ;
		while ( i < n-1 )
		{
			if ( a[i] == -1 )
			{
				int j ;
				int count1 = INT_MAX , count2 = INT_MIN ;
				q = -2 ;
				e = -2 ;
				for ( j = i+1 ; a[j] != -1 && j < n ; j++ )
				{
					if ( count1 > a[j] )
					{
						count1 = a[j];
						e = j ;
					}
					if ( count2 < a[j] )
					{
						count2 = a[j];
						q = j ;
					}
				}
				if ( j == -100 )
					break;
				int x = b[q];
				b[q] = b[e];
				b[e] = x ;
				i = j ;
			}
			else
				i++;
		}
		for ( int i = 0 ; i < n ; i++ )
			cout << b[i] << " ";
		cout << endl;
	}
	return 0 ;
 } 
