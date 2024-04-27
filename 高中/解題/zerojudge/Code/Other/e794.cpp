#include <iostream>
using namespace std;
//int count = 0 ;
int f ( int n )
{
	if ( n <= 2 )
		return 1 ;
	else
		return f( n-1 ) + f( n-2 ) ;
}
int main ()
{
	int n ;
	while ( scanf( "%d" , &n ) )
	{
		int i = f( n ) ;
		int j =  i + f( n-1 ) ;
		printf( "%d:%d\n" ,i , j  );
	}
	return 0 ;
 } 
