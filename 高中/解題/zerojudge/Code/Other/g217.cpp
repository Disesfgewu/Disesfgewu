#include <iostream>
#include <algorithm>
using namespace std ;
int t , n ;
pair<int,int> d[1000] ;
int find ( int k , int j )
{
	for ( int i = 0 ; i < k ; ++i )
	{
		if ( d[i].first == j )
			return i ;
	}
	return -100 ;
}
int cmp ( pair<int,int> a , pair<int,int> b )
{
	return a.second > b.second ;
}
int main ()
{
	cin >> t ;
	while ( t-- )
	{
		cin >> n ;
		int k = 0 ;
		for ( int i = 0 ; i < n ; ++i )
		{
			int j ;
			cin >> j ;
			int it = find(  k , j ) ;
			if ( it == -100 )
			{
				d[k].first = j ;
				d[k].second = 1 ;
				k++ ;
			}
			else
			{
				d[it].second++ ;
			}
		}
	//	for ( int i = 0 ; i < n ; i++ )
	//		cout << d[i].first << " " << d[i].second << endl;
		sort( d , d+n , cmp );
//		cout << d[0].first << " " << d[0].second << endl ;
		if ( d[0].second <= n/2 )
			cout << "Yes\n" ;
		else
			cout << "No\n" ;
	}
}//https://zerojudge.tw/UserStatistic?id=167312
