#include <iostream>
#define long long int 
using namespace std;
int main()
{
	int m , n ;
	cin >> m ;
	while ( cin >> n && n != 0 )
	{
		if ( n % m == 0 )
			cout << n / m << endl;
		else
			cout << m - ( n % m ) << endl ;
	 }
 }
