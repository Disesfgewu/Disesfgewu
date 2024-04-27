#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a , b ;
	cin >> a >> b ;
	for ( int i = 0 ; i < b.size() ; i++ )
	{
		int u = 0 ;
		for ( int j = 0 ; j < a.size() ; j++ )
		{ 
			if ( b[i] == a[j] )
			{
				cout << j+1 << " " ;
				a[j] = -12 ;
				break ;
			}
			if ( b[i] != a[j] && j == a.size()-1 )
				u = -1 ;
		}
		if ( u == -1 )
			cout << "X " ; 
	}
	cout << '\n' ; 
}
