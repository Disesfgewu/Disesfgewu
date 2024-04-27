#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std ;
int n ;
string s ;
int main ()
{
	cin >> n ;
	cin >> s ;
	stack <int> d ;
	int count = 0 ;
	bool flag = true ;
	for ( int i = 0 ; s[i] != '\0' ; ++i )
	{
		if ( s[i] != '?' )
		{
			if ( s[i] == ']' )
			{
				if ( d.empty() )
				{
					continue ;
				}
				else
				{
					d.pop() ;
					count++ ;
				}
			}
			if ( s[i] == '[' )
				d.push(1) ;
			
		}
	}
	if ( flag == true )
		cout << count << '\n' ;
	return 0 ;
}
