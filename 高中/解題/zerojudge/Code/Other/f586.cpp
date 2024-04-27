#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int t , u , j = 0 ;
	cin >> t ;
	int a[t] = {0} ;
	while ( j < t )
	{
		cin >> u ;
		if ( u == 1 )
		{
			a[j] = 1 ;
			j++ ;
		}
		else
			for ( int i = 2 ;  ; i++ )
			{
				if ( u % (i*i) == 0 )
				{
					a[j] = 0 ;
					j++ ;
					break ;
				}
				if ( i*i > u )
				{
					a[j] = -1 ;
					j++;
					break; 
				}
			}
	}
	for ( int i = 0 ; i < t ; i++ )
	{
		cout << a[i] << endl;
	}
 } 
