#include <stdio.h>
int main ()
{
	//Circumference
	float pi = 3.14 , redius , circumference ;
	printf( "Redius is : " ) ;
	scanf ( "%f" , &redius ) ;
	circumference = 2 * pi * redius ;
	printf( "Circumference is %.2f ." , circumference ) ;
	return 0 ;
 } 
