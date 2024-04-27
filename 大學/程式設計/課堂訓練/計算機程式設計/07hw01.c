#include <stdio.h>
#include <string.h>
int main ()
{
	char input_num[10] ;
	int i = 0 , flag = 0 ;
	printf( "input:" ) ;
	scanf( "%s" , &input_num ) ;
	for ( i = 0 ; i < strlen( input_num ) ; ++i )
	{
		if ( ( input_num[i] - '0' ) > 7 )
			flag = 1 ;
	}
	if ( flag == 0 )
		printf( "This is an octal number." ) ;
	else
		printf( "Not a number." ) ;
}
