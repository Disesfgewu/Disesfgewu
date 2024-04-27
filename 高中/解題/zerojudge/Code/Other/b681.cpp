#include <iostream>
using namespace std;
long long d = 0 , l = 0 , i ;
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> l ;
	for ( i = 1 ; d != l ; i++ )
	{
		if ( i % 2 == 0 )
			d -= i ;
		else
			d += i ; 
	}
	cout << i-1 << endl;
 } 
