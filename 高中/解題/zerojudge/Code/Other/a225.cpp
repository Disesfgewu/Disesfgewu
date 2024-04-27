#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool po ( int a , int b )
{
	return a > b ; 
}
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int a[n] = {0} , b[n] = {0} , c[n] = {0} ;
		vector <int> d[10] ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> a[i];
			b[i] = a[i];
			c[i] = b[i] % 10 ;
		//	cout << c[i] << endl; 
		}
		int k = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			d[c[i]].push_back(b[i]);
			//cout << d[c[i]][k] << " " << c[i] << " " << k << endl;
			k++;
			sort( d[c[i]].begin() , d[c[i]].end() , po ) ;
		}
		for ( int i = 0 ; i < 10 ; i++ )
		{
			for ( int j = 0 ; j < d[i].size() ; j++ )
				cout << d[i][j] <<  " " ;
		}
		cout << endl;
	}
	return 0 ;
 } 
