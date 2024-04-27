#include <iostream>
using namespace std;
int main ()
{
	int a ;
	while ( cin >> a )
	{
		int sum = 0 ;
		for( int i = 1 ; i < a ; i++ )
		{
			if ( a % i == 0 )
				sum += i ;
		}
		if ( sum > a )
			cout << "盈數" << '\n';
		else if ( sum == a )
			cout << "完全數" << '\n';
		else
			cout << "虧數" << '\n' ;
	}
	return 0 ;
 } 
