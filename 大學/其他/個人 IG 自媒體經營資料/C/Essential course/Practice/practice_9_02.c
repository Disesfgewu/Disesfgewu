#include <stdio.h>
int main (){
	int n ;
	scanf( "%d" , &n ) ;
	int a[n] ;
	for ( int i = 0 ; i < n ; ++i ){
		scanf( "%d" , &a[i] ) ;
	}
	int count = 0 ;
	for ( int i = 0 ; i < n ; ++i ){
		if ( a[i] == 0 ){
			if ( i != 0 && i != n-1 ){
				if ( a[i-1] < a[i+1] ){
					count += a[i-1] ;
				} 
				else {
					count += a[i+1] ;
				}
			}
			else {
				if ( i == 0 ){	
					count += a[i+1] ;
				}
				else{
					count += a[i-1] ;
				}
			}
		}
	}
	printf( "%d\n" , count ) ;
	return 0 ;
}
