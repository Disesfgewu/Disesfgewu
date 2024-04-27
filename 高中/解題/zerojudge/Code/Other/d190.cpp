#include <iostream>
using namespace std ;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		if ( n == 0 )
			break ;
		int a[100] = {0} ;
		int age ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> age ;
			a[age-1]++ ;
		}
		for ( int i = 0 ; i < 100 ; i++ )
		{
			while ( a[i] )
			{
				cout << i+1 << " " ;
				a[i]-- ;
			}
		}
		cout << endl ;
	}
}
