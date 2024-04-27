#include <iostream>
#include <algorithm>
using namespace std;
const int nm_max = 12 ;
int n , m ;
char area[nm_max][nm_max] ;
int road( int i , int j ) ;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) 
	{
		for ( int j = 1 ; j <= m ; j++ )
			cin >> area[i][j] ;
	}
	cout << road( 1 , 1 ) << endl ;
}
int road( int i , int j )
{
	int count[4] = {0} ;
	if ( i == n && j == m )
		return 1 ;
	if ( &area[i-1][j] == "." )
		count[0] = count[0] + 1 + road( i-1 , j ) ;
	else
		count[0] += 1000 ;
	if ( &area[i+1][j] == "." )
		count[1] = count[1] + 1 + road( i+1 , j ) ;
	else
		count[1] += 1000 ;
	if ( &area[i][j-1] == "." )
		count[2] = count[2] + 1 + road( i , j-1 ) ;
	else
		count[0] += 1000 ;
	if ( &area[i][j+1] == "." )
		count[3] = count[3] + 1 + road( i , j+1 ) ;
	else
		count[3] += 1000 ;
	sort( count , count+4 ) ;
	return count[0] ; 
}
