#include <stdio.h>
void swap ( int *a , int *b )
{
	int c = *a ;
	*a = *b ;
	*b = c ;
 } 
int main ()
{
	int a[2] = { 1 , 9 } ;
	swap( &a[0] , &a[1] ) ;
	printf( "%d %d" , a[0] , a[1] ) ;
}
