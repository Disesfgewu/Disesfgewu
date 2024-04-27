#include <stdio.h>
int main ()
{
	char input_str[10] ;
	printf( "Input string: " ) ;
	int i = 0 ;
	while ( ( input_str[i] = getchar() ) && input_str[i] != '\n' )
		++i ;
	//printf( "%d\n" , i ) ;
	for ( int j = 0 ; j <= ( i-1 )/2 ; ++j )
	{
		char c = input_str[i-j-1] ;
		input_str[i-1-j] = input_str[j] ;
		input_str[j] = c ;
	}
	//++i ;
	for ( int j = 0 ; input_str[j] != '\n' ; ++j )
		printf( "%c" , input_str[j] ) ;
	printf( "\n" ) ;
	return 0 ;
 } 
