#include <stdio.h>

int main ()
{
	int n , m ;
	printf( "How much bottles of water you want to get : " ) ;
	scanf( "%d" , &n ) ;
	printf( "Please give the money : " ) ;
	scanf( "%d" , &m ) ;
	int count = m-5*n ;
	int ans = 0 ; 
	ans += count/100 ;
	count %= 100 ;
	ans += count/50 ;
	count %= 50 ;
	ans += count/10 ;
	count %= 10 ;
	ans += count/5 ;
	count %= 5 ;
	ans += count ;
	printf( "The staff need to give %d coins.\n" , ans ) ;
	return 0 ;
}


