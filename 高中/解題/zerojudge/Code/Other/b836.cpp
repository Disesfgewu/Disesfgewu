#include <iostream>

using namespace std;
long long int n , m ;

int main ()
{
	while ( cin >> n >> m )
	{
		if ( m == 0 )
			cout << "Go Kevin!!" << endl;
		else
		{
			long long int i = ( n - 1 ) / m + 1 ;
			if ( ( 1 + ( i-1 ) * m ) == n )
				cout << "Go Kevin!!" << endl;
			else
				cout << "No Stop!!" << endl;
		} 
	}
	return 0 ;
} 
