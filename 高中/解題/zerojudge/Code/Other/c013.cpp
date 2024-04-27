#include <bits/stdc++.h>
using namespace std;
int n ;
void line ( int l )
{
	for ( int i = 1 ; i <= l ; i++ )
		cout << l ;
	cout << endl;
}
void up( int u )
{
	for ( int i = 1 ; i <= u ; i++ )
		line(i);
}
void down ( int d )
{
	for ( int i = d-1 ; i >= 1 ; i-- )
		line(i);
}
int main ()
{
	while ( cin >> n )
	{
		int a[n] = {0} , f[n] = {0};	
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i] >> f[i] ;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < f[i] ; j++ )
			{
				up(a[i]);
				down(a[i]);
			}
	}
	return 0 ;
 } 
