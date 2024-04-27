#include <iostream>
using namespace std;
int main ()
{
	int a , b , n ;
	cin >> a >> b >> n ;
	int l[n+1] = {0}, count = 0 ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		int j ;
		int peo[101] = {0} ;
		while ( cin >> j )
		{
			if ( j == 0 )
				break;
			else if ( j < 0 )
			{
				j *= -1 ;
				peo[j]-- ;
			}
			else
			{
				peo[j]++ ;
			}
		}
		if ( peo[a] > 0 && peo[b] > 0 )
			count++ ;
	}
	cout << count << endl; 
 } 
