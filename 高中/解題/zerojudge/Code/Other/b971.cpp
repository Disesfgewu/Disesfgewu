#include <iostream>
using namespace std;
int main ()
{
	int a , b , c ;
	while ( cin >> a >> b >> c )
	{
		if ( a != b  )
		{
			for ( int i = a ; i != b  ; i += c )
				cout << i << " ";
			cout << b ;
		}
		else 
			cout << b ;
		cout << endl;
	}
	return 0 ;
}
