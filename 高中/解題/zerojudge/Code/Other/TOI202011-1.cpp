#include <iostream>
using namespace std;
int main ()
{
	int n , s ;
	while ( cin >> n >> s )
	{
		int ans[n] = {0};;
		for ( int i = 0 ; i < n ; i++ )
			cin >> ans[i] ;
		int p ;
		cin >> p ;
		int st[p] ={0} ;
		for ( int i = 0 ; i < p ; i++ )
		{
			for ( int j = 0 ; j < n ; j++ )
			{
				int o ;
				cin >> o;
				if ( ans[j] == o )
					st[i] += s ;
			}
		}
		for ( int i = 0 ; i < p ; i++ )
			cout << st[i] << endl;
	} 
	return 0 ;
 } 
