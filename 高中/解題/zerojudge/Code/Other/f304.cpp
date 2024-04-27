#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		if ( n % 4 == 0 )
			cout << "4" << endl;
		else
			cout << n % 4 << endl;
	}
	return 0 ;
}
