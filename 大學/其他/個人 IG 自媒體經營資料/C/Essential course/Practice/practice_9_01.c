#include <stdio.h>
int main (){
	int N;
	scanf( "%d" , &N ) ;
	int score[N] ;
	for ( int i = 0 ; i < N ; i++ ){
		scanf( "%d" , &score[i] );
	}
	for ( int i = N-1 ; i >= 0 ; i-- ){
		int y = 0 , c = 0;
		for ( int j = 0 ; j <= i ; j++ ){
			if ( c < score[j] ){
				c = score[j] ;
				y = j ;
			}
		}
		int u = score[i];
		score[i] = c ;
		score[y] = u ;
	}
	int best = 101 , worst = -1 , b = 0 , w = 0 ;
	for ( int i = 0 ; i < N ; i++ ){
		printf( "%d " , score[i] );
		if ( score[i] >= 60 && score[i] < best ){
			best = score[i];
		}
		else if ( score[i] < 60 && score[i] > worst ){
			worst = score[i];
		}
	}
	printf( "\n" ) ;
	if ( worst == -1 ){
		printf( "best case\n" ) ;
	}
	else{	
		printf( "%d\n" , worst ) ;
	}
	if ( best == 101 ){	
		printf( "worst case\n");
	}
	else{	
		printf( "%d\n" , best ) ;
	} 
	return 0 ;
}
