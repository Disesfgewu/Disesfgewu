#include <stdio.h>
int m , n ;
int arr[10] = {0} ;
int win ( void )
{
	if ( arr[1] == arr[2] && arr[3] == arr[2] && arr[1] != 0 )
		return arr[1] ;
	else if ( arr[4] == arr[5] && arr[5] == arr[6] && arr[4] != 0 )
		return arr[4] ;
	else if ( arr[7] == arr[8] && arr[9] == arr[8] && arr[7] != 0  )
		return arr[7] ;
	else if ( arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != 0 )
		return arr[1] ;
	else if ( arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != 0 )
		return arr[2] ;
	else if ( arr[3] == arr[6] && arr[6] == arr[9] && arr[3] != 0 )
		return arr[3] ;
	else if ( arr[1] == arr[5] && arr[5] == arr[9] && arr[1] != 0  )
		return arr[1] ;
	else if ( arr[3] == arr[5] && arr[5] == arr[7] && arr[3] != 0 )
		return arr[3] ;
	else
		return 0 ;
}
int main ()
{
	scanf( "%d %d" , &m , &n ) ;
	int flag = 0 , h = m ;
	int ins , k = 0 ;
	for ( int i = 0 ; i < 2*n ;  )
	{
		scanf( "%d" , &ins ) ;
		if ( k != 0 )
		{
			i++ ;
			continue ;
		}
		if ( ins > 9 || ins < 1 )
		{
			flag = 1 ;
			continue ;
		}
		if ( arr[ins] != 0 )
		{
			flag = 1 ;
			continue ;
		}
		else
		{
			arr[ins] = h ;
			i++ ;
		}
		k = win() ;
		if ( h == 1 )
			h = 2 ;
		else
			h = 1 ;
	}
	if ( flag == 0 )
		printf( "OK\n" ) ;
	else
		printf( "Error\n" ) ;
	if ( k == 0 )
	{
		flag = 3 ;
		for ( int i = 1 ; i < 10 ; ++i )
		{
			if ( arr[i] == 0 )
			{
				arr[i] = 2 ;
				k = win() ;
				if ( k != 0 )
				{
					k = i ;
					arr[i] = 0 ;
					break ;
				}
				arr[i] = 0 ;
			}
		}
	}
	if ( k == 0 )
	{
		for ( int i = 1 ; i < 10 ; ++i )
		{
			if ( arr[i] == 0 )
			{
				arr[i] = 1 ;
				k = win() ;
				if ( k != 0 )
				{
					k = i ;
					arr[i] = 0 ;
					break ;
				 }
				arr[i] = 0 ;
			}
		}
	}
	int sum = 0 ;
	for ( int i = 1 ; i < 10 ; ++i )
	{
		if ( arr[i] == 0 )
			sum++ ;
	}
	for ( int i = 1 ; i < 10 ; ++i )
	{
		printf( "%d " , arr[i] ) ;
		if ( i % 3 == 0 )
			printf( "\n" ) ;
	  }
	if ( flag == 3 && sum > 1 ) 	
		printf( "4\n" ) ;
	else if ( flag == 3 )
		printf( "3\n" ) ;
	if ( k != 0 )
		printf( "%d\n" , k ) ;
}
