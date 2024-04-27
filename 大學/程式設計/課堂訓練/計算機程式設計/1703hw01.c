#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node_s{
    char name[10];
    struct Node_s* next;
}Node;

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

void construct_from_left( Node_List* head , char animal[5][10] )
{
    Node *new_node , *prev_node ;
    prev_node = head -> headp ;
    for ( int i = 0 ; i < 5 ; ++i )
    {
        new_node = malloc( sizeof( Node ) ) ;
        copy( new_node -> name , animal[i] ) ;
        if ( i == 0 )
        {
            head -> headp = new_node ;
            prev_node = new_node ;
        }
        else
        {
            prev_node -> next = new_node ;
            prev_node = new_node ;
        }
    }    
}

void construct_from_right( Node_List* head , char animal[5][10] )
{
    Node *new_node , *prev_node ;
    prev_node = head -> headp ;
    for ( int i = 4 ; i >= 0 ; --i )
    {
        new_node = malloc( sizeof( Node ) ) ;
        copy( new_node -> name , animal[i] ) ;
        if ( i == 4 )
        {
            new_node -> next = NULL ;
            prev_node = new_node ;
        }
        else
        {
            new_node -> next = prev_node ;
            prev_node = new_node ;
        }
    }   
    head -> headp = prev_node ;
}
Node* copy_list( Node *head )
{
    Node *new_node = NULL ;
    if ( head != NULL )
    {
        new_node = malloc( sizeof( Node ) ) ;
        copy( new_node -> name , head -> name ) ;
        new_node -> next = copy_list( head -> next ) ;
    }
    else
        return NULL ;
    return new_node ;
}
void print_list( Node_List *head , int x )
{
    Node *t = head -> headp ;
    printf( "List%d" , x ) ;
    while ( t != NULL )
    {
        Node *temp = t ;
        printf( " -> %s" , t -> name ) ;
        t = t -> next ;
        free( temp ) ;
    }
    printf( "\n" ) ; 
}
int main()
{
    Node_List head1,head2;
    head1.headp = NULL, head2.headp = NULL; head1.size = 0, head2.size = 0;
    char animal[5][10] ;
    memset( animal , 0 , sizeof( animal ) ) ;
    copy( animal[0] , "Alligator\0" ) ;
    copy( animal[1] , "Bear\0" ) ;
    copy( animal[2] , "Cat\0" ) ;
    copy( animal[3] , "Duck\0" ) ;
    copy( animal[4] , "Elephant\0" ) ;
    construct_from_left(&head1,animal); 
    head1.size = 5 ;
    construct_from_right(&head2,animal);
    head2.size = 5 ;
    Node_List listcopy; 
    listcopy.size = 5;
    listcopy.headp = copy_list( head1.headp ) ;
    print_list( &head1 , 1 ) ;
    print_list( &head2 , 2 ) ;
    print_list( &listcopy , 3 ) ;
    return 0;
}

