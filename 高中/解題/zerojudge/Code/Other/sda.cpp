#include <iostream>
#include <iomanip>
using namespace std ;
struct cube
{
	long double x[2];
	long double y[2];
	long double z[2];
};
long double tri ( cube a )
{
	return a.x[0] * a.y[1] - a.y[0]*a.x[1] ;
}
long double X( cube a )
{
	return a.z[0] * a.y[1] - a.y[0]*a.z[1] ;
 } 
long double Y( cube a )
 {
 	return a.x[0] * a.z[1] - a.z[0]*a.x[1] ;
 }
int main ()
{
	cube p ;
	while ( cin >> p.x[0] >> p.y[0] >> p.z[0] >> p.x[1] >> p.y[1] >> p.z[1] )
	{
		long double dt = tri( p ), 
					dx = X( p ),
					dy = Y( p ) ;
		if ( dt == 0.0 )
		{
			if ( dx == 0.0 && dy == 0.0 )
				cout << "Too many\n" ;
			else
				cout << "No answer\n" ;
		}
		else
		{
			cout << "x=" << fixed << setprecision(2) << dx/dt << endl << "y=" << fixed << setprecision(2) << dy/dt << endl ;
		}
	}
 } 
