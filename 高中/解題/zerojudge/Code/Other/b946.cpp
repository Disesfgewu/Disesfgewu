#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	//cout << 3 * pow( 5 , 4 ) + pow ( 5  , 3 ) + 3*pow( 5 , 2 ) + 4 * pow( 5 , 1 ) ;
	long double s1 , s2 , t , k;
	while ( cin >> s1 >> s2 >> t >> k )//scanf( "%d %d %d %d" , &s1 , &s2 , &t , &k ) != EOF )
	{
		long double coun1 = ( t - s2*k ) / ( s1 - s2 ) , 
			coun2 = ( t - s1*k ) / ( s2 - s1 ) ;
		if ( coun1 != int( coun1) || coun2 != int( coun2) )
			printf( "impossible\n" );
		else
		{
			long long count1 = coun1 , count2 = coun2 ;
			if ( count1 <= 0 || count2 <= 0 )
				printf( "impossible\n" );
			else
				cout << count1 << " " << count2 << '\n' ;
		}
	}
	return 0 ;
}
