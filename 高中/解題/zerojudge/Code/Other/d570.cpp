#include <iostream>
using namespace std;
int main()
{
	int n ;
	while ( cin >> n )
	{
		while ( n )
		{
			cout << n << endl;
			n/=10;
		}
	}
	return 0 ;
 } 
