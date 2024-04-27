#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int* k ( char a[3] )
{
	int* numa = malloc( 100*sizeof( int )) , flag = 0;
	for ( int i = 0 ; i < strlen(a) ; ++i )
	{
		if ( a[i] != '/' && a[i] != '(' && a[i] != ')' && a[i] != '-' ) 
			numa[i] = a[i] - '0' ;
		else if ( a[i] == '/' && flag == 0 )
		{
			flag = 1 ;
			numa[i] = -1 ;
		}
		else if ( a[i] == '(' && flag == 0 )
		{
			flag = 2 ;
			numa[i] = -2 ;
		}
		else if ( a[i] == ')' )
		{
			flag = 3 ;
			numa[i] = -3 ;
		}
		else if ( a[i] == '-' )
		{
			numa[i] = -9 ;
		}
	}
	return numa ;
}
int* k2( int* numa , char a[3] )
{
	int* num1 = malloc( 3*sizeof( int )) ;
	for ( int i = strlen(a)-1 , j = 0 , p = 1 ; i >= 0 ; i-- )
	{
		if ( numa[i] >= 0 )
		{
			num1[p] += pow( 10 , j )*numa[i] ;
			++j ; 
		}  
		else
		{
			if ( numa[i] == -9 )
				num1[2] = -9 ;
			p-- ;
			j = 0 ; 
		}
	}
	return num1 ;
}
int* k3( int* num1 )
{
	num1[1] += num1[2]*num1[0] ;
	if ( num1[2] == -9 )
		num1[1] = -1*num1[1] ; 
	return num1 ; 
}
int gcd ( int *num1 )
{
	int a = num1[0] , b = num1[1] ;
	if ( a < b )
	{
		int c = a ;
		a = b ;
		b = c ;
	}
	while ( a > 0 )
	{
		if ( a > b )
		{
			a = a%b ;
			int c = a ;
			a = b ;
			b = c ;
		}
	 } 
	return b ;
 } 
int* swi ( int* num1 )
{
	int a = num1[0]/num1[1] ;
	num1[3] = a ;
	num1[0] %= num1[1] ;
	return num1 ;
}
int* plus ( int* num1 , int* num2 )
{
	int* numk = malloc( 100*sizeof( int )) ;
	numk[0] = ( num1[0]*num2[1]+num1[1]*num2[0] ) ;
	numk[1] = ( num1[1]*num2[1] ) ;
	int k = gcd( numk ) ;
	numk[0] /= k ;
	numk[1] /= k ;
	numk = swi( numk ) ;
	return numk ;
}// (ad+bc)/bd
int* sub ( int* num1 , int* num2 )
{
	int* numk = malloc( 100*sizeof( int )) ;
	numk[0] = ( num1[0]*num2[1]-num1[1]*num2[0] ) ;
	numk[1] = ( num1[1]*num2[1] ) ;
	int k = gcd( numk ) ;
	numk[0] /= k ;
	numk[1] /= k ;
	numk = swi( numk ) ;
	return numk ;
}
int* pro( int* num1 , int* num2 )
{
	int* numk = malloc( 100*sizeof( int )) ;
	numk[0] = ( num1[0]*num2[0] ) ;
	numk[1] = ( num1[1]*num2[1] ) ;
	int k = gcd( numk ) ;
	numk[0] /= k ;
	numk[1] /= k ;
	numk = swi( numk ) ;
	return numk ;
}
int* rem( int* num1 , int* num2 )
{
	int* numk = malloc( 100*sizeof( int )) ;
	int y = num2[0] ;
	num2[0] = num2[1] ;
	num2[1] = y ;
	numk[0] = ( num1[0]*num2[0] ) ;
	numk[1] = ( num1[1]*num2[1] ) ;
	int k = gcd( numk ) ;
	numk[0] /= k ;
	numk[1] /= k ;
	numk = swi( numk ) ;
	return numk ;
}
int main ()
{
	do
	{
		char a[3] , b[3] ;
		scanf( "%s" , &a ) ;
		int flag = 0 ;
		int* numa = k( a ) ;
		scanf( "%s" , &b ) ;
		int* numb = k( b ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , numa[i] ) ;
		printf( "\n" ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , numb[i] ) ;
		printf( "\nkkkkkkkkkkkkkk\n" ) ;
		int* num1 = k2( numa , a ) ;
		int* num2 = k2( numb , b ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , num1[i] ) ;
		printf( "\n" ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , num2[i] ) ;
		printf( "\nkkkkkkkkkkkkkk\n" ) ;
		num1 = k3( num1 ) ;
		num2 = k3( num2 ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , num1[i] ) ;
		printf( "\n" ) ;
		for ( int i = 0 ; i < 3 ; ++i )
			printf( "%d " , num2[i] ) ;
		printf( "\n" ) ;
		int f = gcd( num1 ) , f2 = gcd( num2 ) ;
		num1[0] /= f ;
		num1[1] /= f ;
		num2[0] /= f2 ;
		num2[1] /= f2 ;
		char c ;
		scanf( "%s" , &c ) ; 
		int* ans;
		if ( c == '+' )
			ans = plus( num1 , num2 ) ;
		else if ( c == '-' )
			ans = sub ( num1 , num2 ) ;
		else if ( c == '*' )
			ans = pro ( num1 , num2 ) ;
		else 
			ans = rem ( num1 , num2 ) ;
		for ( int i = 0 ; i < 3 ; ++i )
		{
			printf( "%d " , ans[i] ) ;
		}
	}while ( 1 ) ;
}
