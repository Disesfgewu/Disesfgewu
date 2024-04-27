#include <iostream>
using namespace std;

int main ()
{
	int i = 0;
	int a[3] = {0} , b[3] = {0} , c[3] = {0};
	for ( i = 0 ; i < 3 ; i++ )
		cin >> a[i] >> b[i];
	for ( int j = 1 ; j <= 2000000 ; j++ )
	{
		if ( j % a[0] == b[0] && j % a[1] == b[1] && j % a[2] == b[2] )
		{
			cout << j << endl;
			break;
		}
	}
}
