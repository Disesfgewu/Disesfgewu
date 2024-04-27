#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main ()
{
	int r = 0 ;
	for ( int k = 0 ; k < 5 ; k++ )
	{
		int a[3] = {0} , count = 0 ; 
		while ( cin >> a[0] >> a[1] >> a[2] )
		{
			sort( a , a+3 ) ;
		    if ( a[0]+a[1] > a[2] )
				r++ ;
		}
	}
	cout << r << endl;
	//return 0 ;
}
