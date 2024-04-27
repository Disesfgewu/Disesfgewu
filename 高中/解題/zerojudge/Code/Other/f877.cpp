#include <iostream>
#include <cstring>
using namespace std ;
int main ()
{
	string s ;
	while ( getline( cin , s ) )
	{
		if( s[s.size()-1] == '!' )
			cout << "YES\n" ;
		else
			cout << "NO\n";
	}
 }
