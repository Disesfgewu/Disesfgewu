#include <iostream>
using namespace std ;

int main () 
{
    int t ;
    cin >> t ;
    while ( t > 0 ) {
    	t-- ;
    	int a , b , c , d ;
    	cin >> a >> b >> c >> d ;
    	if ( b/a == c/b && c/b == d/c ) 
		{
			cout << a << " " << b << " " << c << " " << d << " " << d*(d/c) << endl ;
    	}
		else if ( b-a == c-b && c-b == d-c ) 
		{
			cout << a << " " << b << " " << c << " " << d << " " << d+(d-c) << endl ;
		} 
	}
    return 0 ;
}
