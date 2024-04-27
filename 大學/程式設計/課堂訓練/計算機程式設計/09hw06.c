#include <stdio.h>
#include <string.h>
struct school
{
	char name[10] ;
	int special[8]  ;
}university[100] ;
struct ins
{
	int special[10][8] ;	
 	int number ; 
}instruct[100] ;
void check2 ( char* name , int i , int j )
{
	if ( name[0] == 'G' && name[1] == 'F' )
		instruct[i].special[j][0] = 1 ;
	else if ( name[0] == 'B' && name[1] == 'C' )
		instruct[i].special[j][1] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'C' )
		instruct[i].special[j][2] = 1 ;
	else if ( name[0] == 'C' && name[1] == 'T' )
		instruct[i].special[j][3] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'S' )
		instruct[i].special[j][4] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'M' )
		instruct[i].special[j][5] = 1 ;
	else if ( name[0] == 'H' && name[1] == 'L' )
		instruct[i].special[j][6] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'L' )
		instruct[i].special[j][7] = 1 ;
}
void check( char* name , int i )
{
	if ( name[0] == 'G' && name[1] == 'F' )
		university[i].special[0] = 1 ;
	else if ( name[0] == 'B' && name[1] == 'C' )
		university[i].special[1] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'C' )
		university[i].special[2] = 1 ;
	else if ( name[0] == 'C' && name[1] == 'T' )
		university[i].special[3] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'S' )
		university[i].special[4] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'M' )
		university[i].special[5] = 1 ;
	else if ( name[0] == 'H' && name[1] == 'L' )
		university[i].special[6] = 1 ;
	else if ( name[0] == 'N' && name[1] == 'L' )
		university[i].special[7] = 1 ;
}
int compare( int i , int h , int z )
{
	for ( int j = 0 ; j < 8 ; ++j )
	{
		if ( university[h].special[j] != instruct[i].special[z][j] )
			return 0 ;
	}
	return 1 ;
}
int main ()
{
	int n ;
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; i < n ; ++i )
		memset( university[i].special , 0 , sizeof( university[i].special ) ) ;
	char line[100] ;
	for ( int i = 0 ; i < n ; ++i )
	{
		memset( line , 0 , sizeof( line ) ) ;
		int j = 0 ;
		while ( ( line[j] = getchar() ) && line[j] != '\n' )
			j++ ;
		int k = 0 , l = 0 ;
		char na[10] ;
		for ( j = 0 ; j < strlen( line ) ; ++j )
		{
			if ( line[j] == ' ' )
			{
				if ( k > 0 )
					check( na , i ) ;
				k++ ;
				l = 0 ;
			}
			else if ( k == 0 )
			{
				university[i].name[l] = line[j] ;
				l++ ;
			}
			else
			{
				na[l] = line[j] ;
				l++ ;
			}
		}
	}
	int m ;
	scanf( "%d" , &m ) ;
	for ( int i = 0 ; i < m ; ++i )
	{
		memset( line , 0 , sizeof( line ) ) ;
		memset( instruct[i].special , 0 , sizeof( instruct[i].special ) ) ;
		instruct[i].number = 0 ;
		int j = 0 ;
		while ( ( line[j] = getchar() ) && line[j] != '\n' )
			j++ ;
		int l = 0 , h = 0 ;
		char a[100] ; 
		for ( j = 0 ; j < strlen( line ) ; ++j )
		{
			if ( line[j] == ' ' )
			{
				check2( a , i ,  h ) ;
				memset( a , 0 , sizeof( a ) ) ;
				l = 0 ; 
				continue ;
			}
			else if ( line[j] == '+' )
			{
				h++ ;
				instruct[i].number++ ;
			}
			else
			{
				a[l] = line[j] ;
				++l ;
			}
		}
		check2( a , i ,  h ) ;
		instruct[i].number++ ;
	}
	int b ;
	scanf( "%d" , &b ) ;
	char ans[10000] = "" ;
	if ( b == 0 )
	{
		for ( int i = 0 ; i < m ; ++i )
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				int flag ;
				for ( int z = 0 ; z < instruct[i].number ; ++z )
				{
					flag = compare( i , j , z ) ;
					if ( flag == 1 )
					{
						
					}
				}
			}
		}
	}
}
