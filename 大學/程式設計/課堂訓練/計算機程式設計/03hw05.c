#include <stdio.h>
int gcd ( int b , int c )
{
	int f1 = b ;
	int f2 = c ;
	if ( f1 < f2 )
	{
		int c1 = f1 ;
		f1 = f2 ;
		f2 = c1 ;
	}
	while ( f2 > 0 )
	{
		int c1 = f1%f2 ;
		f1 = f2 ;
		f2 = c1 ;
	}
	return f1 ;
 }
int main ()
{
	char nex ;
	do
	{
		int a[2][3] = {0}  ;
		char mo , kk ;
		int flag[2] = { 1 , 1 } ;
		for ( int i = 0 ; i < 2 ; ++i )
		{
			scanf( "%d%c" , &a[i][0] , &mo ) ;
			if ( a[i][0]  < 0 )
			{
				a[i][0] *= -1 ;
				flag[i] = -1 ;
			}
			if ( mo == '/' )
			{
				int h ;
				scanf( "%d%c" , &h , &kk ) ;
				a[i][1] = h ;
				a[i][2] = a[i][1] ;
				a[i][1] = a[i][0] ;
				a[i][0] = 0 ;
				int k = gcd( a[i][1] , a[i][2] ) ;
				a[i][1] /= k ;
				a[i][2] /= k ; 
			}
			else if ( mo == '(' )
			{
				char mo2 , mo3 ;
				int c ;
				scanf( "%d/%d)%c" , &a[i][1] , &a[i][2] , &kk ) ;
				a[i][1] += a[i][0]*a[i][2]  ;
				a[i][0] = 0 ;
				int k = gcd( a[i][1] , a[i][2] ) ;
				a[i][1] /= k ;
				a[i][2] /= k ;
			}
		}
		char mot ;
		fflush( stdin ) ;
		scanf( "%c%c" , &mot , &kk ) ;
		if ( a[0][2] == 0 || a[1][2] == 0 )
		{
			printf( "ERROR\n" ) ;
			goto next ;
		}
		int ansu = 0 , ansd = 0 , h = 1 ;
		if ( mot == '+' )
		{
			ansu = a[0][1]*flag[0]*a[1][2] + a[0][2]*a[1][1]*flag[1] ;
			ansd = a[0][2]*a[1][2] ;
			if ( ansu < 0 )
			{
				h = -1 ;
				ansu *= h ;
			}
			int f = gcd( ansu , ansd ) ;
			ansu /= f ;
			ansd /= f ;
		}
		else if ( mot == '-' )
		{
			ansu = a[0][1]*flag[0]*a[1][2] - a[0][2]*a[1][1]*flag[1] ;
			ansd = a[0][2]*a[1][2] ;
			if ( ansu < 0 )
			{
				h = -1 ;
				ansu *= h ;
			}
			int f = gcd( ansu , ansd ) ;
			ansu /= f ;
			ansd /= f ;
		}
		else if ( mot == '*') 
		{
			ansu = a[0][1]*a[1][1]*flag[0]*flag[1] ;
			ansd = a[0][2]*a[1][2] ;
			if ( ansu < 0 )
			{
				h = -1 ;
				ansu *= h ;
			}
			int f = gcd( ansu , ansd ) ;
			ansu /= f ;
			ansd /= f ;
		}
		else if ( mot == '/' )
		{
			ansu = a[0][1]*a[1][2]*flag[0]*flag[1] ;
			ansd = a[0][2]*a[1][1] ;
			if ( ansu < 0 )
			{
				h = -1 ;
				ansu *= h ;
			}
			int f = gcd( ansu , ansd ) ;
			ansu /= f ;
			ansd /= f ;
		}
		if ( ansu == 0 )
			printf( "0\n" ) ;
		else if ( ansu >= ansd )
		{
			int d = ansu/ansd ;
			ansu %= ansd ;
			d *= h ;
			printf( "%d(%d/%d)\n" , d , ansu , ansd ) ;
		}
		else
		{
			ansu *= h ;
			printf( "%d/%d\n" , ansu , ansd ) ;
		}
		next :
		scanf( "%c" , &nex ) ;
	} while ( nex == 'y' ) ;
	return 0 ;
}
