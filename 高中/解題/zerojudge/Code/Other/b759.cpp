#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string s;
	while ( cin >> s )
	{
		int y = s.length();
		int i  , j = 0 , z = 0 ;
		while ( j < y )
		{
			i = j ;
			z = 0 ;
			while ( z < y )
			{
				cout << s[i];
				i++;
				z++;
				if ( i == y )
					i = 0 ;
			}
			j++;
			cout << endl;
		}
	}
	return 0 ;
}
