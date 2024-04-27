#include <stdio.h>
int main ()
{
	int a , b , c ;
	printf( "Input three integers: " ) ;
	scanf ( "%d %d %d" , &a , &b , &c ) ;
	printf( "The result of \"%d\" ,\"%d\" , \"%d\" equals %d\n " , a , b , c , a+b+c ) ;
	return 0 ; 
}
