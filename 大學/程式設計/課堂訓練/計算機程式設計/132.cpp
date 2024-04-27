#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int *p ;
	int *n = ( int* ) malloc( sizeof( int ) * 10 ) ;
	for ( int i = 0 ; i < 8 ; ++i ) *(n+i) = i ;
	p = n ;
	p++ ;
	printf( "m %d\n\n" , (*p)++ ) ;
	for ( int i = 0 ; i < 8 ; ++i ) printf( "%d\n" , p[i] ) ;
	printf( "m %d\n\n" , ++(*p) ) ;
	for ( int i = 0 ; i < 8 ; ++i ) printf( "%d\n" , p[i] ) ;
	printf( "m %d\n\n" , &p ) ;
	//for ( int i = 0 ; i < 8 ; ++i ) printf( "%d\n" , p[i] ) ;
	for ( int i = 0 ; i < 8 ; ++i ) printf( "%d\n" , p[i] ) ;
	printf( "m %d\n\n" , p[0]  ) ;
	
	for ( int i = 0 ; i < 8 ; ++i ) printf( "%d\n" , p[i] ) ;
	printf( "%d\n" , n[1] ) ;
	//for ( int i = 1 ; i < 8 ; ++i ) printf( "%d\n" , *(p+i) ) ;
 } 
