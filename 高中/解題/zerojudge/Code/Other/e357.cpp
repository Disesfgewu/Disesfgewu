#include <iostream>
using namespace std;
int n ;
int f ( int i )
{
	if ( i % 2 == 0 )
		return f ( i / 2 );
	else if ( i == 1 )
		return 1 ;
	else
		return f ( i - 1 ) + f ( i + 1 );
}
int main ()
{
	while ( cin >> n )
		cout << f(n) << endl;
	return 0 ;
 } 
