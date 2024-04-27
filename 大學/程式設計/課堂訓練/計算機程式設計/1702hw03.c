#include <stdio.h>
struct data
{
	char name[100] ;
	int height ;
};
int main ()
{
	struct data student[4] = {
		"Ivy" ,
		168 
	};
	for ( int i = 1 ; i < 4 ; ++i )
	{
		printf( "Enter the name and height: " ) ;
		scanf( "%s" , student[i].name ) ;
		scanf( "%d" , &student[i].height ) ;
	}
	printf( "Who is taller than Ivy?\n" ) ;
	for ( int i = 1 ; i < 4 ; ++i )
	{
		if ( student[i].height > student[0].height )
		{
			printf( "%s, %d cm tall.\n" , student[i].name , student[i].height ) ;
		}
	}
}


