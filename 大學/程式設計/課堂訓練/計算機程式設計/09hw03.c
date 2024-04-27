#include <stdio.h>
int main ()
{
	char num[5] = {0} ;
	printf( "Input 5 characters: " ) ;
	for ( int i = 0 ; i < 5 ; ++i )
		scanf( "%c" , &num[i] ) ;
	for ( int i = 4 ; i >= 0 ; --i )
	{
		for ( int j = 0 ; j < i ; ++j )
		{
			if ( num[j] > num[j+1] )
			{
				char c = num[j] ;
				num[j] = num[j+1] ;
				num[j+1] = c ; 
			}
		}
	}
	printf( "Sorted list: " ) ;
	for ( int i = 0 ; i < 5 ; ++i )
		if ( i != 4 )
			printf( "%c, " , num[i] ) ;
		else
			printf( "%c" , num[i] ) ;
}
