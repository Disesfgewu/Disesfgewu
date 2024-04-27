#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int num[n] = {0};
		for ( int i = 0 ; i < n ; i++ )
			cin >> num[i];
		for ( int i = 0 ; i < n ; i++ )
		{
			int count = 1 ;
			if ( num[i] == 0 )
				cout << "0" << endl;
			else
			{
				while ( num[i] > 0 )
				{
					int y = num[i] % 10 ;
					count *= y ;
					num[i] = num[i] / 10 ; 
				}
				cout << count << endl;
			}
		}
	}
	return 0 ;
}
