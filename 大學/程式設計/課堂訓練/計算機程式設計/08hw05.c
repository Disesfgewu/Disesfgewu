#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int map_card[14][4] = {0} , check_map_card[14][4] = {0} ;
bool flag = false , flag2 = false ;
void map ( char a , int b )
{
	int f = a - '0' ;
	switch ( a )
	{
		case 'A' :
			map_card[1][b] = 1 ;
			check_map_card[1][b]++ ;
			break ; 
		case 'J' :
			map_card[11][b] = 11 ;
			check_map_card[11][b]++ ;
			break ; 
		case 'Q' :
			map_card[12][b] = 12 ;
			check_map_card[12][b]++ ;
			break ; 
		case 'K' :
			map_card[13][b] = 13 ;
			check_map_card[13][b]++ ;
			break ;  
		default : 
			if ( f < 10 && f >= 2 )
			{	
				map_card[f][b] = f ;
				check_map_card[f][b]++ ;
			}
			else
				flag = true ;
			break ;
	}
}
bool judge2 ( void )
{
	for ( int i = 1 ; i < 14 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
				sum++ ;
		}
		if ( sum == 2 )
			return true ; 
	 } 
	return false ;
}
bool judge3 ( void )
{
	int get = 0 ;
	for ( int i = 1 ; i < 14 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
				sum++ ;
		}
		if ( sum == 2 )
			get++ ;
		if ( get == 2 )
			return true ; 
	 } 
	return false ;
}
bool judge4 ( void )
{
	for ( int i = 1 ; i < 14 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
				sum++ ;
		}
		if ( sum == 3 )
			return true ; 
	 } 
	return false ;
}
bool judge5 ( void )
{
	int sum = 0 ;
	for ( int i = 1 ; i < 14 ; ++i )
	{
		bool ju0 = false ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
			{
				sum++ ;
				ju0 = true ;
				break ;
			}
		}
		if ( ju0 == false )
			sum = 0 ;
		if ( sum == 5 )
			return true ;
	}
	for ( int i = 1 ; i < 5 ; ++i )
	{
		bool ju0 = false ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
			{
				sum++ ;
				ju0 = true ;
				break ;
			}
		}
		if ( ju0 == false )
			sum = 0 ;
		if ( sum == 5 )
			return true ;
	}
	return false ;
}
bool judge6 ( void )
{
	for ( int i = 0 ; i < 4 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 1 ; j < 14 ; ++j )
		{
			if ( map_card[j][i] != 0 )
				sum++ ;
			if ( sum == 5 )
				return true ;
		}
	}
	return false ;
}
bool judge7 ( void )
{
	if ( judge2() && judge4() )
		return true ;
	else
		return false ;
}
bool judge8 ( void )
{
	for ( int i = 1 ; i < 14 ; ++i )
	{
		int sum = 0 ;
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( map_card[i][j] != 0 )
				sum++ ;
			else
				sum = 0 ;
		}
		if ( sum == 4 )
			return true ; 
	 } 
	return false ;
}
bool judge9 ( void )
{
	int sum = 0 ;
	for ( int i = 0 ; i < 4 ; ++i )
	{
		for ( int j = 1 ; j < 14 ; ++j )
		{
			if ( map_card[j][i] != 0 )
				sum++ ;
			else
				sum = 0 ;
			if ( sum == 5 )
				return true ;
		}
		for ( int j = 1 ; j < 5 ; ++j )
		{
			if ( map_card[j][i] != 0 )
				sum++ ;
			else
				sum = 0 ;
			if ( sum == 5 )
				return true ;
		}
	}
	return false ;
}

int main () 
{
	char card[10000] , c ;
	int ans[2] = {0} ;
	for ( int i = 0 ; i < 2 ; ++i )
	{
		memset( map_card , 0 , sizeof( map_card ) ) ;
		memset( card , '0' , sizeof( card ) ) ;
		for ( int j = 0 ; j < 5 ; ++j )
		{
			int y = 0 ;
			scanf( "%s" , &card ) ;
			if ( card[0] == '1' && card[1] == '0' )
			{
				if ( card[2] == 'S' )
				{
					map_card[10][0] = 10 ;
					check_map_card[10][0]++ ; 
				}
				else if ( card[2] == 'H' )
				{
					map_card[10][1] = 10 ;
					check_map_card[10][1]++ ; 
				}
				else if ( card[2] == 'D' )
				{
					map_card[10][2] = 10 ;
					check_map_card[10][2]++ ; 
				}
				else if ( card[2] == 'C' )
				{
					map_card[10][3] = 10 ;
					check_map_card[10][3]++ ; 
				}
			}
			else if ( strlen( card ) >= 3 )
				flag = true ;
			else if ( card[1] == 'S' )
				map( card[0] , 0 ) ;
			else if ( card[1] == 'H' )
				map( card[0] , 1 ) ;
			else if ( card[1] == 'D' )
				map( card[0] , 2 ) ;
			else if ( card[1] == 'C' )
				map( card[0] , 3 ) ;
			else
				flag = true ;
		}
		for ( int i = 1 ; i < 14 ; ++i )
		{
			for ( int j = 0 ; j < 4 ; ++j )
			{
				//printf( "%d " , check_map_card[i][j] ) ;
				if ( check_map_card[i][j] > 1 )
				{
					flag2 = true ;
					break ;
				}
			}
			//printf( "\n" ) ;
			if ( flag2 )
				break ;
		}
		if ( flag || flag2 )
			continue ;
		if ( judge9() )
		{
			ans[i] = 9 ;
		}
		else if ( judge8() )
		{
			ans[i] = 8 ;
		}
		else if ( judge7() )
		{
			ans[i] = 7 ;
		}
		else if ( judge6() )
		{
			ans[i] = 6 ;
		}
		else if ( judge5() )
		{
			ans[i] = 5 ;
		}
		else if ( judge4() )
		{
			ans[i] = 4 ;
		}
		else if ( judge3() )
		{
			ans[i] = 3 ;
		}
		else if ( judge2() )
		{
			ans[i] = 2 ;
		}
		else
			ans[i] = 1 ;
	}
	//printf( "%d\n" , flag ) ;
	if ( flag )
		printf( "Error input\n" ) ;
	else if ( flag2 )
		printf( "Duplicate deal\n" ) ;
	else if ( ans[0] > ans[1] )
		printf( "%d\n" , ans[0] ) ;
	else
		printf( "%d\n" , ans[1] ) ;
	return 0 ;
}
