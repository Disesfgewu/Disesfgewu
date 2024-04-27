/*#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
int n , m ;
int main ()
{
	cin >> n >> m ;
	int a[m][2] = {0} ;
	vector <int> d ;
	for ( int i = 0 ; i < m ; i++ )
	{
		cin >> a[i][0] >> a[i][1] ;
		if ( a[i][0] == 0 || a[i][1] == 0 )
		{
			int count[2] = {0} ;
			for ( int j = 0 ; j < d.size() ; j++ )
			{
				if ( a[i][0] == d[j] ) 
					count[0] = 1 ;
				if ( a[i][1] == d[j] )
					count[1] = 1 ;
				if ( count[0] == 1 && count[1] == 1 )
					break ;	
			}
			if ( count[0] == 0 )
				d.push_back( a[i][0] ) ;
			if ( count[1] == 0 )
				d.push_back( a[i][1] ) ;
		}
	}
	for ( int u = 0 ; u < 2 ; u++ )
		for ( int i = 0 ; i < m ; i++ )
			for ( int y = 0 ; y < d.size() ; y++ )
				if ( a[i][0] == d[y] || a[i][1] == d[y] )
				{
					int count[2] = {0} ;
					for ( int j = 0 ; j < d.size() ; j++ )
					{
						if ( a[i][0] == d[j] ) 
							count[0] = 1 ;
						if ( a[i][1] == d[j] )
							count[1] = 1 ;
						if ( count[0] == 1 && count[1] == 1 )
							break ;	
					}
					if ( count[0] == 0 )
						d.push_back( a[i][0] ) ;
					if ( count[1] == 0 )
						d.push_back( a[i][1] ) ;
				}
	int p[2*n] = {0} , count = 0 ;
	for ( int i = 0 ; i < d.size() ; i++ )
		p[ d[i] ] = 1 ;
	for ( int i = 0 ; i < n ; i++ )
		cout << p[i] << " " ;
	cout << endl ; 
	for ( int i = 0 ; i < n ; i++ )
		if ( p[i] == 1 )
			count++ ;
	cout << count << endl ;
}*/
#include <iostream>
using namespace std ;
int n , m ;
int main ()
{
	cin >> n >> m ;
	int a[n] = {0} , par[n] = {0} ;
	for ( int i = 0 ; i < n ; i++ )
		par[i] = -1 ;
	a[0] = 1 ;
	for ( int i = 0 ; i < m ; i++ )
	{
		int p1 , p2 ;
		cin >> p1 >> p2 ;
		if ( p1 > p2 )
		{
			par[p1] = p2 ;
		}
		else
			par[p2] = p1 ;
		for ( int j = 0 ; j < n ; j++ )
		{
			if ( par[j] == 0 )
			{
				a[j] = 1 ;
			}
		}
		int j = ( ( p1 > p2 ) ? p1 : p2 )  ;
		int tmp = par[ j ] ;
		while ( tmp != -1 )
		{
			if ( tmp == 0 )
			{
				a[ j ] = 1 ;
				break ;
			}
			else
			{
				tmp = par[ par[j] ] ;
				j = par[j] ;
			}
		}
		/*for ( int j = 0 ; j < n ; j++ )
		{
			if ( a[ par[j] ] == 1 && a[j] == 0 )
				a[j] = 1 ;
		}*/
	}
	int count = 0 ;
	for ( int i = 0 ; i < n ;i++ )
	{
		if ( a[i] == 1 )
			count++ ;
	}
	cout << count << endl;
}
