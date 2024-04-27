#include <iostream>
using namespace std;
long long int sum ( int a )
{
	if ( a > 1 )
		return a + sum ( a - 1 ) ;
	else
		return 1 ;
}
int main ()
{
	int N ;
	while ( cin >> N )
		cout << sum(N) << '\n' ;
	return 0 ;
}
