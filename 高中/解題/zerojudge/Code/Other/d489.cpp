#include <iostream>

using namespace std;
int main ()
{
	int a , b , c;
	while ( cin >> a >> b >> c )
	{
		int x = (a + b + c) / 2 ;
		long long int u = 0 ;
		u = x *( x - a ) * ( x - b ) * ( x - c ) ;
		cout << u << endl;
	}
	return 0 ;
 }
