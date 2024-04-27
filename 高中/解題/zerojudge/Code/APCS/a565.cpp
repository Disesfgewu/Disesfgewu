#include <stdio.h>
#include <stdlib.h>
#include <string.h>		
char s ;
int n ;
int main ()
{
	scanf( "%d " , &n );
	while ( n-- )
	{
		int count = 0 , l = 0 ;
		while ( 1 )
		{
			s = getchar_unlocked();
			if ( s == '\n' )
				break;
			else 
			{
				if ( s == 'p' )
					l++ ;
				else if ( s == 'q' )
					if ( l > 0 )
					{	
						l-- ;
						count++ ;
					}
			}
		}
		printf( "%d\n" , count );
	 } 
	 return 0 ;
 } 
