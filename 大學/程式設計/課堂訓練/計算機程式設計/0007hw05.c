#include <stdio.h> //¯BÂI¼Æ 
#include <string.h>
int numa1[10000] = {0} , numa2[10000] = {0} , numb1[10000] = {0} , numb2[10000] = {0} ;
int numa1_comp[10000] = {0} , numa2_comp[10000] = {0} , numb1_comp[10000] = {0} , numb2_comp[10000] = {0} ;
int plus[2][10000] = {0} , sub[2][10000] = {0} , po[2000][1000] = {0} , power[2][100000] = {0} , po_ans[10000] = {0} ; 
char numa[1000] , numb[1000] ;
int plus_index1 = 0 , plus_index2 = 0 ;
void plu_pp ( void ) // doing the plus function in two positive number 
{
	for ( int i = 1 ; i < 101 ; ++i ) // plus these number's integer part
	{
		plus[0][i] = numa1[i] + numb1[i] ;
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 60 ; ++i ) // plus these number's decimal part
	{
		plus[1][i] = numa2[i] + numb2[i] ;
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i ) // 22~38checking if numbers needs a carry.
		if ( plus[1][i] > 9 )
		{
			plus[1][i] %= 10 ;
			plus[1][i-1]++ ;
		}
	if ( plus[1][0] > 9 )
	{
		plus[1][0] %= 10 ;
		plus[0][100]++ ; 
	}
	for ( int i = 100 ; i > 0 ; --i )
		if ( plus[0][i] > 9 )
		{
			plus[0][i] %= 10 ;
			plus[0][i-1]++ ;
		}
	int flag = 0 ;
	for ( int i = 1 ; i <= 100 ; ++i ) // print the answer
	{
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		flag = 1 ;
		printf( "%d" , plus[0][i] ) ;
	}
	printf( "." ) ;
	for ( int i = 0 ; i <= plus_index2 ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void su_pp ( void )   // doing the minus function between two positive number by using the complement technique
{
	memset( plus , 0 , sizeof( plus ) ) ;
	for ( int i = 1 ; i < 101 ; ++i )
	{
		plus[0][i] = numa1[i] + numb1_comp[i] ; // let a number+b's complement 
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 60 ; ++i )
	{
		plus[1][i] = numa2[i] + numb2_comp[i] ;
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i ) // checking if numbers needs a carry.
		if ( plus[1][i] > 9 )
		{
			plus[1][i] %= 10 ;
			plus[1][i-1]++ ;
		}
	for ( int i = 100 ; i > plus_index1 ; --i )
		if ( plus[0][i] > 9 )
		{
			plus[0][i] %= 10 ;
			plus[0][i-1]++ ;
		}
	if ( plus[0][plus_index1] > 0 )
	{
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			plus[0][plus_index1] = 0 ;
		}
		else
		{
			plus[0][100]-- ;
			int j = 100 ;
			while ( plus[0][j] < 0 )
			{
				plus[0][j] += 10 ;
				plus[0][j-1]-- ;
				j-- ;
			}
			if ( plus[0][plus_index1] <= 0 ) // check if the number is negative or positive , if it is negative , get the 10's complement.
			{
				printf( "-" ) ;
				for ( int i = plus_index1+1 ; i <= 100 ; ++i )
					plus[0][i] = 9 - plus[0][i] ;
			}
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
	}
	else // check if the number is negative or positive , if it is negative , get the 10's complement.
	{
		printf( "-" ) ;
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			for ( int i = plus_index1+1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
		else
		{
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
			for ( int i = plus_index1+1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			plus[0][100]++ ;
			j = 100 ;
			while ( plus[0][j] > 9 )
			{
				plus[0][j] -= 10 ;
				plus[0][j-1]++ ; 
				j-- ;
			}
		}
	 }
	int flag = 0 ;
	for ( int i = plus_index1+1 ; i <= 100 ; ++i )  // print the answer
	{
		if ( plus[0][i] != 0 )
			flag = 1;
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		printf( "%d" , plus[0][i] ) ;
	}
	if ( flag == 0 )
		printf( "0" ) ; 
	flag = plus_index2 ;
	for ( flag ; plus[1][flag] == 0 && flag > -1 ; --flag ) ;
	if ( flag != -1 )
		printf( "." ) ;
	for ( int i = 0 ; i <= flag ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void plu_pm ( void ) // doing the plus function between a positive number and a negtive number , 
{					 // it just like the minus function between two positiove numbers
	memset( plus , 0 , sizeof( plus ) ) ; 
	for ( int i = 1 ; i < 101 ; ++i )
	{
		plus[0][i] = numa1[i] + numb1_comp[i] ;
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 60 ; ++i )
	{
		plus[1][i] = numa2[i] + numb2_comp[i] ;
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i )
		if ( plus[1][i] > 9 )
		{
			plus[1][i] %= 10 ;
			plus[1][i-1]++ ;
		}
	for ( int i = 100 ; i > plus_index1 ; --i )
		if ( plus[0][i] > 9 )
		{
			plus[0][i] %= 10 ;
			plus[0][i-1]++ ;
		}
	while ( plus[0][plus_index1] >= 10 )
	{
		plus[0][plus_index1-1] += plus[0][plus_index1] / 10 ;
		plus[0][plus_index1] %= 10 ;
		plus_index1-- ; 
	}
	if ( plus[0][plus_index1] > 0 )
	{
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			plus[0][plus_index1] = 0 ;
		}
		else
		{
			plus[0][100]-- ;
			int j = 100 ;
			while ( plus[0][j] < 0 )
			{
				plus[0][j] += 10 ;
				plus[0][j-1]-- ;
				j-- ;
			}
			if ( plus[0][plus_index1] <= 0 )
			{
				printf( "-" ) ;
				for ( int i = plus_index1-1 ; i <= 100 ; ++i )
					plus[0][i] = 9 - plus[0][i] ;
			}
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
	}
	else
	{
		printf( "-" ) ;
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			int k ;
			for ( k = 0 ; plus[0][k] == 0 ; ++k ) ;
			plus_index1 = k ;
			for ( int i = plus_index1-1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
		else
		{
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			for ( int i = plus_index1-1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			plus[0][100]++ ;
			j = 100 ;
			while ( plus[0][j] > 9 )
			{
				plus[0][j-1] += plus[0][j] / 10 ;
				plus[0][j] %= 10 ; 
				j-- ;
			}
		}
	 }
	int flag = 0 ; // print the answer
	for ( int i = 1 ; i <= 100 ; ++i )
	{
		if ( plus[0][i] != 0 )
			flag = 1;
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		printf( "%d" , plus[0][i] ) ;
	}
	if ( flag == 0 )
		printf( "0" ) ; 
	flag = plus_index2 ;
	for ( flag ; plus[1][flag] == 0 && flag > -1 ; --flag ) ;
	if ( flag != -1 )
		printf( "." ) ;
	for ( int i = 0 ; i <= flag ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void su_pm ( void ) // doing the minus function between a positive number and a negative number 
{                   // the same , it just like the plus function between the positive numbers.
	for ( int i = 1 ; i < 101 ; ++i )
	{
		plus[0][i] = numa1[i] + numb1[i] ;
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 60 ; ++i )
	{
		plus[1][i] = numa2[i] + numb2[i] ;
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i )
		if ( plus[1][i] > 9 )
		{
			plus[1][i] %= 10 ;
			plus[1][i-1]++ ;
		}
	if ( plus[1][0] > 9 )
	{
		plus[1][0] %= 10 ;
		plus[0][100]++ ; 
	}
	for ( int i = 100 ; i > plus_index1 ; --i )
		if ( plus[0][i] > 9 )
		{
			plus[0][i] %= 10 ;
			plus[0][i-1]++ ;
		}
	while ( plus[0][plus_index1] > 9 )
	{
		plus[0][plus_index1 ] -= 10 ;
		plus[0][plus_index1 - 1 ] ++ ;
		plus_index1-- ;
	}
	int flag = 0 ;
	for ( int i = plus_index1 ; i <= 100 ; ++i )
	{
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		flag = 1 ;
		printf( "%d" , plus[0][i] ) ;
	}
	printf( "." ) ;
	for ( int i = 0 ; i <= plus_index2 ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void plu_mm ( void ) // doing the plus function between thw negative numbers ,
{                    // it is just the same function as the plus function between two positive numbers , and plus a minus sign in front of the answer. 
	for ( int i = 1 ; i < 101 ; ++i )
	{
		plus[0][i] = numa1[i] + numb1[i] ;
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 100 ; ++i )
	{
		plus[1][i] = numa2[i] + numb2[i] ;
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i )
	{
		plus[1][i-1] += plus[1][i] / 10  ;
		plus[1][i] %= 10 ;
	}
	if ( plus[1][0] > 9 )
	{
		plus[0][100] += plus[1][0] / 10 ;
		plus[1][0] %= 10 ;
	}
	int j ;
	for ( j = 100 ; j > 0 ; --j )
	{
		plus[0][j-1] += plus[0][j] / 10  ;
		plus[0][j] %= 10 ;
	}
	int flag = 0 ;
	for ( int i = 1 ; i <= 100 ; ++i )
	{
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		flag = 1 ;
		printf( "%d" , plus[0][i] ) ;
	}
	printf( "." ) ;
	for ( int i = 0 ; i <= plus_index2 ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void su_mm ( void ) // doing the minus function between two negative numbers.
{                   // we can regard it as a plus function between a negative number and a positive number.
	memset( plus , 0 , sizeof( plus ) ) ;
	for ( int i = 1 ; i < 101 ; ++i )
	{
		plus[0][i] = numb1[i] + numa1_comp[i] ;// doing the 10's complement of number a plus the number b ( the integer part)
		if ( plus[0][i] == 0 )
			plus_index1 = i ; 
	}
	for ( int i = 0 ; i < 60 ; ++i )
	{
		plus[1][i] = numb2[i] + numa2_comp[i] ;// doing the 10's complement of number a plus the number b ( the decimal part)
		if ( plus[1][i] != 0 )
			plus_index2 = i ; 
	}
	for ( int i = plus_index2 ; i > 0 ; --i ) // checking if numbers need a carry.
		if ( plus[1][i] > 9 )
		{
			plus[1][i] %= 10 ;
			plus[1][i-1]++ ;
		}
	for ( int i = 100 ; i > plus_index1 ; --i )
		if ( plus[0][i] > 9 )
		{
			plus[0][i] %= 10 ;
			plus[0][i-1]++ ;
		}
	if ( plus[0][plus_index1] > 0 )
	{
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			plus[0][plus_index1] = 0 ;
		}
		else
		{
			plus[0][100]-- ;
			int j = 100 ;
			while ( plus[0][j] < 0 )
			{
				plus[0][j] += 10 ;
				plus[0][j-1]-- ;
				j-- ;
			}
			if ( plus[0][plus_index1] <= 0 ) // // check if the number is negative or positive , if it is negative , get the 10's complement.
			{
				printf( "-" ) ;
				for ( int i = plus_index1+1 ; i <= 100 ; ++i )
					plus[0][i] = 9 - plus[0][i] ;
			}
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
	}
	else
	{
		printf( "-" ) ;// check if the number is negative or positive , if it is negative , get the 10's complement.
		if ( plus[1][0] > 9 )
		{
			plus[1][0] -= 10 ;
			for ( int i = plus_index1+1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
		}
		else
		{
			for ( int i = 0 ; i <= plus_index2 ; ++i )
				plus[1][i] = 9 - plus[1][i] ;
			plus[1][plus_index2]++ ;
			int j = plus_index2 ;
			while ( plus[1][j] > 9 )
			{
				plus[1][j] -= 10 ;
				plus[1][j-1]++ ; 
				j-- ;
			}
			for ( int i = plus_index1+1 ; i <= 100 ; ++i )
				plus[0][i] = 9 - plus[0][i] ;
			plus[0][100]++ ;
			j = 100 ;
			while ( plus[0][j] > 9 )
			{
				plus[0][j] -= 10 ;
				plus[0][j-1]++ ; 
				j-- ;
			}
		}
	 }
	int flag = 0 ; // print the answer
	for ( int i = plus_index1+1 ; i <= 100 ; ++i )
	{
		if ( plus[0][i] != 0 )
			flag = 1;
		if ( plus[0][i] == 0 && flag == 0 )
			continue ;
		printf( "%d" , plus[0][i] ) ;
	}
	if ( flag == 0 )
		printf( "0" ) ; 
	flag = plus_index2 ;
	for ( flag ; plus[1][flag] == 0 && flag > -1 ; --flag ) ;
	if ( flag != -1 )
		printf( "." ) ;
	for ( int i = 0 ; i <= flag ; ++i )
		printf( "%d" , plus[1][i] ) ;
}
void powe( int point ) // doing the multiplication between two numbers.
{
	for ( int i = 400 ; i >= 0 ; --i ) // implement the vertical multiplication function
		for ( int j = 400 , k = i ; j >= 0 ; --j , k-- )
			po[i][k] = power[0][j]*power[1][i] ; 
	for ( int i = 400 ; i >= 0 ; --i ) 
		for ( int j = 400 ; j >= 0 ; --j )
			po_ans[i] += po[j][i] ;
	for ( int i = 400 ; i > 0 ; --i ) // check if it needs a carry
		if ( po_ans[i] > 9 )
		{
			po_ans[i-1] += po_ans[i]/10 ;
			po_ans[i] %= 10 ;
		}
	int flag = 0 ; // print the answer
	for ( int i = 0 ; i <= 400 ;++i )
	{
		if ( po_ans[i] == 0 && flag == 0 )
			continue ;
		if ( i == 400-point+1 )
			printf( "." ) ;
		flag = 1 ;
		printf( "%d" , po_ans[i] ) ;
	} 
}
int main ()
{
	scanf( "%s\n%s" , &numa , &numb ) ; // get the input
	int i ;
	if ( numa[0] == '-' ) // detecting if the numbers are positive or negative
		numa1[0] = -1 ;
	else
		numa1[0] = 1 ;
	if ( numb[0] == '-')
		numb1[0] = -1 ;
	else
		numb1[0] = 1 ;
	for ( i = 0 ; numa[i] != '.' ; ++i ) ; // cut the number to the integer part and decimal part.
	int a_point = i , j;
	for ( i = 0 ; numb[i] != '.' ; ++i ) ;
	int b_point = i ;
	for ( i = a_point -1 , j = 100 ; i >= 0 ; --i , --j )
	{
		if ( numa[i] == '-' )
			continue ;
		numa1[j] = ( numa[i] - '0') ; // convert the char type to int type 
		numa1_comp[j] = 9 - numa1[j] ; // get the 10's complement
	}
	numa1_comp[100]++ ;
	j = 0 ;
	while ( numa1_comp[j] > 9 )
	{
		numa1_comp[j] -= 10 ;
		numa1_comp[j-1]++ ;
		j-- ; 
	}
	for ( i = b_point -1 , j = 100 ; i >= 0 ; --i , --j )
	{
		if ( numb[i] == '-' )
			continue ;
		numb1[j] = ( numb[i] - '0' ) ;// same as number a 
		numb1_comp[j] = 9 - numb1[j] ;
	}
	numb1_comp[100]++ ;
	j = 0 ;
	while ( numb1_comp[j] > 9 )
	{
		numb1_comp[j] -= 10 ;
		numb1_comp[j-1]++ ;
		j-- ; 
	}
	if( a_point < b_point )
		for ( int i = 100-a_point ; i > ( 100-b_point ) ; --i )
			numa1_comp[i] = 9 ;
	else
		for ( int i = 100-b_point ; i > ( 100-a_point ) ; --i )
			numb1_comp[i] = 9 ;
	for ( i = a_point+1 , j = 0 ; i < strlen( numa ) ; ++i , ++j )
	{
		numa2[j] = ( numa[i] - '0' ) ;
		numa2_comp[j] = 9 - numa2[j] ;
	}
	numa2_comp[j-1]++ ;
	while ( numa2_comp[j-1] > 9 )
	{
		numa2_comp[j-1] -= 10 ;
		numa2_comp[j-2]++ ;
		j-- ; 
	}
	for ( i = b_point+1 , j = 0 ; i < strlen( numb ) ; ++i , ++j )
	{
		numb2[j] = ( numb[i] - '0' ) ;
		numb2_comp[j] = 9 - numb2[j] ;
	}
	numb2_comp[j-1]++ ;
	while ( numb2_comp[j-1] > 9 )
	{
		numb2_comp[j-1] -= 10 ;
		numb2_comp[j-2]++ ;
		j-- ; 
	}
	for ( i = strlen( numa ) - 1 , j = 400 ; numa[i] != '.' ; --i , --j ) // put the number a into the multiplicand array
		power[0][j] = numa[i] - '0' ;
	for ( i , j ; i > 0 ; --i , --j )
	{
		if ( numa[i-1] == '-' )
			continue ;
		power[0][j] = numa[i-1] - '0' ;
	}
	for ( i = strlen( numb ) - 1 , j = 400 ; numb[i] != '.' ; --i , --j ) // put the number b into the multiplicator array
		power[1][j] = numb[i] - '0' ;
	for ( i , j ; i > 0 ; --i , --j )
	{
		if ( numb[i-1] == '-' )
			continue ;
		power[1][j] = numb[i-1] - '0' ;
	}
	int point = strlen( numa ) - a_point + strlen( numb ) - b_point - 2 ;
	if ( numa1[0] >= 0 && numb1[0] >= 0 ) // doing each function
	{
		plu_pp() ;
		printf( "\n" ) ;
		su_pp()  ;
		printf( "\n" ) ;
		powe( point ) ;
		printf( "\n" ) ;
	}
	else if ( numa1[0] >= 0 && numb1[0] < 0 )
	{
		plu_pm() ;
		printf( "\n" ) ;
		su_pm() ;
		printf( "\n-" ) ;
		powe( point ) ;
		printf( "\n" ) ;
	}
	else if ( numa1[0] < 0 && numb1[0] < 0 )
	{
		printf( "-" ) ;
		plu_mm() ;
		printf( "\n" ) ;
		su_mm() ;
		printf( "\n" ) ;
		powe( point ) ;
		printf( "\n" ) ;
	}
	else
	{
		su_mm() ;
		printf( "\n-" ) ;
		plu_mm() ;
		printf( "\n-" ) ;
		powe( point ) ;
		printf( "\n" ) ;
	}
 } 
