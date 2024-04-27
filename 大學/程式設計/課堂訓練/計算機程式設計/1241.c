#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
   struct node* next[100] ;
   struct node* n ;
   int next_reg[100] ;
   int sit ;
   int data ;
   int next_index ;
} ;
int Max( int a , int b )
{
    if ( a > b )
        return a ;
    return b ;
}
void free_mem( struct node* head )
{
    while ( head != NULL )
    {
        struct node* temp = head ;
        head = head -> n ;
        free( temp ) ;
    }
}
int DFS( struct node* head )
{
    int max = 0 ;
    if ( head != NULL )
        for ( int i = 0 ; i < head -> next_index ; ++i )
            max = Max( max , DFS( head->next[i] ) ) ;
    return max+head->data ;
}
int main ()
{
    struct node* current = NULL ;
    struct node* head = NULL ;
    int N ;
    scanf( "%d" , &N ) ;
    int *time = (int*)malloc( (N+1)*sizeof( int ) ) ;
    memset( time , 0 , sizeof( time ) ) ;
    for ( int i = 0 ; i < N ; ++i )
    {
        current = malloc( sizeof( struct node ) ) ;
        current -> sit = i+1 ;
        current -> n = head ;
        scanf( "%d" , & current -> data ) ;
        scanf( "%d" , & current -> next_index ) ;
        memset( current -> next_reg , 0 , sizeof( current -> next_reg ) ) ;
        for ( int j = 0 ; j < current -> next_index ; ++j )
        {
            scanf( "%d" , & current -> next_reg[j] ) ;
            time[current -> next_reg[j]]++ ;
        }
        head = current ;
    }
    struct node* find = head ;
    for ( int i = 0 ; i < N ; ++i )
    {
        for ( int j = 0 ; j < find -> next_index ; ++j )
        {
            struct node* search = head ;
            while ( search && search -> sit != find -> next_reg[j] )
                search = search -> n ;
            find -> next[j] = search ;
        }
        find = find -> n ;
    }
    struct node *start[100] ;
    int index = 0 , max = 0 ;
    for ( int i = 1 ; i <= N ; ++i )
    {
        find = head ;
        if ( time[i] == 0 )
        {
            while ( find && find->sit != i )
                find = find -> n ;
            if ( find )
                start[index++] = find ;
        }
    }
    for ( int i = 0 ; i < index ; ++i )
        max = Max( max , DFS( start[i] ) ) ;
    printf( "%d\n" , max ) ;
    free( time ) ;
    free_mem( head ) ;
    return 0 ;
}
