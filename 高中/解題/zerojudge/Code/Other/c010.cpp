#include <bits/stdc++.h>
using namespace std;
vector <int> n ;

int main ()
{
	int c ;
	while ( cin >> c )
	{
		if ( n.empty() )
			n.push_back(c);
		else
			n.insert( lower_bound( n.begin() , n.end() , c ) , c );
		int r = n.size();
		if ( r % 2 == 1 )
			cout << n[ r/2 ] << endl;
		else
			cout << ( n[ r/2 ] + n[ r/2 - 1 ] )/2 << endl;
	}
	return 0 ;
}
