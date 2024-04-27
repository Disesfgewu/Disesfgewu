#include <iostream>
using namespace std;
int main ()
{
	int N;
	while ( cin >> N )
	{
		int D[N][3] = {0};
		for ( int i = 0 ; i < N ; i++ )
		{
			int a , b, c ;
			cin >> a >> b >> c ;
			int j = a+1 ;
			int count = 0 ;
			while ( j < b )
			{
				if ( j % c != 0 )
				{
					cout << j << " ";
					count++;
				}
				j++;
			}
			if ( count > 0 )
				cout << endl;
			else
				cout << "No free parking spaces." << endl;
		}
	}
	return 0 ;
}
