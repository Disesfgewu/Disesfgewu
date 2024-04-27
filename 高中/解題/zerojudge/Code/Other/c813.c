#include <stdio.h>

long long f ( long long n )
{
	if ( n / 10 == 0 )
		return n ; 
	long long sum = 0 ;
	while ( n > 0 )
	{
		sum += n%10 ;
		n /= 10 ;
	} 
	return f( sum ) ;
}
int main ()
{
	long long n ;
	while ( scanf( "%lld" , &n ) != 0 )
	{
		if ( n == 0 )
			return 0 ;
		printf( "%lld\n" , f( n ) ) ;
	 } 
}


