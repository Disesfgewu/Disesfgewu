#include <stdio.h>

int main()
{
	int n , m ;
	scanf( "%d%d" , &n , &m ) ;
	int arr[n][6] ;
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < 6 ; j++ ) {
			arr[i][j] = j+1 ;
		}
	}
	for ( int i = 0 ; i < m ; i++ ) {
		int a , b ;
		scanf( "%d%d" , &a , &b ) ;
		a-- ;
		if ( b == -1 ) {
			int tmp = arr[a][3] ;
			arr[a][3] = arr[a][0] ;
			arr[a][0] = arr[a][2] ;
			arr[a][2] = arr[a][5] ;
			arr[a][5] = tmp ;
		}
		else if ( b == -2 ) {
			int tmp = arr[a][5] ;
			arr[a][5] = arr[a][1] ;
			arr[a][1] = arr[a][0] ;
			arr[a][0] = arr[a][4] ;
			arr[a][4] = tmp ;
		}
		else {
			b-- ;
			for ( int j = 0 ; j < 6 ; ++j ) {
				int tmp = arr[a][j] ;
				arr[a][j] = arr[b][j] ;
				arr[b][j] = tmp ;
			}
		}
	}
	for ( int i = 0 ; i < n ; i++ ){
		printf( "%d " , arr[i][0] ) ; 
	}
	return 0 ;
}
