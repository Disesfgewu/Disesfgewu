#include <stdio.h>
void sort( int *a, int b )
{
	for ( int i = b-1 ; i >= 0 ; --i )
	{
		int index = 0 , max_num = 0 ;
		for ( int j = 0 ; j <= i ; ++j )
		{
			if ( max_num < a[j] )
			{
				index = j ;
				max_num = a[j] ;
			}
		}
		int c = a[i] ;
		a[i] = a[index] ;
		a[index] = c ;
	}
}
int main ()
{
	int num[5] = {0};
	printf( "Enter 5 numbers: " ) ;
	for ( int i = 0 ; i < 5 ; ++i )
		scanf( "%d" , &num[i] ) ;
	char a ;
	scanf( "%c" , &a ) ;
	printf( "Sorted numbers: " ) ;
	sort( num , 5 ) ;
	for ( int i = 0 ; i < 5 ; ++i )
		if ( i == 4 )
			printf( "%d" , num[i] ) ;
		else
			printf( "%d " , num[i] ) ;
 } 
