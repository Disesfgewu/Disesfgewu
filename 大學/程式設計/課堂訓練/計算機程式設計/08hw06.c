#include <stdio.h> // °£ªk 
#include <stdbool.h>
#include <string.h>
bool check ( int* a , int* b ) // compare which bigger
{
	for ( int i = 0 ; i < 100 ; ++i )
	{
		if ( b[i] > a[i] )
			return false ;
		if ( a[i] > b[i] )
			return true ;
	}
	return true ;
}
void minus ( int* a , int* b ) // doing the minus function
{
	for ( int i = 0 ; i < 100 ; ++i )
	{
		a[i] -= b[i] ; 
	}
	for ( int i = 99 ; i > 0 ; --i )
	{
		if ( a[i] < 0 )
		{
			a[i] += 10 ;
			a[i-1]-- ;
		}
	}
}
int main ()
{
	char numa[100] , numb[100] ;
	int indexa = 0 , indexb = 0 , count = 0 , count_index = 0 ;
	scanf( "%s" , &numa ) ;
	scanf( "%s" , &numb ) ;
	int num1[100] = {0} , num2[100] = {0} ;
	int signa = 0 , signb = 0 ; 
	if ( numa[0] == '-' )
	  	signa = 1 ;
	if ( numb[0] == '-' )
		signb = 1 ; 
	for ( int i = 0 ; i < strlen( numa ) ; ++i ) // convert the numbers from char type into integer type
		num1[i] = numa[i] - '0' ;
	if ( signa == 1 )
		for ( int i = 0 ; i < 99 ; ++i )
			num1[i] = num1[i+1] ;
	int numa_index = strlen( numa ) - signa ;
	for ( int j = strlen( numb ) - 1 ; j >= 0 ; --j )
		num2[j] = numb[j] - '0' ;
	if ( signb == 1 )
		for ( int i = 0 ; i < 99 ; ++i )
			num2[i] = num2[i+1] ;
	int numb_index = strlen( numb ) - signb ;
	int d[100] = {0} , R[100] = {0} , Q[100] = {0} ;
	for ( int i = 0 ; i < 100 ; ++i )
	{
		d[i] = num2[i] ;
	}
	bool fl = false ;
 	if ( signa != 1 ) // doing the function whick if the number a is positive
	{
		while ( 1 ) // implement the straight division
		{
			bool che = check( num1 , d ) ;
			if ( che == false )
			{
				if ( numb_index < numa_index )
				{
					count_index++ ;
					numb_index++ ;
					count=0;
					for ( int i = 99 ; i > 0 ; --i )
					{
						d[i] = d[i-1] ;
						d[i-1] = 0 ;
					 } 
				}
				else
					break ;
			}
			else
			{
				minus( num1 , d ) ;
				count++ ;
				Q[count_index] = count ;
			}
		}
		for ( int i = 0 ; i < 100 ;++i )
			d[i] = num1[i] ;
		while ( d[0] == 0 ) // get the remainder
		{
			for ( int i = 0 ; i < 99 ; ++i )
			{
				d[i] = d[i+1] ;
				d[i+1] = 0 ;
				if ( d[i] != 0 )
					fl = true ;
			}
			if ( !fl )
				break ;
		}
	}
	else // doing the function which if the number a is a negative number
	{
		count = 0 , count_index = 0 ;
		while ( 1 ) // implement the straight division
		{
			bool che = check( num1 , d ) ;
			if ( che == false )
			{
				if ( numb_index < numa_index )
				{
					count_index++ ;
					numb_index++ ;
					count=0;
					for ( int i = 99 ; i > 0 ; --i )
					{
						d[i] = d[i-1] ;
						d[i-1] = 0 ;
					 } 
				}
				else
					break ;
			}
			else
			{
				minus( num1 , d ) ;
				count++ ;
				Q[count_index] = count ;
			}
		}
		bool flk = false ;
		for ( int i = 0 ; i < 100 ; ++i )
		{
			if ( num1[i] != 0 )
				flk = true ;
		}
		if ( flk == false )
		{
			for ( int i = 0 ; i < 100 ; ++i )
				d[i] = num1[i] ;
			goto back ;
		}
		Q[count_index]++ ;
		int h = count_index ;
		while ( Q[h] > 9 )
		{
			Q[h-1] += Q[h]/10 ;
			Q[h] %= 10 ;
			h-- ;
		}
		for ( int i = 0 ; i < 100 ;++i )
		{
			int c = d[i] ;
			d[i] = num1[i] ;
			num1[i] = c ;
		}
		minus( num1 , d ) ;
		for ( int i = 0 ; i < 100 ;++i )
		{
			d[i] = num1[i] ;
		}
		while ( d[0] == 0 ) // get the remainder
		{
			for ( int i = 0 ; i < 99 ; ++i )
			{
				d[i] = d[i+1] ;
				d[i+1] = 0 ;
				if ( d[i] != 0 )
					fl = true ;
			}
			if ( !fl )
				break ;
		}
	}
	back : ;
	
	bool fg = false ;
	if ( Q[0] != 0 )
		fg = true ;
	while ( Q[0] == 0 )
	{
		for ( int i = 0 ; i < 99 ; ++i )
		{
			Q[i] = Q[i+1] ;
			Q[i+1] = 0 ;
			if ( Q[i] != 0 )
				fg = true ;
		}
		count_index -- ;
		if ( fg == false )
			break ;
	 }
	int i ; // print the answer
	if ( !fg )
		printf( "0\n" ) ; 
	else
	{
		if ( signa != signb )
				printf( "-" ) ;
		for ( int j = 0 ; j <= count_index ; ++j )
			printf( "%d" , Q[j] ) ;
		printf( "\n" ) ;
	}
	if ( !fl )
		printf( "0\n" ) ;
	else
	{
		while ( d[0] == 0 )
			for ( int i = 0 ; i < 99 ; ++i )
			{
				d[i] = d[i+1] ;
				d[i+1] = 0 ;
			}
		for ( i = 99 ; d[i] == 0 ; --i ) ; 
		for ( int j = 0 ; j < i+1 ; ++j )
			printf( "%d" , d[j] ) ;
	}
	return 0 ;
}
