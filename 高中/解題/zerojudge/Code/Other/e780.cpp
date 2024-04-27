#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
	int n , count = 0 , x = 0 , y ;
	string gift ;
	cin >> n ;
	while ( n-- )
	{
		cin >> gift ;
		if ( gift == "L" )
			x-- ;
		else if ( gift == "R" )
			x++ ;
		else
		{
			cin >> y ;
			if ( x == y )
				count++ ;
		}
	}
	cout << count << endl;
}
