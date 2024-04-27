#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main ()
{
	int a[2] , b[2] , c[2] , m ;
	while ( cin >> a[0] >> b[0] >> c[0] >> a[1]>>b[1]>>c[1] >> m )
	{
		int x[m+1] = {0};
		for ( int i = 0 ; i <= m ; i++ )
			x[i] += a[0] * pow( i , 2 ) + b[0] * i + c[0] + a[1]*pow(m-i,2) + b[1]*(m-i) + c[1];
		sort( x , x+(m+1) );
		cout << x[m] << endl; 
	 } 
	 return 0 ;
 } 
