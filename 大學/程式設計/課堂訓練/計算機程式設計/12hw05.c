#include <stdio.h>
struct Player
{
	int point ;
	int dice[2][6] ;	
};
void swap( int* a , int* b )
{
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}
void forward( struct Player* player , int x )
{
	swap( & ( player -> dice[x][0] ) , &( player -> dice[x][1] ) ) ;
	swap( & ( player -> dice[x][1] ) , &( player -> dice[x][2] ) ) ;
	swap( & ( player -> dice[x][2] ) , &( player -> dice[x][3] ) ) ;
}
void right(  struct Player* player , int x )
{
	swap( & ( player -> dice[x][1] ) , &( player -> dice[x][5] ) ) ;
	swap( & ( player -> dice[x][3] ) , &( player -> dice[x][4] ) ) ;
	swap( & ( player -> dice[x][5] ) , &( player -> dice[x][4] ) ) ;
}

int main ()
{
	struct Player player[2] ;
	for ( int i = 0 ; i < 2 ; ++i )
	{
		player[i].point = 0 ;
		for ( int j = 0 ; j < 2 ; ++j )
		{
			player[i].dice[j][0] = 3 ;
			player[i].dice[j][1] = 1 ;
			player[i].dice[j][2] = 4 ;
			player[i].dice[j][3] = 6 ;
			player[i].dice[j][4] = 2 ;
			player[i].dice[j][5] = 5 ;
		}
		int m ;
		scanf( "%d" , &m ) ;
		for ( int j = 0 ; j < m ; ++j )
		{
			int x , y ;
			scanf( "%d%d" , &x , &y ) ;
			if ( x == 1 )
				forward( &player[i] ,  0 ) ;
			else
				right( &player[i] , 0 ) ;
			if ( y == 1 )
				forward( &player[i] , 1 ) ;
			else
				right( &player[i] , 1 ) ;
		}
		if ( player[i].dice[0][1] == player[i].dice[1][1] )
			player[i].point = 0 ;
		else
			player[i].point = player[i].dice[0][1] + player[i].dice[1][1] ;
	}
	for ( int q = 0 ; q < 2 ; ++q )
		for ( int w = 0 ; w < 2 ; ++w )
		{
			for ( int z = 0 ; z < 6 ; ++z )
				printf( "%d " , player[q].dice[w][z] ) ;
			printf( "\n" ) ;
		}
	if ( player[0].point == player[1].point )
		printf( "Tie\n" ) ;
	else if ( player[0].point > player[1].point )
		printf( "A win\n" ) ;
	else
		printf( "B win\n" ) ; 	
}
