#include <iostream>
using namespace std ;
int main ()
{
	int h , m , s , t ;
	cin >> h >> m >> s >> t ;
	int anss = h * 3600 + m * 60 + s ;
	int plus = t * ( 90 * 60 ) ;
	anss += plus ;
	if ( anss < 0 )
	{
		anss += 36 * 3600 ;
	}
	else if ( anss > 36*3600 )
		anss -= 36*3600 ;
	int ansss = anss % 60 , 
		ansm = ( anss / 60 ) % 60 ,
		ansh = ( anss / 3600 ) % 36 ;
	cout << ansh << ":" ;
	if ( ansm / 10 == 0 )
	 	cout << "0" ;
	cout << ansm << ":" ;
	if ( ansss / 10 == 0 )
		cout << "0" ;
	cout << ansss << endl ;
	
 } 
