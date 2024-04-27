#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	long double v , r ;
	while ( cin >> v >> r )
	{
		v *= 1.0 ;
		r *= 1.0 ;
		long double i = v / r * 1000.0 ;
		cout << fixed << setprecision( 4 ) << i << endl;
	}
	return 0 ;
 } 
