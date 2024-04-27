#include <iostream>
using namespace std;
int main ()
{
	int N;
	while ( cin >> N )
	{
		int n[N] = {0};
		for ( int i = 0 ; i < N ; i++ )
			cin >> n[i];
		int a = 0 , b = 0 ;
		for ( int i = N-1 ; i >= 0 ; i-- )
		{
			a = 0 ;
			for ( int j = 0 ; j <= i ; j++ )
			{
				if ( a < n[j] )
				{
					a = n[j];
					b = j ;
				}
			}
			int c = n[i];
			n[i] = a;
			n[b] = c ;
		}
		int count = 0  , k = 0 ;
		for ( int i = 0 ; i < N ; i++ )
		{
			if ( k == n[i] )
			{
				count++;
				n[i] = 0 ;
			}
			else
				k = n[i];
		}
		cout << N-count << endl;
		for ( int i = 0 ; i < N ; i++ )
		{
			if ( n[i] != 0 )
				cout << n[i] << " ";
		}
		cout << endl;
	}
	return 0 ;
 }
