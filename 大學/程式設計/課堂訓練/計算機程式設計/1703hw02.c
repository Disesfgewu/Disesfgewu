#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Link node
typedef struct Node_s{
    char name[10];
    int index ;
    struct Node_s* next;
}Node;

// Head node
typedef struct{
    int size;
    Node* headp;
}Node_List;

void copy( char*a , char*b )
{
    memset( a , 0 , sizeof( a ) ) ;
    for ( int i = 0 ; i < strlen( b ) ; ++i )
    {
        a[i] = b[i] ;
    }
}

void print_list( Node_List *head )
{
    Node *t = head -> headp ;
    printf( "List" ) ;
    while ( t != NULL )
    {
        Node *temp = t ;
        printf( " -> %s" , t -> name ) ;
        t = t -> next ;
        //free( temp ) ;
    }
    printf( "\n===============\n" ) ;
}
void insertion( Node_List *head , int *count )
{
    Node *new_node = malloc( sizeof( Node ) ) , *pre = NULL ;
    
    printf( "Which index?[range:%d]: " , *count ) ;
    *count = *count + 1  ;
	int index = 0 ;
    scanf( "%d" , &index ) ;
    if ( index > *count-1 )
    {
    	printf( "Index is out of range!insert to last of list!\n"  ) ;
	}
    printf( "Enter name: " ) ;
    scanf( "%s" ,  new_node -> name ) ;
    char space ;
    space = getchar() ;
    //printf( "new_node %s\n" , new_node -> name ) ;
    if ( index == 0 )
    {
        pre = head -> headp ;
        new_node -> next = pre ;
        new_node -> index = 0 ;
        head -> headp = new_node ;
    }
    else 
    {
        pre = head -> headp ;
        Node *t = NULL ;
        while ( pre && pre -> index != index )
        {
        	t = pre ;
			pre = pre -> next ;
		}
		if ( pre == NULL )
        {
        	if ( t != NULL )
        	{
        		t -> next = new_node ;
        		new_node -> index = *count-1 ;
        		new_node -> next = NULL ;
        		return ;
			}
		}
        Node *temp = pre -> next ;
        if ( pre -> next != NULL )
            pre -> next -> index += 1 ;
        pre -> next = new_node ;
        new_node -> next = temp ;
        new_node -> index = index+1 ;
    }
}
void deletion( Node_List *head , int *count )
{
    printf( "Which index?[range:%d]: " , *count ) ;
    *count = *count - 1 ;
    int index = 0 ;
    char space  ;
    scanf( "%d%c" , &index , &space ) ;
    Node *cur = head -> headp , *pre = NULL ;
    while ( cur && cur -> index != index )
    {    
        pre = cur ;
        cur = cur -> next ;
    }
    if ( cur == NULL )
    {
    	printf( "Index is out of range!\n" ) ;
    	return ;
	}
    if ( pre != NULL )
    {
        pre -> next = cur -> next ;
        free( cur ) ;
    }
    else
    {
        head -> headp = head -> headp -> next ;
    }
}
int main()
{
    Node_List head ;
    head.headp = NULL ;
    int count = 0 ;
    while ( 1 )
    {
        char ins , space;
        printf( "What to do: " ) ;
        scanf( "%c%c" , &ins , &space ) ;
        //printf( "ins %c\n" , ins ) ;
        if ( count < 0 )
        	count = 0 ;
        switch( ins )
        {
            case 'i' :
                insertion( &head , &count ) ;
                print_list( &head ) ;
				break ;
            case 'd' :
                deletion( &head , &count ) ;
                print_list( &head ) ;
                break ;
            case 'q' :
                printf( "Exit" ) ;
                return 0 ;
            default :
                printf( "Wrong code!\n===============\n" ) ;
                //break ;
        }
    }
    return 0;
}

