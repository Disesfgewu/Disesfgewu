#include <bits/stdc++.h>
using namespace std;

int main ()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s ;
	while ( cin >> s )
	{
		int ASCLL[256] = {0};
		for ( int i = 0 ; i < s.length() ; i++ )
		{
			if ( isalpha(s[i]) )
			{
				s[i] = toupper(s[i]);
				ASCLL[s[i]]++;
			}
		}
		int count = 0 ;
		for ( int i = 0 ; i < 256 ; i++ )
		{
			if ( ASCLL[i] % 2 != 0 )
				count++ ;
		}
		cout << (( count <= 1 ) ? "yes !" : "no...") << endl;
	}
	return 0 ;
 } 
