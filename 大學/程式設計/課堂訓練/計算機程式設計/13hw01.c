#include <stdio.h>
#include <string.h>

int main ()
{
	printf( "Input string: " ) ;
	char line[1000] ; 
	fgets( line , 1000 , stdin  ) ;
	int index = 0 , count = 0 ;
	while ( line[index] != '\0' )
	{
		if ( *(line+index) == 'a' || *(line+index) == 'e'|| *(line+index) == 'i' || *(line+index) == 'o' || *(line+index) == 'u') 
			count++ ;
		else if ( *(line+index) == 'A' || *(line+index) == 'E'|| *(line+index) == 'I' || *(line+index) == 'O' || *(line+index) == 'U') 
			count++ ;
		index++ ;
	}
	printf( "There are total %d vowels.\n" , count ) ; 
 } 
