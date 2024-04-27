#include <iostream>
using namespace std;
int main ()
{
	int n , k ;
	while ( cin >> n >> k )
	{
		int num1[n] = {0} ,num2[k] = {0};
		for ( int i = 0 ; i < n ; i++ )
			cin >> num1[i];
		for ( int i = 0 ; i < k ; i++ )
			cin >> num2[i];
		for ( int i = 0 ; i < k ; i++ )
		{
			int j , z = 0 ;
			for ( j = 0 ; j < n ; j++ )
			{
				if ( num2[i] == num1[j] )
				{
					cout << j+1 << '\n' ;
					z++;
					break;
				}
			}
			if ( z == 0 )
				cout << "0" << '\n';
		}
	}
	return 0 ;
 } 
