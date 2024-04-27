#include <stdio.h>
#include <stdbool.h>
int stack[3] = { 0 } ;
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
void Push( int point , int index )
{
	stack[index] = point ;
}
int main ()
{
	char instruct[4] ;
	int data , index = 2 ;
	while ( true )
	{	
		printf( "push, pop, stop: " ) ;
		scanf( "%s" , &instruct ) ;
		if ( instruct[0] == 'p' )
		{
			if ( instruct[1] == 'u' )
			{
				printf( "push an integer: " ) ;
				scanf( "%d" , &data ) ;
				Push( data , index-- ) ;
			}
			else
			{
				Pop( ++index ) ;
			}
		}
		else
			break ;
	}
	if ( !isEmpty() )
	{
		if ( index == 2 ) 
		{	
			printf( "stack: empty\n" ) ;
			PrintStack() ; 
		}
		else
			printf( "stack:\n" ) ;
	}
	else
	{
		printf( "stack:\n" ) ;
		PrintStack( ) ;
	}
}
