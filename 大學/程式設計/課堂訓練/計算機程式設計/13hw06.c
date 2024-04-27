#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Word
{
	char the_word[100] ;
	int line_index ;
	int word_index ;
	int registerA ;
} ;
struct position
{
	int index ;
}; 
int find ( int a , int b , struct Word* word , struct position* ans , int count , bool flag )
{
	if ( flag == true )
		for ( int i = 0 ; i < count ; ++i )
		{
			if ( word[ans[i].index].line_index == a && word[ans[i].index].word_index == b )
				return i ;
		}
	else
		for ( int i = 0 ; i < count ; ++i )
		{
			if ( word[ans[i].index].line_index > a && word[ans[i].index].word_index == b )
				return i ;
		}
}
void judge_the_word ( char* a , int begin , struct Word* word , struct position* ans , bool flag  , int count )
{
	if ( flag == true )
	{
		for ( int i = begin ; i < count ; ++i )
		{
			if ( strcmp( word[ans[i].index].the_word , a ) == 0 && word[ans[i].index].registerA == 0 )
			{
				word[ans[i].index].registerA = -1 ;
			}
		}
	}
	else
	{
		for ( int i = begin ; i < count ; ++i )
		{
			if ( strcmp( word[ans[i].index].the_word , a ) == 0 && word[ans[i+1].index].registerA == 0 )
			{
				word[ans[i+1].index].registerA = -1 ;
			}
		}
	}
}
void shift ( int result , int* count , struct position* ans )
{
	for ( int i = *count+1 ; i > result ; --i )
		ans[i].index = ans[i-1].index ;
}
void shift_line ( struct Word* word , struct position* ans, int a , int original_index )
{
	for ( int i = 0 ; i < original_index ; ++i )
	{
		if ( word[ans[i].index].line_index >= a )
			word[ans[i].index].line_index++ ;
	}
}
void shift_line_delete( struct Word* word , int a , int original_index )
{
	for ( int i = 0 ; i < original_index ; ++i )
	{
		if ( word[i].line_index == a )
			word[i].line_index = -1 ;
		else if ( word[i].line_index > a )
			word[i].line_index-- ;
	}
}
void copy ( char* a , char* b )
{
	for ( int i = 0 ; i < strlen(b) ; ++i )
		a[i] = b[i] ;
}
int main ()
{
	int n , m ;
	char get[100] ;
	char space ;
	scanf( "%d%d%c" , &n , &m , &space ) ;
	struct Word word[1000] ;
	struct position ans[1000] ;
	// 歸零 
	for ( int i = 0 ; i < 1000 ; ++i )
	{
		word[i].line_index = 0 ;
		word[i].word_index = 0 ;
		word[i].registerA = 0 ;
		ans[i].index = 0 ;
		memset( word[i].the_word , 0 , sizeof( word[i].the_word ) ) ;
	}
	int count = 0 ;
	// 文章切割並存進每一個的位置 
	for ( int i = 0 ; i < n ; ++i )
	{
		gets( get ) ;
		int j = 0 ;
		char* token = strtok( get , " " ) ;
		while ( token != NULL )
		{
			word[count].line_index = i+1 ;
			word[count].word_index = ++j ;
			ans[count].index = count ;
			copy( word[count++].the_word , token ) ;
			token = strtok( NULL , " " ) ;
		}
	}
	int original_index = count ;
	// 進行編輯 
	for ( int i = 0 ; i < m ; ++i )
	{
		char instruct[100] ;
		scanf( "%s" , instruct ) ;
		if ( strcmp(  instruct , "awf" ) == 0 )
		{
			int a , b ;
			scanf( "%d%c%d%c" , &a , &space , &b , &space ) ;
			int result = find( a , b , word , ans , count , true ) ;
			shift( result , &count , ans ) ;
			for ( int j = result+1 ; j < count ; ++j )
			{
				if ( word[ans[j].index].line_index == a )
					word[ans[j].index].word_index++ ;
				else
					break ;
			}
			ans[result].index = count ;
			word[count].line_index = a ;
			word[count].word_index = b ;
			gets( word[count++].the_word ) ;
		}
		else if ( strcmp( instruct , "awa" ) == 0 )
		{
			int a , b ;
			scanf( "%d%c%d%c" , &a , &space , &b , &space ) ;
			int result = find( a , b , word , ans , count , true ) ;
			shift( result+1 , &count , ans ) ;
			for ( int j = result+2 ; j < count ; ++j )
			{
				if ( word[ans[j].index].line_index == a )
					word[ans[j].index].word_index++ ;
				else
					break ;
			}
			ans[result+1].index = count ;
			word[count].line_index = a ;
			word[count].word_index = b+1 ;
			scanf( "%s" , word[count++].the_word ) ;
		}
		else if ( strcmp( instruct , "asf" ) == 0 )
		{
			int a ;
			scanf( "%d " , &a ) ;
			char line[100] ;
			gets( line ) ;
			char* token = strtok( line , " " ) ;
			int j = 1 , sum = count , result ;
			while ( token != NULL )
			{
				result = find( a , j , word , ans , count , true ) ;
				shift( result , &count , ans ) ;
				ans[result].index = count ;
				word[count].line_index = -1;
				word[count].word_index = -1;
				copy( word[count++].the_word , token ) ;
				token = strtok( NULL , " " ) ;
			}
			for ( j = sum ; j < count ; ++j )
			{
				word[j].line_index = a ;
				word[j].word_index = j-sum ; 
			}
			shift_line( word , ans , a , sum ) ;
		}
		else if ( strcmp( instruct , "asa" ) == 0 )
		{
			int a ;
			scanf( "%d " , &a ) ;
			char line[100] ;
			gets( line ) ;
			char* token = strtok( line , " " ) ;
			int j = 1 , sum = count , result ;
			while ( token != NULL )
			{
				result = find( a , j , word , ans , count , false ) ;
				shift( result , &count , ans ) ;
				ans[result].index = count ;
				word[count].line_index = -1;
				word[count].word_index = -1;
				copy( word[count++].the_word , token ) ;
				token = strtok( NULL , " " ) ;
			}
			for ( j = sum ; j < count ; ++j )
			{
				word[j].line_index = a ;
				word[j].word_index = j-sum ; 
			}
			shift_line( word , ans , a+1 , original_index ) ;
		}
		else if ( strcmp ( instruct , "if") == 0 )
		{
			char a[100] , b[100] ;
			scanf( "%s" , a ) ;
			scanf( "%s" , b ) ;
			judge_the_word( a , 0 , word , ans , true , count ) ;
			for ( int j = 0 ; j < count ; ++j )
			{
				if ( word[ans[j].index].registerA == -1 )
				{
					word[ans[j].index].registerA = 0 ;
					int line = word[ans[j].index].line_index ;
					int row  = word[ans[j].index].word_index ;
					shift( j , &count , ans ) ;
					ans[j].index = count ;
					word[count].line_index = line ;
					word[count].word_index = row ;
					copy( word[count++].the_word , b ) ; 
					for ( int z = j+1 ; z < count ; ++z )
					{		
						if ( word[ans[z].index].line_index == line )
							word[ans[z].index].word_index++ ;
						else
							break ;
					}
				}
			}
		}
		else if ( strcmp( instruct , "ia" ) == 0 )
		{
			char a[100] , b[100] ;
			scanf( "%s" , a ) ;
			scanf( "%s" , b ) ;
			judge_the_word( a , 0 , word , ans , true , count ) ;
			for ( int j = 0 ; j < count ; ++j )
			{
				if ( word[ans[j].index].registerA == -1 )
				{
					word[ans[j].index].registerA = 0 ;
					int line = word[ans[j].index].line_index ;
					if ( line == 0 )
						line = word[ans[j].index].line_index ;
					int row  = word[ans[j+1].index].word_index ;
					if ( row == 0 )
						row = word[ans[j].index].word_index+1 ;
					shift( j+1 , &count , ans ) ;
					ans[j+1].index = count ;
					word[count].line_index = line ;
					word[count].word_index = row ;
					copy( word[count++].the_word , b ) ; 
					for ( int z = j+2 ; z < count ; ++z )
					{		
						if ( word[ans[z].index].line_index == line )
							word[ans[z].index].word_index++ ;
						else
							break ;
					}
				}
			}
		}
		else if ( strcmp( instruct , "dw" ) == 0 )
		{
			int a , b ;
			scanf( "%d%c%d%c" , &a , &space , &b , &space ) ;
			int result = find( a , b , word , ans , count , true ) ;
			int j = 0 ;
			for ( j = result+1 ; j < count ; ++j )
			{
				if ( word[ans[j].index].line_index == a )
					word[ans[j].index].word_index-- ;
				else
					break ;
			}
			for ( int z = result ; z < j-1 ; ++z )
			{
				word[ans[z].index].line_index = word[ans[z+1].index].line_index ;
				word[ans[z].index].word_index = word[ans[z+1].index].word_index ;
			}
			word[ans[j-1].index].line_index = 0 ;
			word[ans[j-1].index].word_index = 0 ;
			memset( word[ans[j-1].index].the_word , 0 , sizeof( word[ans[j-1].index].the_word ) ) ;
		}
		else if ( strcmp( instruct , "dl" ) == 0 )
		{
			int a ;
			scanf( "%d" , &a ) ;
			shift_line_delete( word , a , count ) ;
			int tips = 0 ;
			for ( int j = 0 ; j < count ; ++j )
			{
				if ( word[ans[j].index].line_index == -1 )
					tips++ ;
			}
			int j = 0 ;
			while ( j < count )
			{
				if ( word[ans[j].index].line_index >= 0 )
					j++ ;
				else
				{
					for ( int z = j ; z < count ; ++z )
					{
						word[ans[z].index].line_index = word[ans[z+1].index].line_index ;
						word[ans[z].index].word_index = word[ans[z+1].index].word_index ;
						memset( word[ans[z].index].the_word , 0 , sizeof( word[ans[z].index].the_word ) ) ;
						copy( word[ans[z].index].the_word , word[ans[z+1].index].the_word ) ;
					}
				}
			}
			for ( j = count-tips ; j < count ; ++j )
			{
				word[ans[j].index].line_index = 0 ;
				word[ans[j].index].word_index = 0 ;
				memset( word[ans[j].index].the_word , 0 , sizeof( word[ans[j].index].the_word ) ) ;
			}
		}
		else if ( strcmp( instruct , "rp" ) == 0 )
		{
			char a[100] , b[100] ;
			scanf( "%s" , a ) ;
			scanf( "%s" , b ) ;
			judge_the_word( a , 0 , word , ans , true , count ) ;
			for ( int j = 0 ; j < count ; ++j )
			{
				if ( word[ans[j].index].registerA == -1 )
				{
					word[ans[j].index].registerA = 0 ;
					memset( word[ans[j].index].the_word , 0 , sizeof( word[ans[j].index].the_word ) ) ;
					copy( word[ans[j].index].the_word , b ) ; 
				}
			}
		}
		else if ( strcmp( instruct , "c" ) == 0 )
		{
			int sum = 0 ;
			for ( int j = 0 ; j < count ; ++j )
			{
				if ( word[ans[j].index].line_index > 0 )
					sum++ ;
			}
			printf( "%d\n" , sum ) ;
		}
	}
	int record = 1 ; 
	for ( int j = 0 ; j < count ; ++j )
	{
		if ( word[ans[j].index].line_index > 0 )
		{
			if ( word[ans[j].index].line_index != record )
			{
				record = word[ans[j].index].line_index ;
				printf( "\n" ) ;
			}
			printf( "%s " , word[ans[j].index].the_word ) ;
		}
	}
	return 0 ;
}
