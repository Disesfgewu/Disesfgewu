#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string s ; 
	char h  ="0";
	while ( cin >> s )
	{
		for ( int i = s.size()-1 ;  i >= 0 ; i-- )
		{
			if ( s[i] == h )
				continue;
			else 
				cout << s[i];
		}
		cout << endl;
	}
 } 
