#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Player 
{
	int n ;
	int card_n ;
	int type ;
	int card[17][5] ;
}player[100] ;
int tp ( char t )
{
	if ( t == 'Q' )
		return 12 ;
	else if ( t == 'J' )
		return 11 ;
	else if ( t == 'K' )
		return 13 ;
	else if ( t == 'A' )
		return 14 ;
	else if ( t == '2' )
		return 15 ;
	else if ( t == 'S' )
		return 4 ;
	else if ( t == 'H' )
		return 3 ;
	else if ( t == 'D' )
		return 2 ;
	else if ( t == 'C' )
		return 1 ;
	else 
		return 0 ;
}
int judge1( int k )
{
	for ( int i = 15 ; i >= 3 ; --i )
	{
		for ( int j = 4 ; j >= 1 ; --j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				player[k].n = 1 ;
				player[k].type = player[k].card[i][j] ;
				return true ;
			}
		}
	}
	return false ;
}
int judge2 ( int k )
{
	for ( int i = 15 ; i >= 3 ; --i )
	{
		int sum = 0 , index = 0 ;
		for ( int j = 1 ; j <= 4 ; ++j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				sum++ ;
				index = j ;
			}
		}
		if ( sum == 2 )
		{
			player[k].n = 2 ;
			player[k].type = player[k].card[i][index] ;
			return true ; 
		}
	 } 
	return false ;
}
bool judge3 ( int k )
{
	int get = 0 ;
	for ( int i = 3 ; i < 16 ; ++i )
	{
		int sum = 0 , index = 0;
		for ( int j = 4 ; j >= 1 ; --j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				sum++ ;
				index = j ;
			}
		}
		if ( sum == 2 )
			get++ ;
		if ( get == 2 )
		{
			player[k].n = 3 ;
			player[k].type = player[k].card[i][index] ;
			return true ; 
		}
	 } 
	return false ;
}
bool judge4 ( int k )
{
	for ( int i = 15 ; i >= 3 ; --i )
	{
		int sum = 0 , index = 0;
		for ( int j = 1 ; j <= 4 ; ++j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				sum++ ;
				index = j ;
			}
		}
		if ( sum == 3 )
		{
			player[k].n = 3 ;
			player[k].type = player[k].card[i][index] ;
			return true ; 
		}
	 } 
	return false ;
}

bool judge5 ( int k )
{
	int sum = 0 ;
	for ( int i = 15 ; i >= 3 ; --i )
	{
		bool ju0 = false ;
		int index = 0;
		for ( int j = 4 ; j >= 1 ; --j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				sum++ ;
				index = j ;
				ju0 = true ;
				break ;
			}
		}
		if ( ju0 == false )
			sum = 0 ;
		if ( sum == 5 )
		{
			player[k].n = 5 ;
			player[k].type = player[k].card[i][index] ;
			return true ; 
		}
	}
	for ( int i = 1 ; i < 5 ; ++i )
	{
		bool ju0 = false ;
		int index = 0 ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( player[k].card[i][j] != 0 )
			{
				sum++ ;
				index = j ;
				ju0 = true ;
				break ;
			}
		}
		if ( ju0 == false )
			sum = 0 ;
		if ( sum == 5 )
		{
			player[k].n = 5 ;
			player[k].type = player[k].card[i][index] ;
			return true ; 
		}
	}
	return false ;
}
bool judge6 ( int k )
{
	for ( int i = 4 ; i >= 1 ; --i )
	{
		int sum = 0 ;
		for ( int j = 15 ; j >= 3 ; --j )
		{
			if ( player[k].card[j][i] != 0 )
				sum++ ;
			if ( sum == 5 )
			{
				player[k].n = 6 ;
				player[k].type = player[k].card[j][i] ;
				return true ;
			}
		}
	}
	return false ;
}
bool judge7 ( int k )
{
	if ( judge2( k ) && judge4( k ) )
	{
		player[k].n = 7 ;
		return true ;
	 } 
	 return false ;
}
bool judge8 ( int k )
{
	for ( int i = 15 ; i >= 3 ; --i )
	{
		int sum = 0 ;
		for ( int j = 4 ; j >= 1 ; --j )
		{
			if ( player[k].card[i][j] != 0 )
				sum++ ;
			else
				sum = 0 ;
		}
		if ( sum == 4 )
		{
			player[k].n = 8 ;
			player[k].type = player[k].card[i][4] ;
			return true ;
		}
	 } 
	return false ;
}
bool judge9 ( int k )
{
	int sum = 0 ;
	for ( int i = 4 ; i >= 1 ; --i )
	{
		for ( int j = 15 ; j >= 3 ; --j )
		{
			if ( player[k].card[j][i] != 0 )
				sum++ ;
			else
				sum = 0 ;
			if ( sum == 5 )
			{
				player[k].n = 9 ;
				player[k].type = player[k].card[j][i] ;
				return true ;
			}
		}
		for ( int j = 15 ; j >= 10 ; --j )
		{
			if ( player[k].card[j][i] != 0 )
				sum++ ;
			else
				sum = 0 ;
			if ( sum == 5 )
			{
				player[k].n = 9 ;
				player[k].type = player[k].card[j][i] ;
				return true ;
			}
		}
	}
	return false ;
}

