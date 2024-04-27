#include <stdio.h>
enum color
{
	BLUE , 
	RED	
} ;

int main ()
{
	char key ;
	enum color hat ;
	printf( "Which color of the hat do you want?\n1. Red : input r\n2. Blue : input b\n" ) ;
	scanf( "%c" , &key ) ;
	hat = key ;
	switch ( hat )
	{
		case 'r' :
			printf( "You buy a red hat." ) ;
			break ;
		case 'b' :
			printf( "You buy a blue hat." ) ;
			break ;
		default :
			printf( "Without this color." ) ;
			break ;
	}
}


