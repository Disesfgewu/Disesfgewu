#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct 
{
	int room_number ;
	int people_number ;
	int ans[100] ;
	int ans_index ; 
} Classroom ;
typedef struct
{
	int class_number ;
	int people_number ;
	int start ;
	int end ;
	int hour ;	
} Lesson ;
typedef struct 
{
	int a[2][100] ;
	int index ;
	int hours ;
	int class_number ;
} set ;
void swap ( Lesson* lesson1 , Lesson* lesson2 )
{
	Lesson change = {} ;
	change = *lesson1 ;
	*lesson1 = *lesson2 ;
	*lesson2 = change ;
}
void swap2 ( set* list1 , set* list2 )
{
	set change = {} ;
	change = *list1 ;
	*list1 = *list2 ;
	*list2 = change ;
}
void swap3 ( Classroom* classroom1 , Classroom* classroom2 )
{
	Classroom change = {} ;
	change = *classroom1 ;
	*classroom1 = *classroom2 ;
	*classroom2 = change ;
}
void normal_swap( int* a , int* b )
{
	int tmp = *a ;
	*a = *b ;
	*b = tmp ; 
}
void array_sort( int* a , int n )
{
	for ( int i = 0 ; i < n ; ++i )
	{
		int min = 100000 , index = i ;
		for ( int j = i ; j < n ; ++j )
		{
			if ( min > a[j] )
			{
				min = a[j];
				index = j ;
			}
		}
		normal_swap( a+i , a+index ) ;
	}
}
void sort( Lesson* lesson , int n )
{
	for ( int i = 0 ; i < n ; ++i )
	{
		int min = 100000 , index = i ;
		for ( int j = i ; j < n ; ++j )
		{
			if ( min > lesson[j].start )
			{
				min = lesson[j].start ;
				index = j ;
			}
			else if ( min == lesson[j].start)
			{
				if ( lesson[j].end > lesson[index].end )
					index = j ;
			}
		}
		swap( &lesson[index] , &lesson[i] ) ;
	}
}
void check ( set* list , Lesson* lesson , int n , int m  )
{
	if ( lesson[n].start <= list[m].a[0][list[m].index] )
		return ;
	if ( list[m].index != 0 ) 
		list[m].index++ ;
	list[m].a[0][list[m].index] = lesson[n].start ;
	list[m].a[1][list[m].index] = n ;
	if ( lesson[n].start != lesson[n].end-1 )
		list[m].a[0][++list[m].index] = lesson[n].end-1 ;
	list[m].a[1][list[m].index] = n ;
	list[m].hours += lesson[n].hour ;
	list[m].class_number++ ;
}
void sorted ( Classroom* classroom , int m )
{
	for ( int i = 0 ; i < m ; ++i )
	{
		int max = 0 , index = i ;
		for ( int j = i ; j < m ; ++j )
		{
			if ( max < classroom[j].people_number )
			{
				max = classroom[j].people_number ;
				index = j ;
			} 
		} 
		swap3( &classroom[index] , &classroom[i] ) ;
	}
}
void sorting ( Classroom* classroom , int m )
{
	for ( int i = 0 ; i < m ; ++i )
	{
		int min = 10000 , index = i ;
		for ( int j = i ; j < m ; ++j )
		{
			if ( min > classroom[j].room_number )
			{
				min = classroom[j].room_number ;
				index = j ;
			} 
		} 
		swap3( &classroom[index] , &classroom[i] ) ;
	}
}
int main ()
{
	int m , n , b ;
	scanf( "%d%d" , &m , &n ) ;
	Classroom classroom[m] ;
	Classroom ans_classroom[m] ;
	for ( int i = 0 ; i < m ; ++i )
	{
		scanf( "%d%d" , &classroom[i].room_number , &classroom[i].people_number ) ;
		memset( classroom[i].ans , -1 , sizeof( classroom[i].ans ) ) ;
		ans_classroom[i].room_number = classroom[i].room_number ;
		classroom[i].ans_index = 0 ;
	}
	sorted( classroom , m  ) ;
	Lesson lesson[n] ;
	for ( int i = 0 ; i < n ; ++i )
	{
		scanf( "%d%d%d%d" , &lesson[i].class_number , &lesson[i].people_number , &lesson[i].start , &lesson[i].end ) ;
		lesson[i].hour = lesson[i].end - lesson[i].start ;
	}
	scanf( "%d" , &b ) ;
	sort( lesson , n ) ;
	set list[100] ;
	for ( int i = 0 ; i < 100 ; ++i )
	{
		memset( list[i].a , -1 , sizeof( list[i].a ) ) ;
		list[i].index = 0 ;
		list[i].hours = 0 ;
		list[i].class_number = 0 ;
	}
	int count = 0 ;
	for ( int i = 0 ; i < n ; ++i )
	{
		for ( int j = i ; j < n ; ++j )
			check( list , lesson , j , count ) ;
		count++ ;
	}
	for ( int i = 0 ; i < count ; ++i )
	{
		int max = 0 , index = i ;
		for ( int j = i ; j < count ; ++j )
		{
			if ( max < list[j].hours )
			{
				max = list[j].hours ;
				index = j ;
			}
		}
		swap2( &list[i] , &list[index] ) ;
	}
	if ( b == 0 )
	{
		int ans1 = 0 , ans2 = 0 ;
		for ( int i = 0 ; i < m ; ++i )
		{
			ans1 += list[i].hours ;
			ans2 += list[i].class_number ;
		}
		printf( "max hours %d\nmax courses %d\n" , ans1 , ans2 ) ;
	}
	else
	{
		int ans1 = 0 , ans2 = 0 , ans_index = 0 ;
		for ( int i = 0 ; i < count ; ++i )
		{
			bool flag = true , flag2 = true ;
			int j = 0 ;
			for ( j = m-1 ; j >= 0 ; --j )
			{
				if ( classroom[j].people_number == -1 )
					continue ;
				flag2 = false ;
				flag = true ;
				for ( int z = 0 ; z < list[i].index ; ++z )
				{
					if ( classroom[j].people_number < lesson[list[i].a[1][z]].people_number )
					{
						flag = false ;
						break ;
					}
				}
				if ( flag == true )
				{
					classroom[j].people_number = -1 ;
					break ;
				}
			}
			if ( flag && !flag2 )
			{
				int ans_index = 0 ;
				for ( int j = 0 ; j < list[i].index ; ++j )
				{
					if ( ans_index != 0 && classroom[i].ans[ans_index-1] != lesson[list[i].a[1][j]].class_number )
					{
						classroom[i].ans[ans_index++] = lesson[list[i].a[1][j]].class_number ;
					}
					else if ( ans_index == 0 )
						classroom[i].ans[ans_index++] = lesson[list[i].a[1][j]].class_number ;
					
				}
				ans1 += list[i].hours ;
				ans2 += ans_index ;
				classroom[i].ans_index = ans_index ;
			}
		}
		if ( b == 1 )
		{
			printf( "max hours %d\nmax courses %d\n" , ans1 , ans2 ) ;
		}
		else
		{
			printf( "max hours %d\nmax courses %d\n" , ans1 , ans2 ) ;
			for ( int j = 0 ; j < m ; ++j )
			{
				for ( int i = 0 ; i < m; ++i )
				{
					if ( classroom[i].room_number != ans_classroom[j].room_number )
						continue ;
					array_sort( classroom[i].ans ,classroom[i].ans_index ) ;
					for ( int j = 0 ; j < classroom[i].ans_index ; ++j )
					{
						printf( "%d %d\n" , classroom[i].ans[j] , classroom[i].room_number ) ;
					}
					classroom[i].room_number = -1 ;
				}
			}
		}
	}
} 
