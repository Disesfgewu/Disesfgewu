#include <stdio.h>

int main ()
{
	int n ;
	scanf( "%d" , &n ) ;
	if ( n == 0 )
	{
		printf( "0\n" ) ;
	}
	else 
	{
		int flag = 0 ;
		while ( n > 0 )
		{
			if ( flag == 0 && n%10 == 0 )
			{
				n /= 10 ;
				continue ;
			}
			else if ( flag == 0 && n%10 != 0 )
			{
				flag = 1 ;
			}
			printf( "%d" , n%10 ) ;
			n /= 10 ;
		}
		printf( "\n" ) ;
	} 	
	return 0 ;
}
