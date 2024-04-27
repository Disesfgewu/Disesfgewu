#include <stdio.h>

int main (){
	int n ;
	scanf( "%d" , &n ) ;
	while ( n-- ) {
		int a[2][7] ;
		for ( int i = 0 ; i < 2 ; ++i ){
			for ( int j = 0 ; j < 7 ; ++j ){
				a[i][j] = 0 ;
			}
		}
		for ( int i = 0 ; i < 2 ; ++i ){
			for ( int j = 0 ; j < 7 ; ++j ){
				scanf( "%d" , &a[i][j] ) ;
			}
		}
		int c[3] , count = 0 ;
		for ( int i = 0 ; i < 3 ; ++i ){
			c[i] = 0 ;
		}
		if ( a[0][1] != a[0][3] && a[0][1] == a[0][5] && a[1][1] != a[1][3] && a[1][1] == a[1][5] ) {
			c[0] = 1 , count++ ;
		}
		if ( a[0][6] == 1 && a[1][6] == 0 ){
			c[1] = 1 , count++ ;
		}
		if ( a[0][1] != a[1][1] && a[0][3] != a[1][3] && a[0][5] != a[1][5] ){
			c[2] = 1 , count++ ;
		}
		if ( c[0] == 0 ){
			printf( "A" ) ;
		}
		if ( c[1] == 0 ) {
			printf( "B" ) ;
		}
		if ( c[2] == 0 ) {
			printf( "C" ) ;
		}
		if ( count == 3 ){
			printf( "None" ) ;
		}
		printf( "\n" ) ;
	}
	return 0 ;
 }
