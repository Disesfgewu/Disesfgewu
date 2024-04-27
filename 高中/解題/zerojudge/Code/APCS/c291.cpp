#include <iostream>
using namespace std;
int main ()
{
	int N ;
	while ( cin >> N )
	{
		int fri[N] = {0};
		for ( int i = 0 ; i < N ; i++ )
			cin >> fri[i] ;
		int i = 0 , count = 0 , a = i ;
		while ( i < N )
		{
			if ( i != fri[a] && fri[a] != N+1 )
			{
				int u = a ;
				a = fri[a];
				fri[u] = N+1 ;
			}
			else if ( i == fri[a] )
			{
				fri[a] = N+1 ;
				count++ ;
				i++ ;
				a = i ;
			}
			else
			{
				i++ ;
				a = i ;
			}
		}
		cout << count << endl;
	}
	return 0 ;
}
