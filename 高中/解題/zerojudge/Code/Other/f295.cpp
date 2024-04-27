#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		string s ;
		char a[n][1000] = {0};
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> s ;
			int j ;
			for ( j = 0 ; s[j] != '\0' ; j++ )
			{
				a[i][j] = s[j];
			}
			a[i][j+1] = '\0';
		}
		int b[n][2] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
		{
			for ( int j = 0 ; j < 2 ; j++ )
				cin >> b[i][j];
		}
		for ( int i = 0 ; i < n ; i++ )
		{
			char c[b[i][1]-b[i][0]+1] ;
			int y = 0 ;
			for ( int j = b[i][0]-1 ; j < b[i][1] ; j++ )
			{
				c[y] = a[i][j];
				y++ ;
			}
			char d[b[i][1]-b[i][0]+1] = {0};
			for ( int j = 0 ; j < b[i][1]-b[i][0]+1 ; j++ )
				d[j] = c[b[i][1]-b[i][0]-j];
			sort( c , c + b[i][1]-b[i][0]+1 );
			y = 0 ;
			for ( int j = b[i][0]-1 ; j < b[i][1] ; j++ )
			{
				a[i][j] = d[y];
				y++ ;
			}
		}
		for ( int i = 0 ; i < n ; i++ )
		{
			for ( int j = 0 ; a[i][j] != '\0' ; j++ )
			{
				cout << a[i][j] ;
			}
			if ( i == n-1 )
				cout << "." << endl;
			else 
				cout << " " ;
		}
	}
	return 0 ;
}
