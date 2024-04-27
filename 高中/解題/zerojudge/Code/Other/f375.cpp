#include <bits/stdc++.h>
using namespace std;

int main()
{
	int S = 0 , E = 0 , A = 0 ;
	cin >> S >> E >> A ; 
	int count = 1 ;
	for ( int i = S ; i <= E ; ++i )
	{
		if ( S == E )
		{
			printf( "1\n" ) ;
			break ;
		}
		if ( count % 10 == 1 && count != 1 )
			A -= 1 ;
		if ( A == 0 )
		{
			printf( "unsalable\n" ) ;
			break ;
		}
		if( count % 3 == 0 && count % 10 != 9 )
		{
			S += S/3 ;
		}
		else if ( count % 10 != 9 && count % 10 !=0 )
		{
			S += S/10;
		}
		if( S >= E )
		{
			printf( "%d\n", count + 1 );
			break;
		}
		count += 1 ;
	}
}

