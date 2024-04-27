#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
	// ,,,,,,.
	string s1 = "Monday" ,
		   s2 = "Tuesday" ,
		   s3 = "Wednesday" ,
		   s4 = "Thursday" ,
		   s5 = "Friday" ,
		   s6 = "Saturday" ,
		   s7 = "Sunday" ;
	string s ;
	getline( cin , s ) ;
	unsigned int y ;
	unsigned long long u ;
	cin >> y ;
	if ( s == s1 )
	{
		u = ( 1 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	else if ( s == s2 )
	{
		u = ( 2 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	else if ( s == s3 )
	{
		u = ( 3 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	else if ( s == s4 )
	{
		u = ( 4 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	else if ( s == s5 )
	{
		u = ( 5 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	else if ( s == s6 )
	{
		u = ( 6 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
	if ( s == s7 )
	{
		u = ( 7 + y ) % 7 ;
		if ( u == 0 )
			cout << s7 << endl;
		else if ( u == 1 )
			cout << s1 << endl;
		else if ( u == 2 )
			cout << s2 << endl;
		else if ( u == 3 )
			cout << s3 << endl;
		else if ( u == 4 )
			cout << s4 << endl;
		else if ( u == 5 )
			cout << s5 << endl;
		else if ( u == 6 )
			cout << s6 << endl;
	}
 } 
