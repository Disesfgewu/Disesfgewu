#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	cin.sync_with_stdio( false ) ; 
	cin.tie( nullptr ) ;
	unsigned a , x ;
	int times ;
	cin >> times ;
	while ( times-- ) 
	{
		cin >> a >> x ;
		cout << ( unsigned ) ceil ( ( sqrt( ( ( ( unsigned long long ) a * ( a - 1 ) + ( x << 1) ) << 2 ) + 1 ) - 1 ) / 2 ) << '\n' ;
	}
	return 0 ;
}
