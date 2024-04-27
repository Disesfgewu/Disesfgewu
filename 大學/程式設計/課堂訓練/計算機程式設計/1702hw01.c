#include <stdio.h>
#include <string.h>

struct data
{
	char name[1000] ;
	char point[100] ;
	int get_point ;
} ; 

int main ()
{
	struct data student[3] ;
	for ( int i = 0 ; i < 3 ; ++i )
	{
		printf( "Enter the student's name and math score: " ) ;
		char line[1000] ;
		gets( line ) ;
		char* p = strtok( line , " " ) ;
		int j = 0 ;
		while ( p != NULL )
		{
			if ( j == 0 )
			{
				strcpy( student[i].name , p ) ;
			}
			else
			{
				strcpy( student[i].point , p ) ;
				student[i].get_point = 10 * ( student[i].point[0] - '0' ) + student[i].point[1] - '0' ;
				if ( student[i].get_point < 0 || student[i].point[0] == '-' )
					student[i].get_point = 0 ;
				else if ( student[i].get_point > 100 || strlen( student[i].point ) > 2 )
					student[i].get_point = 100 ;
			}
			j++ ;
			p = strtok( NULL , " " ) ;
		}
	}
	for ( int i = 0 ; i < 3 ; ++i )
	{
		printf( "Student name = %s\nMath score = %d\n" , student[i].name , student[i].get_point ) ;
	}
}
