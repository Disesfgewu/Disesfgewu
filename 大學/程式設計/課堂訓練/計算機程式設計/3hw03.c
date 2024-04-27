#include <stdio.h>
int main ()
{
	int month , day , year , hour , minute , second ;
	printf( "Input datatime: " ) ;
	scanf ( "%d/%d/%d/%d/%d/%d" , &month , &day , &year , &hour , &minute , &second ) ;
	printf( "The formatted datatime: %4d.%02d.%02d %02d:%02d:%02d\n" , year , month , day , hour , minute , second ) ;
	return 0 ; 
}
