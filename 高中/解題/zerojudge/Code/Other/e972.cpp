#include <bits/stdc++.h>
using namespace std;
int main ()
{
	double n , m , y ;
	string s ;
	cin >> n >> m >> s ;
	if ( s == "T" )
		n = n ;
	else if ( s == "U" )
		n /= 30.9 ;		
	else if ( s == "J" )
		n /= 0.28 ;
	else
		n /= 34.5 ;
	if ( n < m )
		cout << "No Money" << endl ;
	else
	{
		y = n - m ;
		if ( y <= 0.05 )
			cout << s << " " << "0.00" << endl ;
		else
			cout << s << " " << fixed << setprecision(2) << y << endl ;
	}
 } 
