#include <stdio.h>
int main ()
{
	int a , b ;
	printf( "Input two integers: " ) ;
	scanf ( "%d %d" , &a , &b ) ;
	float q = (float)a/(float)b ;
	printf( "The result of \"%d\" / \"%d\" equals %.2f\n" , a , b , q ) ; 
}
