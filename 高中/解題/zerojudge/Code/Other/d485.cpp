#include <iostream>
using namespace std;
int main ()
{
	long long int a , b ;
	while ( cin >> a >> b )
	{
		int count = 0 ;
		for ( int i = a ; i <= b ; i += 2 )
			count++;
		if ( a % 2 == 1 && b % 2 == 1 )
			count--;
		cout << count << endl;
	}
	return 0 ;
}
