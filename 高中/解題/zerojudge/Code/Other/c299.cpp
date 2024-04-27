#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int S[n] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> S[i] ;
		for ( int i = n-1 ; i >= 0 ; i-- )
		{
			int y = 0 , m ;
			for ( int j = i ; j >= 0 ; j-- )
			{
				if ( y < S[j] )
				{
					y = S[j];
					m = j ;
				}
			}
			int u = S[i];
			S[i] = S[m];
			S[m] = u ;
		}
		cout << S[0] << " " << S[n-1] << " ";
		int count = 0 ;
		for ( int i = 0 ; i < n - 1 ; i++ )
		{
			if ( S[i] == S[i+1]-1 )
			{
				count++;
				//cout << count << endl;
			}
		}
		if ( count == n-1 )
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0 ;
 } 
