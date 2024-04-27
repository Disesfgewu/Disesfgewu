#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int n ;
struct Player
{
	int point ;
	int card_num ;
	int win_lose ;
	float count ;
	float differ ;
};
int main ()
{
	scanf( "%d" , &n ) ;
	struct Player player[n+1] ;
	player[0].win_lose = 0 ;
	for ( int i = 1 ; i < n+1 ; ++i )
	{
		char space ;
		scanf( "%d%c" , &player[i].point , &space ) ;
		player[i].win_lose = 0 ;
	}
	for ( int i = 0 ; i < n+1 ; ++i )
	{
		char c , b , space ;
		scanf( "%c%c" , &c , &b ) ;
		if ( c == '1' && b == '0' )
		{
			player[i].count = 10.0 ;
			scanf( "%c" , &space ) ;
		}
		else if ( c == 'A')
			player[i].count = 1.0 ;
		else if ( c == 'J' )
			player[i].count = 0.5 ;	
		else if ( c == 'Q' )
			player[i].count = 0.5 ;
		else if ( c == 'K' )
			player[i].count = 0.5 ;
		else
			player[i].count = (float)( c - '0' ) ;
		player[i].card_num = 1 ;
	}
	for ( int i = 1 ; i < n+1 ; )
	{
		char c , space , card , b ;
		scanf( "%c%c" , &c , &space ) ;
		if ( c == 'Y' )
		{
			scanf( "%c%c" , &card , &space ) ;
			if ( card == '1' && space == '0' )
			{
				player[i].count += 10.0 ;
				scanf( "%c" , &space ) ;
			} 
			else if ( card == 'A')
				player[i].count += 1.0 ;
			else if ( card == 'J' )
				player[i].count += 0.5 ;	
			else if ( card == 'Q' )
				player[i].count += 0.5 ;
			else if ( card == 'K' )
				player[i].count += 0.5 ;
			else
				player[i].count += (float)( card - '0' ) ;
			player[i].card_num++ ;
			if ( player[i].count == 10.5 )
			{
				player[i].win_lose += player[i].point ;
				player[0].win_lose -= player[i].point ;
				++i ;
			}
			else if ( player[i].count > 10.5 )
			{
				player[i].win_lose -= player[i].point ;
				player[0].win_lose += player[i].point ; 
				++i ;
			}
			else if ( player[i].count < 10.5 && player[i].card_num == 5 )
			{
				player[i].win_lose += player[i].point ;
				player[0].win_lose -= player[i].point ;
				++i ;
			}
		}
		else
			++i ;
	}
	int max = 0 ;
	while ( true )
	{
		bool flag = true ;
		for ( int i = 1 ; i < n+1 ; ++i )
		{
			if ( player[0].count < player[i].count )
				max++ ; 
			if ( player[i].win_lose == 0 )
				flag = false ;
		}
		if ( flag )
			break ;
		if ( max == n )
		{
			char card , space ;
			scanf( "%c%c" , &card , &space ) ;
			if ( card == '1' && space == '0' )
			{
				scanf( "%c" , &space ) ;
				player[0].count += 10.0 ;
			}
			else if ( card == 'A')
				player[0].count += 1.0 ;
			else if ( card == 'J' )
				player[0].count += 0.5 ;	
			else if ( card == 'Q' )
				player[0].count += 0.5 ;
			else if ( card == 'K' )
				player[0].count += 0.5 ;
			else
				player[0].count += (float)( card - '0' ) ;
		}
		else
			break ;
	}
	for ( int i = 0 ; i < n+1 ; ++i )
	{
		if ( player[i].win_lose != 0 && i != 0 )
			continue ;
		if ( player[0].count > 10.5 && i != 0 )
		{
			player[i].win_lose += player[i].point ;
			player[0].win_lose -= player[i].point ; 
		}
		player[i].differ = 10.5 - player[i].count ;
		if ( i == 0 )
			continue ;
		if ( player[i].differ < player[0].differ )
		{
			player[i].win_lose += player[i].point ;
			player[0].win_lose -= player[i].point ;
		}
		else if ( player[i].differ >= player[0].differ && i != 0 )
		{
			player[i].win_lose -= player[i].point ;
			player[0].win_lose += player[i].point ;
		}
	}
	for ( int i = 1 ; i < n+1 ; ++i )
	{
		if ( player[i].win_lose <= 0 )
			printf( "Player%d %d\n" , i , player[i].win_lose ) ;
		if ( player[i].win_lose > 0 )
			printf( "Player%d +%d\n" , i , player[i].win_lose ) ;
	 } 
	if ( player[0].win_lose <= 0 )
		printf( "Computer %d\n" , player[0].win_lose ) ;
	if ( player[0].win_lose > 0 )
		printf( "Computer +%d\n" , player[0].win_lose ) ;
 } 
