#include <stdio.h>
#include <string.h>
struct Password
{
	char password[100] ;
	int small_letter;
	int big_letter ;
	int num ;
	int mark ;
	float point ;
	int extra ;
};
int main ()
{
	struct Password password[5] ;
	float small = 100 , big = 0 ;
	int small_index = 0 , big_index = 0 ; 
	for ( int i = 0 ; i < 5 ; ++i )
	{
		password[i].big_letter = 0 ;
		password[i].mark = 0 ;
		password[i].point = 0.0 ;
		password[i].small_letter = 0 ;
		password[i].extra = -1 ;
		password[i].num = 0 ;
	}
	int i = 0 ;
	while ( scanf( "%s" , password[i].password ) && i < 5 )
	{
		if ( strcmp( password[i].password , "-1" ) == 0 )
			break ;
		for ( int j = 0 ; j < strlen( password[i].password ) ; ++j )
		{
			if ( password[i].password[j] >= '0' && password[i].password[j] <= '9' )
			{
				if ( password[i].extra == -1 )
					password[i].extra = 0 ; 
				password[i].num++ ;
				if ( password[i].extra != -2 )
					if ( j != 0 )
						if ( password[i].password[j-1] >= '0' && password[i].password[j-1] <= '9' )
							password[i].extra = -2 ;
			}
			else if ( password[i].password[j] >= 'a' && password[i].password[j] <= 'z' )
				password[i].small_letter++ ;
			else if ( password[i].password[j] >= 'A' && password[i].password[j] <= 'Z' )
				password[i].big_letter++ ;
			else
				password[i].mark++ ;
		}
		password[i].point = (float)password[i].small_letter + 3*(float)password[i].big_letter + 2*(float)password[i].num + 4.5*(float)password[i].mark ;
		if ( password[i].extra == 0 && password[i].num >= 5 )
			password[i].point += 10 ;
		if ( small > password[i].point )
		{
			small = password[i].point ;
			small_index = i ;
		}
		if ( big < password[i].point )
		{
			big = password[i].point ;
			big_index = i ;
		}
		i++ ;
	}
	if ( i == 0 )
		return 0 ;
	printf( "%s %.1f\n" , password[big_index].password , password[big_index].point ) ;
	printf( "%s %.1f\n" , password[small_index].password , password[small_index].point ) ;
}
