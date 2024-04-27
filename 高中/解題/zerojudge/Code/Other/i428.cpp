#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;
struct position
{
	int x ;
	int y ;
};
int main ()
{
	int n ;
	cin >> n ;
	struct position point[n] ;
	for ( int i = 0 ; i < n ; ++i )
		cin >> point[i].x >> point[i].y ;
	int count[n] = {0} ;
	for ( int i = 0 ; i < n-1 ; ++i )
	{
		count[i] = abs( point[i+1].x - point[i].x ) + abs( point[i+1].y - point[i].y ) ;
	}
	sort( count , count+n ) ;
	cout << count[n-1] << " " << count[1] << endl ;
}
