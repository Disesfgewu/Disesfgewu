#include <iostream>
using namespace std;
int main ()
{
	int n;
	while ( cin >> n )
	{
		int day[n] = {0}, count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> day[i];
			count += ( i+1 ) * day[i];
		}
		cout << count << endl;
	}
	return 0 ;
}
