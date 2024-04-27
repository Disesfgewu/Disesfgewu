#include <stdio.h>
#include <math.h>
#include <string.h>
char num[15] ;
int pre_num , aft_num , i , int_num[15] = {0} , sum = 0 , num2[100000] = {0} ;
int nk[1000] = {0};
char tran_num[1000000] ;
int numk[100][1000] = {0} ;
int f = 0 , io = 0 ;
int j = 0 , q = 0 , h = 17 , ans0[1000] = {0} , ans1[1000] 9A1588CBB127A= {0} , an = 0  ;
int find( int io  )
{
	for ( int i = 0 ; i < io ; ++i )
		if ( nk[i] > 0 )
			return 1 ;
	return 0 ;
}
void copy ( int j )
{
	memset( nk , 0 , sizeof( nk ) ) ;
	for ( int i = 0 ; i <= j ; ++i )
		nk[j-i] = ans0[i] ;
}
int main ()
{
	
	scanf( "%s\n%d\n%d" , &num , &pre_num , &aft_num ) ;
	for ( i = 0 ; num[i] ; ++i )
	{
		int_num[i] = num[i] - '0' ;
		if ( int_num[i] > 9 )
			int_num[i] -= 7 ;
		if ( int_num[i] >= pre_num )
		{
			printf( "ERROR\n" ) ;
			//goto next ;
		}
	}
	for ( int j = 0 ; j < i ; ++j )
		printf( "%d" , int_num[j] ) ;
	printf( "\n" ) ; 
	for ( int j = 0 ; j < 16 ; ++j  )
		numk[j][0] = 1 ;
	numk[i-1][0] = int_num[i-1] ;
	int le = i-1 ;
	for ( int j = 0 ; j < i-1 ; ++j )
	{
		if ( io < f )
			io = f ;
		f = 0 ;
		numk[j][f] *= int_num[j] ;
		for ( int z = 0 ; z < i-j-1 ; ++z )
		{	
			for ( int h = 0 ; h <= f ; ++h )
			{
				numk[j][h] *= pre_num ;
			}
			for ( int h = 0 ; h <= f ; ++h )
			{
				if ( numk[j][h] >= 10 )
				{
					f = h+1 ;
					while ( numk[j][h] >= 10 )
					{
						//f++ ;
						numk[j][h+1] += numk[j][h]/10  ;
						numk[j][h] %= 10 ;
					}
					printf( "%d \n opopo \n" , numk[j][h] ) ;
				}
			//	printf( "%d vvv %d\n" , f , io ) ;
			}
		}
		//le-- ;
	}
	for ( int h = 0 ; h < 16 ; ++h )
	{
		for ( int g = 0 ; g <= io ; ++g )
			printf( "%4d " , numk[h][g] ) ;
		printf( "\nmmmmmmmmmmmmmmm\n" ) ;
	}
	for ( int h = 0 ; h <= io ; ++h )
	{
		for ( j = 0 ; j < i ; ++j )
		{
			numk[16][h] += numk[j][h] ; 
		}
		while ( numk[16][h] > 10 )
		{
			numk[16][h+1] += numk[16][h] / 10 ;
			numk[16][h] %= 10 ;
			if ( io < h+1 ) 
				io = h+1 ;
		}
	}
	for ( j = 0 ; j <= io ; ++j )
		nk[j] =  numk[16][j] ;
	for ( j = 0 ; j <= io ; ++j )
		printf( "%d " , nk[j] ) ;
	printf( "\n" ) ;
	j = io ;
	while ( find( io ) ) 
	{
		while ( nk[j] < aft_num && ans0[0] == 0 && j > 0 )
		{
			j-- ;
			nk[j] += nk[j+1]*10 ;
			nk[j+1] = 0 ;
		}
		if ( j > 0 )
		{
			ans0[q] = nk[j] / aft_num ;
			nk[j-1] += 10 * ( nk[j] % aft_num ) ;
			j-- ;
			q++ ;
		}
		else 
		{
			ans0[q] = nk[0] / aft_num ;
			if ( j == -1 )
				printf( "\neeeeeeeeeeee\n%d %dj\n" , nk[0] , j);
			ans1[an] = nk[0] % aft_num ;
			for ( int r = 0 ; r <= an ; ++r )
				printf( "%d " , ans1[r] ) ;
			printf( "\n" ) ;
			an++ ;
			j = q ;
			printf( "%d\n" , q ) ;
			for ( int r = 0 ; r <= io ; ++r )
			{
				printf( "%d %d \n" , r , ans0[r] ) ;
			}
			//memset( nk , 0 , sizeof( nk ) ) ;
			copy( q ) ;
			q = 0 ;
			for ( int r = 0 ; r <= io ; ++r )
			{
				printf( "%d " , ans0[r] ) ;
			}
			printf( "\n" ) ;
			memset( ans0 , 0 , sizeof( ans0 ) ) ;
			for ( int r = 0 ; r <= io ; ++r )
			{
				printf( "%d " , nk[r] ) ; 
			}
			printf( "   qwqwqwqwqw\n" ) ;
		}
		/*if ( j == -1 )
		{
			j = q ;
			printf( "%d\n" , numk[16][0] ) ;
			ans[1][an] = numk[16][0] ;
			an++ ;
			
		}*/
	}
	for ( j = 0 ; j < an ; ++j )
		printf( "%d " , ans1[j] ) ;
	printf( "\n" ) ;
	char ans_up[10000] ;
	for ( j = an-1 ; j >= 0 ; --j )
	{
		if ( ans1[j] >= 10 )
		{
			ans1[j] += 7 ;
		}
		ans_up[an-1-j] = ans1[j] + '0';
	}
	for ( int j = 0 ; j < an ; ++j )
		printf( "%c " , ans_up[j] ) ;
	return 0 ;
}
