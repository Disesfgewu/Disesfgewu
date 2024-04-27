#include <stdio.h>
#include <stdbool.h>
int stack[3] = { 5 , 3 , 1 } ;
bool isEmpty ( )
{
	for ( int i = 0 ; i < 3 ; ++i )
	{
		if ( stack[i] != 0 )
			return true ;
	}	
	return false ;
}
void Pop ( int index )
{
	stack[index] = 0 ;
}
void PrintStack( )
{
	for ( int i = 0 ; i < 3 ; ++i )
	{
		if ( stack[i] == 0 )
		{
			printf( "|   |\n" ) ;
		}
		else
		{
			printf( "| %d |\n" , stack[i] ) ;
		}
		printf( "|---|\n" ) ; 
	}	
}
int main ()
{
	char instruct[4] ;
	int data , index = 0 ;
	while ( true )
	{	
		printf( "pop, stop: " ) ;
		scanf( "%s" , &instruct ) ;
		if ( instruct[0] == 'p' )
		{
			if ( !isEmpty() )
			{
				printf( "stack empty\n" ) ;
				PrintStack() ;
				return 0 ;
			}
			Pop( index++ ) ;
		}
		else
			break ;
	}
	if ( !isEmpty() )
	{
		printf( "stack: " ) ;
		printf( "empty\n" ) ;
		PrintStack( ) ;
	}
	else
	{
		printf( "stack:\n" ) ;
		PrintStack( ) ;
	}
}
