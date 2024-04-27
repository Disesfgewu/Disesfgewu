#include <iostream>
using namespace std;
int main ()
{
	int N;
	while ( cin >> N )
	{
		int count = 0 ;
		for ( int i = 0 ; i < N ; i++ )
		{
			int y ;
			cin >> y;
			count += y ;
		}
		if ( count > N*59 )
			cout << "no" << endl;
		else
			cout << "yes" << '\n'; 
	}
	return 0 ;
 } 
