#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		while ( n > 50 )
		{
			n-- ;
			break;
		}
		cout << n << endl;
	}
	return 0 ;
}
