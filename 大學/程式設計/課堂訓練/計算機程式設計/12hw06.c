#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct word
{
	char voc[1000] ;
	int possibility ;
};
void get_word( char* a , int i , struct word* sp )
{
	for ( int j = 0 ; j < strlen( a ) ; ++j )
		sp -> voc[j] = a[j] ; 
}
int main ()
{
	struct word sp[1000] , sp2[1000] ;
	char line[1000] ;
	gets( line );
	const char* d = " " ;
	char* slice = strtok( line , d ) ;
	int j = 0 ;
	while ( slice != NULL )
	{
		get_word( slice , j , &sp[j] ) ;
		j++ ;
		slice = strtok( NULL , d ) ;
	}
	char line2[1000] ;
	gets( line ) ;
	gets( line2 ) ;
	int N , c ;
	scanf( "%d" , &N ) ;
	scanf( "%d" , &c ) ;
	if ( c == 1 )
		for ( int i = 0 ; i < j ; ++i )
		{
			if ( strcmp( sp[i].voc , line ) == 0 )
			{
				memset( sp[i].voc , 0 , sizeof( sp[i].voc) ) ;
				get_word( line2 , i , &sp[i] ) ;
			}
			printf( "%s " , sp[i].voc ) ;
		}
	else if ( c == 2 )
		for ( int i = 0 ; i < j ; ++i )
		{
			if ( strcmp( sp[i].voc , line ) == 0 )
				printf( "%s " , line2 ) ;
			printf( "%s " , sp[i].voc ) ;
		}
	else if ( c == 3 )
		for ( int i = 0 ; i < j ; ++i )
		{
			if ( strcmp( sp[i].voc , line ) == 0 )
				continue ;
			printf( "%s " , sp[i].voc ) ;
		}
	else if ( c == 4 )
	{
		int k = 0 ;
		for ( int i = 0 ; i < j ; ++i )
		{
			bool flag = false ;
			for ( int z = 0 ; z < k ; ++z )
				if ( strcmp( sp2[z].voc , sp[i].voc ) == 0 )
				{
					sp2[z].possibility++ ;
					flag = true ;
					break ;
				}
			if ( !flag )
			{
				k++ ;
				get_word( sp[i].voc , k-1 , &sp2[k] ) ;
				sp2[k].possibility = 1 ; 
			}
		}
		for ( int i = 0 ; i < 2; ++i )
		{
			int max = 0 , max_index = 0 ;
			for ( int z = 0 ; z < k ; ++z )
				//printf( "%s : %d\n" , s)
				if ( max < sp2[z].possibility )
				{
					max = sp2[z].possibility ;
					max_index = z ;
				}
			printf( "%s:%d\n" , sp2[max_index].voc , max ) ;
			sp2[max_index].possibility = -1 ;
		}
	}
	else
	{
		int k = 0 ;
		for ( int i = 0 ; i < j ; ++i )
		{
			bool flag = false ;
			for ( int z = 0 ; z < k ; ++z )
				if ( strcmp( sp2[z].voc , sp[i].voc ) == 0 )
				{
					sp2[z].possibility++ ;
					flag = true ;
					break ;
				}
			if ( !flag )
			{
				k++ ;
				get_word( sp[i].voc , k-1 , &sp2[k] ) ;
				sp2[k].possibility = 1 ; 
			}
		}
		for ( int z = 0 ; z < k ; ++z )
			if ( sp2[z].possibility < N )
				memset( sp2[z].voc , 0 , sizeof( sp2[z].voc ) ) ;
		for ( int i = 0 ; i < j ; ++i )
			for ( int z = 0 ; z < k ; ++z )
				if ( strcmp( sp[i].voc , sp2[z].voc ) == 0 )
					printf( "%s " , sp[i].voc ) ;
	}
}
