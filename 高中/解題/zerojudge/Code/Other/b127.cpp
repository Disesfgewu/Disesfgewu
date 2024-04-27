#include <bits/stdc++.h>
using namespace std;
int m ;
int F ( int i )
{
	if ( i == 1 )
		return 1 ;
	else if ( i == 2 )
		return F(i-1) + 1 ;
	else 
		return F(i-1) + F(i-2);
}
int main ()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	while ( cin >> m )
		cout << F(m) << endl;
	return 0 ;
 } 
