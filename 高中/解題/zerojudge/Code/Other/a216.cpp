#include <iostream>
using namespace std;
long long int f ( int n )
{
	if ( n > 1 )
		return n + f(n-1);
	else
		return 1 ;
}
long long int g ( int n )
{
	if ( n > 1 )
		return f(n) + g(n-1) ;
	else
		return 1 ;
}
int main ()
{
	int N ;
	while ( cin >> N )
	{
		cout << f(N) << " " << g(N) << endl;
	}
	return 0 ;
}
