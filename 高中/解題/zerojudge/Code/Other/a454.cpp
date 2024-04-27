#include <iostream>
#include <algorithm>
using namespace std;

int n , k , p;
int main ()
{
	cin >> p ;
	while ( p > 0 )
	{
		int number[1001][1001] = {0} ;
		int day[1001] = {0} ;
		p-- ;
		cin >> n ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> day[i] ;
			cin >> k ;
			for ( int j = 0 ; j < k ; j++ )
			{
				int base ;
				cin >> base ;
				number[i][j] = base-1 ;
			}
			number[i][1000] = k ;
		}
		int count = 0 , mmax;
		for ( int i = 0 ; i < n ; i++ )
		{
			mmax = 0 ;
			for ( int j = 0 ; j < number[i][1000] ; j++ )
			{
				mmax = max( day[number[i][j]] , mmax ) ;
			}
			count += mmax ;
		}
		cout << count << endl;
	 } 
 } 
