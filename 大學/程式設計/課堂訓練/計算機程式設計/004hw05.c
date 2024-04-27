#include <stdio.h>
#include <string.h>
int main ()
{
	long long int sum = 0 , pre_num , aft_num ;
	char num[15] , ans[10000] ;
	printf( "請輸入待轉換數字 : " ) ;
	scanf( "%s" , &num ) ;
	printf( "待轉換數字的進制(2~16) : " ) ;
	scanf( "%lld" , &pre_num ) ;
	if ( pre_num < 2 || pre_num > 16 )
	{
		printf( "ERROR\n" ) ;
		goto back ;
	}
	printf( "輸入指定的轉換進制(2~16) : " ) ;
	scanf( "%lld" , &aft_num ) ;
	if ( aft_num < 2 || aft_num > 16 )
	{
		printf( "ERROR\n" ) ;
		goto back ;
	}
	long long int kkk[6] = { 10 , 11 , 12 , 13 , 14 , 15 } ;
	int numb[15] = {0} ;
	for ( int i = 0 ; i < strlen( num ) ; ++i )
	{
		if ( num[i] - '0' > 10 )
			numb[i] = kkk[num[i] - 'A'] ;
		else
		 	numb[i] = num[i] - '0' ;
		if ( numb[i] >= pre_num )
		{
			printf( "ERROR\n" ) ;
			goto back ;
		}
	}
	for ( int i = strlen( num ) - 1 ; i >= 0 ; --i )
	{
		long long int qw = 1 ;
		qw *= numb[i] ;
		for ( int j = 0 ; j < strlen( num )-1-i ; ++j )
			qw *= pre_num ;
		sum += qw ;
	}
	int i = 0 ;
	while ( sum > 0 )
	{
		if ( sum%aft_num >= 10 )
		{
			int u = sum % aft_num - 10 ;
			if ( u == 0 )
				ans[i] = 'A' ; // char ans[100] 
			else if ( u == 1 )
				ans[i] = 'B' ;
			else if ( u == 2 )
				ans[i] = 'C' ;
			else if ( u == 3 )
				ans[i] = 'D' ;
			else if ( u == 4 )
				ans[i] = 'E' ;
			else
				ans[i] = 'F' ; 
		}
		else
			ans[i] = sum%aft_num + '0';
		sum /= aft_num ;
		++i ; 
	}
	for ( int j = strlen( ans ) - 1 ; j >= 0 ; --j )
		printf( "%c" , ans[j] ) ;
	back :
		return 0 ;
 } 
