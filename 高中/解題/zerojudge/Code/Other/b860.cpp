#include <iostream>
using namespace std;

int main ()
{
	int c , w ;
	while ( cin >> c >> w )
	{
		int count = 0 ;
		while ( w > 1 || c >= 12 )
		{
			if ( c >= 12 && w > 0 )
			{
				c -= 12 ;
				c += 2 ;
				w--;
				count++;
			}
			else
			{
				w--;
				c++ ;
			}
		}
		cout << count << endl;
	}
	return 0 ;
 } 
