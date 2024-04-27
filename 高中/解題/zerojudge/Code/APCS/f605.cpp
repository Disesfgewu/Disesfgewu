#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n , d , mid , count = 0 ;
	cin >> n >> d ;
	int a[3] = {0} , b[n][3] = {0};
	for ( int i = 0 ; i < n ; i++ )
	{
		count = 0 ;
		for ( int j = 0 ; j < 3 ; j++ ) 
		{
			cin >> a[j] ;
			count += a[j];
		}
		count /= 3 ;
		sort( a , a+3 ) ;
		mid = a[2] - a[0] ;
		if ( mid >= d )
		{
			b[i][0] = 1 ;
			b[i][1] = count ;
		}
	}
	count = 0 ;
	int count2 = 0 ;
	for ( int i = 0 ; i < n ; i++ )
	{
		if ( b[i][0] == 1 )
		{
			count++ ;
			count2 += b[i][1] ; 
		}
	}
	cout << count << " " << count2 << endl;
 } 
