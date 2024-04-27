#include <stdio.h>
#include <stdbool.h>
int stack[3] = {0} ;
bool isFull ( )
{
	for ( int i = 0 ; i < 3 ; ++i )
	{
		if ( stack[i] != 0 )
			return true ;
	}	
	return false ; 
}
void Push( int point , int index )
{
	stack[index] = point ;
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
	int data , index = 2 ;
	while ( true )
	{	
		printf( "push or stop: " ) ;
		scanf( "%s" , &instruct ) ;
		if ( instruct[0] == 'p' )
		{
			printf( "push an integer: " ) ;
			scanf( "%d" , &data ) ;
			if ( index == -1 )
			{
				printf( "stack overflow\n" ) ;
				return 0 ;
			}
			Push( data , index-- ) ;
		}
		else
			break ;
	}
	//printf( "stack:\n" ) ;
	if ( !isFull() )
	{
		if ( index == 2 )
		{
			printf( "stack: " ) ;
			printf( "empty\n" ) ;
			PrintStack( ) ;
		}
		else
		{
			printf( "stack:\n" ) ;
			printf( "empty\n" ) ;
		}
	}
	else
	{
		printf( "stack:\n") ;
		PrintStack( ) ;
	}
}
