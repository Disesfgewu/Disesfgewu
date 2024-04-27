#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		if ( n % 2 == 0 )
		{
			n--;
			int d = n/2 + 1 ;
			cout << ( 1+n )*d / 2 << endl; 
		}
		else 
		{
			int d = n / 2 + 1 ;
			cout << ( 1 + n ) * d / 2 << endl;
		}
	}
	return 0 ;
}
