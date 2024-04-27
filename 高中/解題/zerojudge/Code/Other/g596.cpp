#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std ;
int n , m  , h ;
const int nmax = 205 , mmax = 205 ;
int a[nmax][mmax] = {0} ;
int str( int r , int c )
{
	int coun = 0 ;
	for ( int i = c-1 ; i >= 0 ; --i )
	{
		if ( a[r][i] == -1 )
		{
			for ( int j = i+1 ; j < c ; ++j )
			{
				if ( a[r][j] == 1 )
					continue;
				if ( a[r][j] == 0 )
					coun++ ;
				a[r][j]++ ;
			}
			break;
		}
	}
	for ( int i = c+1 ; i < n ; ++i )
	{
		if ( a[r][i] == -1 )
		{
			for ( int j = c+1 ; j < i ; ++j )
			{
				if ( a[r][j] == 1 )
					continue;
				if ( a[r][j] == 0 )
					coun++ ;
				a[r][j]++ ;
			}
			break;
		}
	}
	for ( int i = r-1 ; i >= 0 ; --i )
	{
		if ( a[i][c] == -1 )
		{
			for ( int j = i+1 ; j < r ; ++j )
			{
				if ( a[j][c] == 1 )
					continue;
				if ( a[j][c] == 0 )
					coun++ ;
				a[j][c]++ ;
			}
			break;
		}
	}
	for ( int i = r+1 ; i < m ; ++i )
	{
		if ( a[i][c] == -1 )
		{
			for ( int j = r+1 ; j < i ; ++j )
			{
				if ( a[j][c] == 1 )
					continue;
				if ( a[j][c] == 0 )
					coun++ ;
				a[j][c]++ ;
			}
			break;
		}
	}
	return coun ;
}
int dstr( int r , int c )
{
	int coun = 0 ;
	for ( int i = c-1 ; i >= 0 ; --i )
	{
		if ( a[r][i] == -1 )
		{
			for ( int j = i+1 ; j < c ; ++j )
			{
				a[r][j]-- ;
				if ( a[r][j] == 0 )
					coun++ ;
				
			}
			break;
		}
	}
	for ( int i = c+1 ; i < n ; ++i )
	{
		if ( a[r][i] == -1 )
		{
			for ( int j = c+1 ; j < i ; ++j )
			{
				a[r][j]-- ;
				if ( a[r][j] == 0 )
					coun++ ;
			}
			break;
		}
	}
	for ( int i = r-1 ; i >= 0 ; --i )
	{
		if ( a[i][c] == -1 )
		{
			for ( int j = i+1 ; j < r ; ++j )
			{
				a[j][c]-- ;
				if ( a[j][c] == 0 )
					coun++ ;
			}
			break;
		}
	}
	for ( int i = r+1 ; i < m ; ++i )
	{
		if ( a[i][c] == -1 )
		{
			for ( int j = r+1 ; j < i ; ++j )
			{
				a[j][c]-- ;
				if ( a[j][c] == 0 )
					coun++ ;
			}
			break;
		}
	}
	return coun ;
}
void out()
{
	for ( int i = 0 ; i < m ; ++i )
	{
		for ( int j = 0 ; j < n ; ++j )
			cout << setw(2) << a[i][j] << " " ;
		cout << endl;
	}
}
int main ()
{
	cin >> m >> n >> h ;
	int count = 0 , mcount = -1 ;
	for ( int i = 0 ; i < h ; ++i )
	{
		int r , c , k ;
		cin >> r >> c >> k ;
		if ( k == 0 )
		{
			if ( a[r][c] == 0 )
				count++ ;
			a[r][c] = -1 ;
			count += str( r , c ) ;
			out();
		}
		else
		{
			a[r][c] = 0 ;
			count--;
			count -= dstr( r , c ) ;
			out();
		}
		mcount = max( mcount , count ) ;
	}
	cout << mcount << '\n' << count << '\n' ;
 } 