int main ()
{
	int n ;
	scanf( "%d\n" , &n ) ;
	while ( n-- )
	{
		int map_card[17][4] = {0} , flag = 0  , ans[4] = {0} ;
		for ( int i = 0 ; i < 4 ; ++i )
		{
			memset( player[i].card , 0 , sizeof( player[i].card ) ) ;
			char line[100] ;
			for ( int j = 0 ; j < 5 ; ++j )
			{
				scanf( "%s" , &line ) ;
				if ( flag != 0 )
					continue ;
				if ( strlen( line ) == 2 )
				{
					if ( line[0] <= '9'&& line[0] > '2' )
					{
						int t = tp( line[1] ) ;
						if ( t == 0 )
						{
							flag = 1 ;
							continue ;
						}
						if ( map_card[line[0]-'0'][t] != 0 )
						{
							flag = 2 ;
							continue ;
						}
						map_card[line[0]-'0'][t] = 1 ;
						player[i].card[line[0]-'0'][t] = ( line[0]-'0' ) * 10 +t ;
					}
					else if ( line[0] == 'K' || line[0] == 'Q' || line[0] == 'J' || line[0] == 'A' || line[0] == '2' )
					{
						int t1 = tp( line[0] ) ;
						int t2 = tp( line[1] ) ;
						if ( t1 == 0 || t2 == 0 )
						{
							flag = 1 ;
							continue ;
						}
						if ( map_card[t1][t2] != 0 )
						{
							flag = 2 ;
							continue ;
						}
						map_card[t1][t2] = 1 ;
						player[i].card[t1][t2] = t1*10+t2 ;
					 } 
					else
					{
						flag = 1 ;
						continue ;
					}
				}
				else if ( strlen( line ) == 3 && ( line[0] == '1' && line[1] == '0' ) )
				{
					int t = tp( line[2] ) ;
					if ( t == 0 )
					{
						flag = 1 ;
						continue ;
					}
					if ( map_card[10][t] != 0 )
					{
						flag = 2 ;
						continue ;
					} 
					map_card[10][t] = 1;
					player[i].card[10][t] = 100+t ;
				}
				else
				{
					flag = 1 ;
					continue ;
				 } 
			}
			if ( judge9( i ) )
			{
				ans[i] = 9 ;
			}
			else if ( judge8( i ) )
			{
				ans[i] = 8 ;
			}
			else if ( judge7( i ) )
			{
				ans[i] = 7 ;
			}
			else if ( judge6( i ) )
			{
				ans[i] = 6 ;
			}
			else if ( judge5( i ) )
			{
				ans[i] = 5 ;
			}
			else if ( judge4( i ) )
			{
				ans[i] = 4 ;
			}
			else if ( judge3( i ) )
			{
				ans[i] = 3 ;
			}
			else if ( judge2( i ) )
			{
				ans[i] = 2 ;
			}
			else if ( judge1( i ))
				ans[i] = 1 ;
			//printf( "%d\n" , ans[i] ) ;
		}
		if ( flag == 1 )
		{
			printf( "Error input\n" ) ;
		}
		else if ( flag == 2 )
		{
			printf( "Duplicate deal\n" ) ;
		}
		else
		{
			int max = 0 , max_index = 0 ;
			for ( int i = 0 ; i < 4 ; ++i )
			{
				if ( max < player[i].n )
				{
					max = player[i].n ;
					max_index = i ;
				}
				else if ( max == player[i].n )
				{
					if ( player[i].type < player[i].type )
					{
						max_index = i ;
					}
				}
			}
			printf( "%c\n" , max_index+'A' ) ;
		}
	}
}
/*
1
JH AD 4H 7H 9H
3S 2H AH 5H 6H
7S 10H AC 8D 4D
10S 8S QS 2C KC
*/
