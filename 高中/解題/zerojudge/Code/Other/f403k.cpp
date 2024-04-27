#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int n , k , q ;
	cin.tie(0);
	ios::sync_with_stdio(false);
	while ( cin >> n >> k >> q )
	{
		int c[n] = { 0 }; 
		vector <int> d[n];
		for ( int i = 0 ; i < k ; i++ )
		{
			int a , b ;
			cin >> a >> b ;
			d[b-1].push_back( a );
		}
		int day[q][2];
		for ( int i = 0 ; i < q ; i++ )
			cin >> day[i][0] >> day[i][1] ;	
		for ( int i = 0 ; i < q ; i++ )
		{
			int count = 0 ;
			int s = d[day[i][0]-1].size();
			int h = d[day[i][1]-1].size();
			sort ( d[day[i][0]-1].being() , d[day[i][0]-1].end() );
			sort ( d[day[i][1]-1].begin() , d[day[i][0]-1].end() );
			
			cout << count << endl;
		}
	}
	return 0 ;
}
