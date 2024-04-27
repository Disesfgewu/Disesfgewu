#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node_s
{
    char data ;
    struct node_s *right , *left ;
    int level ;
} tree_t ;
typedef tree_t* btree ;
void cut_left  ( btree *new_node , char* line1 , char* line2 , int start , int first , int end , btree *node_sit )
{
    if ( end == -1 )
        return ;
    int j = 0 ;        
    bool flag = true ;
    for ( j = end ; j >= first ; --j )
    {
        for( int i = 0 ; i < start ; ++i )
            if ( line1[i] == line2[j] )
            {
                flag = false ;
                break ;
            }
        if ( !flag )
            break ;
    }
    if ( j == end && start != 0 )
        return ;
    int z , i ;
    bool h = true ;
    for ( i = start+1 ; i < strlen( line1 ) ; ++i )
    {
        for ( z = j+1 ; z <= end ; ++z )
            if ( line1[i] == line2[z] )
            {
                h = false ;
                break ;
            }
        if ( !h )
            break ;
    }
    for ( int i = 0 ; i < strlen( line1 ) ; ++i )
        if ( node_sit[i] -> data == line2[z] )
        {
            (*new_node) -> left = node_sit[i] ;
            return ;
        }
    return ;
}
void cut_right ( btree *new_node , char* line1 , char* line2 , int start , int first , int end , btree *node_sit )
{
    if ( first == strlen( line1 ) )
        return ;
    int j = 0 ;        
    bool flag = true ;
    for ( j = first ; j <= end ; ++j )
    {
        for( int i = 0 ; i < start ; ++i )
            if ( line1[i] == line2[j] )
            {
                flag = false ;
                break ;
            }
        if ( !flag )
            break ;
    }
    if ( j == first && start != 0 )
        return ;
    int z , i ;
    bool h = true ;
    for ( i = start+1 ; i < strlen( line1 ) ; ++i )
    {
        for ( z = first ; z < j ; ++z )
            if ( line1[i] == line2[z] )
            {
                h = false ;
                break ;
            }
        if ( !h )
            break ;
    }
    for ( int i = 0 ; i < strlen( line1 ) ; ++i )
        if ( node_sit[i] -> data == line2[z] )
        {
            (*new_node) -> right = node_sit[i] ;
            return ;
        }
}
void cut ( btree* head , char* line1 , char* line2 , btree *node_sit )
{
    btree new_node ;
    int left_index = 0 , right_index = strlen( line1 ) - 1 ;
    for ( int i = 0 ; i < strlen( line1 ) ; ++i )
    {
        int j = 0 ;
        for ( j = 0 ; j < strlen( line2 ) ; ++j )
            if ( line1[i] == line2[j] )
                break ;
        new_node = node_sit[i] ;
        cut_left ( &new_node , line1 , line2 , i , left_index , j-1 , node_sit ) ; 
        cut_right( &new_node , line1 , line2 , i , j+1 ,  right_index , node_sit ) ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cut_left_back  ( btree *new_node , char* line1 , char* line2 , int start , int first , int end , btree *node_sit )
{
    int j = 0 ;        
    bool flag = true ;
    for ( int i = start-1 ; i >= 0 ; --i )
    {
        for ( j = first ; j <= end ; ++j )
            if ( line1[i] == line2[j] )
            {
                flag = false ;
                break ;
            }
        if ( !flag )
            break ;
    }
    if ( flag )
        return ;
    for ( int i = 0 ; i < strlen( line1 ) ; ++i )
        if ( node_sit[i] -> data == line2[j] )
        {
            (*new_node) -> left = node_sit[i] ;
            return ;
        }
}
void cut_right_back ( btree *new_node , char* line1 , char* line2 , int start , int first , int end , btree *node_sit )
{
    int j = 0 ;        
    bool flag = true ;
    for ( int i = start-1 ; i >= 0 ; --i )
    {
        for ( j = first ; j <= end ; ++j )
            if ( line1[i] == line2[j] )
            {
                flag = false ;
                break ;
            }
        if ( !flag )
            break ;
    }
    if ( flag )
        return ;
    for ( int i = 0 ; i < strlen( line1 ) ; ++i )
        if ( node_sit[i] -> data == line2[j] )
        {
            (*new_node) -> right = node_sit[i] ;
            return ;
        }
}
void cut_back ( btree* head , char* line1 , char* line2 , btree *node_sit )
{
    btree new_node ;
    int left_index = 0 , right_index = strlen( line1 ) - 1 ;
    for ( int i = strlen( line1 ) - 1  ; i >= 0 ; --i )
    {
        int j = 0 ;
        for ( j = strlen( line2 ) ; j >= 0 ; --j )
            if ( line1[i] == line2[j] )
                break ;
        new_node = node_sit[i] ;
        cut_left_back ( &new_node , line1 , line2 , i , left_index , j-1 , node_sit ) ; 
        cut_right_back( &new_node , line1 , line2 , i , j+1 ,  right_index , node_sit ) ;
    }
}

void check_level( btree *head , int i )
{
    btree go = *head ;
    go -> level = i ;
    if ( go -> left != NULL )
        check_level( & go -> left , i+1 ) ; 
    if ( go -> right != NULL )
        check_level( & go -> right , i+1 ) ;
}
int main ()
{
    btree head = NULL ;
    int n ;
    char space ;
    scanf( "%d%c" , &n , &space ) ;
    char  p1 , p2 ;
    scanf( "%c%c" , &p1 , &space ) ;
    char line1[1000] , line2[1000] ;
    scanf( "%s%c" , line1 , &space ) ;
    scanf( "%c%c" , &p2 , &space ) ;
    scanf( "%s%c" , line2 , &space ) ;
    btree new_node ;
    btree node_sit[n] ;
    for ( int i = 0 ; i < n ; ++i )
    {
        new_node = malloc( sizeof( tree_t ) ) ;
        new_node -> data = line1[i] ;
        new_node -> left = NULL ;
        new_node -> right = NULL ;
        new_node -> level = 0 ;
        node_sit[i] = new_node ;
    }
    if ( p1 == 'P' && p2 == 'I' ) 
    {
        cut( &head , line1 , line2 , node_sit ) ;
        for ( int i = 0 ; i < n ; ++i )
        {
            if ( node_sit[i] -> level != 0 )
                continue ;
            check_level( &node_sit[i] , 1 ) ;
        }
        int count = 0 ; 
        int index = 1 ;
        while ( 1 )
        {
            for ( int i = 0 ; i < n ; ++i )
                if ( node_sit[i] -> level == index )
                {
                    printf( "%c" , node_sit[i] -> data ) ;
                    count++ ;
                    if ( count == n )
                        return 0 ;
                }
            index++ ;
        }
    }
    else
    {
        cut_back( &head , line1 , line2 , node_sit ) ;
        for ( int i = 0 ; i < n ; ++i )
        {
            if ( node_sit[i] -> level != 0 )
                continue ;
            check_level( &node_sit[i] , 1 ) ;
        }
        int count = 0 ; 
        int index = 1 ;
        while ( 1 )
        {
            for ( int i = 0 ; i < n ; ++i )
                if ( node_sit[i] -> level == index )
                {
                    printf( "%c" , node_sit[i] -> data ) ;
                    count++ ;
                    if ( count == n )
                        return 0 ;
                }
            index++ ;
        }
    }
}
