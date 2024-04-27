#include <iostream>
using namespace std ;
int main ()
{
	int n ;
	while ( cin >> n )
		( ( n % 4 == 0 && n % 100 != 0 ) || ( n % 400 == 0 ) ) ? cout << "¶|¦~\n" : cout << "¥­¦~\n" ;
}
