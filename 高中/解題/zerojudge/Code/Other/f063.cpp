#include <bits/stdc++.h>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	vector <int> d[n] ;
	vector <int> count ;
	int k ;
	for ( int i = 0 ; i < n ; ++i )
	{
		cin >> k ;
		for ( int j = 0 ; j < k ; ++j )
		{
			int a ;
			cin >> a ;
			d[i].push_back( a ) ;
		}
		sort( d[i].begin() , d[i].end() ) ;
		count.push_back( d[i][0] ) ;
	}
	sort( count.begin() , count.end() ) ;
	cout << count[ count.size()-1 ] << endl;
 } 
