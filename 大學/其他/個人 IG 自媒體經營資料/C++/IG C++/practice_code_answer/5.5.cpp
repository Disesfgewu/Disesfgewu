#include <iostream>
using namespace std ;

int main ()
{
	int n ;
	cin >> n ;
	if ( n == 0 )
	{
		cout << "0" << endl ;
	}
	else 
	{
		int flag = 0 ;
		while ( n > 0 )
		{
			if ( flag == 0 && n%10 == 0 )
			{
				n /= 10 ;
				continue ;
			}
			else if ( flag == 0 && n%10 != 0 )
			{
				flag = 1 ;
			}
			cout << n%10 ;
			n /= 10 ;
		}
		cout << endl ;
	} 	
	return 0 ;
}
