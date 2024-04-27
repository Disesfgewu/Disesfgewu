#include <stdio.h>
#include <string.h>
struct school // define a structure named school , it contains three elements ( name , special[8] , index ) 
{
	char name[10] ;
	int special[8]  ;
	int index ;
}university[100] ;
struct ins // define a structure named ins , it contains tow elements ( special[8] , number ) 
{
	int special[10][8] ;	
 	int number ; 
}instruct[100] ;
void check2 ( char* name , int i , int j ) // check2 and check functions are doing the indiction each elements.
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
		if ( university[h].special[j] != instruct[i].special[z][j] && instruct[i].special[z][j] == 1 ) // check if the insturct special element is same as the school
			return 0 ; // if not , return 0 
	return 1 ;
}
int compare2( int i , int h , int z )
{
	int count = 0 ;
	for ( int j = 0 ; j < 8 ; ++j )
		if ( university[h].special[j] == instruct[i].special[z][j] && instruct[i].special[z][j] == 1 )
			count++ ;
	return count ;
}
int main ()
{
	int n ;
	scanf( "%d\n" , &n ) ;
	char line[100] ;
	for ( int i = 0 ; i < n ; ++i )
	{
		gets( line ) ; // get a line of input into a string variable named "line" 
		memset( university[i].special , 0 , sizeof( university[i].special ) ) ;
		char a[100] ;
		for ( int j = 0 , k = 0 , l = 0 ; j < strlen( line ) ; ++j ) // cut it by space
		{
			if ( line[j] == ' ' )
			{
				k++ ;
				l = 0 ;
				if ( k > 1 )
					check( a , i ) ;
				memset( a , 0 , sizeof(a) ) ;
				continue ;
			}
			if ( k == 0 )
			{
				university[i].name[l] = line[j] ;
				l++ ;
			}
			else
			{
				a[l] = line[j] ;
				l++ ;
			}
		}
		check( a , i ) ;
	}
	int m ;
	scanf( "%d\n" , &m ) ;
	memset( line , 0 , sizeof( line ) ) ;
	for ( int i = 0 ; i < m ; ++i )
	{
		gets( line ) ;
		instruct[i].number = 0 ;
		char a[100] ;
		int k = 0 ;
		for ( int j = 0 , l = 0 ; j < strlen( line ) ; ++j )
		{
			if ( line[j] == ' ' )
			{
				if ( l == 0 )
					continue ;
				check2( a , i , k ) ;
				memset( a , 0 , sizeof( a ) ) ;
				l = 0 ;
				continue ;
			}
			else if ( line[j] == '+' )
			{
				instruct[i].number++ ;
				k++ ;
			}
			else
			{
				a[l] = line[j] ;
				l++ ;
			}
		}
		check2( a , i , k ) ;
		instruct[i].number++ ;
	}
	int b ;
	scanf( "%d" , &b ) ; // get it want to get 1 instruction or 2 instruction 
	if ( b == 0 )
	{
		for ( int i = 0 ; i < m ; ++i )
		{
			for ( int a = 0 ; a < n ; ++a )
				university[a].index = 0 ;
			for ( int z = 0 ; z < instruct[i].number ; ++z )
			{
				for ( int j = 0 ; j < n ; ++j )
				{
					int flag = compare( i , j , z ) ;
					if ( flag == 1 && university[j].index != -1 )
						university[j].index = 1 ;
				}
				for ( int j = 0 ; j < n ; ++j )
					if ( university[j].index == 1 )
					{
						printf( "%s " , university[j].name ) ;
						university[j].index = -1 ;
					}
			}
			printf( "\n" ) ;
		}
	}
	else if ( b == 1 )
	{
		for ( int i = 0 ; i < m ; ++i )
		{
			for ( int a = 0 ; a < n ; ++a )
				university[a].index = 0 ;
			for ( int z = 0 ; z < instruct[i].number ; ++z )
				for ( int j = 0 ; j < n ; ++j )
					university[j].index = compare2( i , j , z ) ;
			int index = 0 , max = -1 ;
			for ( int j = 0 ; j < n ; ++j )
				if ( max < university[j].index )
				{
					max = university[i].index ;
					index = j ;
				}
			printf( "%s\n" , university[index].name ) ;
		}
	}
	return 0 ;
}
