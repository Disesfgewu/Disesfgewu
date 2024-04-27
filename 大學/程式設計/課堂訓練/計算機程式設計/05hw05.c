#include <stdio.h>
#include <string.h>
int main ()
{
	int a , ch = 0 ;
	char hit[10][10] ;
	for ( int i = 0 ; i < 9 ; ++i )
	{
		scanf( "%d " , &a ) ;
		if ( ch < a )
			ch = a ;
		for ( int j = 0 ; j < a ; ++j )
		{
			scanf( "%c " , &hit[i][j] ) ;
		}
	}
	int b ;
	scanf( "%d" , &b ) ;
	int goal[4] = {0} , get = 0 , get_goal[9] = {0} , successful_hit[9] = {0} , out = 0 , fail = 0 ;
	for ( int i = 0 ; i < ch ; ++i )
	{
		for ( int j = 0 ; j < 9 ; ++j )
		{
			if ( hit[j][i] == '\0' )
				continue ;
			if ( hit[j][i] == 'O' )
			{
				out++ ;
				fail++ ;
				if ( fail == 3 )
				{
					fail = 0 ;
					memset( goal , 0 , sizeof( goal ) ) ;
				}
				if ( out == b )
					break ;
				continue ;
			}
			else if ( hit[j][i] == '1' )
			{
				for ( int z = 3 ; z > 0 ; z-- )
				{
					goal[z] = goal[z-1] ;
				}
				goal[0] = j+1 ;
				if ( goal[3] != 0 )
				{
					get_goal[goal[3]-1]++ ;
					get++ ;
					goal[3] = 0 ;
				}
			}
			else if ( hit[j][i] == '2' )
			{
				if ( goal[2] != 0 )
				{
					get++ ;
					get_goal[goal[2]-1]++ ;
					goal[2] = 0 ;
				}
				if ( goal[1] != 0 )
				{
					get++ ;
					get_goal[goal[1]-1]++ ;
					goal[1] = 0 ;
				}
				if ( goal[0] != 0 )
				{
					goal[2] = goal[0] ;
					goal[0] = 0 ;
				}
				goal[1] = j+1 ;
			}
			else if ( hit[j][i] == '3' )
			{
				for ( int z = 0 ; z < 3 ; ++z )
				{
					if ( goal[z] != 0 )
					{
						get_goal[goal[z]-1]++ ;
						goal[z] = 0 ;
						get++ ;
					}
				}
				goal[2] = j+1 ; 
			}
			else if ( hit[j][i] == 'H' )
			{
				for ( int z = 0 ; z < 3 ; ++z )
				{
					if ( goal[z] != 0 )
					{
						get_goal[goal[z]-1]++ ;
						goal[z] = 0 ;
						get++ ;
					}
				}
				get_goal[j]++ ;
				get++ ;
			}
			successful_hit[j]++ ;
		}
		if ( out == b )
			break ;
	}
	printf( "%d\n" , get ) ;
	int max = 0 , maxpeo = 0 ;
	for ( int j = 0 ; j < 3 ; ++j )
	{
		for ( int i = 0 ; i < 9 ; ++i )
		{
			if ( max < get_goal[i] )
			{
				max = get_goal[i] ;
				maxpeo = i ;
			}
		}
		printf( "%d %d %d\n" , maxpeo+1 , successful_hit[maxpeo] , get_goal[maxpeo] ) ;
		get_goal[maxpeo] = -1 ;
		max = -1 ; 
	}
	return 0 ;
}
