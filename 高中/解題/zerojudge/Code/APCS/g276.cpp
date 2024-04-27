#include <iostream>

using namespace std ;
const int nmax = 105 , mmax = 105 , kmax = 505 ;
int bomb[nmax][mmax] = {0} , peo[nmax][mmax] = {0} ;
pair <int,int> b[kmax] , p[kmax] ; 
int n , m , k ;
int main ()
{
	ios::sync_with_stdio( false );
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n >> m >> k ;
	int r ,c , s, t ;
	for ( int i = 0 ; i < k ; ++i )
	{
		cin >> r >> c >> s >> t ;
		bomb[r][c] = -1 ;
		b[i].first = r , b[i].second = c ;
		p[i].first = s , p[i].second = t ;
	}
	int j = k ;
	while ( j > 0 )
	{
		for ( int i = 0 ; i < k ; ++i )
		{
			if ( b[i].first == -1 )
				continue ; 
			b[i].first += p[i].first , b[i].second += p[i].second ;
			if ( b[i].first >= n || b[i].first < 0 || b[i].second >= m || b[i].second < 0 )
			{
				b[i].first = -1 ;
				j-- ;
				continue;
			}
			else
			{
				if ( bomb[b[i].first][b[i].second]  == -1 )
					bomb[b[i].first][b[i].second] = 1 ;
				else if ( bomb[b[i].first][b[i].second]  >= 1 )
					bomb[b[i].first][b[i].second]+=1 ;
			}
		}
		for ( int i = 0 ; i < k && j > 0; ++i )
		{
			if ( b[i].first == -1 )
				continue ; 
			if ( bomb[b[i].first][b[i].second]  >= 1 )
			{
				bomb[b[i].first][b[i].second]-- ;
				b[i].first = -1 ;
				j-- ;
			}
			else if ( bomb[b[i].first][b[i].second] == 0 )
			{
				bomb[b[i].first][b[i].second] = -1 ;
			}
		}
	}
	int count = 0 ;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; ++j )
			if ( bomb[i][j] == -1 )
				count++ ;
	cout << count << endl;
}
