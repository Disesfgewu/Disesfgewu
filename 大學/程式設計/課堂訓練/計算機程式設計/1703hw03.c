#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
   struct node* next[10000] ;
   int next_reg[10000] ;
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
    int N ;
    struct node *current = NULL ;
    struct node *start[10000] ;
    struct node *go[10000] ;
    scanf( "%d" , &N ) ;
    int time[N+1] ;
    memset( time , 0 , sizeof( time ) ) ;
    for ( int i = 0 ; i < N ; ++i )
    {
        current = malloc( sizeof( struct node ) ) ;
        current -> sit = i+1 ;
        go[i+1] = current ;
        scanf( "%d%d" , & current -> data , & current -> next_index ) ;
        memset( current -> next_reg , 0 , sizeof( current -> next_reg ) ) ;
        for ( int j = 0 ; j < current -> next_index ; ++j )
        {
            scanf( "%d" , & current -> next_reg[j] ) ;
            time[current -> next_reg[j]]++ ;
        }
    }
    int index = 0 , max = 0 ;
    for ( int i = 1 ; i <= N ; ++i )
    {
        for ( int j = 0 ; j < go[i] -> next_index ; ++j )
            go[i] -> next[j] = go[go[i]->next_reg[j]] ;
        if ( time[i] == 0 )
            start[index++] = go[i] ;
    }
    for ( int i = 0 ; i < index ; ++i )
        max = Max( max , DFS( start[i] ) ) ;
    printf( "%d\n" , max ) ;
    for ( int i = 0 ; i < N ; ++i )
        free( go[i] ) ;
    return 0 ;
}
