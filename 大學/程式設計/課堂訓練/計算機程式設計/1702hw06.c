#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node_s
{
	int coef ;
	int exp ;
	struct node_s *next ;
}node_t ;

typedef node_t * nodep_t ;

typedef struct pol_s 
{
	nodep_t root ;
 } pol_t ;
 
 void free_mem( pol_t *x )
 {
     nodep_t current = x -> root ;
     while ( current != NULL )
     {
         nodep_t temp = current ;
         current = current -> next ;
         free( temp ) ;
     }
 }
 
 void add ( pol_t *x , pol_t *y , pol_t *z )
 {
    nodep_t x_head = x -> root ;
    nodep_t y_head = y -> root ;
    nodep_t z_head = NULL ;
    nodep_t current ;
    while ( x_head != NULL || y_head != NULL )
    {
        current = malloc( sizeof( node_t ) ) ;
        current -> coef = 0 ;
        if ( x_head != NULL )
        {
            current -> coef += x_head -> coef ;
            current -> exp = x_head -> exp ;
            x_head = x_head -> next ;
        }
        if ( y_head != NULL )
        {
            current -> coef += y_head -> coef ;
            current -> exp = y_head -> exp ;
            y_head = y_head -> next ;
        }
        current -> next = z_head ;
        z_head = current ;
    }
    z -> root = z_head ;
 }
 
  void sub ( pol_t *x , pol_t *y , pol_t *z )
 {
    nodep_t x_head = x -> root ;
    nodep_t y_head = y -> root ;
    nodep_t z_head = NULL ;
    nodep_t current ;
    while ( x_head != NULL || y_head != NULL )
    {
        current = malloc( sizeof( node_t ) ) ;
        current -> coef = 0 ;
        if ( x_head != NULL )
        {
            current -> coef += x_head -> coef ;
            current -> exp = x_head -> exp ;
            x_head = x_head -> next ;
        }
        if ( y_head != NULL )
        {
            current -> coef -= y_head -> coef ;
            current -> exp = y_head -> exp ;
            y_head = y_head -> next ;
        }
        current -> next = z_head ;
        z_head = current ;
    }
    z -> root = z_head ;
 }
 
void mul ( pol_t *x , pol_t *y ,pol_t *z )
{
    nodep_t x_head = x -> root ;
    nodep_t y_head = y -> root ;
    nodep_t z_head = NULL ;
    nodep_t current ;
    while ( x_head != NULL )
    {
        y_head = y -> root ;
        while ( y_head != NULL )
        {    
            nodep_t z_current = z_head ;
            int find_exp = x_head -> exp + y_head -> exp ;
            while ( z_current != NULL && z_current -> exp != find_exp )
                z_current = z_current -> next ;
            if ( z_current == NULL )
            {
                current = malloc( sizeof( node_t ) ) ;
                current -> exp = find_exp ;
                current -> coef = x_head -> coef * y_head -> coef ;
                current -> next= z_head ;
                z_head = current ;
            }
            else
                z_current -> coef += x_head -> coef * y_head -> coef ;
            y_head = y_head -> next ;
        }
        x_head = x_head -> next ;
    }
    z -> root = z_head ;
}
int main ()
{
    int n1 , n2 ;
    pol_t x , y , z ;
    nodep_t x_head = NULL ;
    nodep_t current = NULL ;
    scanf( "%d" , &n1 ) ;
    for ( int i = 0 ; i < n1 ; ++i )
    {
        current = malloc( sizeof( node_t ) ) ;
        scanf( "%d" , & current -> coef ) ;
        current -> exp = n1 - i - 1 ;
        current -> next = x_head ;
        x_head = current ;
    }
    x.root = x_head ;
    nodep_t y_head = NULL ;
    scanf( "%d" , &n2 ) ;
    for ( int i = 0 ; i < n2 ; ++i )
    {
        current = malloc( sizeof( node_t ) ) ;
        scanf( "%d" , & current -> coef ) ;
        current -> exp = n2 - i - 1 ;
        current -> next = y_head ;
        y_head = current ;
    }
    y.root = y_head ;
    z.root = NULL ;
    add( &x , &y , &z ) ;
    nodep_t z_head = z.root ;
    while ( z_head != NULL )
    {
        printf( "%d %d " , z_head -> coef , z_head -> exp ) ;
        z_head = z_head -> next ;
    }
    free_mem( &z ) ;
    printf( "\n" ) ;
    z.root = NULL ;
    sub( &x , &y , &z ) ;
    z_head = z.root ;
    while ( z_head != NULL )
    {
        printf( "%d %d " , z_head -> coef , z_head -> exp ) ;
        z_head = z_head -> next ;
    }
    free_mem( &z ) ;
    printf( "\n" ) ;
    z.root = NULL ;
    mul( &x , &y , &z ) ;
    z_head = z.root ;
    while ( z_head != NULL )
    {
        printf( "%d %d " , z_head -> coef , z_head -> exp ) ;
        z_head = z_head -> next ;
    }
    printf( "\n" ) ;
    free_mem( &x ) ;
    free_mem( &y ) ;
    free_mem( &z ) ;
    return 0 ;
}
