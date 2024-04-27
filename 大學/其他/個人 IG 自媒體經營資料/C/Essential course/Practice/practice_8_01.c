#include <stdio.h>

int main () {
	int i = 0 ;
	while ( i < 5 ) {
		int j = 0 ;
		while ( j < 5-i-1 ) {
			printf( " " ) ;
			j++ ;
		}
		j = 0 ;
		while ( j <= i ) {
			printf( "*" ) ;
			j++ ;
		}
		printf( "\n" ) ;
		i++ ; 
	} 
	return 0 ;
}


