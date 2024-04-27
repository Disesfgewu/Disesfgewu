#include <iostream>
using namespace std;
int main ()
{
	int a , b ;
	while ( cin >> a >> b )
	{
		int count = 0 ;
		for ( int i = a ; i <= b ; i++ )
			if ( ( ( i % 4 == 0 ) && ( i % 100 != 0 ) ) || ( i % 400 == 0 ) )
				count++ ;
		cout << count << endl; 
	}	 
	return 0;
}
