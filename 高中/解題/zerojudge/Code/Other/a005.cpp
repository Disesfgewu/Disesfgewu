#include <iostream>
using namespace std;
int main()
{
	int number[5] = {0} ;
	int t ;
	cin >> t ;
	while ( t-- )
	{
		for ( int i = 0 ; i < 5 ; i++ )
			number[i] = 0 ;
		for ( int i = 0 ; i < 4 ; i++ )
		{
			cin >> number[i] ;
		}
		int d[3] = {0} , r[3] = {0} ;
		for ( int i = 0 ; i < 3 ; i++ )
		{
			d[i] = number[i+1] - number[i] ;
			r[i] = number[i+1] / number[i] ;
		}
		if ( d[0] == d[1] )
		{
			number[4] = number[3] + d[1] ;
			for ( int i = 0 ; i < 5 ; i++ )
			{
				cout << i[number] << " " ;
			}
			cout << endl ;
		}
		else if ( r[0] == r[1] )
		{
			4[number] = 3[number] * 0[r] ;
			for ( int i = 0 ; i < 5 ; i++ )
			{
				cout << i[number] << " " ;
			}
			cout << endl;
		}
		else 
			break;
		 
	}
	return 0;
}
