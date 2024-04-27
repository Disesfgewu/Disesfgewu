#include <stdio.h> 
int main ()
{
	// Personal information
	char name[100] ;
	int birthday ;
	printf( "Name : " ) ;
	scanf ( "%s" , &name ) ;
	printf( "Birthday : " ) ;
	scanf ( "%d" , &birthday ) ;
	printf( "My name is %s , my birthday is %d. " , name , birthday  ) ;
	return 0 ; 
}
