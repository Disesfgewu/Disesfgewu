#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main ()
{
	string a ;
	while ( cin >> a )
	{
		long long int c = 0 , b = 0 ;
		for ( int i = 0 ; a[i] != '\0' ; i++ )
		{
			a[i] -= '0' ; 
			if ( i % 2 == 0 )
				c += a[i];
			else
				b += a[i];
		}
		cout << abs( c - b ) << endl;
	}
	return 0 ; 
}
