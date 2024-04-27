#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		for ( int i = 1 ; i <= n ; ++i )
		{
			long long int tri[3] = {0} ;
			cin >> tri[0] >> tri[1] >> tri[2] ;
			sort( tri , tri+3 ) ;
			if ( tri[0] <= 0 )
				cout << "Case " << i << ": Invalid\n" ;
			else
			{
				if ( tri[0]+tri[1] <= tri[2] )
					cout << "Case " << i << ": Invalid\n" ;
				else if ( tri[0] == tri[1] && tri[1] == tri[2] )
					cout << "Case " << i << ": Equilateral\n" ;
				else if ( tri[0] == tri[1] || tri[1] == tri[2] )
					cout << "Case " << i << ": Isosceles\n" ;
				else
					cout << "Case " << i << ": Scalene\n" ;
			}
		}
	 } 
	 return 0 ;
 }
