#include <iostream>
using namespace std ;

int main ()
{
	int n ;
	cin >> n ;
	for ( int i = 0 ; n != 0 ; ++i )
	{
		for ( int j = 0 ; j < n ; ++j )
		{
			for ( int z = 0 ; z < n-j-1 ; ++z )
			{
				cout << "_" ;
			}
			for ( int z = 0 ; z <= j ; ++z )
			{
				cout << "+" ; 
			}
			cout << endl ;
		}
		cin >> n ; 
	}
	return 0 ;
}


