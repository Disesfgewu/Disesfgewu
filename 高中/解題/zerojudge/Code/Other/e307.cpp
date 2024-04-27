#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		if ( n == 0 )	
			cout << "0" << endl ;
		else
		{
			if ( n < 0 )
			{
				cout << "-" ;
				n *= -1 ;
			}
			int i = 0 ;
			while ( n )
			{
				//i++ ;
				int y = n%10 ;
				n /= 10 ;
				if ( y == 0 && i == 0 )
				{
					continue ;
				//	i-- ;
				}
				else
				{
					cout << y ;
					i++ ;
				}
			}
			cout << '\n' ;
		}
	}
}
