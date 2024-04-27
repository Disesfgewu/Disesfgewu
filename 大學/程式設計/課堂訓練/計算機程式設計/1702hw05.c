#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct node_s
{
	int data ;
	struct node_s *next ;
} node_t ;

int main ()
{
	int n ;
	scanf( "%d" , &n ) ;
	node_t* head_node = NULL ;
	node_t* current ;
	node_t* current2 ;
	node_t* current3 ;
	for ( int i = 0 ; i < n ; ++i)
	{
		current = malloc( sizeof( node_t ) ) ;
		scanf( "%d" , & current -> data ) ;
		current -> next = head_node ;
		head_node = current ;
	}
	int c ;
	scanf( "%d" , &c ) ;
	int reverse = 0 ;
	for ( int i = 0 ; i < c ; ++i )
	{
		int instruct ;
		scanf( "%d" , &instruct ) ;
		//printf( "i = %d\n" , i ) ;
		if ( instruct == 1 )
		{
			current = malloc( sizeof( node_t ) ) ;
			scanf( "%d" , & current -> data ) ;
			current -> next = head_node ;
			head_node = current ;
		}
		else if ( instruct == 3 )
		{
			if ( head_node != NULL )
				head_node = head_node -> next ;
		}
		else if ( instruct == 2 )
		{
			if ( head_node != NULL )
			{
				node_t* cut = head_node ;
				node_t* pre = NULL ;
				while ( cut -> next != NULL )
				{
					pre = cut ;
					cut = cut -> next ;
				}
				if ( pre == NULL )
					head_node = NULL ;
				else if ( pre -> next != NULL )
					pre -> next = NULL ;
			}
		}
		else if ( instruct == 4 )
		{
			int x ;
			scanf( "%d" , &x ) ;
			if ( head_node == NULL )
				continue ;
			node_t* cut = head_node ;
			node_t* pre = NULL ;
			while ( cut && cut -> data != x )
			{
				pre = cut ;
				cut = cut -> next ;
			}
			if ( cut != NULL && pre != NULL ) 
				pre -> next = cut -> next ;
			else if ( pre == NULL && cut -> data == x )
				head_node = head_node -> next ;
		}
		else if ( instruct == 5 )
		{
			int x , t ;
			scanf( "%d%d" , &x , &t ) ;
			node_t* cut = head_node ;
			node_t* pre = NULL ; 
			while ( cut != NULL && cut -> data != x )
			{
				pre = cut ;
				cut = cut -> next ;
			}
			if ( cut == NULL )
			    continue ;
			if ( pre != NULL && cut -> data == x ) 
			{
				current = malloc( sizeof( node_t ) ) ;
				current -> data = t ;
				current -> next = cut ;
				pre -> next = current ;
			}
			else if ( cut -> data == x )
			{
				current = malloc( sizeof( node_t ) ) ;
				current -> data = t ;
				current -> next = cut ;
				head_node = current ;
			}
		}
		else if ( instruct == 6 )
		{
		    if ( head_node == NULL || head_node -> next == NULL )
		        continue ;
		    node_t* final_pos = head_node ;
		    while ( final_pos -> next != NULL )
		    {
		        final_pos = final_pos -> next ;
		    }
		    int t = final_pos -> data ;
		    node_t *curren2 = final_pos ;
		    node_t *curren3 = head_node ;
		    while ( head_node -> data != t )
		    {
		        int temp = curren3 -> data ;
		        curren3 -> data = curren3 -> next -> data ;
		        curren3 -> next -> data = temp ;
		        if ( curren3 -> next == curren2 )
		        {
		            curren2 = curren3 ;
		            curren3 = head_node ;
		        }
		        else
		        {
		            curren3 = curren3 -> next ;
		        }
		    }
 		}
		else
		{
			int x , y ;
			scanf( "%d %d" , &x , &y ) ;
			if ( head_node == NULL )
				continue ;
			node_t* x_pos = head_node ;
			node_t* y_pos = head_node ;
			node_t* x_pre = NULL ;
			node_t* y_pre = NULL ;
			//printf( "x = %d y = %d\n" , x , y ) ;
			while ( x_pos && x_pos -> data != x )
			{
				x_pre = x_pos ;
				x_pos = x_pos -> next ;
			}
			while ( y_pos && y_pos -> data != y )
			{
				y_pre = y_pos ;
				y_pos = y_pos -> next ;
			}
			if ( x_pos == NULL || y_pos == NULL )
			{
			    continue ;	
			}
			else
			{
			    int t = x_pos -> data ;
			    x_pos -> data = y_pos -> data ;
			    y_pos -> data = t ;
			}
		}
	}
	if ( head_node == NULL )
	{
		printf( "None\n" ) ;
		while ( head_node != NULL )
		{
			node_t* temp = head_node ;
			//printf( "%d " , head_node -> data ) ;
			head_node = head_node -> next ;
			free( temp ) ;
		}
	}
	else
	{
	    node_t* final_pos = head_node ;
	    while ( final_pos -> next != NULL )
	    {
	        final_pos = final_pos -> next ;
	    }
	    int t = final_pos -> data ;
	    node_t *curren2 = final_pos ;
	    node_t *curren3 = head_node ;
	    while ( head_node -> data != t )
	    {
	        int temp = curren3 -> data ;
	        curren3 -> data = curren3 -> next -> data ;
	        curren3 -> next -> data = temp ;
	        if ( curren3 -> next == curren2 )
	        {
	            curren2 = curren3 ;
	            curren3 = head_node ;
	        }
	        else
	        {
	            curren3 = curren3 -> next ;
	        }
	    }
	    while ( head_node != NULL )
		{
			node_t* temp = head_node ;
			printf( "%d " , head_node -> data ) ;
			head_node = head_node -> next ;
			free( temp ) ;
		}
	}
	free( current ) ;
	free( head_node ) ;
	return 0 ;
}
