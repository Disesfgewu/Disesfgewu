#include <stdio.h>

struct date
{
	int month ;
	int day ;	
} ;
struct data
{
	char n[100] ;
	char p[100] ;
	struct date bir ;	
} ;

int main ()
{
	struct data frien ;
	printf( "Enter the name: " ) ;
	scanf( "%s" , frien.n ) ;
	printf( "Enter the telephone number: " ) ;
	scanf( "%s" , frien.p ) ;
	printf( "Enter the birthday day: " ) ;
	scanf( "%d%d" , &frien.bir.month , &frien.bir.day ) ;
	printf( "Friend name = %s\nTelephone = %s\nBirthday = %d/%d\n" , frien.n , frien.p , frien.bir.month , frien.bir.day ) ; 
}
