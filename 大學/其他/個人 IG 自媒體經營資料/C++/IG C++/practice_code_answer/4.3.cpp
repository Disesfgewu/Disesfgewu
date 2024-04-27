#include <iostream>
using namespace std;

int main ()
{
	int a, b , c ;
	while ( cin >> a >> b >> c )
	{
		int count = 0 ;
		if ( c == 0 )
		{
			if ( a == 0 || b == 0 )
			{
				cout << "AND" << endl;
				count ++;
			}
			if ( a == 0 && b == 0 )
			{
				cout << "OR" << endl;
				count++;
			}
			if ( ( a == 0 && b == 0 ) || ( a != 0 && b != 0 ) )
			{
				cout << "XOR" << endl;
				count++;
			}
		}
		else
		{
			if ( a != 0 && b != 0 )
			{
				cout << "AND" << endl;
				count++;
			}
			if ( a != 0 || b != 0 )
			{
				cout << "OR" << endl;
				count++;
			}
			if ( ( a == 0 && b != 0 ) || ( a == 1 && b == 0 ))
			{
				cout << "XOR" << endl;
				count++;
			}
		}
		if ( count == 0 )
		{
			cout << "IMPOSSIBLE" << endl;
		}	
	}
	return 0 ;
}
