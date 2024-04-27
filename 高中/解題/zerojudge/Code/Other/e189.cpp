#include <iostream>
using namespace std;
long long int n ;
int a ( long long int u )
{
	long long int count = 0 ;
	while ( u > 0 )
	{
		count += u%10 ;
		u /= 10 ;
	}
	if ( count == 3 || count == 6 || count == 9 || count == 0 )
		return 1 ;
	else if ( count/10 == 0 )
		return 0 ;
	else
		return a( count );
}
int main ()
{
	while ( cin >> n )
	{
		if ( a(n) == 1 )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0 ;
}
