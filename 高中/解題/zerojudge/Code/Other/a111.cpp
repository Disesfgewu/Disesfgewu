#include <iostream>
using namespace std;
int main ()
{
	int s ;
	while ( cin >> s )
	{
		if ( s == 0 )
			break;
		else
			cout << s * ( s + 1 ) * ( 2 * s + 1 ) / 6 << endl ;
 	}
 return 0 ;
} 
