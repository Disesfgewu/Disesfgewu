#include <stdio.h>

int main () {
    int t ;
    scanf( "%d" , &t ) ;
    while ( t > 0 ) {
    	t-- ;
    	int a , b , c , d ;
    	scanf( "%d%d%d%d" , &a , &b , &c , &d ) ;
    	if ( b/a == c/b && c/b == d/c ) {
			printf( "%d %d %d %d %d\n" , a , b , c , d , d*(d/c) ) ;
    	}
		else if ( b-a == c-b && c-b == d-c ) {
			printf( "%d %d %d %d %d\n" , a , b , c , d , d+d-c ) ;
		} 
	}
    return 0 ;
}
