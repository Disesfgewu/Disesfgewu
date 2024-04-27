#include <stdio.h>
int main ()
{
	char input_char ;
	printf( "Input:" ) ;
	scanf( "%c" , &input_char ) ;
	if ( (int)input_char >= 48 && (int)input_char <= 57 )
	{
		printf( "The input is a number, the number is %c, the ASCII number is %d" , input_char , (int)input_char ) ;
	}
	else if ( (int)input_char >= 65 && (int)input_char <= 90 )
	{
		printf( "The input is a uppercase letter, the letter is %c, the ASCII number is %d" , input_char , (int)input_char ) ;
	}
	else if ( (int)input_char >= 97 && (int)input_char <= 122 )
	{
		printf( "The input is a lowercase letter, the letter is %c, the ASCII number is %d" , input_char , (int)input_char ) ;
	}
	else
	{
		printf( "Wrong input" ) ;
	}
}
