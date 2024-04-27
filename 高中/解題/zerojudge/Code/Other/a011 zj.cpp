
#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string s ;
	//vector < string > ss ;
	string a;
	int ans = 0 ;
	while ( getline( cin , s ) )
	{
		ans = 0 ;
		for( int i = 0 ; i < s.size() ; i++ )
		{
            if ( ! isalpha( s[i] ) )  
				s[i] = ' ' ;

		}
		stringstream input( s ) ;
		while ( input >> a )
		{
			ans++ ;
		}
		cout << ans << endl;
	}
	return 0 ;
}

