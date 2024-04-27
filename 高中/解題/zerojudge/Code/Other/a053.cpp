#include <iostream>
using namespace std;
int main ()
{
	int N;
	while ( cin >> N )
	{
		int count = 0 ;
		if ( N > 0 )
		{	
			int u ;
			if ( N - 10 >= 0 )
				u = 10 ;
			else 
				u = N;
			for ( int i = 0 ; i < u ; i++ )
				count = count + 6 ;
		}
		if ( N >= 11 )
		{
			int u ;
			if ( N - 20 >= 0 )
				u = 10 ;
			else 
				u = N-10;
			for ( int i = 0 ; i < u ; i++ )
				count = count + 2 ;
		}
		if ( N >= 21 )
		{
			int u = N - 20 ;
			for ( int i = 0 ; i < u ; i++ )
				count = count + 1 ;
		}
		if ( N >= 40 )
			count = 100;
		cout << count << endl;
	}
	return 0 ; 
}
