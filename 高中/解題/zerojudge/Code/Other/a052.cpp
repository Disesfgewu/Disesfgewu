#include <iostream>
using namespace std;
int main ()
{
	int N ;
	while ( cin >> N )
	{
		int a = 0 , b = 0 , c = 0 ;
		for ( int i = 0 ; i < N ; i++ )
		{
			int y ;
			cin >> y ;
			if ( y % 3 == 0 )
				a++;
			else if ( y % 3 == 1 )
				b++;
			else if ( y % 3 == 2 )
				c++;
		}	
		cout << a << " " << b << " " << c <<" "<< endl;
	}
	return 0 ;
}
