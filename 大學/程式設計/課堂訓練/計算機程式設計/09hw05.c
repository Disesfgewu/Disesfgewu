#include <stdio.h> // Hmm...就是loop 我就不打註解了
 
int f1 ()
{
	int a ;
	scanf( "%d" , &a ) ;
	if ( a < 1 || a > 30 )
		printf( "Error\n" ) ;
	else
	{
		for ( int i = 1 ; i <= a ; ++i )
		{
			for ( int j = 1 ; j <= i ; ++j )
				printf( "*" ) ;
			for ( int j = a-i+1 ; j >= 1 ; --j )
			{
				if ( j > 9 )
				{
					printf( "%c" , ( j%10 ) + 'a' ) ;
				}
				else
					printf( "%d" , j ) ;
			}
			printf( "\n" ) ; 
		}
	}
 } 
int f2 ( )
{
	int n1 , n2 ;
	scanf( "%d\n%d" , &n1 , &n2 ) ;
	if ( n1 < 1 || n1 > 3 || n2%2 == 0 || n2 < 1 || n2 > 29 )
		printf( "Error\n" ) ;
	else if ( n1 == 1 )
	{
		for ( int i = 1 ; i <= n2/2+1 ; ++i )
		{
			for ( int j = 1 ; j <= i ; ++j )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
		for ( int i = n2/2+1-1 ; i >= 1 ; --i )
		{
			for ( int j = 1 ; j <= i ; ++j )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
	}
	else if ( n1 == 2 )
	{
		for ( int i = 1 ; i <= n2/2 ; ++i )
		{
			for ( int j = n2/2+1-i ; j >= 1 ; --j )
				printf( "#" ) ;
			for ( int j = 1 ; j <= i ; ++j )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
		for ( int i = 0 ; i <= n2/2 ; ++i )
			printf( "*" ) ;
		printf( "\n" ) ;
		for ( int i = 1 ; i <= n2/2 ; ++i )
		{
			for ( int j = 1 ; j <= i ; ++j )
				printf( "#" ) ;
			for ( int j = n2/2+1-i ; j >= 1 ; --j )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
	}
	else
	{
		int j = n2/2 ;
		for ( int i = 1 ; i <= n2 ; i+=2 )
		{
			for ( int h = 0 ; h < j ; ++h )
				printf( "#" ) ;
			j-- ;
			for ( int h = 1 ; h <= i ; ++h )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
		j = n2/2 ;
		for ( int i = n2-2 ; i >= 1 ; i-=2)
		{
			for ( int h = n2/2 ; h >= j ; --h )
				printf( "#" ) ;
			j-- ;
			for ( int h = 1 ; h <= i ; ++h )
				printf( "*" ) ;
			printf( "\n" ) ;
		}
	}
}
int main ()
{
	int num ;
	while ( scanf( "%d" , &num ) && num != 0 )
	{
		if ( num == 1 )
			f1() ;
		else if ( num == 2 )
			f2() ;
		else
		{
			printf( "Error\n" ) ;
			break ;
		}
	}
}
