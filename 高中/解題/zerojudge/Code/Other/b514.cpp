#include <iostream>
using namespace std;
int main ()
{
	int x , y , a , b , c , d , e , f , n ;
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n ;
	while ( n-- )
	{
		cin >> a >> b >> c >> d >> e >> f ;
		x = ( c * e - b * f ) / ( a * e - b * d ) ;
		y = ( c * d - a * f ) / ( b * d - a * e );
		cout << x << " " << y << '\n' ; 
	}
	return 0 ;
 } 
